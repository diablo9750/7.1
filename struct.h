#ifndef _struct
#define _struct
#include <fstream>
using namespace std;

//Обобщённый фильм
class film {
public:
	static film* In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0;//Ввод данных о фильме
	virtual void Out(ofstream &ofst) = 0;//Вывод дынных о фильме
	//Мультиметод
	virtual void MultiMethod(film* other,ofstream& ofst) = 0;
	virtual void MGame(ofstream& ofst) = 0;
	virtual void MCartoon(ofstream& ofst) = 0;
};
//Контейнер
class container
{
private:
	class List {
	public:
		List();//Инициализация списка
		void Del();//Функция удаления данных из списка
		List* Next;//Указатель на следующий список
		List* Priv;//Указатель на предыдущий список
		film* data;//Указатель на данные о фильме
	};
public:
	int add(ifstream &ifst);//Функция добавление нового списка в контейнер
	void In(ifstream &ifst);//Ввод данных в контейнер
	void Out(ofstream &ofst);//Вывод данных из контейнера
	void Clear();//Отчистка данных из контейнер
	container();//Инициализация контейнера
	List* Top;//Указатель на последний список в контейнере
	int count;//Число списков в контейнере
	void MultiMethod( ofstream& ofst);
};

//Игровой фильм
class game : public film {
	char country[100];//Страна
	char name[100];//Название фильма
	char director[100];//Имя режиссёра
public:
	void InData(ifstream &ifst);//Ввод данных о фильме
	void Out(ofstream &ofst);//Вывод дынных о фильме
	//Мультиметод
	void MultiMethod(film* other, ofstream& ofst);
	void MGame(ofstream& ofst);
	void MCartoon(ofstream& ofst);
	game() {}//Создание без инициализации.
};
//Мультфильм
class cartoon : public film {
	char country[100];//Страна
	char name[100];//Название фильма
	int type;//Вид мультфильма
public:
	void InData(ifstream &ifst);//Ввод данных о фильме
	void Out(ofstream &ofst);//Вывод дынных о фильме
	//Мультиметод
	void MultiMethod(film* other, ofstream& ofst);
	void MGame(ofstream& ofst);
	void MCartoon(ofstream& ofst);
	cartoon() {}//Создание без инициализации.
};
#endif 