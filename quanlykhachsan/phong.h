#pragma once
#include"khachhang.h"
class phong
{
protected:
	string maphong, tenphong;
	int tinhtrang, id;
public:
	void nhap();
	void xuat();
	string getter_maphong();
	void setter_maphong(string);
	string getter_tenphong();
	void setter_tenphong(string);
	int getter_tinhtrang();
	void setter_tinhtrang(int);
	int getter_id();
	void setter_id(int);

};

