#include <iostream>
#include "date.h"
#include <string.h>
#define MAXLISTVE 200
#include "dsmaybay.h"

using namespace std;

struct ve {
	char soVe[5];
	char soCMND[12];
};
typedef struct ve Ve;

struct NodeVe {
	Ve data;
};
typedef struct nodeVe nodeVe;

struct danhsachve {
	int n = 0;
	nodeVe* dsVe;
};
typedef struct danhsachve danhSachVe;

struct chuyenbay {
	char maChuyenBay[20];
	NGAY_THANG ngayKhoiHanh;
	NGAY_THANG gioKhoiHanh;
	char sanBayDen[50];
	int trangThai;
	char soHieuMayBay[20];
	danhSachVe listVe;
};
typedef struct chuyenbay chuyenBay;

struct listChuyenBay {
	chuyenBay data;
	struct listChuyenBay *next;
};
typedef struct listChuyenBay* PTRListChuyenBay;

chuyenBay nhapChuyenBay(PTRListChuyenBay &First, chuyenBay &cb, listMayBay lmb);

void xuatChuyenBay(chuyenBay cb);

void insertNodeCB(PTRListChuyenBay &First, chuyenBay cb);

void traverseCB(PTRListChuyenBay First);

void deleteNodeCB(PTRListChuyenBay &First);

//void danhSachVe (PTRListChuyenBay pCB, chuyenBay cb);

bool searchNodeCB(PTRListChuyenBay First, char *s);

void nhapSoHieuCB(listMayBay &lmb, char *soHieu);

void nhapMaCB(PTRListChuyenBay &First, char *MaCB);

NGAY_THANG nhapNgayThangNam();

NGAY_THANG nhapGioKhoiHanh();

