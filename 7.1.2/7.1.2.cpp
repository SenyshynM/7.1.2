// Lab_7_1.cpp
// < Сенишина Михайла >
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 10

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -26; // нижня границя
	int High = 23; // верхня границя
	int rowCount = 6; // кількість рядків
	int colCount = 8; // кількість стовпців
	int** q = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		q[i] = new int[colCount];
	Create(q, rowCount, colCount, Low, High);
	Print(q, rowCount, colCount);
	Sort(q, rowCount, colCount);
	Print(q, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] q[i];
	delete[] q;
	return 0;
}

void Create(int** q, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			q[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** q, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << q[i][j];
		cout << endl;
	}
	cout << endl;
}

void Sort(int** q, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < colCount - 1; i0++)
		for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
			if ((q[0][i1] > q[0][i1 + 1]) // 1 умова - зростання
				||
				(q[0][i1] == q[0][i1 + 1] && // якщо однакові елементи - 
					q[1][i1] < q[1][i1 + 1]) // спадання
				||
				(q[0][i1] == q[0][i1 + 1] && // якщо однакові елементи в 1 рядку
					q[1][i1] == q[1][i1 + 1] && // і однакові елементи в 2 рядку
					q[2][i1] > q[2][i1 + 1])) // зростання
				Change(q, i1, i1 + 1, rowCount);
}

void Change(int** a, const int col1, const int col2, const int rowCount)
{
	int tmp;
	for (int j = 0; j < rowCount; j++)
	{
		tmp = a[j][col1];
		a[j][col1] = a[j][col2];
		a[j][col2] = tmp;
	}
}