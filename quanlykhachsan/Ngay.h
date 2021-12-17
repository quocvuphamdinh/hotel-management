#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
//#include<ctime>
using namespace std;
class Ngay
{
private:
	int ngay, thang, nam;
public:
	void nhap();
	void xuat();
	void tinhngayhientai();
	void congngay(int);
	int getter_ngay();
	void setter_ngay(int);
	int getter_thang();
	void setter_thang(int);
	int getter_nam();
	void setter_nam(int);
};

