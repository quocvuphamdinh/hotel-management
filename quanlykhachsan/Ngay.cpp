#include "Ngay.h"

void Ngay::nhap()
{
	do {
		cout << "\nNhap vao ngay: ";
		cin >> ngay;
		if (ngay < 1)
		{
			cout << "\nNgay khong hop le !";
		}
	} while (ngay < 1);

	do {
		cout << "\nNhap vao thang: ";
		cin >> thang;
		if (thang < 1 || thang>12)
		{
			cout << "\nThang khong hop le!";
		}
	} while (thang < 1 || thang>12);
	do {
		cout << "\nNhap vao nam: ";
		cin >> nam;
		if (nam < 0)
		{
			cout << "\nNam khong hop le!";
		}
	} while (nam < 0);
}

void Ngay::xuat()
{
	cout << ngay << "/" << thang << "/" << nam;
}

void Ngay::tinhngayhientai()
{
	time_t t = time(0);
	struct tm* Now = localtime(&t);
	ngay = Now->tm_mday;
	thang = Now->tm_mon + 1;
	nam = Now->tm_year + 1900;
}

void Ngay::congngay(int x)
{
	int mangngay[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
	{
		mangngay[1] = 29;
	}
	ngay += x;
	int tempngay;
	if (ngay > mangngay[thang - 1])
	{
		do {
			tempngay = ngay - mangngay[thang - 1];
			thang++; // cong len 1
			ngay = tempngay;
		} while (ngay > mangngay[thang - 1]);
	}
}
int Ngay::getter_ngay()
{
	return ngay;
}
void Ngay::setter_ngay(int d)
{
	ngay = d;
}
int Ngay::getter_thang() 
{
	return thang;
}
void Ngay::setter_thang(int m) 
{
	thang = m;
}
int Ngay::getter_nam()
{
	return nam;
}
void Ngay::setter_nam(int y)
{
	nam = y;
}

