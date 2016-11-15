#pragma once
#include <iostream>
#include <vector>
using namespace std;
template <class T>

class CMang
{
private:
	int KichThuoc;
	vector <T> Mang;
public:
	CMang()
	{
		KichThuoc = 0;
	}
	CMang(int kichthuoc)
	{
		KichThuoc = kichthuoc;
		for (int i = 0; i < kichthuoc; i++)
			Mang.push_back(0);
	}
	~CMang();
	T LayPhanTu(int vitri)
	{
		return Mang[vitri];
	}
};

