#pragma once
#include"Ngay.h"
#include<string>
class khachhang
{
private:
	string CMND, hoten;
	Ngay ngaysinh;
	int discount;
public:
	void nhap();
	void xuat();
	string getter_cmnd();
	void setter_cmnd(string);
	string getter_hoten();
	void setter_hoten(string);
	Ngay getter_ngaysinh();
	void setter_ngaysinh(Ngay);
	int getter_discount();
	void setter_discount(int);
};

