#include <iostream>
#include "chuyenbay.h"

using namespace std;

int rangBuocThoiGian(NGAY_THANG tg)
{
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	//int posx = X_VT + 95,
		//posy = Y_VT + 10;
	if(tg.ngay > ltm->tm_mday || tg.thang > 1 + ltm->tm_mon || tg.nam > 1900 + ltm->tm_year)
	{
		if(tg.thang >= 1 + ltm->tm_mon || tg.nam > 1900 + ltm->tm_year)
		{
			if(tg.nam >= 1900 + ltm->tm_year)
			{
				//TextColor(MAUNEN);
				//gotoxy(posx + 2, posy + 28);
				cout << "HIEN TAI LA NGAY " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "! VUI LONG NHAP NGAY THANG HOP LE!";
				Sleep(1000);
				//TextColor(MAU_CONSOLE);
				//gotoxy(posx + 2, posy + 28);
				//cout << "                                                                           ";
				return TRUE;
			}
		}
	}
	if (tg.ngay == 31 && (tg.thang == 4 || tg.thang == 6 || tg.thang == 9 || tg.thang == 11))
	{
		//TextColor(MAUNEN);
		//gotoxy(posx + 2, posy + 28);
		cout << "THANG " << tg.thang << " CHI CO 30 NGAY!";
		Sleep(1000);
		//TextColor(MAU_CONSOLE);
		//gotoxy(posx + 2, posy + 28);
		//cout << "                                             ";
		return TRUE;
	}
	if((tg.ngay == 30 || tg.ngay == 31) && tg.thang == 2)
	{
		//TextColor(MAUNEN);
		//gotoxy(posx + 2, posy + 28);
		cout << "THANG " << tg.thang << " CHI CO 29 NGAY!";
		Sleep(1000);
		//TextColor(MAU_CONSOLE);
		//gotoxy(posx + 2, posy + 28);
		//cout << "                                             ";
		return TRUE;
	}
	if(!((tg.nam % 4 == 0 && tg.nam % 100 != 0) || tg.nam % 400 == 0) && tg.ngay == 29 && tg.thang == 2) // kiem tra nam nhuan
	{
		//TextColor(MAUNEN);
		//gotoxy(posx + 2, posy + 28);
		cout << "NAM " << tg.nam << " LA NAM KHONG NHUAN NEN THANG 2 CHI CO 28 NGAY! NHAP LAI!";		
		Sleep(1000);
		//TextColor(MAU_CONSOLE);
		//gotoxy(posx + 2, posy + 28);
		//cout << "                                                                                   ";			
		return TRUE;
	}
	if(tg.nam <= 1999)
	{
		//TextColor(MAUNEN);
		//gotoxy(posx + 2, posy + 28);
		cout << "VUI LONG NHAP NAM TU 1999 TRO LEN!";		
		Sleep(1000);
		//TextColor(MAU_CONSOLE);
		//gotoxy(posx + 2, posy + 28);
		//cout << "                                  ";			
		return TRUE;
	}
	return FALSE;
}

int rangBuocGio(NGAY_THANG h)
{
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	
	if (h.gio > 24 || h.gio < 1)
	{
		cout << "GIO BAT DAU TU 1H DEN 24H! VUI LONG NHAP GIO HOP LE!";
		return TRUE;
	}
	if (h.phut > 59 || h.phut < 0)
	{
		cout << "GIO BAT DAU TU 0 DEN 59 PHUT! VUI LONG NHAP PHUT HOP LE!";
		return TRUE;
	}
	if (h.gio > ltm->tm_hour)
	{
		cout << "HIEN TAI LA NGAY " << ltm->tm_hour << ":" << 1 + ltm->tm_min << "! VUI LONG NHAP GIO PHUT HOP LE!";
		return TRUE;
	}
	return FALSE;
}

int toTime(NGAY_THANG time)
{
	int sumyear = 0;
	int summonth = 0;
	for (int i = 1999; i < time.nam; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
		{
			sumyear = sumyear + 366;
		}
		else
		{
			sumyear = sumyear + 365;
		}
	}
	for (int j = 1; j < time.thang; j++)
	{
		if (j == 2)
		{
			if ((time.nam % 4 == 0 && time.nam % 100 != 0) || time.nam % 400 == 0)
			{
				summonth = summonth + 29;
			}
			else
			{
				summonth = summonth + 28;
			}
		}
		if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
		{
			summonth = summonth + 31;
		}
		if (j == 4 || j == 6 || j == 9 || j == 11)
		{
			summonth = summonth + 30;
		}
	}
	return sumyear + summonth + time.ngay;
}

chuyenBay nhapChuyenBay(PTRListChuyenBay &First, chuyenBay &cb, listMayBay lmb) 
{
	nhapMaCB(First, cb.maChuyenBay);
	cout<<"Nhap ngay gio khoi hanh!"<<endl;
	cb.ngayKhoiHanh = nhapNgayThangNam();
	cb.gioKhoiHanh = nhapGioKhoiHanh();
	fflush(stdin);
	cout<<"Nhap san bay den: ";
	gets(cb.sanBayDen);
	nhapSoHieuCB(lmb, cb.soHieuMayBay);
	
	return cb;
}

void xuatChuyenBay(chuyenBay cb)
{
	cout<<"\nMa chuyen bay: "<<cb.maChuyenBay<<endl;
	cout<<"Ngay khoi hanh: "<<cb.ngayKhoiHanh.ngay<<"-"<<cb.ngayKhoiHanh.thang<<"-"<<cb.ngayKhoiHanh.nam<<endl;
	cout<<"Gio khoi hanh: "<<cb.gioKhoiHanh.gio<<":"<<cb.gioKhoiHanh.phut<<endl;
	cout<<"San bay den: "<<cb.sanBayDen<<endl;
}

void insertNodeCB(PTRListChuyenBay &First, chuyenBay cb)
{
	PTRListChuyenBay p = new listChuyenBay;
		p->data = cb ; 
		p->next=NULL;
		if (First==NULL) 
			First = p;
		else 
		{ PTRListChuyenBay Last;
	       for (Last = First;Last->next !=NULL; Last=Last->next) ;		
	       Last->next = p;
	   	}
}

void traverseCB(PTRListChuyenBay First)
{
	for(PTRListChuyenBay p = First; p != NULL; p = p->next)
	{
		xuatChuyenBay(p->data);
	}
}

void deleteNodeCB(PTRListChuyenBay &First)
{
	char maChuyenBay[20];
	PTRListChuyenBay p;
	string kt;
	Xoatiep	 :
		cout << "\nMa chuyen bay vien muon xoa :" ;
		fflush(stdin); 
		gets(maChuyenBay);
		
		if (stricmp(First->data.maChuyenBay,maChuyenBay) == 0)
		{
			cout<<"Ban co that su muon xoa hay khong (Y/N)?";
			cin>>kt;
			if (kt == "y") 
			{
				PTRListChuyenBay p = First;
				First = p ->next ; 
				delete p;
				cout<<"Xoa thanh cong! Ban co muon xoa nua khong(y/n)?";
				cin>>kt;
				if (kt == "y")
				{
					goto Xoatiep;
				}
				return;
			}
			else
			{
				cout<<"Ban co muon xoa nua khong(y/n)?";
				cin>>kt;
				if (kt == "y")
				{
					goto Xoatiep;
				}
				return;
			}
		}
		for(p = First; p->next != NULL && stricmp(p->next->data.maChuyenBay, maChuyenBay) != 0; p = p->next);
		if (p->next!=NULL)
		{
			cout<<"Ban co that su muon xoa hay khong (Y/N)?";
			cin>>kt;
			if (kt == "y") 
			{
				PTRListChuyenBay q = p->next ;
				p->next= q->next;
				delete q;
				cout<<"Xoa thanh cong! Ban co muon xoa nua khong(y/n)?";
				cin>>kt;
				if (kt == "y")
				{
					goto Xoatiep;
				}
				return;
			}
			else
			{
				cout<<"Ban co muon xoa nua khong(y/n)?";
				cin>>kt;
				if (kt == "y")
				{
					goto Xoatiep;
				}
				return;
			}
		}
		else 
		{
			cout << "Ma chuyen bay muon xoa khong ton tai. Ban co muon xoa nua khong(y/n)?";
			cin>>kt;
			if (kt == "y")
			{
				goto Xoatiep;
			}
		}
		return;
}

/*void danhSachVe (PTRListChuyenBay pCB, chuyenBay cb)
{
	char day[24] = {'A','B','C','D','E','F','G','H','I'};
}*/

bool searchNodeCB(PTRListChuyenBay First, char *s)
{
	for (PTRListChuyenBay p = First; p != NULL; p = p->next)
	{
		if(stricmp(p->data.maChuyenBay,s) == 0)
			return true;
	}
	return false;
}

void nhapSoHieuCB(listMayBay &lmb, char *soHieu)
{
	Nhap:
		fflush(stdin);
		cout<<"Nhap so hieu may bay: ";
		gets(soHieu);
		int l = strlen(soHieu);
		chuanHoaChuoi(soHieu,l);
		if (searchNodeMB(lmb,soHieu) < 0)
		{
			cout<<"Khong tim thay so hieu nay. Vui long nhap lai!"<<endl;
			goto Nhap;
		}
		else if (checkNhapKyTu(soHieu) == 2)
		{
			cout<<"Ban khong duoc nhap ki tu dac biet. Vui long nhap lai!"<<endl;
			goto Nhap;
		}
		else if (checkNhapKyTu(soHieu) == 0)
		{
			cout<<"Khong duoc de trong. Vui long nhap lai!"<<endl;
			goto Nhap;
		}
}

void nhapMaCB(PTRListChuyenBay &First, char *MaCB)
{
	Nhap:
		fflush(stdin);
		cout<<"Nhap ma chuyen bay: ";
		gets(MaCB);
		int l = strlen(MaCB);
		chuanHoaChuoi(MaCB,l);
		if (searchNodeCB(First,MaCB))
		{
			cout<<"Ma nay da ton tai. Vui long nhap lai!"<<endl;
			goto Nhap;
		}
		else if (checkNhapKyTu(MaCB) == 2)
		{
			cout<<"Ban khong duoc nhap ki tu dac biet. Vui long nhap lai!"<<endl;
			goto Nhap;
		}
		else if (checkNhapKyTu(MaCB) == 0)
		{
			cout<<"Khong duoc de trong. Vui long nhap lai!"<<endl;
			goto Nhap;
		}
}

NGAY_THANG nhapNgayThangNam()
{
	NGAY_THANG nt;
	do
	{
		cout<<"Nhap ngay khoi hanh: ";
		cin>>nt.ngay;
		cout<<"Nhap thang khoi hanh: ";
		cin>>nt.thang;
		cout<<"Nhap nam khoi hanh: ";
		cin>>nt.nam;
		if (rangBuocThoiGian(nt) == FALSE)
		{
			break;
		}
		cout << endl;
	}
	while (1);
	
	/*cout<<"Nhap ngay khoi hanh: ";
	cin>>nt.ngay;
	cout<<"Nhap thang khoi hanh: ";
	cin>>nt.thang;
	cout<<"Nhap nam khoi hanh: ";
	cin>>nt.nam;*/
	
	return nt;
}

NGAY_THANG nhapGioKhoiHanh()
{
	NGAY_THANG gp;
	do
	{
		cout<<"Nhap gio khoi hanh: ";
		cin>>gp.gio;
		cout<<"Nhap phut khoi hanh: ";
		cin>>gp.phut;
		if (rangBuocGio(gp) == FALSE)
		{
			break;
		}
		cout << endl;
	}
	while (1);
	
	/*cout<<"Nhap gio khoi hanh: ";
	cin>>gp.gio;
	cout<<"Nhap phut khoi hanh: ";
	cin>>gp.phut;*/
	
	return gp;
}

int doDaiDS(PTRListChuyenBay First)
{
	int doDai = 0;
	for (PTRListChuyenBay p = First; p != NULL; p = p->next)
	{
		doDai++;
	}
	return doDai;
}

void chuyenDoiMang(PTRListChuyenBay First, chuyenBay *flight)
{
	/*int length;
	length = doDaiDS(First);
	flight = new chuyenBay[length];*/
	int i = 0;
	for (PTRListChuyenBay p = First; p != NULL; p = p->next)
	{
		//flight[i] = p->data;
		//flight[i] = new chuyenBay;
		strcpy(flight[i].maChuyenBay, p->data.maChuyenBay);
		flight[i].ngayKhoiHanh = p->data.ngayKhoiHanh;
		flight[i].gioKhoiHanh = p->data.gioKhoiHanh;
		strcpy(flight[i].sanBayDen, p->data.sanBayDen);
		i++;
	}
}

void quickSort(chuyenBay *flight, int q, int r)
{
	//chuyenBay *temp = new chuyenBay;
	chuyenBay temp;
	int i, j;
	i = q;
	j = r;
	chuyenBay x;
	//x = flight[(q + r) / 2];
	strcpy(x.maChuyenBay, flight[(int)(q + r) / 2].maChuyenBay);
	do
	{
		while (stricmp(flight[i].maChuyenBay, x.maChuyenBay) < 0)
		{
			i++;
		}
		while (stricmp(flight[j].maChuyenBay, x.maChuyenBay) > 0)
		{
			j--;
		}
		if (i <= j)
		{
			temp = flight[i];
			flight[i] = flight[j];
			flight[j] = temp;
			i++;
			j--;
		}
	}
	while (i <= j);
	if (q < j)
	{
		quickSort(flight, q, j);
	}
	if (i < r)
	{
		quickSort(flight, i, r);
	}
}

void sapXepCB(PTRListChuyenBay &First, chuyenBay *flight)
{
	int i = 0;
	int size = doDaiDS(First);
	quickSort(flight, 0, size - 1);
	//cout << "\nQuick sort good!\n";
	for (PTRListChuyenBay p = First; p != NULL; p = p->next)
	{
		//p->data = flight[i++];
		strcpy(p->data.maChuyenBay, flight[i].maChuyenBay);
		p->data.ngayKhoiHanh = flight[i].ngayKhoiHanh;
		p->data.gioKhoiHanh = flight[i].gioKhoiHanh;
		strcpy(p->data.sanBayDen, flight[i].sanBayDen);
		i++;
	}
}
