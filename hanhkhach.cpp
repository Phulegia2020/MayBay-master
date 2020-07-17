# include <iostream>
# include <string.h>
# include <stdio.h>
# include <conio.h>
# include <windows.h>
# include <fstream>
//# pragma once
//# include "mylib.h"
# include "hanhkhach.h"
# define Up 72
# define Down 80
# define Enter 13

using namespace std;

void SetColor1(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void SetBGColor1(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void gotoxy1(short x,short y)
{
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

void khoiTao(TREEhanhkhach &t)
{
	t = NULL;
}

void themNode(TREEhanhkhach &t, hanhKhach p)
{
	if (t == NULL)
	{
		t = new NodeHanhKhach;
		t->data = p;
		t->Left = NULL;
		t->Right = NULL;
	}
	else
	{
		if (stricmp(t->data.soCMND, p.soCMND) > 0)
		{
			themNode(t->Left, p);
		}
		else if (stricmp(t->data.soCMND, p.soCMND) < 0)
		{
			themNode(t->Right, p);
		}
	}
}

int timTrungHK(TREEhanhkhach t, char* soCMND)
{
	if (t != NULL)
	{
		if (stricmp(t->data.soCMND, soCMND) == 0) // neu so CMND ton tai trong cay
		{
			return 1;
		}
		else if (stricmp(t->data.soCMND, soCMND) > 0)
		{
			timTrungHK(t->Left, soCMND);
		}
		else if (stricmp(t->data.soCMND, soCMND) < 0) 
		{
			timTrungHK(t->Right, soCMND);
		}
	}
}

int checkNhapKyTuHK(char* a)
{
	int dem = 0;
	if (a[0] == '\0') 
	{
		return 0;
	}
	
	for (int i = 0;i<strlen(a);i++)
		if (((a[i]>=65) && (a[i]<=90)) || ((a[i]>=97) && (a[i]<=122)) || ((a[i] >= 48) && (a[i] <= 57)) || a[i] == 32)
			dem++;
	if(dem == strlen(a))	return 1;
	return 2;
}

void chuanHoaChuoiHK(char st[100], int &l)
{
	int i;
	while (st[0] == ' ')
		strcpy(st,st+1);
	l=strlen (st);
	while(st[l-1] == ' ')
	{
		strcpy(st+l-1,st+l);
		l--;
	}
	while (st[i] != '\0')
	{
		if (st[i] == ' ')
			if (st[i+1] == ' ')
			{
				strcpy(st+i,st+i+1);
				i--;
				l--;
			}
			else i++;
	i++;
	}
}

void nhapSoCMND(TREEhanhkhach t, char* soCMND)
{
	do
	{
		fflush(stdin);
		cout<<"So CMND: ";
		gets(soCMND);
		if(checkNhapKyTuHK(soCMND) == 1)
		{
			int l = strlen(soCMND);
			chuanHoaChuoiHK(soCMND,l);
			if (timTrungHK(t, soCMND) == 1)
			{
				cout << "So CMND nay da ton tai. Vui long nhap lai!" << endl;
			}
			else
			{
				break;
			}
		}
		else if (checkNhapKyTuHK(soCMND) == 0)	cout<<"Khong duoc de trong. Vui long nhap lai!"<<endl;
		else cout<<"Ban khong duoc nhap ki tu dac biet. Vui long nhap lai!"<<endl;
	}
	while(1);
}

void nhapHo(TREEhanhkhach t, char* ho)
{
	do
	{
		fflush(stdin);
		cout<<"Ho: ";
		gets(ho);
		if(checkNhapKyTuHK(ho) == 1)
		{
			int l = strlen(ho);
			chuanHoaChuoiHK(ho,l);
			break;
		}
		else if (checkNhapKyTuHK(ho) == 0)	cout<<"Khong duoc de trong. Vui long nhap lai!"<<endl;
		else cout<<"Ban khong duoc nhap ki tu dac biet. Vui long nhap lai!"<<endl;
	} while(checkNhapKyTuHK(ho) != 1);
}


void nhapTen(TREEhanhkhach t, char* ten)
{
	do
	{
		fflush(stdin);
		cout<<"Ten: ";
		gets(ten);
		if(checkNhapKyTuHK(ten) == 1)
		{
			int l = strlen(ten);
			chuanHoaChuoiHK(ten,l);
			break;
		}
		else if (checkNhapKyTuHK(ten) == 0)	cout<<"Khong duoc de trong. Vui long nhap lai!"<<endl;
		else cout<<"Ban khong duoc nhap ki tu dac biet. Vui long nhap lai!"<<endl;
	} while(checkNhapKyTuHK(ten) != 1);
}

void nhapPhai(TREEhanhkhach t, int &phai)
{
	while (1)
	{
		cout << "Phai (1 - Nam, 2 - Nu): ";
		cin >> phai;
		if (phai != 1 && phai != 2 && phai != 0)
		{
			cout << "\nChi nhap 1 hoac 2. Vui long nhap lai!\n";
		}
		else
		{
			break;
		}
	}
}

void taoCay(TREEhanhkhach &t)
{
	char key;
	do
	{
		system("cls");
		cout << "\t\tNHAP THONG TIN KHACH HANG\n";
		cout << "\t\t\t(q - thoat)\n\n";
		hanhKhach p;
		fflush(stdin);
		/*cout << "So CMND: ";
		cin.getline(p.soCMND, 12);*/
		nhapSoCMND(t, p.soCMND);
		if (stricmp(p.soCMND, "q") == 0)
		{
			break;
		}
		/*cout << "Ho: ";
		cin.getline(p.ho, 50);
		cout << "Ten: ";
		cin.getline(p.ten, 10);*/
		nhapHo(t, p.ho);
		nhapTen(t, p.ten);
		nhapPhai(t, p.phai);
		
		themNode(t, p);
		
		cout << "\nBan co muon tiep tuc nhap khong (Y/N)?";
		key = getch();
		if (key == 'n')
		{
			break;
		}
	}
	while(key == 'y');
}

TREEhanhkhach timKiemCay(TREEhanhkhach t, char* cmnd)
{
	TREEhanhkhach p;
	p = t;
	while(p != NULL && stricmp(p->data.soCMND, cmnd) != 0)
	{
		if (stricmp(p->data.soCMND, cmnd) > 0)
		{
			p = p->Left;
		}
		else if (stricmp(p->data.soCMND, cmnd) < 0)
		{
			p = p->Right;
		}
	}
	return p;
}

void xuatCay(TREEhanhkhach t, int &stt)
{
	char hoTen[70];
	if (t != NULL)
	{
		strcpy(hoTen, t->data.ho);
		strcat(hoTen, " ");
		strcat(hoTen, t->data.ten);
		if (t->data.phai == 1)
		{
			printf("%-20d%-20s%-20s%-20s", stt, t->data.soCMND, hoTen, "Nam");
		}
		else
		{
			printf("%-20d%-20s%-20s%-20s", stt, t->data.soCMND, hoTen, "Nu");
		}
		stt++;
		cout << endl;
		xuatCay(t->Left, stt);
		xuatCay(t->Right, stt);
	}
}

void timNodeTheMang(TREEhanhkhach &t, TREEhanhkhach &r)
{
	if (r->Left != NULL)
	{
		timNodeTheMang(t, r->Left);
	}
	else
	{
		t->data = r->data;
		t = r;
		r = r->Right;
	}
}

void xoaNode(TREEhanhkhach &t, char *soCMND)
{
	if (t != NULL)
	{
		if (stricmp(t->data.soCMND, soCMND) > 0)
		{
			xoaNode(t->Left, soCMND);
		}
		else if (stricmp(t->data.soCMND, soCMND) < 0)
		{
			xoaNode(t->Right, soCMND);
		}
		else if (stricmp(t->data.soCMND, soCMND) == 0)
		{
			TREEhanhkhach q;
			q = t;
			if (t->Left == NULL) // truong hop t khong co cay con ben trai
			{
				t = t->Right;
			}
			else if (t->Right == NULL) // truong hop t khong co cay con ben phai
			{
				t = t->Left;
			}
			else // truong hop t co cay con 2 ben
			{
				timNodeTheMang(q, t->Right);
			}
			delete q;
		}
	}
}

void hieuChinhNode(TREEhanhkhach &t, char* soCMND)
{
	if (t != NULL)
	{
		if (stricmp(t->data.soCMND, soCMND) > 0)
		{
			hieuChinhNode(t->Left, soCMND);
		}
		else if (stricmp(t->data.soCMND, soCMND) < 0)
		{
			hieuChinhNode(t->Right, soCMND);
		}
		else if (stricmp(t->data.soCMND, soCMND) == 0)
		{
			char hoTen[70];
			cout << "\n\n\tThong tin cu:\n";
			printf("\n%20s%20s%20s", "SO CMND", "HO TEN", "PHAI");
			strcpy(hoTen, t->data.ho);
			strcat(hoTen, " ");
			strcat(hoTen, t->data.ten);
			cout << endl;
			if (t->data.phai == 1)
			{
				printf("%20s%20s%20s", t->data.soCMND, hoTen, "Nam");
			}
			else
			{
				printf("%20s%20s%20s", t->data.soCMND, hoTen, "Nu");
			}
			cout << endl;
			cout << "\n\tNhap thong tin moi (De trong hoac nhap 0 neu khong thay doi):\n";
			hanhKhach p;
			fflush(stdin);
			cout << "So CMND: ";
			cin.getline(p.soCMND, 12);
			//nhapSoCMND(t, p.soCMND);
			if (stricmp(p.soCMND, "") == 0)
			{
				strcpy(p.soCMND, t->data.soCMND);
			}
			cout << "Ho: ";
			cin.getline(p.ho, 50);
			//nhapHo(t, p.ho);
			if (stricmp(p.ho, "") == 0)
			{
				strcpy(p.ho, t->data.ho);
			}
			cout << "Ten: ";
			cin.getline(p.ten, 10);
			//nhapTen(t, p.ten);
			if (stricmp(p.ten, "") == 0)
			{
				strcpy(p.ten, t->data.ten);
			}
			cout << "Phai (1 - Nam, 2 - Nu): ";
			cin >> p.phai;
			//nhapPhai(t, p.phai);
			if (p.phai == 0)
			{
				p.phai = t->data.phai;
			}
			// cap nhat lai thong tin
			t->data = p;
		}
	}
}

void demCay(TREEhanhkhach t, int &dem)
{
	if (t != NULL)
	{
		dem++;
		demCay(t->Left, dem);
		demCay(t->Right, dem);
	}
}

void luuHK(TREEhanhkhach t, fstream &file)
{
	if (t != NULL)
	{
		file << t->data.soCMND << endl;
		file << t->data.ho << endl;
		file << t->data.ten << endl;
			//file << t->data.phai << endl;
		if (t->data.phai == 1)
		{
			file << "Nam" << endl;
		}
		else
		{
			file << "Nu\n";
		}
		//file << endl;
		luuHK(t->Left, file);
		luuHK(t->Right, file);
	}
}

void saveHK(TREEhanhkhach t)
{
	fstream file;
	file.open("DSHK.txt", ios::out);
	if (!file.fail())
	{
		int dem = 0;
		demCay(t, dem);
		file << dem << endl;
		luuHK(t, file);
	}
	else
	{
		cout << "Khong mo duoc FILE!\n";
	}
	file.close();
}

void loadHK(TREEhanhkhach &t)
{
	int soluong;
	ifstream file;
	file.open("DSHK.txt");
	if (!file.fail())
	{
		string temp;
		char c[100];
		hanhKhach k;
		file >> soluong;
		getline(file, temp);
		for (int i = 0; i < soluong; i++)
		{
			//file.getline(temp, 5);
			//getline(file, temp);
			file.getline(c, 100);
			strcpy(k.soCMND, c);
			file.getline(c, 100);
			strcpy(k.ho, c);
			file.getline(c, 100);
			strcpy(k.ten, c);
			//char phai[5];
			//file.getline(phai, 5);
			file.getline(c, 200);
			if (stricmp(c, "Nam") == 0)
			{
				k.phai = 1;
			}
			else if (stricmp(c, "Nu") == 0)
			{
				k.phai = 2;
			}
			themNode(t, k);
		}
	}
	else
	{
		cout << "Khong mo duoc FILE!\n";
	}
	file.close();
}

void norMal()
{
	SetColor1(15);
	SetBGColor1(0);
}

void highLight()
{
	SetColor1(15);
	SetBGColor1(1);
}

int giaoDienHK(int chon)
{
	int So_Item = 6;
	int Vitrix = 40;
	int Vitriy = 5;
	char MucLucHK[So_Item][50] = {"1. Nhap danh sach hanh khach",
							  "2. In danh sach hanh khach",
							  "3. Them may hanh khach",
							  "4. Xoa hanh khach",
							  "5. Hieu chinh hanh khach",
							  "6. Ket thuc chuong trinh"};
	norMal();
	gotoxy1(Vitrix - 10, Vitriy - 3);
	cout << "==================== HANH KHACH ===================";
	gotoxy1(Vitrix - 10, Vitriy - 2);
	cout << "|";
	gotoxy1(Vitrix - 10, Vitriy - 1);
	cout << "|";
	gotoxy1(Vitrix + 40, Vitriy - 2);
	cout << "|";
	gotoxy1(Vitrix + 40, Vitriy - 1);
	cout << "|";
	for (int i = 0; i < So_Item; i++)
	{
		gotoxy1(Vitrix - 10, Vitriy + i);
		cout << "|";
		gotoxy1(Vitrix, Vitriy + i);
		cout << MucLucHK[i];
		gotoxy1(Vitrix + 40, Vitriy + i);
		cout << "|";
	}
	gotoxy1(Vitrix - 10, Vitriy + 5);
	cout << "|";
	gotoxy1(Vitrix - 10, Vitriy + 6);
	cout << "|";
	gotoxy1(Vitrix + 40, Vitriy + 5);
	cout << "|";
	gotoxy1(Vitrix + 40, Vitriy + 6);
	cout << "|";
	gotoxy1(Vitrix - 10, Vitriy + 7);
	cout << "======================= END =======================";
	highLight();
	gotoxy1(Vitrix, Vitriy + chon);
	cout << MucLucHK[chon];
	char kytu;
	while(1)
	{
		kytu = getch();
		switch(kytu)
		{
			case Up:
				{
					norMal();
					gotoxy1(Vitrix, Vitriy + chon);
					cout << MucLucHK[chon];
					chon--;
					if (chon < 0)
					{
						chon = 5;
					}
					highLight();
					gotoxy1(Vitrix, Vitriy + chon);
					cout << MucLucHK[chon];
					break;
				}
			case Down:
				{
					norMal();
					gotoxy1(Vitrix, Vitriy + chon);
					cout << MucLucHK[chon];
					chon++;
					if (chon > 5)
					{
						chon = 0;
					}
					highLight();
					gotoxy1(Vitrix, Vitriy + chon);
					cout << MucLucHK[chon];
					break;
				}
			case Enter:
				{
					norMal();
					return chon+1;
				}
		}
	}
}

void menuHK()
{
	int chucnang = 0;
	
	TREEhanhkhach t;
	
	khoiTao(t);
	
	loadHK(t);
	
	char key;
	
	while(1)
	{
		system("cls");
		if (chucnang > 0)
		{
			chucnang = giaoDienHK(chucnang-1);
		}
		else
		{
			chucnang = giaoDienHK(chucnang);
		}
		switch(chucnang)
		{
			case 1:
				{
					system("cls");
					taoCay(t);
					saveHK(t);
					break;
				}
			case 2:
				{
					system("cls");
					int stt = 1;
					cout << "\t\tDANH SACH HANH KHACH\n\n";
					printf("%-20s%-20s%-20s%-20s", "STT", "SO CMND", "HO TEN", "PHAI");
					cout << endl;
					xuatCay(t, stt);
					cout << endl;
					system("pause");
					break;
				}
			case 3:
				{
					system("cls");
					cout << "\t\tTHEM HANH KHACH\n";
					cout << "\t\t  (q - thoat)\n\n";
					hanhKhach p;
					/*fflush(stdin);
					cout << "\tSo CMND: ";
					cin.getline(p.soCMND, 12);*/
					nhapSoCMND(t, p.soCMND);
					if (stricmp(p.soCMND, "q") == 0)
					{
						break;
					}
					/*cout << "\tHo: ";
					cin.getline(p.ho, 50);
					cout << "\tTen: ";
					cin.getline(p.ten, 10);
					cout << "\tPhai (1 - Nam, 2 - Nu): ";
					cin >> p.phai;*/
					nhapHo(t, p.ho);
					nhapTen(t, p.ten);
					nhapPhai(t, p.phai);
					
					themNode(t, p);
					
					saveHK(t);
					
					cout << "\n===> THEM THANH CONG!\n\n";
					system("pause");
					break;
				}
			case 4:
				{
					system("cls");
					cout << "\t\tXOA HANH KHACH\n";
					if (t != NULL)
					{
						cout << "\t\t  (q - thoat)\n\n";
						char cmnd[12] = {'\0'};
						do
						{
							fflush(stdin);
							cout << "\tNhap so CMND cua hanh khach can xoa: ";
							gets(cmnd);
							if (stricmp(cmnd, "") == 0)
							{
								cout << "===> Khong duoc bo trong. Vui long nhap lai!\n";
							}
							else
							{
								break;
							}
						}
						while(1);
						//nhapSoCMND(t, cmnd);
						if (stricmp(cmnd, "q") == 0)
						{
							break;
						}
						if (timTrungHK(t, cmnd) == 1)
						{
							do
							{
								cout << "\n\tBan co chac chan muon xoa hanh khach nay (Y/N)?";
								key = getch();
								if (key == 'y')
								{
									xoaNode(t,cmnd);
									
									saveHK(t);
									
									cout << "\n\n===> XOA THANH CONG!\n";
									break;
								}
								else if (key == 'n')
								{
									cout << "\n\n===> DA HUY XOA!\n";
									break;
								}
								else
								{
									cout << "\n\n===> THONG BAO: CHI NHAP y HOAC n!\n";
								}
							}
							while(1);
						}
						else
						{
							cout << "\n===> THONG BAO: HANH KHACH NAY KHONG TON TAI TRONG DANH SACH!\n";
						}
					}
					else
					{
						cout << "\n===> THONG BAO: DANH SACH RONG!\n";
					}
					cout << endl;
					system("pause");
					break;
				}
			case 5:
				{
					system("cls");
					cout << "\t\tHIEU CHINH HANH KHACH\n";
					if (t != NULL)
					{
						cout << "\t\t   (q - thoat)\n\n";
						char cmnd[12];
						/*fflush(stdin);
						cout << "\tNhap so CMND cua hanh khach can hieu chinh: ";
						gets(cmnd);*/
						//nhapSoCMND(t, cmnd);
						do
						{
							fflush(stdin);
							cout << "\tNhap so CMND cua hanh khach can xoa: ";
							gets(cmnd);
							if (stricmp(cmnd, "") == 0)
							{
								cout << "===> Khong duoc bo trong. Vui long nhap lai!\n";
							}
							else
							{
								break;
							}
						}
						while(1);
						if (stricmp(cmnd, "q") == 0)
						{
							break;
						}
						if (timTrungHK(t, cmnd) == 1)
						{
							hieuChinhNode(t,cmnd);
							
							saveHK(t);
							
							cout << endl;
							cout << "===> HIEU CHINH THANH CONG!\n\n";
						}
						else
						{
							cout << "\n===> THONG BAO: HANH KHACH NAY KHONG TON TAI TRONG DANH SACH!\n\n";
						}
					}
					else
					{
						cout << "\n===> THONG BAO: DANH SACH RONG!\n\n";
					}
					system("pause");
					break;
				}
			case 6:
				{
					system("cls");
					return;
				}
		}
	}
}
