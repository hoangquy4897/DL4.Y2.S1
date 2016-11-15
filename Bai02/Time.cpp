#include "Time.h"

/*Nhom tao huy*/
Time::Time()
{
	Gio = 11;
	Phut = 0;
	Giay = 0;
}
Time::Time(int giay, int phut, int gio)
{
	Giay = giay;
	Phut = phut;
	Gio = gio;
}
Time::Time(int giay, int gio)
{
	cout << "Em khong biet giay tuyet doi la giay gi!" << endl;
}
Time::Time(Time &a)
{
	Giay = a.Giay;
	Phut = a.Phut;
	Gio = a.Gio;
}
Time::~Time()
{
}

/*Nhom truy xuat thong tin*/
void Time::GioPhutGiay()
{
	cout << "Giay Phut Gio hien tai: " << Gio << ":" << Phut << ":" << Giay << endl;
}
int Time::GiayTuyetDoi()
{
	int giayorder = Giay + Phut * 60;
	return giayorder;
}

/*Nhom xu ly nghiep vu*/
int Time::TinhKhoangCachDenThoiDiemKhac(Time &Giay2)
{
	Time Giay1 = *this;
	return (abs(Giay1.GiayTuyetDoi() - Giay2.GiayTuyetDoi()));
}
Time Time::CongGioPhutGiay(Time &a)
{
	Time sum;
	sum.Gio = Gio + a.Gio;
	sum.Phut = Phut + a.Phut;
	sum.Giay = Giay + a.Giay;
	if (sum.Giay >= 60)
	{
		sum.Giay = sum.Giay % 60;
		sum.Phut++;
		if (sum.Phut >= 60)
		{
			sum.Phut = sum.Phut % 60;
			sum.Gio++;
		}
	}
	return sum;
}

/*Nhom toan tu*/
bool Time::operator>(Time &a)
{
	if (Gio > a.Gio)
		return true;
	else
	{
		if (Gio == a.Gio)
		{
			if (Phut > a.Phut)
				return true;
			else
			{
				if (Phut == a.Phut)
				{
					if (Giay > a.Giay)
						return true;
				}
			}
		}
	}
	return false;
}
bool Time::operator<(Time &a)
{
	if (Gio < a.Gio)
		return true;
	else
	{
		if (Gio == a.Gio)
		{
			if (Phut < a.Phut)
				return true;
			else
			{
				if (Phut == a.Phut)
				{
					if (Giay < a.Giay)
						return true;
				}
			}
		}
	}
	return false;
}
bool Time::operator==(Time &a)
{
	return (Gio == a.Gio && Phut == a.Phut && Giay == a.Giay) ? true : false;
}
bool Time::operator>=(Time &a)
{
	if (Gio >= a.Gio)
		return true;
	else
	{
		if (Gio == a.Gio)
		{
			if (Phut >= a.Phut)
				return true;
			else
			{
				if (Phut == a.Phut)
				{
					if (Giay >= a.Giay)
						return true;
				}
			}
		}
	}
	return false;
}
bool Time::operator<=(Time &a)
{
	if (Gio <= a.Gio)
		return true;
	else
	{
		if (Gio == a.Gio)
		{
			if (Phut <= a.Phut)
				return true;
			else
			{
				if (Phut == a.Phut)
				{
					if (Giay <= a.Giay)
						return true;
				}
			}
		}
	}
	return false;
}
bool Time::operator!=(Time &a)
{
	return (Gio != a.Gio || Phut != a.Phut || Giay != a.Giay) ? true : false;
}
istream& operator >> (istream &nhap, Time &a)
{
	cout << "Nhap Giay: "; nhap >> a.Giay;
	cout << "Nhap Phut: "; nhap >> a.Phut;
	cout << "Nhap Gio: "; nhap >> a.Gio;
	return nhap;
}
ostream& operator << (ostream &xuat, Time &a)
{
	xuat << a.Gio << "/" << a.Phut << "/" << a.Giay << endl;
	return xuat;
}
