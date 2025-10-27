#ifndef QUANLYCHUYENBAY_H
#define QUANLYCHUYENBAY_H
#include <bits/stdc++.h>
#include "chuyenBay.h"
using namespace std;
class quanLyChuyenBay{
	private:
		vector<chuyenBay> dsChuyenBay;
		string matkhau = "admin";
	public: 
		void getDanhSachChuyenBay() ;  
		void themChuyenBay();
		void xoaChuyenBay();
		void xemLichTrinh();
		chuyenBay* timChuyenBay(string ma);
};
#endif
