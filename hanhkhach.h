#include <iostream>
# include <fstream>
//# include "mylib.h"

using std::ifstream;

struct hanhkhach {
	char soCMND[12];
	char ho[50];
	char ten[10];
	int phai;
};
typedef struct hanhkhach hanhKhach;

struct nodeHanhKhach {
	hanhKhach data;
	struct nodeHanhKhach *Left;
	struct nodeHanhKhach *Right;
};
typedef struct nodeHanhKhach NodeHanhKhach;
typedef NodeHanhKhach* TREEhanhkhach;

void khoiTao(TREEhanhkhach &t);

int checkNhapKyTuHK(char *a);

void chuanHoaChuoiHK(char st[100], int &l);

void nhapSoCMND(TREEhanhkhach t, char* soCMND);

void nhapHo(TREEhanhkhach t, char* ho);

void nhapTen(TREEhanhkhach t, char* ten);

void nhapPhai(TREEhanhkhach t, int &phai);

int timTrungHK(TREEhanhkhach t, char* soCMND);

TREEhanhkhach timKiemCay(TREEhanhkhach t, char* cmnd);

void themNode(TREEhanhkhach &t, hanhKhach p);

void taoCay(TREEhanhkhach &t);

void xuatCay(TREEhanhkhach t, int &stt); // theo thu tu NLR

void timNodeTheMang(TREEhanhkhach &t, TREEhanhkhach &r);

void xoaNode(TREEhanhkhach &t, char *soCMND);

void hieuChinhNode(TREEhanhkhach &t, char* soCMND);

void norMal();

void highLight();

int giaoDienHK(int chon);

void menuHK();

void demCay(TREEhanhkhach t, int &dem);

void luuHK(TREEhanhkhach t, fstream &file);

void saveHK(TREEhanhkhach t);

void loadHK(TREEhanhkhach &t);
