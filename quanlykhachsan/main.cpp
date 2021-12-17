#include"khachsan.h"


int main()
{
	khachsan x;
	ifstream FileIn;
	FileIn.open("DanhSachPhongCoTrongKhachSan.TXT", ios_base::in);
	if (!FileIn)
	{
		cout << "\nKhong tim thay tap tin DanhSachPhongCoTrongKhachSan.TXT";
		exit(1);
	}
	x.loadthongtinphong(FileIn);
	FileIn.close();

	ifstream FileIn1;
	FileIn1.open("DanhSachKhachHang.TXT", ios_base::in);
	if (!FileIn1)
	{
		cout << "\nKhong tim thay tap tin DanhSachKhachHang.TXT";
		exit(1);
	}
	x.loadthongtinkhachhang(FileIn1);
	FileIn1.close();

	ifstream FileIn2;
	FileIn2.open("DanhSachCacHoaDon.TXT", ios_base::in);
	if (!FileIn2)
	{
		cout << "\nKhong tim thay tap tin DanhSachCacHoaDon.TXT";
		exit(1);
	}
	x.loadthongtinhoadon(FileIn2);
	FileIn2.close();
	x.nhap();
	system("pause");
	return 0;
}