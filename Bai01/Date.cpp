#include "Date.h"

/*Nhom tao huy*/
CDate::CDate()
{
	Ngay = 14;
	Thang = 11;
	Nam = 2016;
}
CDate::CDate(int ngay, int thang, int nam)
{
	Ngay = ngay;
	Thang = thang;
	Nam = nam;
}
CDate::CDate(int ngay, int nam)
{
	cout << "Em khong biet ngay tuyet doi la ngay gi!" << endl;
}
CDate::CDate(CDate &a)
{
	Ngay = a.Ngay;
	Thang = a.Thang;
	Nam = a.Nam;
}
CDate::~CDate()
{
}

/*Nhom truy xuat thong tin*/
void CDate::NgayThangNam()
{
	cout << "Ngay thang nam hien tai: " << Ngay << "/" << Thang << "/" << Nam << endl;
}

void CDate::NgayTuyetDoi()
{
	int dayorder = Ngay;
	int month = 0;
	while (month != Thang - 1)
	{
		dayorder += NgayThang[month];
		month++;
	}
	cout << dayorder;
}