#include <iostream>
using namespace std;
template <class T>
void setMin(T a[], long size) {
	T min = a[0];
	for (int i = 1; i < size; i++)
		if (a[i] < min)
			min = a[i];
	a[0] = min;
}
template <class T>
void insertSortGuarded(T a[], long size) {
	T x;
	long i, j;
	// сохранить старый первый элемент
	T backup = a[0];
	// заменить на минимальный
	setMin(a, size);
	// отсортировать массив
	for (i = 1; i < size; i++) {
		x = a[i];
		for (j = i - 1; a[j] > x; j--)
			a[j + 1] = a[j];
		a[j + 1] = x;
	}
	// вставить backup на правильное место
	for (j = 1; j < size && a[j] < backup; j++)
		a[j - 1] = a[j];
	// вставка элемента
	a[j - 1] = backup;
}
int main() {
	srand((unsigned int)time(NULL));
	const long SIZE = 10;
	int ar[SIZE];
	// до сортировки 
	for (int i = 0; i < SIZE; i++) {
		ar[i] = rand() % 100;
		cout << ar[i] << "\t";
	}
	cout << "\n\n";
	insertSortGuarded(ar, SIZE);
	// после сортировки 
	for (int i = 0; i < SIZE; i++) {
		cout << ar[i] << "\t";
	}
	cout << "\n\n";
	return 0;
}