#include <bits/stdc++.h>
#include "quanLyChuyenBay.h"
void quanLyChuyenBay::themChuyenBay(){
//	string mk;
//	cout << "Nhap mat khau: ";
//	cin >> mk;
//	if(mk != matkhau){
//		cout << "Sai mat khau!!";
//		return;
//	}
	chuyenBay c ; 
	c.nhap() ; 
	dsChuyenBay.push_back(c) ; 
	cout<<"DA THEM!"<<endl ;  
} 

void quanLyChuyenBay::xoaChuyenBay(){
//	string mk;
//	cout << "Nhap mat khau: ";
//	cin >> mk;
//	if(mk != matkhau){
//		cout << "Sai mat khau!!";
//		return;
//	}
    cout<<"=================Cac Chuyen Bay Hien Co=================="<<endl ; 
	for(chuyenBay cb : dsChuyenBay){
		cout<<cb.getMaChuyen()<<endl ;  
	} 
	string maChuyen;
	cout << "Nhap ma chuyen bay can xoa: "; getline(cin, maChuyen);
	for(auto it = dsChuyenBay.begin(); it != dsChuyenBay.end(); it++){
		if(it->getMaChuyen() == maChuyen){
			dsChuyenBay.erase(it);
			cout << "XOA THANH CONG!" << endl;
			return;
		}
	}
	cout << "KHONG TIM THAY CHUYEN BAY!" << endl;
}

void quanLyChuyenBay::xemLichTrinh(){
	cout << "=========================================Danh sach chuyen bay=========================================" << endl;
	chuyenBay c ; c.formFrame() ;  
	for(auto &cb : dsChuyenBay){
		cb.xuat();
	}
}
chuyenBay*  quanLyChuyenBay::timChuyenBay(string ma){
	for(auto it= dsChuyenBay.begin() ; it!=dsChuyenBay.end() ; it++){
		if((it)->getMaChuyen() == ma){
			return  &(*it); 
		}
	} 
	return nullptr ;  
}

void quanLyChuyenBay::getDanhSachChuyenBay(){
	for(chuyenBay cb : dsChuyenBay){
		cout<<cb.getMaChuyen()<<endl ;  
	} 
} 
