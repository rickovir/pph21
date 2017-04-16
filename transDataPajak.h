#include <conio.h>
#include <string>
#include <fstream>
using namespace std;

struct PTKP
{
	string status;
	int besaran;
	int ada=0;
} ptkp[5];

struct PKP
{
	int lapisan_bawah;
	int lapisan_atas;
	int tarif;
	int ada=0;
} pkp[4];
/*
struct DataSetahun
{
	int gapok;
	int tunj;
	int iuran;
};

struct DataHitungPajak
{
	int bruto;
	int bijab;
	int ptkp;
	int pajakpertahun;
	int pajakperbulan;
};
*/
struct DataSheetPajak
{
	DataSheetPajak* link; //to link data to next data (linked list method)
	int NIK;
	string nama;
	int gapok;
	int tunj;
	string status;
	int thr;
	int iuran;
	int jbk;
//	DataSetahun setahun;
//	DataHitungPajak hitungan;
};


//core_pajak
class transDataPajak
{
	private:	
	DataSheetPajak* head = NULL;
	
	public:
		void insert_update_pkp(int la,int lb, int t, int i)
		{
			pkp[i].lapisan_atas = la;
			pkp[i].lapisan_bawah = lb;
			pkp[i].tarif = t;
			pkp[i].ada = 1;
		}
		
		void select_pkp(int* la, int* lb, int* t,int i)
		{
			*la = pkp[i].lapisan_atas;
			*lb = pkp[i].lapisan_bawah;
			*t = pkp[i].tarif;
		}
		
		void insert_update_ptkp(string s, int b,int i)
		{
			ptkp[i].status = s;
			ptkp[i].besaran = b;
			ptkp[i].ada = 1;
		}
		
		void select_ptkp(string* s, int* b, int i)
		{
			*s = ptkp[i].status;
			*b = ptkp[i].besaran;
		}
		
		int is_head_empty()
		{
			if(head == NULL)
				return 1;
			else
				return 0;
		}
		
		void insert_pajak(int nik,string nama,string status,int gapok,int tunj,int iuran,int thr,int jbk)
		{
			DataSheetPajak* pjk = new DataSheetPajak;	
			pjk->NIK = nik;
			pjk->nama = nama;
			pjk->status = status;
			pjk->gapok = gapok;
			pjk->tunj = tunj;
			pjk->iuran = iuran;
			pjk->thr = thr;
			pjk->jbk = jbk;
			pjk->link = NULL;
			
			if(is_head_empty() == 1)
			{
				head = pjk;
				head->link = NULL;
			}
			else
			{
				pjk->link = head;
				head = pjk;
			}
		}
		void select_pajak(int *cek, int* nik,string* nama,string* status,int* gapok,int* tunj,int* iuran,int* thr,int* jbk)
		{
			*cek = 0;
			DataSheetPajak* spjk = head;
			while(spjk!=NULL)
			{
				if(spjk->NIK == *nik)
				{
					spjk->NIK = *nik;
					spjk->nama = *nama;
					spjk->status = *status;
					spjk->gapok = *gapok;
					spjk->tunj = *tunj;
					spjk->iuran = *iuran;
					spjk->thr = *thr;
					spjk->jbk = *jbk;
					*cek = 1;
					break;
				}
				else
				{
					spjk = spjk->link;
				}
			}
		}
		int is_empty(int p)
		{
			int ada = 1;
			if(p==1)
			{
				if(ptkp[4].ada==1)
					ada = 0;
			}
			else if(p==2)
			{
				if(pkp[3].ada==1)
					ada = 0;
			}
			return ada;
		}
		
		void backup_pajak()
		{
			DataSheetPajak* bup = head;
			ofstream outfile;
			outfile.open("data_pajak.txt");
			while(bup != NULL)
			{
				outfile<<bup->nama<<" "<<bup->NIK<<" "<<bup->status<<" "<<bup->gapok<<" "<<bup->tunj<<" "<<bup->thr<<" "<<bup->iuran<<" "<<bup->jbk<<endl;
				bup = bup->link;
			}
			outfile.close();
		}
		void backup_pkp()
		{
			ofstream outfile;
			outfile.open("data_pkp.txt");
			for(int i=0;i<4;i++)
			{
				outfile<<pkp[i].lapisan_atas<<" "<<pkp[i].lapisan_bawah<<" "<<pkp[i].tarif<<" "<<pkp[i].ada<<endl;
			}
			outfile.close();
		}
		void backup_ptkp()
		{
			ofstream outfile;
			outfile.open("data_ptkp.txt");
			for(int i=0;i<5;i++)
			{
				outfile<<ptkp[i].status<<" "<<ptkp[i].besaran<<" "<<ptkp[i].ada<<endl;
			}
			outfile.close();
		}
		void fiil_pajak()
		{
			ifstream infile; 
			infile.open("data_pajak.txt"); 
			string nama, status;
			int nik,gapok,tunj,iuran,thr,jbk;
			while (infile >> nama >> nik >> status >> gapok >> tunj >> thr >>iuran >>jbk)
			{
				insert_pajak(nik,nama,status,gapok,tunj,iuran,thr,jbk);
			}
		   infile.close();
		}
		void fiil_pkp()
		{
			ifstream infile; 
			infile.open("data_pkp.txt"); 
			int a, b, c, d, i = 0;
			while (infile >> a >> b >>c >>d)
			{
				pkp[i].lapisan_atas = a;
				pkp[i].lapisan_bawah = b;
				pkp[i].tarif = c;
				pkp[i].ada = d;
				i++;
			}
		   infile.close();
		}
		void fiil_ptkp()
		{
			ifstream infile; 
			infile.open("data_ptkp.txt"); 
			string a;
			int b, c, i = 0;
			while (infile >> a >> b >>c)
			{
				ptkp[i].status = a;
				ptkp[i].besaran = b;
				ptkp[i].ada = c;
				i++;
			}
		   infile.close();
		}

};
