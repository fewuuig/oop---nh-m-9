#include <iostream>
#include<bits/stdc++.h>
#include "veThuongGia.h"
using namespace std;

veThuongGia::veThuongGia(){
}

void veThuongGia::setPhiDichVu(double phi){
	this->phiPhucVu = phi; 
}
void veThuongGia::setHanhLyMienPhi(double kg){
    this->hanhLyMiePhi = kg ;  
}
double veThuongGia::getPhiPhucVu(){
	return phiPhucVu ;  
}
double veThuongGia::getHanhLyMiePhi(){
	return hanhLyMiePhi ;  
}
double veThuongGia::tinhGia(){
	return veMayBay::getGiaVe() + phiPhucVu ;  
}
void veThuongGia::nhap(){
	veMayBay::nhap() ; 
	cout<<"Phi dich vu : " ; cin>>phiPhucVu ; 
	cout<<"Hanh ly mien phi : " ; cin>>hanhLyMiePhi ;  
} 
void veThuongGia :: xuat(){
	cout << "[Ve Thuong Gia]" << endl;
	veMayBay :: xuat();
	cout << "Phi Dich Vu: " << this->phiPhucVu 
	     << ", Hanh Ly Mien Phi: " << veThuongGia::hanhLyMiePhi << "kg"
		 << ", Tong Tien: " << tinhGia() << endl; 
} 

