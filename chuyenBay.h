#ifndef CHUYENBAY_H 
#define CHUYENBAY_H 
#include<string>
#include <iostream>

using namespace std ; 
class chuyenBay{
	private:
		static int dem ; // dem ma chuyen bay rtu dong 
		string maChuyen ; 
		string diemDi , diemDen , ngayBay , gioBay ; 
		int soGhe , soGheTrong ; 
	public:
		chuyenBay() ; 
		void formFrame() ;  
 	    void nhap() ; 
		void xuat() ; 
		string getMaChuyen() ; 
		int getSoGheTrong() ;
		void setSoGheTrong() ;  
		int getSoGhe() ; 
		string getDiemDi() ; 
		string getDiemDen() ; 
		string getNgayBay() ; 
		string getGioBay() ; 
		void giamGhe() ; // giam so ghe khi dat ve 
		void tangGhe() ; // tang so ghe khi dat ve 
		
};
#endif  
