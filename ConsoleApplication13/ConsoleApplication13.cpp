#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <chrono>
using namespace std;

class Sorts
{
public:
	Sorts();
	~Sorts();
	void bubbleSort();
	void insertSort();
	void selectionSort();
	void quickSort();

private:
	int array_100[100];
	int array_5k[5000];
	int array_10k[10000];
	void reverse();
	void random();
	void bSort(int *array, int size);
	void iSort(int* array, int size);
	void sSort(int* array, int size);
	void qSort(int* array, int low, int high);
};

Sorts::Sorts()
{
	for (int i = 0; i < sizeof(array_100)/sizeof(array_100[0]); i++)
	{
		array_100[i] = i;
	}
	for (int i = 0; i < sizeof(array_5k)/sizeof(array_5k[0]); i++)
	{
		array_5k[i] = i;
	}
	for (int i = 0; i < sizeof(array_10k)/sizeof(array_10k[0]); i++)
	{
		array_10k[i] = i;
	}
}

Sorts::~Sorts()
{
}

void Sorts::bubbleSort()
{
	int cnt = 0;
	double time_begin = 0;
	double time_end = 0;
	double time_spent = 0;
	cout << "Bubble sort:\n";

	while (cnt < 3)
	{
		if (cnt == 1)
		{
			reverse();
			cout << " Back sorted array:\n";
		}
		else if (cnt == 2)
		{
			random();
			cout << " Random array:\n";
		}
		else
		{
			cout << " Sorted array:\n";
		}
		int n = sizeof(array_100) / sizeof(array_100[0]);
		time_begin = clock();
		bSort(array_100, n);
		time_end = clock();
		time_spent = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
		cout << "  100: " << time_spent << " seconds\n";

		n = sizeof(array_5k) / sizeof(array_5k[0]);
		time_begin = clock();
		bSort(array_5k, n);
		time_end = clock();
		time_spent = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
		cout << "   5k: " << time_spent << " seconds\n";

		n = sizeof(array_10k) / sizeof(array_10k[0]);
		time_begin = clock();
		bSort(array_10k, n);
		time_end = clock();
		time_spent = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
		cout << "  10k: " << time_spent << " seconds\n";

		cnt++;
	}
	
}
void Sorts::bSort(int* array, int size)
{
	int temp = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void Sorts::insertSort()
{
	cout << "\nInsertion sort:\n";
	//double time_begin = 0;
	//double time_end = 0;
	//double time_spent = 0;
	int cnt = 0;
	while (cnt < 3)
	{
		if (cnt == 1)
		{
			reverse();
			cout << " Back sorted array:\n";
		}
		else if (cnt == 2)
		{
			random();
			cout << " Random array:\n";
		}
		else
		{
			cout << " Sorted array:\n";
		}			
		int n = sizeof(array_100) / sizeof(array_100[0]);
		auto time_begin = std::chrono::steady_clock::now();
		iSort(array_100, n);
		auto time_end = std::chrono::steady_clock::now();
		auto time_spent = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_begin);
		cout << setprecision(14) << fixed << "  100: " << time_spent.count() << " seconds\n";

		n = sizeof(array_5k) / sizeof(array_5k[0]);
		auto time_begin = std::chrono::steady_clock::now();
		iSort(array_5k, n);
		auto time_end = std::chrono::steady_clock::now();
		auto time_spent = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_begin);
		cout << "   5k: " << time_spent.count() << " seconds\n";

		n = sizeof(array_10k) / sizeof(array_10k[0]);
		auto time_begin = std::chrono::steady_clock::now();
		iSort(array_10k, n);
		auto time_end = std::chrono::steady_clock::now();
		auto time_spent = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_begin);
		cout << "  10k: " << time_spent.count() << " seconds\n";

		cnt++;
	}
}
void Sorts::iSort(int* array, int size)
{
	int key, j;
	for (int i = 1; i < size - 1; i++) {
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

void Sorts::selectionSort()
{
	cout << "\nSelection sort\n";
	double time_begin = 0;
	double time_end = 0;
	double time_spent = 0;
	int cnt = 0;
	int tmp = 0;
	while (cnt < 3)
	{
		if (cnt == 1)
		{
			reverse();
			cout << " Back sorted array:\n";
		}
		else if (cnt == 2)
		{
			random();
			cout << " Random array:\n";
		}
		else
		{
			cout << " Sorted array:\n";
		}
		int n = sizeof(array_100) / sizeof(array_100[0]);
		time_begin = clock();
		sSort(array_100, n);
		time_end = clock();
		time_spent = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
		cout << "  100: " << time_spent << " seconds\n";

		n = sizeof(array_5k) / sizeof(array_5k[0]);
		time_begin = clock();
		sSort(array_5k, n);
		time_end = clock();
		time_spent = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
		cout << "   5k: " << time_spent << " seconds\n";

		n = sizeof(array_10k) / sizeof(array_10k[0]);
		time_begin = clock();
		sSort(array_10k, n);
		time_end = clock();
		time_spent = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
		cout << "  10k: " << time_spent << " seconds\n";

		cnt++;
	}
}

void Sorts::sSort(int* array, int size)
{
	int j = 0;
	int temp = 0;
	for (int i = 0; i < size; i++) {
		j = i;
		for (int k = i; k < size; k++) {
			if (array[j] > array[k]) {
				j = k;
			}
		}
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

void Sorts::quickSort()
{
	cout << "\nQuick sort\n";
	double time_begin = 0;
	double time_end = 0;
	double time_spent = 0;
	int cnt = 0;
	while (cnt < 3)
	{
		if (cnt == 1)
		{
			reverse();
			cout << " Back sorted array:\n";
		}
		else if (cnt == 2)
		{
			random();
			cout << " Random array:\n";
		}
		else
		{
			cout << " Sorted array:\n";
		}
		int n = sizeof(array_100) / sizeof(array_100[0]);
		time_begin = clock();
		qSort(array_100, 0, n);
		time_end = clock();
		time_spent = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
		cout << "  100: " << time_spent << " seconds\n";

		n = sizeof(array_100) / sizeof(array_100[0]);
		time_begin = clock();
		qSort(array_5k, 0, n);
		time_end = clock();
		time_spent = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
		cout << "   5k: " << time_spent << " seconds\n";

		n = sizeof(array_100) / sizeof(array_100[0]);
		time_begin = clock();
		qSort(array_10k, 0, n);
		time_end = clock();
		time_spent = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
		cout << "  10k: " << time_spent << " seconds\n";
		cnt++;
	}
}

void Sorts::qSort(int* array, int low, int high)
{
	int i = low;
	int j = high;
	int pivot = array[(i + j) / 2];
	int temp;

	while (i <= j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (j > low)
		qSort(array, low, j);
	if (i < high)
		qSort(array, i, high);
}

void Sorts::reverse()
{
	for (int i = 0; i < sizeof(array_100) / sizeof(array_100[0]); i++)
	{
		array_100[i] = 99 - i;
	}
	for (int i = 0; i < sizeof(array_5k) / sizeof(array_5k[0]); i++)
	{
		array_5k[i] = 4999 - i;
	}
	for (int i = 0; i < sizeof(array_10k) / sizeof(array_10k[0]); i++)
	{
		array_10k[i] = 9999 - i;
	}
}

void Sorts::random()
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < sizeof(array_100) / sizeof(array_100[0]); i++)
	{
		array_100[i] = rand() % 100;
	}
	for (int i = 0; i < sizeof(array_5k) / sizeof(array_5k[0]); i++)
	{
		array_5k[i] = rand() % 5000;
	}
	for (int i = 0; i < sizeof(array_10k) / sizeof(array_10k[0]); i++)
	{
		array_10k[i] = rand() % 10000;
	}
}

int main()
{
	Sorts smth;
	smth.bubbleSort();
	smth.insertSort();
	smth.selectionSort();
	smth.quickSort();
}

