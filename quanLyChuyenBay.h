#ifndef QUANLYCHUYENBAY_H
#define QUANLYCHUYENBAY_H
#include <bits/stdc++.h>
#include "chuyenBay.h"
using namespace std;
class quanLyChuyenBay{
	private:
		vector<chuyenBay> dsChuyenBay;
		string message ; 
	public: 
		void getDanhSachChuyenBay() ;  
		void themChuyenBay();
		void xoaChuyenBay();
		void xemLichTrinh();
		chuyenBay* timChuyenBay(string ma);
		string getMessage() ; //
		void setMessage(string message) ; //
		void Message() ; //
		void thayDoiLichTrinh() ; // 
};
#endif
