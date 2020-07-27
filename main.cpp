#include <iostream>
#include <string.h>
#include <fstream>
#include "chuyenbay.h"
#include "hanhkhach.h"
#include "dsmaybay.h"

using namespace std;

int main()
{
	chuyenBay cb;
	string kt;
	PTRListChuyenBay First;
	First = NULL;
	mayBay mb;
	listMayBay lmb;
	readFile(lmb);
	//menu(lmb,mb);
//	writeFile(lmb);

	int length;
	length = doDaiDS(First);
	chuyenBay *flight = new chuyenBay[length];
	
	do
	{
		cout<<"\nNhap thong tin chuyen bay!"<<endl;
		cb = nhapChuyenBay(First,cb,lmb);
		insertNodeCB(First, cb);
		cout<<"Ban muon nhap nua khong(y/n)?";
		cin>>kt;
		if (kt == "n") break;
	} while (true);
	
	//hieuChinhCB(First, lmb);
	
	//chuyenDoiMang(First, flight);
	
	//sapXepCB(First, flight);
	
	//deleteNodeCB(First);
	
	traverseCB(First);
	
	//menuHK();
	
	/*gets(cb.soHieuMayBay);
	DSVe(lmb,cb);
	for(int i = 0; i < cb.listVe.n; i++)
	{
		cout<<cb.listVe.dsVe[i].data.soVe<<endl;
	}*/
	
	return 0;
}
