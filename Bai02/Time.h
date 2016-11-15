#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
	int Gio, Phut, Giay;
public:
	/*Nhom tao huy*/
	Time();
	Time(int, int, int);
	Time(int, int);
	Time(Time&);
	~Time();

	/*Nhom truy xuat thong tin*/
	void GioPhutGiay();
	int GiayTuyetDoi();

	/*Nhom xu ly nghiep vu*/
	bool SoSanhThuTu(Time&);
	int TinhKhoangCachDenThoiDiemKhac(Time&);
	Time CongGioPhutGiay(Time&);

	/*Nhom toan tu*/
	bool operator>(Time&);
	bool operator<(Time&);
	bool operator==(Time&);
	bool operator>=(Time&);
	bool operator<=(Time&);
	bool operator!=(Time&);
	friend istream& operator >> (istream&, Time&);
	friend ostream& operator << (ostream&, Time&);
};

