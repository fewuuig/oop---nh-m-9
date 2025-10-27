#include "quanLyVe.h"
#include "veThuongGia.h"
#include "veThuong.h"
#include "chuyenBay.h"
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std ; 
quanLyVe::~quanLyVe(){
	for(auto ve : dsVe) delete ve;
}
quanLyVe::quanLyVe(quanLyChuyenBay* ql):qlcb(ql){
}
void quanLyVe::datVe(){
	qlcb->xemLichTrinh() ;   
	string ma ; cout<<"Nha ma chuyen bay can them ve : " ; cin>>ma ;  cin.ignore() ;  
	chuyenBay* cb = qlcb->timChuyenBay(ma) ; 
	if(cb== nullptr ){
		cout << "KHONG TIM THAY CHUYEN BAY!"<<endl  ; return ; 
	}else if( cb->getSoGheTrong()==0){
		cout<<"HET VE!"<<endl ; 
	}
	int loai;
	cout << "Nhap loai ve(1-Thuong, 2-Thuong gia): "; cin >> loai;
	cin.ignore();
	
	veMayBay* ve = nullptr;
	if(loai == 1){
		ve = new veThuong();
	}else if(loai==2){
		ve = new veThuongGia();
	}else return ;  
	ve->setMaChuyen(ma) ; 
	ve->nhap();
	dsVe.push_back(ve);
	cb->giamGhe();
	cout << "DAT VE THANH CONG!" << endl;
}
void quanLyVe::nhapFile() {
    ifstream fin("nhapVe.txt");
    if (!fin.is_open()) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string maVe, tenHanhKhach, maGheNgoi;
    string soCCCD, soDienThoai, maChuyen;
    double phiPhucVu, hanhLyMienPhi;

    while (fin >> phiPhucVu >> hanhLyMienPhi >> maVe &&
           fin.ignore() && 
	       getline(fin,tenHanhKhach) && 
           fin>> maGheNgoi >> soCCCD >> soDienThoai >> maChuyen) {

        veMayBay* ve;
		if (phiPhucVu != 0) {
    		ve = new veThuongGia();
		} else {
   	 		ve = new veThuong();
		}


        ve->setPhiDichVu(phiPhucVu);
        ve->setHanhLyMienPhi(hanhLyMienPhi);
        ve->setMaVe(maVe);
        ve->setTenHanhKhach(tenHanhKhach);
        ve->setMaGheNgoi(maGheNgoi);
        ve->setSoCCCD(soCCCD);
        ve->setSoDienThoai(soDienThoai);
        ve->setMaChuyen(maChuyen);

        // kiemm  tra trungg vé  
        bool trung = false;
        for (veMayBay* x : dsVe) {
            if (x->getMaVe() == ve->getMaVe()) {
                trung = true;
                break;
            }
        }

        if (trung) {
            delete ve;
            continue;
        }

        //kiem ra chuyen bayy 
        chuyenBay* cb = qlcb->timChuyenBay(ve->getMaChuyen());
        if (cb != nullptr && cb->getSoGhe() > 0) {
            dsVe.push_back(ve);
            cb->giamGhe();
        } else {
            delete ve;
        }
    }

    fin.close();
    cout << "NHAP VE THANH CONG!" << endl;
}

void quanLyVe::huyVe(string maVe){
	
	for (auto it = dsVe.begin(); it!= dsVe.end(); it++){
		if((*it)->getMaVe() == maVe){
			chuyenBay *cb = qlcb->timChuyenBay((*it)->getMaChuyen()) ; 
			if(cb!=nullptr){
				cb->tangGhe() ; 
			}
			delete *it ; 
			dsVe.erase(it) ; 
			cout<<"HUY VE THANH CONG!"<<endl ; 
			return ; 
		}
	}
	cout << "MA VE KHONG TON TAI!"<<endl;
}
// kiem tra xem chuyen bay con ton tai hay khong 
void quanLyVe::checkXoaChuyenBay(){
	for(auto it= dsVe.begin() ; it!= dsVe.end() ; ){
		if(qlcb->timChuyenBay((*it)->getMaChuyen())==nullptr){
			delete *it ; 
			it = dsVe.erase(it) ; 
		}else {
			it ++ ;  
		} 
	}
}
//Cap nhat lai ve khi tahy doi 
void quanLyVe::capNhatVe(){
	string maVe ; cout<<"Nhap ma ve can thay doi thong tin : " ; cin>>maVe ;  
	for(auto ve : dsVe){
		if(ve->getMaVe()==maVe){
			
			while(true){
				cout<<"1. Thay doi ma ve"<<endl ; 
				cout<<"2. Thay doi Ten Hanh Khach"<<endl ; 
				cout<<"3. Thay doi Ma Ghe Ngoi"<<endl ; 
				cout<<"4. Thay doi so CCCD"<<endl ; 
				cout<<"5. Thay doi so Dien Thoai"<<endl ; 
				cout<<"6. Thoat"<<endl ; 
				int choose ; cout<<"Nhap lua chon cua ban : " ; cin>>choose ; cin.ignore() ; 
				if(choose == 1){
					cout<<"Ma ve moi : " ; cin>>maVe ; 
					ve->setMaVe(maVe) ; 
				}else if(choose==2){
					string tenHanhKhach ; 
					cout<<"Ten Hanh Khach Moi : " ; getline(cin,tenHanhKhach) ; 
					ve->setTenHanhKhach(tenHanhKhach) ; 
				}else if(choose == 3){
					string maGheNgoi ; cout<<"Nhap ma ghe ngoi moi : " ; cin>>maGheNgoi ; 
					ve->setMaGheNgoi(maGheNgoi) ; 
				}else if(choose==4){
					string cccd ; cout<<"CCCD moi : " ; cin>>cccd ; 
					ve->setSoCCCD(cccd) ; 
				}else if(choose == 5){
					string sdt ; 
					cout<<"Nhap so dien thoai moi : " ; cin>>sdt ; 
					ve->setSoDienThoai(sdt) ;  
				}else if(choose==6) break ; 
			}
			break ; 
		}
	} 
} 
void quanLyVe::traCuuVe(string soCCCD){
	bool found = false;
	for(auto ve : dsVe){
		if(ve->getSoCCCD() == soCCCD){
			ve->xuat();
			found = true;
		}
	}
	if(!found){
		cout << "KHONG TIM THAY VE CO CCCD : " << soCCCD << endl;
	}
}

void quanLyVe::thongKeVe(){
    int demThuong = 0, demThuongGia = 0;
    for (auto ve : dsVe) {
        if (dynamic_cast<veThuong*>(ve))
            demThuong++;
        else if (dynamic_cast<veThuongGia*>(ve))
            demThuongGia++;
    }
    cout<<"==========================================Danh Sach Ve============================================="<<endl ; 
    cout<<left ;
    	cout<<setw(10)<<"Ma chuyen"
    		<<setw(14)<<"Diem di"
    		<<setw(14)<<"Diem den"
    		<<setw(14)<<"Ngay bay"
    		<<setw(9)<<"Gio bay"
    		<<setw(9)<<"Cho Ngoi"
    		<<setw(9)<<"Ma ve"
    		<<setw(15)<<"Ten khach"
    		<<setw(15)<<"CCCD"
    		<<setw(15)<<"So DT"
    		<<setw(11)<<"Gia ve"  
    		<<setw(12)<<"PhiDV"
			<<setw(4)<<"HLMP"<<endl<<endl ;  
    for(veMayBay* ve : dsVe){
    	chuyenBay *cb = qlcb->timChuyenBay(ve->getMaChuyen()) ; 
    	veThuong* vt = dynamic_cast<veThuong*>(ve) ; 
    	veThuongGia *vtg = dynamic_cast<veThuongGia*>(ve) ; 
    	if(ve->getMaChuyen() == cb->getMaChuyen()){ 
    		if(vt){
    			cout<<setw(10)<<cb->getMaChuyen() 
    		    <<setw(14)<<cb->getDiemDi() 
    		    <<setw(14)<<cb->getDiemDen()  
    		    <<setw(14)<<cb->getNgayBay()  
    		    <<setw(9)<<cb->getGioBay() 
    		    <<setw(9)<<ve->getMaGheNgoi() 
    		    <<setw(9)<<ve->getMaVe() 
    		    <<setw(15)<<ve->getTenKhachHang() 
    		    <<setw(15)<<ve->getSoCCCD() 
    		    <<setw(15)<<ve->getSoDienThoai() 
    		    <<setw(15)<<fixed<<setprecision(1)<<vt->getGiaVe()<<endl ; 
			}else if(vtg){
				cout<<setw(10)<<cb->getMaChuyen() 
    		    <<setw(14)<<cb->getDiemDi() 
    		    <<setw(14)<<cb->getDiemDen()  
    		    <<setw(14)<<cb->getNgayBay()  
    		    <<setw(9)<<cb->getGioBay() 
    		    <<setw(9)<<ve->getMaGheNgoi() 
    		    <<setw(9)<<ve->getMaVe() 
    		    <<setw(15)<<ve->getTenKhachHang() 
    		    <<setw(15)<<ve->getSoCCCD() 
    		    <<setw(15)<<ve->getSoDienThoai()
    		    <<setw(10)<<fixed<<setprecision(1)<<vtg->getGiaVe() 
				<<setw(11)<<fixed<<setprecision(1)<<vtg->getPhiPhucVu()
    		    <<setw(4)<<vtg->getHanhLyMiePhi()<<endl ; 
			}
		}
	}
}
void quanLyVe::xuatFile(){
	ofstream fout("danhSachVe.txt") ; 
	if(fout==nullptr){
		cout<<"FILE khong the mo!"<<endl ; 
		return ;  
	}
	
    fout<<left ;
    	fout<<setw(10)<<"Ma chuyen"
    		<<setw(14)<<"Diem di"
    		<<setw(14)<<"Diem den"
    		<<setw(14)<<"Ngay bay"
    		<<setw(9)<<"Gio bay"
    		<<setw(9)<<"Cho Ngoi"
    		<<setw(9)<<"Ma ve"
    		<<setw(15)<<"Ten khach"
    		<<setw(15)<<"CCCD"
    		<<setw(15)<<"So DT"
    		<<setw(10)<<"Gia ve"  
    		<<setw(11)<<"PhiDV"
			<<setw(4)<<"HLMP"<<endl<<endl ;  
    for(veMayBay* ve : dsVe){
    	chuyenBay *cb = qlcb->timChuyenBay(ve->getMaChuyen()) ; 
    	veThuong* vt = dynamic_cast<veThuong*>(ve) ; 
    	veThuongGia *vtg = dynamic_cast<veThuongGia*>(ve) ; 
    	if(ve->getMaChuyen() == cb->getMaChuyen()){ 
    		if(vt){
    			fout<<setw(10)<<cb->getMaChuyen() 
    		    <<setw(14)<<cb->getDiemDi() 
    		    <<setw(14)<<cb->getDiemDen()  
    		    <<setw(14)<<cb->getNgayBay()  
    		    <<setw(9)<<cb->getGioBay() 
    		    <<setw(9)<<ve->getMaGheNgoi() 
    		    <<setw(9)<<ve->getMaVe() 
    		    <<setw(15)<<ve->getTenKhachHang() 
    		    <<setw(15)<<ve->getSoCCCD() 
    		    <<setw(15)<<ve->getSoDienThoai() 
    		    <<setw(15)<<vt->getGiaVe()<<endl ; 
			}else if(vtg){
				fout<<setw(10)<<cb->getMaChuyen() 
    		    <<setw(14)<<cb->getDiemDi() 
    		    <<setw(14)<<cb->getDiemDen()  
    		    <<setw(14)<<cb->getNgayBay()  
    		    <<setw(9)<<cb->getGioBay() 
    		    <<setw(9)<<ve->getMaGheNgoi() 
    		    <<setw(9)<<ve->getMaVe() 
    		    <<setw(15)<<ve->getTenKhachHang() 
    		    <<setw(15)<<ve->getSoCCCD() 
    		    <<setw(15)<<ve->getSoDienThoai()
    		    <<setw(10)<<vtg->getGiaVe() 
				<<setw(11)<<vtg->getPhiPhucVu()
    		    <<setw(4)<<vtg->getHanhLyMiePhi()<<endl ; 
			}
		}
	}
	fout.close() ;  
	cout<<"DA XUAT FILE!"<<endl ;  
} 
