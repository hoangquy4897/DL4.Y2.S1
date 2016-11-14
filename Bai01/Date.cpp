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
int CDate::ThuTrongTuan()
{
	CDate temp = *this;
	int thu;
	cout << "Nhap vao thu ngay dau tien cua nam: "; cin >> thu;
	thu = thu + (temp.NgayTuyetDoi() % 7) - 1;
	if (thu > 8)
		thu = (thu % 7);
	return thu;
}
int CDate::TuanTrongNam()
{
	CDate temp = *this;
	int dayorder = temp.NgayTuyetDoi();
	int weekorder = dayorder / 7;
	if (dayorder % 7 != 0)
		weekorder++;
	return weekorder;
}
int CDate::NgayTuyetDoi()
{
	int dayorder = Ngay;
	int month = 0;
	while (month != Thang - 1)
	{
		dayorder += NgayThang[month];
		month++;
	}
	return dayorder;
}

/*Nhom xu ly nghiep vu*/
bool CDate::KiemTraNamNhuan()
{
	if ((Nam % 400 == 0) || (Nam % 100 != 0 && Nam % 4 == 0))
	{
		NgayThang[1] = 29;
		return true;
	}
	else
		return false;
}
bool CDate::SoSanhThuTuNgay(CDate &a)
{
	CDate temp = *this;
	return (temp.NgayTuyetDoi() > a.NgayTuyetDoi()) ? true : false;
}
int CDate::TinhKhoangCachDenNgayKhac(CDate &Ngay2)
{
	CDate Ngay1 = *this;
	CDate check;
	if (Ngay1.Nam == Ngay2.Nam) //Neu 2 ngay cung nam
	{
		return abs(Ngay1.NgayTuyetDoi() - Ngay2.NgayTuyetDoi()); //Lay thu tu 2 ngay tru nhau
	}
	else //Neu 2 ngay khong cung nam
	{
		int deductday; //Gia tri tra ve

					   /*TH nam ngay1 > nam ngay2*/
		if (Ngay1.Nam > Ngay2.Nam)
		{
			//Tinh khoang cach giua 2 ngay khong xet nam
			deductday = Ngay1.NgayTuyetDoi() + (365 - Ngay2.NgayTuyetDoi());
			if (Ngay2.KiemTraNamNhuan() == true)
				deductday += 1;
			//Cong them so ngay cua nhung nam giua 2 nam ngay1 va ngay2
			for (int i = Ngay2.Nam + 1; i < Ngay1.Nam; i++)
			{
				check.Nam = i;
				if (check.KiemTraNamNhuan() == true)
					deductday += 366;
				else
					deductday += 365;
			}
		}
		/*TH nam ngay2 > nam ngay 1*/
		else
		{
			//Tuong tu truong hop tren
			deductday = Ngay2.NgayTuyetDoi() + (365 - Ngay1.NgayTuyetDoi());
			if (Ngay1.KiemTraNamNhuan() == true)
				deductday += 1;
			for (int i = Ngay1.Nam + 1; i < Ngay2.Nam; i++)
			{
				check.Nam = i;
				if (check.KiemTraNamNhuan() == true)
					deductday += 366;
				else
					deductday += 365;
			}
		}
		return deductday;
	}
}
void CDate::TimNgayTruocVaSau()
{
	cout << "Ngay lien truoc la: " << Ngay - 1 << "/" << Thang << "/" << Nam << endl;
	cout << "Ngay lien sau la: " << Ngay + 1 << "/" << Thang << "/" << Nam << endl;
}
CDate CDate::CongNgayThangNam(CDate &a)
{
	CDate sum;
	sum.Nam = Nam + a.Nam;
	sum.Thang = Thang + a.Thang;
	if (sum.Thang > 12)
	{
		sum.Nam += sum.Thang / 12;
		sum.Thang = sum.Thang % 12;
	}
	sum.Ngay = Ngay + a.Ngay;
	if (sum.Ngay > NgayThang[sum.Thang-1])
	{
		while (sum.Ngay > NgayThang[sum.Thang - 1])
		{
			sum.Ngay -= NgayThang[sum.Thang - 1];
			sum.Thang++;
		}
		if (sum.Thang > 12)
		{
			sum.Nam += sum.Thang / 12;
			sum.Thang = sum.Thang % 12;
		}
	}
	return sum;
}

/*Nhom toan tu*/
bool CDate::operator>(CDate &a)
{
	if (Nam > a.Nam)
		return true;
	else
	{
		if (Nam == a.Nam)
		{
			if (Thang > a.Thang)
				return true;
			else
			{
				if (Thang == a.Thang)
				{
					if (Ngay > a.Ngay)
						return true;
				}
			}
		}
	}
	return false;
}
bool CDate::operator<(CDate &a)
{
	if (Nam < a.Nam)
		return true;
	else
	{
		if (Nam == a.Nam)
		{
			if (Thang < a.Thang)
				return true;
			else
			{
				if (Thang == a.Thang)
				{
					if (Ngay < a.Ngay)
						return true;
				}
			}
		}
	}
	return false;
}
bool CDate::operator==(CDate &a)
{
	return (Nam == a.Nam && Thang == a.Thang && Ngay == a.Ngay) ? true : false;
}
bool CDate::operator>=(CDate &a)
{
	if (Nam >= a.Nam)
		return true;
	else
	{
		if (Nam == a.Nam)
		{
			if (Thang >= a.Thang)
				return true;
			else
			{
				if (Thang == a.Thang)
				{
					if (Ngay >= a.Ngay)
						return true;
				}
			}
		}
	}
	return false;
}
bool CDate::operator<=(CDate &a)
{
	if (Nam <= a.Nam)
		return true;
	else
	{
		if (Nam == a.Nam)
		{
			if (Thang <= a.Thang)
				return true;
			else
			{
				if (Thang == a.Thang)
				{
					if (Ngay <= a.Ngay)
						return true;
				}
			}
		}
	}
	return false;
}
bool CDate::operator!=(CDate &a)
{
	return (Nam != a.Nam || Thang != a.Thang || Ngay != a.Ngay) ? true : false;
}
istream& operator >> (istream &nhap, CDate &a)
{
	cout << "Nhap ngay: "; nhap >> a.Ngay;
	cout << "Nhap thang: "; nhap >> a.Thang;
	cout << "Nhap nam: "; nhap >> a.Nam;
	return nhap;
}
ostream& operator << (ostream &xuat, CDate &a)
{
	xuat << a.Ngay << "/" << a.Thang << "/" << a.Nam << endl;
}