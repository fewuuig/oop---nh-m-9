#include <iostream>
#include <string>
#include "veThuong.h"
#include <bits/stdc++.h>
using namespace std;
veThuong :: veThuong() : veMayBay() {}

double veThuong(){
}
double veThuong::tinhGia() {
	return veMayBay::getGiaVe() ;  
}
void veThuong::nhap(){
	veMayBay::nhap() ;  
} 
void veThuong::setHanhLyMienPhi(double kg ){
	hanhLyMiePhi = 0 ; 
}
void veThuong::setPhiDichVu(double phi){
	phiPhucVu =0 ; 
}
void veThuong :: xuat(){
	cout << "[Ve Thuong]" << endl;
	veMayBay :: xuat();
	cout << "Tong Gia Tien: "<<fixed<<setprecision(1)<< tinhGia() << endl; 
}

