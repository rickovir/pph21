/*
	PPH 21 Project
	Nama : Ricko Virnanda
	NIM  : 201581200
*/
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "transDataPajak.h"
using namespace std;

// deklarasi object class
transDataPajak dp;

//kumpulan fungsi dan prosedur
void cs()
{
	system("cls");
}
void data_pkp()
{
	int i=0;
	cout<<"No. | Lapisan Bawah  |  Lapisan Atas  |   Besaran    |"<<endl;
	do{
		int la,lb,t;
		dp.select_pkp(&la,&lb,&t,i);
		if(i!=3)
		{
			cout<<" "<<i+1<<" | "<< lb <<"   \t| "<< la <<" \t|  "<< t <<"%\t |"<<endl;
		}
		else
		{
			cout<<" "<<i+1<<" | "<< lb <<"   \t| "<< lb <<" < \t|  "<< t <<"%\t |"<<endl;
		}
		i++;
	}
	while(i<4);
}
void ubah_pkp()
{
	int no;
	if(dp.is_empty(2)==0)
	{
		int la,lb,t;
		cs();
		cout<<"=====================Ubah Data PKP==================="<<endl;
		cout<<"====================================================="<<endl;
		data_pkp();
		cout<<" 5 | Keluar"<<endl;
		cout<<"Nomor berapa yang ingin diubah ? = "; cin>>no;
		if(no!=5){
			cout<<"Masukan Lapisan Bawah = "; cin>>lb;
			cout<<"Masukan Lapisan Atas = "; cin>>la;
			cout<<"Masukan Tarif = "; cin>>t;
			dp.insert_update_pkp(la,lb,t,no-1);
		}
		system("pause");
	}
	else
	{
		cout<<"Mohon Input Data Dahulu"<<endl;
		system("pause");
	}
}

void input_pkp()
{
	int i=0;
	if(dp.is_empty(2)==1)
	{
		do
		{
			cs();
			int la,lb,t;
			cout<<"===================Input Data PKP===================="<<endl;
			cout<<"====================================================="<<endl;
			cout<<"Data Ke "<<i+1<<endl;
			cout<<"Lapisan Penghasilan :"<<endl;
			cout<<"Masukan Terendah ="; cin>>lb;		
			if(i!=3){
				cout<<"Masukan Tertinggi ="; cin>>la;
			}else{
				cout<<"Masukan Tertinggi = Lebih dari "; cout<<lb<<endl;
			}
			cout<<"Tarif (Dalam persen) ="; cin>>t;
			dp.insert_update_pkp(la,lb,t,i);
			i++;
		}
		while(i<4);
	}
	else
	{
		cout<<"Mohon maaf data sudah penuh"<<endl;
		system("pause");
	}
}
void menu_pkp()
{
	int p;
	do{
		cs();
		cout<<"=======================Data PKP======================"<<endl;
		cout<<"====================================================="<<endl;
		cout<<"1. Input Data"<<endl;
		cout<<"2. Ubah Data"<<endl;
		cout<<"3. Kembali"<<endl;
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"Masukan Pilihan = "; cin>>p;
		if(p==1)
			input_pkp();
		else if(p==2)
			ubah_pkp();
	}
	while(p<3);
}
void data_ptkp()
{
	int i=0;
	cout<<"No.| Status          | Besaran            |"<<endl;
	do
	{	
		string st; int b;
		dp.select_ptkp(&st,&b,i);
		cout<<" "<<i+1<<" |  "<<st<<"    \t    |  "<<b<<"\t   |"<<endl;
		i++;
	}
	while(i<5);
}
void ubah_ptkp()
{
	if(dp.is_empty(1) == 0)
	{
		string st; int b;
		cs();
		int no;	
		cout<<"=====================Ubah Data PTKP=================="<<endl;
		cout<<"====================================================="<<endl;
		data_ptkp();
		cout<<" 6 | Keluar"<<endl;
		cout<<"Nomor berapa yang ingin diubah ? = "; cin>>no;
		if(no!=6){
			cout<<"Masukan Status = "; cin>>st;
			cout<<"Masukan Besaran = "; cin>>b;
			dp.insert_update_ptkp(st,b,no-1);
		}
		system("pause");
	}
	else
	{
		cout<<"Mohon Input Data Dahulu"<<endl;
		system("pause");
	}
}

void input_ptkp()
{
	int i=0;
	if(dp.is_empty(1)==1)
	{
		do
		{
			string st; int b;
			cs();
			cout<<"==================Input Data PTKP===================="<<endl;
			cout<<"====================================================="<<endl;
			cout<<"Data Ke "<<i+1<<endl;
			cout<<"Masukan Status  ="; cin>>st;
			cout<<"Masukan Besaran ="; cin>>b;
			dp.insert_update_ptkp(st,b,i);
			i++;
		}
		while(i<5);
	}
	else
	{
		cout<<"Mohon maaf data sudah penuh"<<endl;
		system("pause");
	}
}
void menu_ptkp()
{
	int p;
	do{
		cs();
		cout<<"======================Data PTKP======================"<<endl;
		cout<<"====================================================="<<endl;
		cout<<"1. Input Data"<<endl;
		cout<<"2. Ubah Data"<<endl;
		cout<<"3. Kembali"<<endl;
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"Masukan Pilihan = "; cin>>p;
		if(p==1)
			input_ptkp();
		else if(p==2)
			ubah_ptkp();
	}
	while(p<3);
}
void ubah_pajak()
{
	cs();
	string nm,sts;
	int nik,ck,gpk,tunj,iur,thr,jbk;
	cout<<"====================Ubah Data Pajak=================="<<endl;
	cout<<"====================================================="<<endl;
	cout<<"Masukan NIK pegawai yg ingin diubah = "; cin>>nik;
	dp.select_pajak(&ck,&nik,&nm,&sts,&gpk,&tunj,&iur,&thr,&jbk);
	if(ck == 1)
	{
		cout<<"Nama = "<<nm<<endl;
		cout<<"Gapok = "<<gpk<<endl;
		cout<<"Tunjangan = "<<tunj<<endl;
	}
	else
	{
		cout<<"kosong";
	}
	system("pause");
}
void input_pajak()
{
	int i=0;
	char k;
	do
	{
		string nm,st; 
		int nik,gpk,tunj,thr,iur,jbk;
		cs();
		cout<<"==================Input Data Pajak==================="<<endl;
		cout<<"====================================================="<<endl;
		cout<<"Masukan Nama  ="; cin>>nm;
		cout<<"Masukan NIK ="; cin>>nik;
		cout<<"--- Status PTKP---"<<endl; 
		data_ptkp();
		cout<<"Masukan Status = "; cin>>st;
		cout<<"Masukan Gapok = "; cin>>gpk;
		cout<<"Masukan Tunjangan = "; cin>>tunj;
		cout<<"Masukan THR = "; cin>>thr;
		cout<<"Masukan Iuran = "; cin>>iur;
		cout<<"Masukan Jumlah Bulan = "; cin>>jbk;
		dp.insert_pajak(nik,nm,st,gpk,tunj,iur,thr,jbk);
		cout<<"Tambah Lagi [y/n] ?"; cin>>k;
	}
	while(k=='y' || k=='Y');
}
void menu_pajak()
{
	int p;
	do{
		cs();
		cout<<"=====================Data Pajak======================"<<endl;
		cout<<"====================================================="<<endl;
		cout<<"1. Input DataSheet Pajak"<<endl;
		cout<<"2. Ubah DataSheet Pajak"<<endl;
		cout<<"3. Hapus DataSheet Pajak"<<endl;
		cout<<"4. Tampil Pajak"<<endl;
		cout<<"5. Kembali"<<endl;
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"Masukan Pilihan = "; cin>>p;
		if(p==1)
			input_pajak();
		else if(p==2)
			ubah_pajak();
	}
	while(p<5);
}

void fiil()
{
	dp.fiil_pkp();
	dp.fiil_ptkp();
	dp.fiil_pajak();
}
void backup()
{
	dp.backup_pkp();
	dp.backup_ptkp();
	dp.backup_pajak();
}
void menu(int *p)
{
	cs();
	cout<<"======================Menu Utama====================="<<endl;
	cout<<"====================================================="<<endl;
	cout<<"1. Data PKP"<<endl;
	cout<<"2. Data PTKP"<<endl;
	cout<<"3. Data Pajak"<<endl;
	cout<<"4. Keluar"<<endl;
	cout<<"-----------------------------------------------------"<<endl;
	cout<<"Masukan Pilihan anda = "; 
	cin>>*p;
}
void proses_menu(int p)
{
	if(p==1)
		menu_pkp();
	else if(p==2)
		menu_ptkp();
	else if(p==3)
		menu_pajak();
	else if(p>4)
		cout<<"Pilihan yang anda masukan tidak ada"<<endl;
}

// main function
int main()
{
	int pilih;
	system("title Program PPH 21");
	fiil();
	do
	{
		menu(&pilih);
		proses_menu(pilih);
	}
	while(pilih!=4);
	backup();
}
//end of main function
