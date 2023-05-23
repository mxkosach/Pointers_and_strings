#include <iostream>
#include <iomanip>
#include "myfunctions.h"
#include <fstream>
#pragma warning(disable : 4996)

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	{
		title(2, 'a');
		const int np = 6;
		const char* P[np] = { "именительный","родительный","дательный",
			"винительный","творческий","предложный" };
		const char* F[np] = { "ий","ого","ому", "ого","им","ом" };
		const char* N[np] = { "й", "я", "ю", "я", "ем", "е" };
		const int nt = 25; char* t = new char[nt];
		const int ns = 25; char* s = new char[ns];
		cout << "Склонение фамилии и имени:\n";
		for (int i = 0; i < np; i++)
		{
			mycpy(t, P[i]);	mycat(t, " падеж: ");
			i != 5 ? mycpy(s, "Липницк") : mycpy(s, "о Липницк");
			mycat(s, F[i]);	mycat(s, " Андре"); mycat(s, N[i]);
			cout << setw(20) << left << t << setw(20) << left << s << "len(s) = " << mylen(s) << endl;
		}

		delete[]s;
		delete[]t;
	}

	{
		title(2, 'b');
		const int np = 6;
		const char* P[np] = { "именительный","родительный","дательный",
			"винительный","творческий","предложный" };
		const char* F[np] = { "","а","у", "а","ем","е" };
		const char* N[np] = { "", "а", "у", "а", "ом", "е" };
		const int nt = 25; char* t = new char[nt];
		const int ns = 25; char* s = new char[ns];
		cout << "Склонение фамилии и имени:\n";
		for (int i = 0; i < np; i++)
		{
			mycpy(t, P[i]);	mycat(t, " падеж: ");
			i != 5 ? mycpy(s, "Косач") : mycpy(s, "о Косач");
			mycat(s, F[i]);	mycat(s, " Максим"); mycat(s, N[i]);
			cout << setw(20) << left << t << setw(20) << left << s << "len(s) = " << mylen(s) << endl;
		}

		delete[]s;
		delete[]t;
	}

	{
		title(3);
		const int ns = 32; char* s = new char[ns];
		mycpy(s, "-57012.3971 259.184");
		cout << "Исходная строка:\n" << s << endl;

		char* p = s;
		while (*p != ' ')
			p++;
		int n = p - s;
		p++;

		char* t = new char[ns];
		mycpy(t, s, n, 1);
		mycpy(s, p);
		mycat(s, " ");
		mycat(s, t);

		cout << "Итоговая строка:\n" << s << endl;
		delete[]s;
		delete[]t;
	}

	{
		title(5);
		const int ns = 128; char* s = new char[ns];
		mycpy(s, "Экзаменационные оценки Липницкого Андрея:\nсемь девять восемь семь");
		const int nv = 10;
		const char* V[nv] =
		{
			"один","два","три","четыре","пять",
			"шесть","семь","восемь","девять","десять"
		};
		int sum = 0, n = 0;
		char* p = mystr(s, "\n") + 1;
		while (1)
		{
			for (int i = 0; i < nv; i++)
				if (!mycmp(p, V[i], mylen(V[i])))
				{
					sum += i + 1;
					n++;
					break;
				}
			p = mystr(p, " ");
			if (p == NULL)
				break;
			p++;
		}
		cout << s << "\n\nСредняя оценка = " << fixed << setprecision(2) << (double)sum / n << endl;
		delete[]s;
	}

	{
		title(6);
		const int ns = 1024; char* s = new char[ns];
		const int nt = 128; char* t = new char[nt];

		*s = '\0';
		/*while (1)
		{
			cin.getline(t, nt);
			if (*t == '\0')
				break;
			mycat(s, t);
			mycat(s, "\n");
		}
		cout << s << endl;*/

		/*mycpy(s,
			"Варанчук Максим третья\n\
Данкевич Мария  вторая\n\
Дежиц Ольга     третья\n\
Дмитриева Анна  первая\n\
Казак Наталья   вторая\n\
Клим Павел      первая\n\
Лахно Юлия      третья\n\
Назаров Евгений вторая\n");
		cout << s << endl;*/

		myinput(s, "10.6.txt", '\n');
		cout << s << endl;

		cout << "Студенты второй группы:\n";
		char* p = s;
		while (1)
		{
			char* end = mystr(p, "\n");
			if (end == NULL)
				break;
			char* q = mystr(p, "вторая");
			if (q != NULL && q < end)
				myout(p, 16);
			p = end + 1;
		}
		delete[]s;
		delete[]t;
	}

	{
		title(8);
		const int ns = 1024; char* s = new char[ns];
		myinput(s, "10.8.txt", '\n');
		cout << "Исходный текст:\n" << s;

		char* p = mystr(s, "  ");
		while (p != NULL)
		{
			mydel(p, 1);
			p = mystr(p, "  ");
		}
		for (char* p = s; *p; p++)
			if ((*p == ',' || *p == '.') && *(p + 1) != ' ')
				myins(p + 1, " ");
		cout << "Итоговый текст:\n" << s;
		delete[]s;
	}

	{
		title(10);
		const int ns = 2048;	char* s = new char[ns];
		myinput(s, "10.10.txt", '\n');
		cout << s << endl;

		const char* sep = " .,-*\'\n";
		int nw = 0, maxlen = 0;
		char* p = s, * pmax = NULL;
		while (1)
		{
			int nsel = myspn(p, sep);
			p += nsel;
			int nword = mycspn(p, sep);
			if (nword == 0)
				break;
			nw++;
			if (nword > maxlen)
			{
				pmax = p;
				maxlen = nword;
			}
			p += nword;
		}
		cout << "Количество слов: " << nw << endl;
		cout << "Искомое слово: ";
		myout(pmax, maxlen);
		delete[]s;
	}

	{
		title(12);
		const int ns = 32; char* s = new char[ns];
		strcpy(s, "-57012.3971 259.184");
		cout << "Исходная строка:\n" << s << endl;

		char* p = s;
		while (*p != ' ')
			p++;
		int n = p - s;
		p++;

		char* t = new char[n];
		strncpy(t, s, n);
		strcpy(s, p);
		strcat(s, " ");
		strncat(s, t, n);

		cout << "Итоговая строка:\n" << s << endl;

		delete[]t;
		delete[]s;
	}

	{
		title(13);
		const int ns = 16; char* s = new char[ns];
		strcpy(s, "4dE93aF2c");
		strupr(s);

		strrev(s);
		long long k = 1, n = 0;
		for (char* p = s; *p; p++)
			if (isdigit(*p))
			{
				n += k * (*p - '0');
				k *= 16;
			}
			else
			{
				if (isupper(*p))
				{
					n += k * (*p - '0' - 7);
					k *= 16;
				}
			}
		cout << "n(16) = " << strrev(s) << endl
			<< "n(10) = " << n << endl;
		delete[]s;
	}

	{
		title(14);
		long long n = 238510754827509, m = n;
		const int ns = 16; char* s = new char[ns];

		strnset(s, '\0', ns);

		char* p = s;
		while (m)
		{
			int k = m % 16;
			if (k < 10)
				*p = '0' + k;
			else
				*p = 'A' + k - 10;
			m /= 16;
			p++;
		}
		cout << "n(10) = " << n << endl
			<< "n(16) = " << strrev(s) << endl;
		delete[]s;
	}

	{
		title(15);
		int n = 1024; char* s = new char[n];
		mycpy(s, "Целочисленные типы данных\n\
В зависимости от размера выделяемой памяти целочисленные данные\n\
делятся на следующие типы :\n\
Целочисленные типы могут использоваться в сочетании с парой\n\
следующих модификаторов :\n\
1) signed указывает на то, что переменная может принимать\n\
как положительные, так и отрицательные значения(используется\n\
по умолчанию);\n\
2) unsigned указывает на то, что переменная принимает только\n\
неотрицательные значения.\n");
		char* t = new char[n];
		myinput(t, "10.15.2).txt", '\n');

		char* p = s;
		for (int i = 0; i < 3; i++)
		{
			p = mystr(p, "\n");
			p++;

		}
		myins(p, t);
		cout << s << endl;
		delete[]s; delete[]t;
	}

	{
		title(16);
		const int ns = 1024; char* s = new char[ns];
		myinput(s, "206.txt", '\n');
		cout << s << endl;
		const int ng = 3;
		const char* grades[ng] = { "один","два","три" };
		cout << "Список студентов, имеющих задолженности:\n";
		char* p = s;
		while (true)
		{
			char* end = mystr(p, "\n");
			if (!end)
				break;
			for (int i = 0; i < ng; i++)
			{
				char* q = mystr(p, grades[i]);
				if (q && q < end)
				{
					myout(p, 18);
					break;
				}
			}
			p = end + 1;
		}
		delete[]s;
	}

	{
		title(17);
		char* s = new char[512];
		myinput(s, "197.txt", '\n');
		cout << "Исходный список:\n" << s;

		char* p = mystr(s, "Казаков");
		int len = mycspn(p, "\n");
		char* t1 = new char[128];
		mycpy(t1, p, len, 1);
		mydel(p, len);

		char* q = mystr(s, "Барсуков");
		len = mycspn(q, "\n");
		char* t2 = new char[128];
		mycpy(t2, q, len, 1);
		mydel(q, len);

		myins(q, t1);
		myins(p, t2);
		cout << "\nИтоговый список:\n" << s;
		delete[]s; delete[]t1; delete[]t2;
	}

	{
		title(18);
		char* s = new char[2048];
		int nstr = myinput(s, "591.txt", '\n');
		cout << s<<endl;

		const char* sep = "\n";
		int nmax = 0, lenmax;
		char* pmax=NULL, * p = s;

		while (true) 
		{
			int nword = mycspn(p, "\n");
			if (!nword)
				break;
			int n = 0;
			for (char* q = p, *end = p + nword; q < end; q++)
				if (*q >= '0' && *q <= '9')
					n++;
			if (n > nmax)
			{
				nmax = n;
				lenmax = nword;
				pmax = p;
			}
			p += nword+1;
		}
		cout << "Максимальное количество цифр цифр(" << nmax << ") в строке:\n";
		myout(pmax, lenmax);
		delete[]s;
	}

	cout << endl; system("pause");
	return 0;
}