#include <fstream>
#include "struct.h" 
using namespace std;
namespace types {

	// ���� ���������� �������� ������ �� �����
	game *InGame(game &g, ifstream &ifst) {
		ifst >> g.name >> g.director;
		return &g;
	}

	// ����� ���������� �������� ������ � �����
	void OutGame(game *g, ofstream &ofst) {
		ofst << "��� ������� �����. �������� ������: " << g->name
			<< ", �������: " << g->director << endl;
	}

	//--------------------------------------------------

	// ���� ���������� ����������� �� ������
	cartoon *InCartoon(cartoon &c, ifstream &ifst)
	{
		ifst >> c.name >> c.type;
		return &c;
	}

	// ����� ���������� ����������� � �����
	void OutCartoon(cartoon *c, ofstream &ofst)
	{
		ofst << "��� ���������. �������� ������: "
			<< c->name << ", ��� �����������: ";

		if (c->type == 1) {
			ofst << "����������" << endl;
		}
		if (c->type == 2) {
			ofst << "���������" << endl;
		}
	}

	void Out(film* f, ofstream& ofst) {
		switch (f->key)
		{
		case 1:
		{
			OutGame((game*)f, ofst);
		}break;
		case 2:
		{
			OutCartoon((cartoon*)f, ofst);
		}break;
		default:
		{
			cout << "������������ �����!" << endl;
		}break;
		}
	}
	//--------------------------------------------------

	//���� ���������� ����������� ������ �� �����
	film *In(ifstream &ifst)
	{
		film *fm = new film;
		int k;
		ifst >> k;
		if (k == 1) {
			game *g = new game;
			fm = (film*)InGame(*g, ifst);
			fm->key = GAME;
			return fm;
		}
		if (k == 2)
		{
			cartoon *c = new cartoon;
			fm = (film*)InCartoon(*c, ifst);
			fm->key = CARTOON;
			return fm;
		}
		else 
		{
			return 0; 
		}
	}

	//--------------------------------------------------

	//���������� ���� ������
	int addlist(container &b, ifstream &ifst)
	{
		//���� ��������� ������
		if (b.count == 0)
		{
			b.Top = new List;
			if ((b.Top->data = In(ifst)) != 0)
				return 1;
			else
				return 0;

		}
		else
		{
			List *current = b.Top;
			for (int j = 1; j < b.count; j++)
			{
				current = current->Next;
			}
			current->Next = new List;
			if ((current->Next->data = In(ifst)) != 0)
			{
				b.Top->Priv = current->Next;
				current->Next->Priv = current;
				current->Next->Next = b.Top;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}

	// ������������� ����������
	void Init(container &b) {
		b.Top = nullptr;
		b.count = 0;
	}

	// ������� ���������� �� ���������
	void Clear(container &b) {
		List* current = b.Top;
		int i = 1;
		while (i < b.count)
		{
			current = current->Next;
			delete current->Priv;
			i++;
		}
		delete current;
		b.count = 0;
	}

	// ���� ����������� ���������� �� ���������� ������
	void In(container &b, ifstream &ifst) {
		while (!ifst.eof()) {
			if (addlist(b, ifst) != 0)
				b.count++;
		}
	}

	// ����� ����������� ���������� � ��������� �����
	void Out(container &b, ofstream &ofst) {
		List* current = b.Top;
		ofst << "��������� �������� ���������� ��������� ������: " << b.count << endl;
		for (int j = 0; j < b.count; j++) {
			ofst << j+1 << ": ";
			Out(current->data, ofst);
			current = current->Next;
		}
	}

	//-----------------------------------------------------
	// �����������
	void MultiMethod(container& c, ofstream& ofst) {
		ofst << "�����������." << endl;

		List* currentfirst;
		List* currentsecond;
		int count = 1;

		for (int i = 0; i < c.count - 1; i++)
		{
			currentfirst = c.Top;
			currentsecond = c.Top;
			currentsecond = currentsecond->Next;
			for (int k = 0; k < i; k++)
			{
				currentfirst = currentfirst->Next;
				currentsecond = currentsecond->Next;
			}


			for (int j = i + 1; j < c.count; j++)
			{
				switch (currentfirst->data->key)
				{
				case GAME:
				{
					switch (currentsecond->data->key)
					{
					case GAME:
					{
						ofst << "������� � �������." << endl;
					}break;
					case CARTOON:
					{
						ofst << "������� � ����������." << endl;
					}break;
					default:
					{
						ofst << "����������� ���." << endl;
					}
					}
				}break;

				case CARTOON:
				{
					switch (currentsecond->data->key)
					{
					case GAME:
					{
						ofst << "���������� � �������." << endl;
					}break;
					case CARTOON:
					{
						ofst << "���������� � ����������." << endl;
					}break;
					default:
					{
						ofst << "����������� ���." << endl;
					}
					}
				}break;
				default:
				{
					ofst << "����������� ���." << endl;
				}
				}
				ofst << count << ": ";
				Out(currentfirst->data, ofst);
				Out(currentsecond->data, ofst);
				currentsecond = currentsecond->Next;
				count++;
			}

			currentfirst = currentfirst->Next;
		}
	}

}