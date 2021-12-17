#include "phong.h"

void phong::nhap()
{
	/*rewind(stdin);
	cout << "\nNhap vao ma phong: ";
	getline(cin, maphong);*/

	rewind(stdin);
	cout << "\nNhap vao ten phong: ";
	getline(cin, tenphong);


	cout << "\n------- Tinh Trang -------\n";
	cout << "\n1.Con";
	cout << "\n2.Khong";
	cout << "\n--------------------------\n";
	do {
		cout << "\nTinh trang phong: ";
		cin >> tinhtrang;
		if (tinhtrang < 1 || tinhtrang>2)
		{
			cout << "\nTinh trang khong hop le !";
		}
	} while (tinhtrang < 1 || tinhtrang>2);

}

void phong::xuat()
{
	cout << "\nMa so phong: " << maphong;
	cout << "\nTen phong: " << tenphong;

	/*if (tinhtrang == 1)
	{
		cout << "\nTinh trang: Con";
	}
	else
	{
		cout << "\nTinh trang: Khong";
	}*/
}

string phong::getter_maphong()
{
	return maphong;
}
void phong::setter_maphong(string mp)
{
	maphong = mp;
}
string phong::getter_tenphong()
{
	return tenphong;
}
void phong::setter_tenphong(string tp)
{
	tenphong = tp;
}
int phong::getter_tinhtrang()
{
	return tinhtrang;
}
void phong::setter_tinhtrang(int tt)
{
	tinhtrang = tt;
}

int phong::getter_id()
{
	return id;
}
void phong::setter_id(int i)
{
	id = i;
}
