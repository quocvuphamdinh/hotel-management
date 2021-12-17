#include "khachsan.h"

void khachsan::nhap()
{
quocvu:
	int luachon1;
	cout << "\n************ QUAN LY KHACH SAN ************\n";
	cout << "\n                   MENU                    \n";
	cout << "\n*******************************************\n";
	cout << "\n1.Them Phong";
	cout << "\n2.Xoa Phong";
	cout << "\n3.Dat Phong";
	cout << "\n4.Tra Phong";
	cout << "\n5.Xuat danh sach cac hoa don";
	cout << "\n6.Thuc hien thanh toan phong";
	cout << "\n7.Xuat danh cac phong da thue";
	cout << "\n8.Tinh tong tien khach san thu duoc";
	cout << "\n9.Exit";
	cout << "\n*******************************************\n";
	do {
		cout << "\nVui long chon vao lua chon cua ban: ";
		cin >> luachon1;
		if (luachon1 < 1 || luachon1>9)
		{
			cout << "\nLua chon khong hop le. Vui long lua chon lai !";
		}
	} while (luachon1 < 1 || luachon1>9);
	if (luachon1 == 1)
	{
		xuatdanhsachcacphong();
		themphong();
		ofstream FileOut;
		FileOut.open("DanhSachPhongCoTrongKhachSan.TXT", ios_base::out);
		capnhapthongtinphong(FileOut);
		FileOut.close();
		goto quocvu;
	}
	else if (luachon1 == 2)
	{
		xuatdanhsachcacphong();
		xoaphong();
		ofstream FileOut;
		FileOut.open("DanhSachPhongCoTrongKhachSan.TXT", ios_base::out);
		capnhapthongtinphong(FileOut);
		FileOut.close();
		goto quocvu;
	}
	else if (luachon1 == 3)
	{
		datphong();
		ofstream FileOut;
		FileOut.open("DanhSachCacHoaDon.TXT", ios_base::out);
		luuthongtin(FileOut);
		FileOut.close();
		FileOut.open("DanhSachPhongCoTrongKhachSan.TXT", ios_base::out);
		capnhapthongtinphong(FileOut);
		FileOut.close();
		FileOut.open("DanhSachKhachHang.TXT", ios_base::out);
		luuthongtinkhachhang(FileOut);
		FileOut.close();
		goto quocvu;
	}
	else if (luachon1 == 4)
	{
		ofstream FileOut;

		traphong();

		FileOut.open("DanhSachCacHoaDon.TXT", ios_base::out);
		luuthongtin(FileOut);
		FileOut.close();

		FileOut.open("DanhSachPhongCoTrongKhachSan.TXT", ios_base::out);
		capnhapthongtinphong(FileOut);
		FileOut.close();
		goto quocvu;
	}
	else if (luachon1 == 5)
	{
		xuat();
		goto quocvu;
	}
	else if (luachon1 == 6)
	{
		cout << "\nSo tien phai tra: " << (size_t)thanhtoan();
		goto quocvu;
	}
	else if (luachon1 == 7)
	{
		cout << "\nDanh sach phong vip dang thue:\n";
		for (int i = 0; i < listphongvip.size(); i++)
		{
			if (listphongvip[i].getter_tinhtrang() == 2)
			{
				cout << listphongvip[i].getter_maphong() << endl;
			}
		}
		cout << "\nDanh sach phong thuong dang thue:\n";
		for (int i = 0; i < listphongthuong.size(); i++)
		{
			if (listphongthuong[i].getter_tinhtrang() == 2)
			{
				cout << listphongthuong[i].getter_maphong() << endl;
			}
		}
		goto quocvu;
	}
	else if (luachon1 == 8)
	{
		cout << "\nTong tien khach san thu duoc: " << (size_t)tinhtongtienkhachsan();
		goto quocvu;
	}
	else if (luachon1 == 9)
	{
		exit(1);
	}
}
float khachsan::tinhtongtienkhachsan()
{
	float tongtien = 0;
	for (int i = 0; i < listhoadon.size(); i++)
	{
		tongtien += listhoadon[i].tinhtien();
	}
	return tongtien;
}
void khachsan::xoaphong()
{
	string maphongcanxoa;
	bool checkmaphongcanxoa = false;
	rewind(stdin);
	cout << "\nNhap vao ma phong can xoa: ";
	getline(cin, maphongcanxoa);
	for (int i = 0; i < listphongvip.size(); i++)
	{
		if (listphongvip[i].getter_maphong() == maphongcanxoa)
		{
			checkmaphongcanxoa = true;
			listphongvip.erase(listphongvip.begin() + i);
			break;
		}
	}
	if (checkmaphongcanxoa == false)
	{
		for (int i = 0; i < listphongthuong.size(); i++)
		{
			if (listphongthuong[i].getter_maphong() == maphongcanxoa)
			{
				listphongthuong.erase(listphongthuong.begin() + i);
				break;
			}
		}
	}
}

void khachsan::traphong()
{
	cout << "\nDanh sach hoa don hien co: ";
	for (int i = 0; i < listhoadon.size(); i++)
	{
		cout << "\nHoa don thu " << (i + 1) << " :";
		cout << listhoadon[i].getter_mahoadon() << endl;
	}
	string mahoadonmuontim;
	rewind(stdin);
	cout << "\nNhap vao ma hoa don cam tim de tra phong: ";
	getline(cin, mahoadonmuontim);
	for (int i = 0; i < listhoadon.size(); i++)
	{
		if (listhoadon[i].getter_mahoadon() == mahoadonmuontim)
		{
			cout << "\nDanh phong vip co trong hoa don: \n";
			for (int j = 0; j < listhoadon[i].getter_listphongvip().size(); j++)
			{
				cout << listhoadon[i].getter_listphongvip()[j].getter_maphong() << endl;
			}
			cout << "\nDanh phong thuong co trong hoa don: \n";
			for (int j = 0; j < listhoadon[i].getter_listphongthuong().size(); j++)
			{
				cout << listhoadon[i].getter_listphongthuong()[j].getter_maphong() << endl;
			}
			listhoadon[i].xoaphong();
			string maphongxoa;
			rewind(stdin);
			cout << "\nNhap vao ma phong ma ban vua xoa de cap nhap lai tinh trang: ";
			getline(cin, maphongxoa);
			for (int j = 0; j < listphongthuong.size(); j++)
			{
				if (listphongthuong[j].getter_maphong() == maphongxoa) {
					listphongthuong[j].setter_tinhtrang(1);
					break;
				}
			}
			for (int j = 0; j < listphongvip.size(); j++)
			{
				if (listphongvip[j].getter_maphong() == maphongxoa) {
					listphongvip[j].setter_tinhtrang(1);
					break;
				}
			}
			int sizevip = listhoadon[i].getter_listphongvip().size();
			int sizethuong = listhoadon[i].getter_listphongthuong().size();
			int sizetongphong = sizevip + sizethuong;
			if (sizetongphong == 0)
			{
				listhoadon.erase(listhoadon.begin() + i);
			}
			break;
		}
	}
}

void khachsan::loadthongtinhoadon(ifstream& filein)
{
	string n;
	getline(filein, n);
	int size = atoi(n.c_str());
	for (int i = 0; i < size; i++)
	{
		hoadon x;
		string mahoadon;
		getline(filein, mahoadon, '-');
		mahoadon.erase(mahoadon.begin() + mahoadon.length() - 1);
		filein.seekg(1, SEEK_CUR);
		x.setter_mahoadon(mahoadon);

		string _songaythue;
		getline(filein, _songaythue, '-');
		int songaythue = atoi(_songaythue.c_str());
		filein.seekg(1, SEEK_CUR);
		x.setter_songaythue(songaythue);

		string _ngaydat, _thangdat, _namdat;
		getline(filein, _ngaydat, '/');
		int ngaydat = atoi(_ngaydat.c_str());
		getline(filein, _thangdat, '/');
		int thangdat = atoi(_thangdat.c_str());
		getline(filein, _namdat, '-');
		int namdat = atoi(_namdat.c_str());
		filein.seekg(1, SEEK_CUR);
		
		Ngay ngaydatphong;
		ngaydatphong.setter_ngay(ngaydat);
		ngaydatphong.setter_thang(thangdat);
		ngaydatphong.setter_nam(namdat);
		x.setter_ngaydatphong(ngaydatphong);
		

		string _ngaytra, _thangtra, _namtra;
		getline(filein, _ngaytra, '/');
		int ngaytra = atoi(_ngaytra.c_str());
		getline(filein, _thangtra, '/');
		int thangtra = atoi(_thangtra.c_str());
		getline(filein, _namtra, '-');
		int namtra = atoi(_namtra.c_str());
		filein.seekg(1, SEEK_CUR);

		Ngay ngaytraphong;
		ngaytraphong.setter_ngay(ngaytra);
		ngaytraphong.setter_thang(thangtra);
		ngaytraphong.setter_nam(namtra);
		x.setter_ngaytraphong(ngaytraphong);

		khachhang kh;
		Ngay ngaysinhkhachhang;
		string cmnd;
		getline(filein, cmnd, '-');
		cmnd.erase(cmnd.begin() + cmnd.length() - 1);
		filein.seekg(1, SEEK_CUR);

		string hoten;
		getline(filein, hoten, '-');
		hoten.erase(hoten.begin() + hoten.length() - 1);
		filein.seekg(1, SEEK_CUR);

		string _ngaysinh, _thangsinh, _namsinh;
		getline(filein, _ngaysinh, '/');
		int ngaysinh = atoi(_ngaysinh.c_str());
		getline(filein, _thangsinh, '/');
		int thangsinh = atoi(_thangsinh.c_str());
		getline(filein, _namsinh, '-');
		int namsinh = atoi(_namsinh.c_str());
		filein.seekg(1, SEEK_CUR);
		ngaysinhkhachhang.setter_ngay(ngaysinh);
		ngaysinhkhachhang.setter_thang(thangsinh);
		ngaysinhkhachhang.setter_nam(namsinh);
		kh.setter_cmnd(cmnd);
		kh.setter_hoten(hoten);
		kh.setter_ngaysinh(ngaysinhkhachhang);
		x.setter_khachhang(kh);

		string _discount;
		getline(filein, _discount, '-');
		int discount = atoi(_discount.c_str());
		filein.seekg(1, SEEK_CUR);
		x.setter_discountkhachhang(discount);

		string _soluongphong;
		getline(filein, _soluongphong);
		int soluongphong = atoi(_soluongphong.c_str());
		for (int i = 0; i < soluongphong; i++)
		{
			string _loaiphong;
			getline(filein, _loaiphong, '-');
			int loaiphong = atoi(_loaiphong.c_str());
			filein.seekg(1, SEEK_CUR);
			if (loaiphong == 1)
			{
				phongvip vip;
				string maphong;
				getline(filein, maphong, '-');
				maphong.erase(maphong.begin() + maphong.length() - 1);
				filein.seekg(1, SEEK_CUR);
				vip.setter_maphong(maphong);

				string tenphong;
				getline(filein, tenphong);
				vip.setter_tenphong(tenphong);
				x.setter_listphongvip(vip);
			}
			else
			{
				phongthuong thuong;
				string maphong;
				getline(filein, maphong, '-');
				maphong.erase(maphong.begin() + maphong.length() - 1);
				filein.seekg(1, SEEK_CUR);
				thuong.setter_maphong(maphong);

				string tenphong;
				getline(filein, tenphong);
				thuong.setter_tenphong(tenphong);
				x.getter_listphongvip().clear();
				x.setter_listphongthuong(thuong);
			}
		}
		listhoadon.push_back(x);
	}
}
void khachsan::themphong()
{
	int luachon;
	do {
		cout << "\n------------- Nhap Danh Sach Cac Phong -------------\n";
		cout << "\n1.Nhap Phong VIP";
		cout << "\n2.Nhap Phong Thuong";
		cout << "\n0.Thoat";

		do {
			cout << "\nNhap vao lua chon: ";
			cin >> luachon;
			if (luachon < 0 || luachon>2)
			{
				cout << "\nLua chon khong hop le!";
			}
		} while (luachon < 0 || luachon>2);

		bool checktrungmaphong;
		string maphong;


		if (luachon != 0)
		{
			do {
				checktrungmaphong = true;
				rewind(stdin);
				cout << "\nNhap vao ma phong: ";
				getline(cin, maphong);
				for (int i = 0; i < listphongvip.size(); i++)
				{
					if (listphongvip[i].getter_maphong() == maphong)
					{
						checktrungmaphong = false;
						break;
					}
				}
				if (checktrungmaphong == true)
				{
					for (int i = 0; i < listphongthuong.size(); i++)
					{
						if (listphongthuong[i].getter_maphong() == maphong)
						{
							checktrungmaphong = false;
							break;
						}
					}
				}
			    if (checktrungmaphong == false)
				{
					cout << "\nMa phong nay da bi trung !";
				}
			} while (checktrungmaphong == false);
		}

		if (luachon == 1)
		{
			phongvip vip;
			int sizevip = listphongvip.size();
			vip.nhap();
			vip.setter_maphong(maphong);
			vip.setter_id(sizevip=sizevip+1);
			listphongvip.push_back(vip);
		}
		else if (luachon == 2)
		{
			phongthuong thuong;
			int sizethuong = listphongthuong.size();
			thuong.nhap();
			thuong.setter_maphong(maphong);
			thuong.setter_id(sizethuong=sizethuong+1);
			listphongthuong.push_back(thuong);
		}
	} while (luachon != 0);
}
void khachsan::datphong()
{
	hoadon x;
	bool checktrungmahoadon;
	string mahoadon;
	do {
		checktrungmahoadon = true;
		rewind(stdin);
		cout << "\nNhap vao ma hoa don: ";
		getline(cin, mahoadon);
		for (int i = 0; i < listhoadon.size(); i++)
		{
			if (listhoadon[i].getter_mahoadon() == mahoadon)
			{
				checktrungmahoadon = false;
				break;
			}
		}
		if (checktrungmahoadon == false)
		{
			cout << "\nMa hoa don da bi trung !";
		}
	} while (checktrungmahoadon == false);


	bool checktrungcmnd;
	string cmnd;
	do
	{
		checktrungcmnd = true;
		rewind(stdin);
		cout << "\nNhap vao CMND: ";
		getline(cin, cmnd);

		for (int i = 0; i < listhoadon.size(); i++)
		{
			if (listhoadon[i].getter_khachhang().getter_cmnd() == cmnd)
			{
				checktrungcmnd = false;
				break;
			}
		}

		if (checktrungcmnd == false)
		{
			cout << "\nCMND da bi trung !";
		}
	} while (checktrungcmnd == false);
	//x.setter_cmndkhachhang(cmnd);
	
	khachhang kh;
	Ngay ngaysinh;
	bool checkkhanghang = false;
	
	for (int i = 0; i < listkhachhang.size(); i++)
	{
		if (listkhachhang[i].getter_cmnd() == cmnd)
		{
			checkkhanghang = true;
			cout << "\nBan da duoc giam gia 20%";
			cout << "\nNhap vao ngay sinh: ";
			ngaysinh.nhap();
			x.setter_khachhang(listkhachhang[i]);
			x.setter_discountkhachhang(1);
			x.setter_ngaysinhkhachhang(ngaysinh);
			break;
		}
	}

	if (checkkhanghang == false) {
		kh.nhap();
		x.setter_khachhang(kh);
		x.setter_cmndkhachhang(cmnd);
		x.setter_discountkhachhang(0);
	}
	x.setter_mahoadon(mahoadon);
	x.nhap();

	string timmaphong;
	bool checktimkiemmaphong, checktimthay;
	int luachonloaiphong;
	do {
		do {
			xuatdanhsachcacphong();
			cout << "\n----------------------------------\n";
			cout << "\nLua chon: 1.Phong VIP, 2.Phong Thuong, 0.Thoat";
			cout << "\n----------------------------------\n";
			do {
				cout << "\nVui long chon loai phong: ";
				cin >> luachonloaiphong;
				if (luachonloaiphong < 0 || luachonloaiphong>2)
				{
					cout << "\nLoai phong khong hop le !";
				}
			} while (luachonloaiphong < 0 || luachonloaiphong>2);
			checktimkiemmaphong = true;
			checktimthay = false;
			if (luachonloaiphong != 0) {
				rewind(stdin);
				cout << "\nNhap vao ma phong ban muon thue: ";
				getline(cin, timmaphong);
			}
			if (luachonloaiphong == 1)
			{
				for (int i = 0; i < listphongvip.size(); i++)
				{
					if (timmaphong == listphongvip[i].getter_maphong())
					{
						checktimthay = true;
						if (listphongvip[i].getter_tinhtrang() == 1) //con` phong
						{
							x.setter_listphongvip(listphongvip[i]);
							listphongvip[i].setter_tinhtrang(2);
							x.setter_loaiphong(1);
							break;
						}
						else 
						{
							checktimkiemmaphong = false;
							cout << "\nHien gio phong nay da khong con. Vui long chon phong khac !";
							break;
						}
					}

				}
				if (checktimthay == false)
				{
					checktimkiemmaphong = false;
					cout << "\nPhong nay khong co trong danh sach phong nay !";
				}
			}
			else if (luachonloaiphong == 2)
			{
				for (int i = 0; i < listphongthuong.size(); i++)
				{

					if (timmaphong == listphongthuong[i].getter_maphong())
					{
						checktimthay = true;
						if (listphongthuong[i].getter_tinhtrang() == 1) //con` phong
						{
							x.setter_listphongthuong(listphongthuong[i]);
							listphongthuong[i].setter_tinhtrang(2);
							x.setter_loaiphong(2);
							break;
						}
						else
						{
							checktimkiemmaphong = false;
							cout << "\nHien gio phong nay da khong con. Vui long chon phong khac !";
							break;
						}
					}
				}
				if (checktimthay == false)
				{
					checktimkiemmaphong = false;
					cout << "\nPhong nay khong co trong danh sach phong nay !";
				}
			}

			if (luachonloaiphong == 0)
			{
				checktimthay = true;
				//checktimkiemmaphong = true;
			}
		} while (checktimkiemmaphong == false);
	} while (luachonloaiphong != 0);
	listhoadon.push_back(x);
}

float khachsan::thanhtoan()
{
	cout << "\nDanh sach hoa don hien co: ";
	for (int i = 0; i < listhoadon.size(); i++)
	{
		cout << "\nHoa don thu " << (i + 1) << " :";
		cout << listhoadon[i].getter_mahoadon() << endl;
	}
	float sotienphaitra = 0;
	rewind(stdin);
	string mahoadon;
	cout << "\nNhap vao ma hoa don ban muon thanh toan: ";
	getline(cin, mahoadon);
	for (int i = 0; i < listhoadon.size(); i++)
	{
		if (listhoadon[i].getter_mahoadon()==mahoadon)
		{
			sotienphaitra += listhoadon[i].tinhtien();
			break;
		}
		
	}
	return sotienphaitra;
}

void khachsan::loadthongtinphong(ifstream& filein)
{
	string n;
	getline(filein, n);
	int size = atoi(n.c_str()); // doi chuoi thanh so
	for (int i = 1; i <= size; i++)
	{
		//phong* p = new phong;
		string _loaiphong;
		getline(filein, _loaiphong, '-');
		int loaiphong = atoi(_loaiphong.c_str());
		filein.seekg(1, SEEK_CUR);
		//x.setter_loaiphong(loaiphong);

		if (loaiphong == 1)
		{
			phongvip vip;
			string maphong;
			getline(filein, maphong, '-');
			maphong.erase(maphong.begin() + maphong.length() - 1);
			filein.seekg(1, SEEK_CUR);
			vip.setter_maphong(maphong);

			string tenphong;
			getline(filein, tenphong, '-');
			tenphong.erase(tenphong.begin() + tenphong.length() - 1);
			filein.seekg(1, SEEK_CUR);
			vip.setter_tenphong(tenphong);

			string _tinhtrang;
			getline(filein, _tinhtrang, '-');
			int tinhtrang = atoi(_tinhtrang.c_str());
			filein.seekg(1, SEEK_CUR);
			vip.setter_tinhtrang(tinhtrang);

			string _id;
			getline(filein, _id);
			int id = atoi(_id.c_str());
			//filein.seekg(1, SEEK_CUR);
			vip.setter_id(id);

			listphongvip.push_back(vip);
		}
		else if (loaiphong == 2)
		{
			phongthuong thuong;
			string maphong;
			getline(filein, maphong, '-');
			maphong.erase(maphong.begin() + maphong.length() - 1);
			filein.seekg(1, SEEK_CUR);
			thuong.setter_maphong(maphong);

			string tenphong;
			getline(filein, tenphong, '-');
			tenphong.erase(tenphong.begin() + tenphong.length() - 1);
			filein.seekg(1, SEEK_CUR);
			thuong.setter_tenphong(tenphong);

			string _tinhtrang;
			getline(filein, _tinhtrang, '-');
			int tinhtrang = atoi(_tinhtrang.c_str());
			filein.seekg(1, SEEK_CUR);
			thuong.setter_tinhtrang(tinhtrang);

			string _id;
			getline(filein, _id);
			int id = atoi(_id.c_str());
			//filein.seekg(1, SEEK_CUR);
			thuong.setter_id(id);

			listphongthuong.push_back(thuong);
		}
	}
}

void khachsan::luuthongtin(ofstream& fileout)
{
	int size = listhoadon.size();
	fileout << size << endl;
	for (int i = 0; i < size; i++)
	{
		fileout << listhoadon[i].getter_mahoadon() << " - " << listhoadon[i].getter_songaythue() << " - " << listhoadon[i].getter_ngaydatphong().getter_ngay() << "/" << listhoadon[i].getter_ngaydatphong().getter_thang() << "/" << listhoadon[i].getter_ngaydatphong().getter_nam() <<
			" - " << listhoadon[i].getter_ngaytraphong().getter_ngay() << "/" << listhoadon[i].getter_ngaytraphong().getter_thang() << "/" << listhoadon[i].getter_ngaytraphong().getter_nam() << " - " << listhoadon[i].getter_khachhang().getter_cmnd() << " - " << listhoadon[i].getter_khachhang().getter_hoten()
			<< " - " << listhoadon[i].getter_khachhang().getter_ngaysinh().getter_ngay() << "/" << listhoadon[i].getter_khachhang().getter_ngaysinh().getter_thang() << "/" << listhoadon[i].getter_khachhang().getter_ngaysinh().getter_nam() << " - " << listhoadon[i].getter_khachhang().getter_discount() << " - ";
		int sizevip = listhoadon[i].getter_listphongvip().size();
		int sizethuong = listhoadon[i].getter_listphongthuong().size();
		int sizevipthuong = sizevip + sizethuong;
		fileout << sizevipthuong << endl;
		if (listhoadon[i].getter_listphongvip().size() > 0)
		{
			for (int j = 0; j < listhoadon[i].getter_listphongvip().size(); j++) 
			{
				fileout << 1 << " - " << listhoadon[i].getter_listphongvip()[j].getter_maphong() << " - " << listhoadon[i].getter_listphongvip()[j].getter_tenphong() << endl;
			}
		}
		if (listhoadon[i].getter_listphongthuong().size() > 0)
		{
			for (int j = 0; j < listhoadon[i].getter_listphongthuong().size(); j++) 
			{
				fileout << 2 << " - " << listhoadon[i].getter_listphongthuong()[j].getter_maphong() << " - " << listhoadon[i].getter_listphongthuong()[j].getter_tenphong() << endl;
			}
		}
	}
}

void khachsan::xuat()
{
	for (int i = 0; i < listhoadon.size(); i++)
	{
		cout << "\nThong tin hoa don thu " << (i + 1) << " :";
		listhoadon[i].xuat();
	}
}

void khachsan::capnhapthongtinphong(ofstream& fileout)
{
	int size1 = listphongvip.size();
	int size2 = listphongthuong.size();
	int size = size1 + size2;
	fileout << size << endl;
	for (int i = 0; i < size1; i++)
	{
		fileout << 1 << " - " << listphongvip[i].getter_maphong() << " - " << listphongvip[i].getter_tenphong() << " - " << listphongvip[i].getter_tinhtrang() << " - " << listphongvip[i].getter_id()<< endl;
	}
	for (int i = 0; i < size2; i++)
	{
		fileout << 2 << " - " << listphongthuong[i].getter_maphong() << " - " << listphongthuong[i].getter_tenphong() << " - " << listphongthuong[i].getter_tinhtrang() << " - " << listphongthuong[i].getter_id() << endl;
	}
}

void khachsan::xuatdanhsachcacphong()
{
	cout << "\nPhong VIP: ";
	for (int i = 0; i < listphongvip.size(); i++)
	{
		cout << "|" << listphongvip[i].getter_maphong();
		if (listphongvip[i].getter_tinhtrang() == 1)
		{
			cout << " - Con" << "| ";
		}
		else
		{
			cout << " - Khong" << "|";
		}
	}
	cout << "\nPhong Thuong: ";
	for (int i = 0; i < listphongthuong.size(); i++)
	{
		cout << "|" << listphongthuong[i].getter_maphong();
		if (listphongthuong[i].getter_tinhtrang() == 1)
		{
			cout << " - Con" << "| ";
		}
		else
		{
			cout << " - Khong" << "| ";
		}
	}
}

void khachsan::luuthongtinkhachhang(ofstream& fileout)
{
	int size = listhoadon.size();
	fileout << size << endl;
	for (int i = 0; i < size; i++)
	{
		fileout << listhoadon[i].getter_khachhang().getter_cmnd() << " - " << listhoadon[i].getter_khachhang().getter_hoten() << endl;
	}
}

void khachsan::loadthongtinkhachhang(ifstream& filein)
{
	khachhang y;
	string n;
	getline(filein, n);
	int sizekhachhang = atoi(n.c_str());
	for (int i = 1; i <= sizekhachhang; i++)
	{
		string cmnd;
		getline(filein, cmnd, '-');
		cmnd.erase(cmnd.begin() + cmnd.length() - 1);
		filein.seekg(1, SEEK_CUR);
		y.setter_cmnd(cmnd);

		string hoten;
		getline(filein, hoten);
		//hoten.erase(hoten.begin() + hoten.length() - 1);
		//filein.seekg(1, SEEK_CUR);
		y.setter_hoten(hoten);

		/*string _discount;
	    getline(filein, _discount);
		int discount = atoi(_discount.c_str());
		y.setter_discount(discount);*/

		listkhachhang.push_back(y);
	}

	
}

