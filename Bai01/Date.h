#pragma once
#include <iostream>
using namespace std;

class CDate
{
private:
	int Ngay, Thang, Nam;
public:
	/*Nhom tao huy*/
	CDate();
	CDate(int, int, int);
	CDate(int, int);
	CDate(CDate&);
	~CDate();

	/*Nhom truy xuat thong tin*/
	void NgayThangNam();
	void ThuTrongTuan();
	void TuanTrongNam();
	void NgayTuyetDoi();

	/*Nhom xu ly nghiep vu*/
	bool KiemTraNamNhuan();
	bool SoSanhThuTuNgay(CDate&);
	int TinhKhoangCachDenNgayKhac(CDate&);
	void TimNgayTruocVaSau();
	CDate CongNgayThangNam(CDate&);

	/*Nhom toan tu*/
	bool operator>(CDate&);
	bool operator<(CDate&);
	bool operator==(CDate&);
	bool operator>=(CDate&);
	bool operator<=(CDate&);
	bool operator!=(CDate&);
	friend istream& operator >> (istream&, CDate&);
	friend ostream& operator << (ostream&, CDate&);
};

