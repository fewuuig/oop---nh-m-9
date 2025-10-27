#ifndef VEMAYBAY_H
#define VEMAYBAY_H
#include<string>
#include "veMayBay.h" 
#include <iostream>
using namespace std ;
class veMayBay{
	private:
		static int demMaVe ; 
		string maVe , tenHanhKhach , maGheNgoi ;  
		string soCCCD , soDienThoai ;  
		string maChuyen  ; 
		double giaVe ; // 10.000.000
	public:
		veMayBay() ; 
		virtual void nhap() ; 
		virtual void xuat() ; 
		string getMaVe () ; 
		string getMaChuyen() ; 
		string getTenKhachHang() ;
		double getGiaVe() ; 
		string getSoCCCD() ;  
		string getMaGheNgoi() ; 
		string getSoDienThoai() ; 
		void setMaChuyen(string ma) ; 
		void setMaVe(string maVe) ; 
		void setTenHanhKhach(string ten) ; 
		void setMaGheNgoi(string ma) ; 
		void setSoCCCD(string cccd) ; 
		void setSoDienThoai(string sdt) ; 
		virtual void  setPhiDichVu(double phi)=0;
	    virtual void setHanhLyMienPhi(double kg)=0;  
      	virtual double tinhGia()=0  ; 
      	 
		
};
#endif 
