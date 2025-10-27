#include <iostream>
#include "chuyenBay.h"
#include "veMayBay.h"
#include "veThuong.h"
#include "veThuongGia.h"
#include "quanLyVe.h"
#include "quanLyChuyenBay.h"
// tao tai khoan 
struct acc{
	string username ; 
	string password ;   
	string role ; 
}; 

void convert(string &s ){
	stringstream ss(s) ; 
	string word ; 
	ss>>word ; 
	s="" ; 
	s=word ; 
}

void dangKi( vector<acc>&v ){
	string username , password , role ; 
	acc tmp ; 
	int check = 0 , choose ;  
	while(true){
		cout<<"username : " ; cin>>tmp.username ; convert(tmp.username) ; 
	    cin.ignore() ; 
	    cout<<"password : " ; cin>>tmp.password ; convert(tmp.password ) ; 
	    cin.ignore() ; 
    	cout<<"role (admin/user) : " ; cin>>tmp.role ; convert(tmp.role) ;// vai tro 
    	if(v.size()==0){
    		v.push_back(tmp)  ; 
    		cout<<"DANG KI THANH CONG!"<<endl ;
    		break ; 
		}
	    for(acc a : v){
		    if(a.username ==tmp.username){
			    cout<<"TAI KHOAN DA TON TAI!"<<endl ; 
			    check=1 ; 
			    break ; 
		    }
	    }
	    if(check ==0){
	    	v.push_back(tmp) ; 
	    	cout<<"DANG KI TAI KHOAN THANH CONG!"<<endl ; 
	    	break ; 
		} 
	    else if(check==1){
	    	cout<<"DANG KI TAI KHOAN KHONG THANH CONG!"<<endl ;
	    	cout<<"1. Tiep tuc"<<endl ; 
	        cout<<"2. Thoat"<<endl ; 
	        cin>>choose ; 
	        if(choose==1) continue ; 
	        else if(choose==2) break ; 
		}
	}
}

void dangNhap(string &s , vector<acc> v , int &kiemtra){
	string username , password ; 
	int check =0 ; 
	cout<<"username : " ; cin>>username ; convert(username) ; 
	cin.ignore() ; 
	cout<<"password : " ; cin>>password ; convert(password ) ; 
	cin.ignore() ; 
	if(v.size() == 0 ){
		cout<<"TAI KHOAN HOAC MAT KHAU KHONG TON TAI!"<<endl ; 
		return ; 
	}
	for(acc a : v ){
		if(a.username == username && a.password == password){
			s = a.role ; 
		    cout<<"DANG NHAP THANG CONG !"<<endl ; 
		    check =1 ; 
		    kiemtra = 1; 
			break ; 
		}
	} 
	if(check==0) cout<<"TAI KHOAN HOAC MAT KHAU KHONG TON TAI!"<<endl ; 
}
// tao tai khoan admin tu dong  
void admin(vector<acc>&v){
	acc a ; 
	a.password ="12345" ; 
	a.username ="admin" ; 
	a.role = "admin" ; 
	v.push_back(a) ;  
} 
using namespace std ; 
int main(){
	vector<acc> v ;  
	admin(v) ;  
	string role ="" ; 
	quanLyChuyenBay qlcb ; 
	quanLyVe qlv(&qlcb) ; 
	while(true){
		while(true){
		    cout<<"1. Dang nhap"<<endl ;
		    cout<<"2. Dang ki"<<endl ;  
		    cout<<"3. Thoat"<<endl ; 
		    int choose ; cout<<"Nhap lua chon cua ban : " ; cin>>choose ;  
		    if(choose==1){
		    	int check =0  ; 
		    	dangNhap(role , v ,check) ;
		    	if(check==0) continue ; 
		    	else break ; 
			}
		    else if(choose == 2) dangKi(v) ; 
		    else if(choose ==3 ) return 0; 
	   } 
        if(role=="admin"){
        	while(true){
		        cout<<"===================MENU================="<<endl ; 
		        cout<<"1. Them chuyen bay"<<endl ; // them chuyen bay
		        cout<<"2. Xoa chuyen bay"<<endl ; // Xoa chuyen bay va ca ve cung luc . vi chuyen bay da mat di  
		        cout<<"3. Xem lich trinh chuyen bay"<<endl ; // danh sach cac chuyen bay
		        cout<<"4. Tim chuyen bay"<<endl ; // tim theo ma chuyen bay
		        cout<<"5. Dat ve"<<endl ; //dat ve bay
		        cout<<"6. Huy ve"<<endl ; // huy ve bay
		        cout<<"7. Tra cuu ve"<<endl ;// tim ve theo cccd
		        cout<<"8. Thong ke ve"<<endl ; // thong ke loai : thuong va thuong gia
		        cout<<"9. Nhap ve may bay tu danh sach"<<endl ; 
		        cout<<"10. xuat file"<<endl ; 
		        cout<<"11. Thoat"<<endl ;  
		        int choose ; cout<<"Nhap lua chon cua ban : " ; cin>>choose ; cin.ignore() ; 
		        if(choose==1) qlcb.themChuyenBay() ; 
		        else if(choose==2){	
			        qlcb.xoaChuyenBay() ; 
			        qlv.checkXoaChuyenBay() ; 
		        }
		        else if(choose==3) qlcb.xemLichTrinh()  ; 
		        else if(choose==4){
			        string ma ; cout<<"Nhap ma chuyen bay can tim : " ; cin>>ma ; 
			        chuyenBay *cb = qlcb.timChuyenBay(ma) ; 
			        cb->formFrame() ; 
			        cb->xuat() ; 
		        }else if(choose == 5){
			        qlv.datVe() ; 
		        }else if(choose==6){
			        string mave ; 
			        cout<<"Nhap ma ve can xoa : " ; cin>>mave ; 
			        qlv.huyVe(mave) ; 
		        }else if(choose==7){
			        string cccd ; 
			        cout<<"Nhap so cccd : " ; cin>>cccd ; 
			        qlv.traCuuVe(cccd) ; 
		        }else if(choose==8){
			        qlv.thongKeVe() ;  
		        }else if(choose == 9){
		        	qlv.nhapFile() ; 
				}else if(choose==10){
		        	qlv.xuatFile() ;  
				}else if(choose==11) break ;  
	        }
		}else if(role=="user"){
			while(true){
		        cout<<"===================MENU================="<<endl ; 
		        cout<<"1. Xem lich trinh"<<endl ; // danh sach cac chuyen bay
		        cout<<"2. Tim chuyen bay"<<endl ; // tim theo ma chuyen bay
		        cout<<"3. Dat ve"<<endl ; //dat ve bay
		        cout<<"4. Thay doi thong tin ve"<<endl ; 
		        cout<<"5. Huy ve"<<endl ; // huy ve bay
		        cout<<"6. Thong ke ve"<<endl ; // thong ke loai : thuong va thuong gia
		        cout<<"7. Thoat"<<endl ; 
		        int choose ; cout<<"Nhap lua chon cua ban : " ; cin>>choose ; cin.ignore() ; 
		        if(choose==1) qlcb.xemLichTrinh()  ; 
		        else if(choose==2){
			        string ma ; cout<<"Nhap ma chuyen bay can tim : " ; cin>>ma ; 
			        chuyenBay *cb = qlcb.timChuyenBay(ma) ; 
			        cb->formFrame() ; 
			        cb->xuat() ; 
		        }else if(choose == 3){
			        qlv.datVe() ; 
		        }else if(choose==4){
		        	qlv.capNhatVe() ; 
				}
				else if(choose==5){
			        string mave ; 
			        cout<<"Nhap ma ve can huy : " ; cin>>mave ; 
			        qlv.huyVe(mave) ; 
		        }else if(choose==6){
			        qlv.thongKeVe() ;   
		        }else if(choose==7) break ; 
	        }
		}
		int choose ; 
		cout<<"1. Tiep tuc dang nhap" <<endl ; 
		cout<<"2. Thoat"<<endl;
		cout<<"Nhap lua chon : " ; cin>>choose ; 
		if(choose==1) continue ; 
		else if(choose==2) break ;  
	}
}
