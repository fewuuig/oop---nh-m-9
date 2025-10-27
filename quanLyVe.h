#ifndef QUANLYVE_H
#define QUANLYVE_H
#include "veMayBay.h"
#include "chuyenBay.h"
#include "quanLyChuyenBay.h"
#include <vector>
class quanLyVe{
	private:
		vector<veMayBay*> dsVe;
		quanLyChuyenBay *qlcb ; 
	public:
		~quanLyVe();
		quanLyVe(quanLyChuyenBay *ql) ; 
		void datVe();
		void huyVe(string maVe);
		void traCuuVe(string soCCCD);
		void thongKeVe(); 
		void checkXoaChuyenBay() ; 
		void xuatFile() ;  
		void nhapFile() ;  
		void capNhatVe() ;  
};
#endif
