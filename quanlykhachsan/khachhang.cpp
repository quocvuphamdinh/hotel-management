#include "khachhang.h"


void khachhang::nhap()
{
	/*rewind(stdin);
	cout << "\nNhap vao CMND: ";
	getline(cin, CMND);*/

	rewind(stdin);
	cout << "\nNhap vao ho ten khach khang: ";
	getline(cin, hoten);

	cout << "\nNhap vao ngay sinh: ";
	ngaysinh.nhap();
}

void khachhang::xuat()
{
	cout << "\nCMND: " << CMND;
	cout << "\nHo ten: " << hoten;
	cout << "\nNgay sinh: ";
	ngaysinh.xuat();
}

string khachhang::getter_cmnd()
{
	return CMND;
}
void khachhang::setter_cmnd(string Cmnd)
{
	CMND = Cmnd;
}
string khachhang::getter_hoten()
{
	return hoten;
}
void khachhang::setter_hoten(string ht)
{
	hoten = ht;
}
Ngay khachhang::getter_ngaysinh()
{
	return ngaysinh;
}
void khachhang::setter_ngaysinh(Ngay ns)
{
	ngaysinh = ns;
}

int khachhang::getter_discount()
{
	return discount;
}
void khachhang::setter_discount(int ds)
{
	discount = ds;
}