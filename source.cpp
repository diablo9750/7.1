#include "struct.h" 
#include <iostream>
#include <fstream>
using namespace std;

//--------------------------------------------------

//Ввод параметров игрового фильма из файла
void game::InData(ifstream &ifst) {
	ifst  >> name >> director;
}

//Вывод параметров игрового фильма в поток
void game::Out(ofstream &ofst) {
	ofst << "Это игровой фильм. " << " Название фильма: " << name
		<< ", Режиссёр: " << director << endl;
}

//--------------------------------------------------

//Ввод параметров мультфильма из потока
void cartoon::InData(ifstream &ifst) {
	ifst >>  name >> type;
}

//Вывод параметров мультфильма в поток
void cartoon::Out(ofstream &ofst) {
	ofst << "Это мультильм. " << " Название фильма: " << name << ", вид мультфильма: ";

	if (type == 1) {
		ofst << "рисованный" << endl;
	}
	if (type == 2) {
		ofst << "кукольный" << endl;
	}
}


//--------------------------------------------------

//Ввод параметров обобщенного фильма из файла
film* film::In(ifstream &ifst)
{
	film *fm;
	int key;
	ifst >> key;
	switch (key)
	{
	case 1:
	{
		fm = new game;
	}break;
	case 2:
	{
		fm = new cartoon;
	}break;
	default:
	{
		return 0;
	}break;
	}

	fm->InData(ifst);
	return fm;
}

//Инициализация контейнера
container::container()
{

	Top = nullptr;
	count = 0;
}

//Инициализация нового списка
container::List::List()
{
	this->Next = nullptr;
	this->Priv = nullptr;
	this->data = nullptr;
}

//--------------------------------------------------

//Добавление узла
int container::add(ifstream &ifst)
{
	//Если контейнер пустой
	if (count == 0)
	{
		Top = new List;
		if ((Top->data = film::In(ifst)) != 0)
			return 1;
		else
			return 0;
	}
	//Если контейнер не пустой
	else
	{
		List *current = Top;
		for (int j = 0; j < count - 1; j++)
		{
			current = current->Next;
		}
		current->Next = new List;
		if ((current->Next->data = film::In(ifst)) != 0)
		{
			Top->Priv = current->Next;
			current->Next->Priv = current;
			current->Next->Next = Top;
			return 1;
		}
		else
		{
			delete current->Next;
			return 0;
		}
	}
	return 0;
}

//Удаление всех списков
void container::List::Del()
{
	List* current = this;
	while (current->Next != nullptr)
	{
		current = current->Next;
		delete current->Priv;
	}
	delete current;
}

//Отчистка контейнера
void container::Clear()
{
	List* current = Top;
	for (int i = 1; i < count; i++)
	{
		current = current->Next;
		delete current->Priv;
	}
	delete current;
	count = 0;
}

// Ввод содержимого контейнера из указанного потока
void container::In(ifstream &ifst)
{
	while (!ifst.eof()) {
		if (add(ifst) != 0)
			count++;
	}
}

// Вывод содержимого контейнера в указанный поток
void container::Out(ofstream & ofst)
{
	List* current = Top;
	ofst << "Контейнер содержит количество элементов равное: " << count << endl;
	for (int j = 0; j < count; j++)
	{
		ofst << j + 1 << ": ";
		current->data->Out(ofst);
		current = current->Next;
	}
}
//-----------------------------------------------------

//Мультиметод(Game)
void game::MultiMethod(film* other,ofstream &ofst) {
	other->MGame(ofst);
}
//Мультиметод(Cartoon)
void cartoon::MultiMethod(film* other,ofstream &ofst) {
	other->MCartoon(ofst);
}
// Вывод двух игровыых
void game::MGame(ofstream& ofst) {
	ofst << "Игровой и игровой." << endl;
}
//-----------------------------------------------------
// Вывод треугольника и прямоугольника
void cartoon::MCartoon(ofstream& ofst) {
	ofst << "Мультфильм и игровой." << endl;
}
//-----------------------------------------------------
// Вывод прямоугольника и треугольника
void game::MCartoon(ofstream& ofst) {
	ofst << "Игровой и мультфильм." << endl;
}
//-----------------------------------------------------
// Вывод двух треугольников
void cartoon::MGame(ofstream& ofst) {
	ofst << "Мультфильм и мультфильм." << endl;
}

// Вызов мультиметода для элементов контейнера
void container::MultiMethod(ofstream & ofst) {
	ofst << "Мультиметод." << endl;
	List* currentfirst = Top;
	List* currentsecond = Top;
	int c = 1;
	for (int i = 0; i < count - 1; i++)
	{
		currentsecond = currentsecond->Next;
		for (int j = i + 1; j < count; j++)
		{
			ofst << c << ": ";
			currentfirst->data->MultiMethod(currentsecond->data, ofst);
			currentfirst->data->Out(ofst);
			currentsecond->data->Out(ofst);
			currentsecond = currentsecond->Next;
			c++;
		}
		currentfirst = currentfirst->Next;
	}
}