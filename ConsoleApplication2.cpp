// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <clocale>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "struct.h"
#include "Source.cpp"

namespace types {
	// Сигнатуры требуемых внешних функций
	void Init(container &b);
	void Clear(container &b);
	game *InGame(game &g, ifstream &ifst);
	void OutGame(game *g, ofstream &ofst); 
	cartoon *InCartoon(cartoon &c, ifstream &ifst);
	void OutCartoon(cartoon *c, ofstream &ofst);
	void Out(film *f, ofstream &ofst);
	film *In(ifstream &ifst);
	void In(container &b, ifstream &ifst);
	void Out(container &b, ofstream &ofst);
	void MultiMethod(container& c, ofstream& ofst);
	
}

using namespace std;
using namespace types;

	int main()
	{
		SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
		SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода 
		setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали
		
		ifstream ifst("in.txt");
		ofstream ofst("out.txt", ios::trunc);

		/*if (argc != 3) {
			cout << "incorrect command line! "
				"Waited: command infile outfile" << endl;
			exit(1);
		}
		ifstream ifst(argv[1]);
		ofstream ofst(argv[2]);*/
		cout << "Старт!" << endl;
		container b;
		Init(b);
		In(b, ifst);
		ofst << "Контейнер заполнен. " << endl;
		Out(b, ofst);
		MultiMethod(b, ofst);
		Clear(b);
		ofst << "Контейнер пуст. " << endl;
		Out(b, ofst);
		cout << "Стоп." << endl;


		system("pause");
		return 0;

	}

		
