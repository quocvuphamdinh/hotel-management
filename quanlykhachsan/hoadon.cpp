#include "hoadon.h"

void hoadon::nhap()
{
	/*rewind(stdin);
	cout << "\nNhap vao ma hoa don: ";
	getline(cin, mahoadon);*/
	/*cout << "\nNhap thong tin khach hang: ";
	Khachhang.nhap();*/

	ngaydatphong.tinhngayhientai();

	do {
		cout << "\nNhap vao so ngay thue: ";
		cin >> songaythue;
		if (songaythue < 0)
		{
			cout << "\nSo ngay o khong hop le !";
		}
	} while (songaythue < 0);

	ngaytraphong.tinhngayhientai();
	ngaytraphong.congngay(songaythue);

}
void hoadon::xuat()
{
	cout << "\nMa hoa don: " << mahoadon;
	cout << "\nThong tin khach hang: ";
	Khachhang.xuat();
	cout << "\nNgay dat phong: ";
	ngaydatphong.xuat();
	cout << "\nSo ngay thue: " << songaythue;
	cout << "\nNgay tra phong: ";
	ngaytraphong.xuat();
	cout << "\nThong tin phong thue: ";
	for (int i = 0; i < listphongvip.size(); i++)
	{
		listphongvip[i].xuat();
	}
	for (int i = 0; i < listphongthuong.size(); i++)
	{
		listphongthuong[i].xuat();
	}
}

float hoadon::tinhtien()
{
	float sotien = 0;
	if (Khachhang.getter_discount() == 1)
	{
		cout << "\nDa giam 20%";
		for (int i = 0; i < listphongvip.size(); i++)
		{
			sotien += listphongvip[i].tinhtienphong() * songaythue * 0.8;
		}
		for (int i = 0; i < listphongthuong.size(); i++)
		{
			sotien += listphongthuong[i].tinhtienphong() * songaythue * 0.8;
		}
	}
	else
	{
		for (int i = 0; i < listphongvip.size(); i++)
		{
			sotien += listphongvip[i].tinhtienphong() * songaythue;
		}
		for (int i = 0; i < listphongthuong.size(); i++)
		{
			sotien += listphongthuong[i].tinhtienphong() * songaythue;
		}
	}
	return sotien;
}

void hoadon::xoaphong()
{
	string maphongxoa;
	rewind(stdin);
	cout << "\nNhap vao ma phong ma ban muon xoa: ";
	getline(cin, maphongxoa);
	for (int i = 0; i < listphongvip.size(); i++)
	{
		if (listphongvip[i].getter_maphong() == maphongxoa)
		{
			listphongvip.erase(listphongvip.begin() + i);
			break;
		}
	}
	for (int i = 0; i < listphongthuong.size(); i++)
	{
		if (listphongthuong[i].getter_maphong() == maphongxoa)
		{
			listphongthuong.erase(listphongthuong.begin() + i);
			break;
		}
	}
}

int hoadon::getter_loaiphong()
{
	return loaiphong;
}
void hoadon::setter_loaiphong(int lp)
{
	loaiphong = lp;
}

string hoadon::getter_mahoadon()
{
	return mahoadon;
}
void hoadon::setter_mahoadon(string mhd)
{
	mahoadon = mhd;
}
khachhang hoadon::getter_khachhang()
{
	return Khachhang;
}
void hoadon::setter_cmndkhachhang(string cmnd)
{
	Khachhang.setter_cmnd(cmnd);
}

vector<phongvip>hoadon::getter_listphongvip()
{
	return listphongvip;
}
void hoadon::setter_listphongvip(phongvip vip)
{
	listphongvip.push_back(vip);
}
vector<phongthuong>hoadon::getter_listphongthuong()
{
	return listphongthuong;
}
void hoadon::setter_listphongthuong(phongthuong thuong)
{
	listphongthuong.push_back(thuong);
	
}


void hoadon::setter_hotenkhachhang(string htkh)
{
	Khachhang.setter_hoten(htkh);
}

void hoadon::setter_khachhang(khachhang kh)
{
	Khachhang = kh;
}

void hoadon::setter_ngaysinhkhachhang(Ngay ns)
{
	Khachhang.setter_ngaysinh(ns);
}
void hoadon::setter_discountkhachhang(int dskh)
{
	Khachhang.setter_discount(dskh);
}
Ngay hoadon::getter_ngaydatphong()
{
	return ngaydatphong;
}
void hoadon::setter_ngaydatphong(Ngay ndp)
{
	ngaydatphong = ndp;
}
Ngay hoadon::getter_ngaytraphong()
{
	return ngaytraphong;
}
void hoadon::setter_ngaytraphong(Ngay ntp)
{
	ngaytraphong = ntp;
}
int hoadon::getter_songaythue()
{
	return songaythue;
}
void hoadon::setter_songaythue(int snt)
{
	songaythue = snt;
}