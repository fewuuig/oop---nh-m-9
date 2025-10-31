#include <bits/stdc++.h>
#include "quanLyChuyenBay.h"
void quanLyChuyenBay::themChuyenBay(){

	chuyenBay c ; 
	c.nhap() ; 
	dsChuyenBay.push_back(c) ; 
	cout<<"DA THEM!"<<endl ;  
} 
string quanLyChuyenBay::getMessage(){
	return this->message ; 
}
void quanLyChuyenBay::Message(){   
    if(getMessage().size()!=0){
    	cout<<endl<<"THONG BAO : "<<getMessage()<<endl<<endl  ; 
	}
}

void quanLyChuyenBay::thayDoiLichTrinh(){
	cout<<"1. Thay doi thoi gian bay"<<endl ; 
	cout<<"2. Thay doi ngay bay"<<endl ; 
	int choose ; cout<<"Nhap lua chon : " ;cin>>choose ; 
	string chuyenBayBiThayDoi ; 
	quanLyChuyenBay::xemLichTrinh() ; 
	cout<<"Nhap ma chuyen bay muon thay doi lich trinh : " ; cin>>chuyenBayBiThayDoi ; 
	string ngayBay , gioBay  ; 
	cin.ignore() ; 
	//Nghie vu chuan hoa 
	for(auto &cb : dsChuyenBay){
		if(cb.getMaChuyen() == chuyenBayBiThayDoi){
			if(choose==1){
				cout<<"Nhap gio bay moi : " ; getline(cin,gioBay) ; 
				string temp = cb.getGioBay() ; 
				cb.setGioBay(gioBay) ; 	
				if(getMessage().size() == 0){
					string ms = "Chuyen bay "+chuyenBayBiThayDoi+"doi gio bay tu "+temp+"h -> "+gioBay+"h"+'\n' ;
					setMessage(ms) ;  
				}else {
					string ms = "Chuyen bay "+chuyenBayBiThayDoi+"doi gio bay tu "+temp+"h -> "+gioBay+"h"+'\n' ;
					setMessage(message + ms) ; 
				}
			}else if(choose==2){
				cout<<"Nhap ngay bay moi : "; getline(cin,ngayBay) ; 
				string temp = cb.getNgayBay() ; 
				cb.setNgayBay(ngayBay) ; 
					if(getMessage().size() == 0){
					string ms = "Chuyen bay "+chuyenBayBiThayDoi+"doi ngay bay "+temp+" -> "+ngayBay+'\n' ;
					setMessage(ms) ;  
				}else {
					string ms = "Chuyen bay "+chuyenBayBiThayDoi+"doi ngay bay "+temp+" -> "+ngayBay+'\n' ;
					setMessage(message + ms) ; 
				}
			}
			break ; 
		}
	}
}
void quanLyChuyenBay::setMessage(string message){
	this->message = message ; 
}
void quanLyChuyenBay::xoaChuyenBay(){
	string message ; 
    cout<<"=================Cac Chuyen Bay Hien Co=================="<<endl ; 
	for(chuyenBay cb : dsChuyenBay){
		cout<<cb.getMaChuyen()<<endl ;  
	} 
	string maChuyen;
	cout << "Nhap ma chuyen bay can xoa: "; getline(cin, maChuyen);
	for(auto it = dsChuyenBay.begin(); it != dsChuyenBay.end(); it++){
		if(it->getMaChuyen() == maChuyen){
			dsChuyenBay.erase(it);
			cout<<"Message to client : " ; 
			getline(cin,message) ; 
			quanLyChuyenBay::setMessage(message+'\n') ;  
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
