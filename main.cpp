#include <iostream>
#include <string.h>
#include <fstream>
#include "chuyenbay.h"
#include "hanhkhach.h"

using namespace std;

int main()
{
	chuyenBay cb;
	string kt;
	PTRListChuyenBay First;
	First = NULL;
//	mayBay mb;
	listMayBay lmb;
	readFile(lmb);
//	menu(lmb,mb);
//	writeFile(lmb);
	do
	{
		cout<<"\nNhap thong tin chuyen bay!"<<endl;
		cb = nhapChuyenBay(First,cb,lmb);
		insertNodeCB(First, cb);
		cout<<"Ban muon nhap nua khong(y/n)?";
		cin>>kt;
		if (kt == "n") break;
	} while (true);
	traverseCB(First);
	deleteNodeCB(First);
	traverseCB(First);
	
	//menuHK();
	
	return 0;
}
