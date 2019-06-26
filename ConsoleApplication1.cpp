// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <clocale>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "struct.h"
#include "Source.cpp"

using namespace std;
void main(int argc, char* argv[])
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода 
	setlocale(LC_ALL, "Russian"); // вызов функции настройки локали

	ifstream ifst("in.txt");
	ofstream ofst("out.txt", ios::trunc);
	/*if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		system("pause");
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);*/
	cout << "Старт!" << endl;
	container c;
	c.In(ifst);
	ofst << "Контейнер полон." << endl;
	c.Out(ofst);
	c.MultiMethod(ofst);
	c.Clear();
	ofst << "Контейнер пуст." << endl;
	c.Out(ofst);
	cout << "Стоп!" << endl;
	system("pause");
}

