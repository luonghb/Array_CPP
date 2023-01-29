#include <iostream>
#include <conio.h>
#include "Array.h"


void PrintArray(Array<int> &arr);

void Pause();

int main() {
	Array<int> arr;
	int choose = 0;
	int val = 0;
	int pos = 0;
	while (choose != 10) {
		std::cout << "\nCac chuc nang:\n1.Them vao cuoi mang;\n2.Lay phan tu cuoi mang;\n3.Tim phan tu;\n4.Xoa mang;\n5.Dao mang;\n6.In mang;\n7.Xem kich thuoc mang;\n8.Xem capacity;\n10.Ket thuc.\nChon chuc nang: ";
		std::cin >> choose;
		switch (choose) {
			case 1:
				std::cout << "\nNhap gia tri can them: ";
				std::cin >> val;
				arr.PushBack(val);
				break;
			case 2:
				std::cout << "\nGia tri cuoi cua arr: " << arr.PopBack() << '\n';
				Pause();
				break;
			case 3:
				std::cout << "\nNhap gia tri can tim";
				std::cin >> pos;
				if (arr.Find(val) != -1) {
					std::cout << "\nVi tri cua phan tu " << val << " la: " << arr.Find(val);
				}
				else {
					std::cout << "\nKhong ton tai";
				}
				Pause();
				break;
			case 4:
				arr.Clear();
				std::cout << "\nDa xoa mang";
				break;
			case 5:
				arr.Reserve();
				std::cout << "\nDa dao mang thanh cong";
				Pause();
				break;
			case 6:
				PrintArray(arr);
				Pause();
				break;
			case 7:
				std::cout << "\nKich thuoc cua mang la: " << arr.GetSize();
				Pause();
				break;
			case 8:
				std::cout << "\nCapacity cua mang la: " << arr.GetCapacity();
				Pause();
				break;
			case 10:
				getch();
				break;
			default:
				break;
		}
		system("cls");
	}
	return 0;
}

void PrintArray(Array<int> &arr) {
	std::cout << "\nArray: ";
	for (int i = 0; i < arr.GetSize(); ++i) {
		std::cout << arr.At(i) << ' ';
	}
	std::cout << '\n';
}

void Pause() {
	std::cout << "\nNhan phim bat ky de tiep tuc";
	getch();
}
