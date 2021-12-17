#pragma once
#include"khachhang.h"
#include"phongthuong.h"
#include"phongvip.h"
#include<vector>
class hoadon
{
private:
	string mahoadon;
	int loaiphong, songaythue;
	khachhang Khachhang;
	Ngay ngaydatphong, ngaytraphong;
	vector<phongvip>listphongvip;
	vector<phongthuong>listphongthuong;
public:
	void nhap();
	void xuat();
	void xoaphong();
	float tinhtien();
	int getter_loaiphong();
	void setter_loaiphong(int);
	string getter_mahoadon();
	void setter_mahoadon(string);
	khachhang getter_khachhang();
	void setter_khachhang(khachhang);
	void setter_cmndkhachhang(string);
	void setter_discountkhachhang(int);
	void setter_ngaysinhkhachhang(Ngay);
	vector<phongvip>getter_listphongvip();
	void setter_listphongvip(phongvip);
	vector<phongthuong>getter_listphongthuong();
	void setter_listphongthuong(phongthuong);
	void setter_hotenkhachhang(string);
	Ngay getter_ngaydatphong();
	void setter_ngaydatphong(Ngay);
	Ngay getter_ngaytraphong();
	void setter_ngaytraphong(Ngay);
	int getter_songaythue();
	void setter_songaythue(int);
};

