#include <iostream>
#include "Sort.h"
#include <cstring>
#include <cstdarg>
using namespace std;
Sort::Sort(int count, int mini, int maxi)
{
	n = count;
	b = new int[n];
	srand(time(NULL));
	for(int i=0;i<count;i++)
	b[i] = rand() % (maxi - mini + 1) + mini;
}
Sort::Sort(char* s)
{
	int k = 1;
	for (int i=0; s[i] != '\0'; i++)
		if (s[i] == ',')
			k++;
	n = k;
	k = 0;
	int val = 0;
	b = new int[n];
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ',')
		{
			b[k] = val;
			val = 0;
			k++;
		}
		else
			val = val * 10 + s[i] - '0';
	}
	b[k] = val;
}
Sort::Sort(int count, ...)
{
	va_list args;
	va_start(args, count);
	n = count;
	b = new int[n];
	for (int i = 0; i < count; i++)
	{
		int numar = va_arg(args, int);
		b[i] = numar;
	}
	va_end(args);
}

Sort::Sort(int v[], int count)
{
	n = count;
	b = new int[n];
	for (int i = 0; i < count; i++)
		b[i] = v[i];
}
void Sort::InsertSort(bool ascendent)
{
		
			int i, key, j;

		for (i = 1; i < n; i++) 
		{
			key = b[i];
			j = i - 1;
			if (ascendent)
			{
				while (j >= 0 && b[j] > key) {
					b[j + 1] = b[j];
					j = j - 1;
				}
			}
			else
			{
				while (j >= 0 && b[j] < key) {
					b[j + 1] = b[j];
					j = j - 1;
				}
			}
				b[j + 1] = key;
			
			
		}

}
void Sort::Print()
{
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;
}
void Sort::BubbleSort(bool ascendent)
{
		int i, j;
		bool swapped;
		for (i = 0; i < n - 1; i++) {
			swapped = false;
			for (j = 0; j < n - i - 1; j++)
			{
				if (ascendent)
				{
					if (b[j] > b[j + 1]) {
						swap(b[j], b[j + 1]);
						swapped = true;
					}
				}
				else
				{
					if (b[j] < b[j + 1]) {
						swap(b[j], b[j + 1]);
						swapped = true;
					}
				}
			}
			if (swapped == false)
				break;
		}
}
int Sort::GetElementsCount()
{
	return n;
}
int Sort::GetElementFromIndex(int index)
{
	if (index < 0 || index >=n)
		return -1;
	return b[index];
}
int partition(bool ascendent,int* arr, int low, int high)
{

	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high; j++)
	{
		if (ascendent)
		{
			if (arr[j] < pivot)
			{

				i++;
				swap(arr[i], arr[j]);
			}
		}
		else
		{
			if (arr[j] > pivot)
			{

				i++;
				swap(arr[i], arr[j]);
			}
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}
void Sort::QuickSort(bool ascendent,int left,int right)
{
	
	if (left < right)
	{
		

		int pi = partition(ascendent,b, left, right);


		QuickSort(ascendent, left, pi - 1);
		QuickSort(ascendent, pi + 1, right);
	}
}
