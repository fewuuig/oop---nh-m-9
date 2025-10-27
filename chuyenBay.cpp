#include<string>
#include <iostream>
#include "chuyenBay.h"
#include<bits/stdc++.h>
using namespace std ;

chuyenBay::chuyenBay(){
	this->maChuyen = "000" ; 
	this->diemDi = "Null" ; 
	this->diemDen = "Null" ; 
	this->ngayBay = "00/00/0000" ; 
	this->gioBay = "00:00" ; 
	this->soGhe = 0 ; 
	this->soGheTrong = 0; 
	
	// tang tu dong ma chuyen bay 
	dem ++ ; 
	stringstream ss ; 
	ss<<"F"<<setfill('0')<<setw(3)<<dem ; 
	maChuyen = ss.str() ; 
}
// bo nho tinh 
int chuyenBay::dem =0 ; 
// nhap thong tin chuyen bay 
void chuyenBay::nhap(){
	cout<<"Diem di : " ; getline(cin , diemDi) ; 
	cout<<"Diem den : " ; getline(cin,diemDen) ; 
	cout<<"Ngay bay : " ; getline(cin,ngayBay) ;
	if(ngayBay[1]=='/') ngayBay = "0" + ngayBay ; 
	if(ngayBay[4]=='/') ngayBay= ngayBay.insert(3,"0") ;  
	cout<<"Gio bay : "  ; getline(cin,gioBay) ; 
	cout<<"so ghe : " ; cin>>soGhe ; 
	chuyenBay::soGheTrong = soGhe ; 
	cin.ignore() ; 
} 
// gan so ghe trong bang vio so ghe ma minh nhap 
void chuyenBay::setSoGheTrong(){
	soGheTrong = soGhe ; 
}
// xuat thong tin chuyen bay 
void chuyenBay::xuat(){
	cout<<left ; 
	
	cout<<setw(10)<<maChuyen
	<<setw(20)<<diemDi
	<<setw(20)<<diemDen
	<<setw(20)<<ngayBay 
	<<setw(10)<<gioBay
	<<setw(10)<<soGhe
	<<setw(10)<<soGheTrong<<endl ; 
}
// lay ma chuyen bay
string chuyenBay::getMaChuyen(){
	return maChuyen ; 
}
// lay duiem di 
string chuyenBay::getDiemDi(){
	return diemDi ; 
}
// lay diem den 
string chuyenBay::getDiemDen(){
	return diemDen ; 
}
// lay ngay bay
string chuyenBay::getNgayBay(){
	return ngayBay ; 
}
// lay gio bay 
string chuyenBay::getGioBay(){
	return gioBay ;
}
//lay so ghe con trong
int chuyenBay::getSoGheTrong(){
	return soGheTrong ; 
}
// giam so ghe khi co nguoi ddat ve 
void chuyenBay::giamGhe(){
	if(soGheTrong>0)
	    soGheTrong-- ; 
}
// tang so so khi co nguoi huy 
void chuyenBay::tangGhe(){
	if(soGheTrong>=0)
	    soGheTrong++ ; 
}
// lay so ghe cua may bay 
int chuyenBay::getSoGhe(){
	return soGhe ; 
}

void chuyenBay::formFrame(){
	cout<<left ;  
	cout<<setw(10)<<"Ma so"
	<<setw(20)<<"Diem di"
	<<setw(20)<<"Diem den"
	<<setw(20)<<"Ngay bay"
	<<setw(10)<<"Gio bay"
	<<setw(10)<<"So ghe"
	<<setw(10)<<"So ghe trong"<<endl<<endl  ;  
} 
