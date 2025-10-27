#ifndef VETHUONGGIA_H
#define VETHUONGGIA_H
#include <iostream>
#include <string>
#include "veMayBay.h"
using namespace std;
//.h veThuongGia 
class veThuongGia:public veMayBay {
	private:
	    double phiPhucVu;
	    double hanhLyMiePhi;
	public:  
	    veThuongGia();
	    double getPhiPhucVu() ; 
		double getHanhLyMiePhi() ;  
	    void  setPhiDichVu(double phi) override;
	    void setHanhLyMienPhi(double kg) override;  	
	    double tinhGia() override;
	    void xuat() ; 
	    void nhap() override ;  
};
#endif
