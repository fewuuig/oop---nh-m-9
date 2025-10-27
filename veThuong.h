#ifndef VETHUONG_H
#define VETHUONG_H
#include <iostream>
#include <string>
#include "veMayBay.h"
using namespace std;
class veThuong:public veMayBay{
	private:
	    double phiPhucVu;
	    double hanhLyMiePhi; 
	public: 
	    veThuong();
	    void  setPhiDichVu(double phi) override;
	    void setHanhLyMienPhi(double kg) override;  	
	    double tinhGia() override ; 
	    void xuat() ; 
	    void nhap() override ;  
	    
};
#endif
