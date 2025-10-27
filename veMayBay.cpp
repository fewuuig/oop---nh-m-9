#include <iostream>
#include <string>
#include "veMayBay.h"
#include <bits/stdc++.h>
using namespace std ; 
veMayBay::veMayBay(){
	this->tenHanhKhach = "Null" ; 
	this->soCCCD = "Null" ; 
	this->soDienThoai ="Null" ; 
	this->giaVe = 10000000 ;  // 10.000.000
	// sinh ma ve tu dong 
	demMaVe++ ; 
	stringstream ss ; 
	ss<<"VE"<<setfill('0')<<setw(5)<<demMaVe ; 
	this->maVe = ss.str() ; 
	stringstream ss1 ; 
	ss1<<"GH"<<setfill('0')<<setw(3)<<demMaVe ; 
	this->maGheNgoi = ss1.str() ; 
}

int veMayBay::demMaVe = 0 ; 
// nhap thong tin cho ve may bay 
void veMayBay::nhap(){
	// chuan hoa ten khach hang
	cout<<"Ten khach hang : " ; getline(cin , tenHanhKhach) ; 
	vector<string> v ; 
	stringstream ss(tenHanhKhach) ; 
	string word ;  
	while(ss>>word){
		word[0] = toupper(word[0]) ;  
		for(int i =1 ; i<word.size() ; i++){
			word[i] = tolower(word[i]) ;  	
		} 
		v.push_back(word) ; 
	} 
	tenHanhKhach ="" ;  
	for(int i =0 ; i< v.size() ; i++){
		tenHanhKhach+= v[i] ; 
		if(i!=v.size()-1){
			tenHanhKhach+=" " ; 
		} 
	} 
	
	//kiem tra hop le cua cccd
	bool check = false ; 
	int tmp = 0 ; 
	do{
		
		cout<<"So cccd : " ;getline(cin , soCCCD) ;  
		for(int i =0 ; i<soCCCD.size() ; i++){
			if(isalpha(soCCCD[i])){
				check =true ; 
				break ; 
			}
		}
		if(check){
			tmp = 1 ; 
			check=false ; 
		}else{
			tmp = 0 ; 
		}
		if(tmp==1){
			cout<<"CCCD phai la chu so!"<<endl ; 
		}
	}while(tmp==1) ; 
	
	// kiem tra so dien thoai co hop le khong
	tmp = 0 ; 
	check = false ; 
	do{
	
		cout<<"So dien thoai : "  ; getline(cin , soDienThoai); 
		stringstream ss2(soDienThoai) ; 
		ss2>>word ;
		soDienThoai="" ; 
		soDienThoai = word ; 
		for(int i =0 ; i<soDienThoai.size() ; i++){
			if(isalpha(soDienThoai[i]) || soDienThoai.size()!=10 ){
				check = true ; 
				break ; 
			}
		}
		if(check){
			tmp =1 ; 
			check = false ; 
		}else{
			tmp = 0 ; 
		}
		if(tmp==1){
			cout<<"So dien thoai phai la chu so va co 10 so!"<<endl ; 
		}
	}while(tmp==1) ;
}
// xuat thong tin cua ve may bay 
void veMayBay::xuat() {
	cout<<left ; 
	
	cout<<setw(20)<<"Ten Khach hang"
	<<setw(20)<<"CCCD"
	<<setw(15)<<"SDT"
	<<setw(10)<<"Ma Ve"
	<<setw(14)<<"Ma chuyen"
	<<setw(15)<<"Gia chuyen"<<endl  ; 
	
	cout<<setw(20)<<tenHanhKhach 
    <<setw(20)<<soCCCD 
    <<setw(15)<<soDienThoai
	<<setw(10)<<maVe
	<<setw(14)<<maChuyen
	<<setw(15)<<fixed<<setprecision(1)<<giaVe <<endl;  
}

// lay ra ma ve 
string veMayBay::getMaVe(){
	return maVe ; 
}
// lay ra ma chuyen bay 
string veMayBay::getMaChuyen(){
	return maChuyen ; 
}
// lay ra ten khach hang 
string veMayBay::getTenKhachHang(){
	return tenHanhKhach ; 
}
// lay ra gia ve  
double veMayBay::getGiaVe(){
	return giaVe ; 
}
// lay so CCCD 
string veMayBay::getSoCCCD(){
	return soCCCD ;  
} 
// lay ma ghe noi 
string veMayBay::getMaGheNgoi(){
	return maGheNgoi; 
}
string veMayBay::getSoDienThoai(){
	return soDienThoai ; 
}
//set ma chuyen bay 
void veMayBay::setMaChuyen(string ma){
	this->maChuyen = ma ; 
} 
void veMayBay::setMaVe(string maVe){
	this->maVe = maVe ; 
}  
void veMayBay::setTenHanhKhach(string ten){
	this->tenHanhKhach = ten ; 
}
void veMayBay::setMaGheNgoi(string ma){
	this->maGheNgoi = ma ; 
}
void veMayBay::setSoCCCD(string cccd){
	this->soCCCD  = cccd ; 
}
void veMayBay::setSoDienThoai(string sdt ){
	this->soDienThoai = sdt ; 
}
