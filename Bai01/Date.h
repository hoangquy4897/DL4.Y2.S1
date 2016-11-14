#pragma once
#include <iostream>
using namespace std;

class CDate
{
private:
	int Ngay, Thang, Nam;
	int NgayThang[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
	/*Nhom tao huy*/
	CDate();
	CDate(int, int, int);
	CDate(int, int);
	CDate(CDate&);
	~CDate();

	/*Nhom truy xuat thong tin*/
	void NgayThangNam();
	int ThuTrongTuan();
	int TuanTrongNam();
	int NgayTuyetDoi();

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

