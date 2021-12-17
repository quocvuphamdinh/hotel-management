#pragma once
#include"hoadon.h"
#include<fstream>
class khachsan
{
private:
	vector<phongvip>listphongvip;
	vector<phongthuong>listphongthuong;
	vector<hoadon>listhoadon;
	vector<khachhang>listkhachhang;
public:
	void nhap();
	void xuat();
	void themphong();
	void xoaphong();
	void datphong();
	void traphong();
	void xuatdanhsachcacphong();
	float thanhtoan();
	float tinhtongtienkhachsan();
	void loadthongtinphong(ifstream&);
	void loadthongtinkhachhang(ifstream&);
	void luuthongtin(ofstream&);
	void capnhapthongtinphong(ofstream&);
	void luuthongtinkhachhang(ofstream&);
	void loadthongtinhoadon(ifstream&);
};

