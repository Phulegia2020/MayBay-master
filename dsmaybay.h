#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#define MAXLIST 300

using namespace std;

struct maybay{
	char soHieuMayBay[20];
	char loaiMayBay[45];
	int soDay;
	int soDong;
};
typedef struct maybay mayBay;

struct nodeMayBay {
	mayBay data;
};
typedef struct nodeMayBay nodeMB;
typedef struct nodeMayBay* NODEMAYBAY;

struct ListMayBay{
	int n = 0;
	NODEMAYBAY NodeMayBay[MAXLIST];
};
typedef struct ListMayBay listMayBay;

mayBay nhapMayBay(listMayBay &lmb, mayBay &mb);

void xuatMayBay(mayBay mb);

int fullDS (listMayBay lmb);

void insertNodeMB(listMayBay &lmb, mayBay mb);

void chuanHoaChuoi(char st[100], int &l);

int checkNhapKyTu(char *a);

int searchNodeMB(listMayBay lmb, char *s);

void deleteNodeMB(listMayBay &lmb, int i);

void updateNodeMB(listMayBay &lmb, int i);

void nhapSoHieuMB(listMayBay &lmb, char *soHieu);

void nhapLoaiMB(listMayBay &lmb, char *loaiMB);

void menu(listMayBay &lmb, mayBay &mb);

void readFile(listMayBay &lmb);

void writeFile (listMayBay lmb);

