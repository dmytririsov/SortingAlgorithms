#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <stack>
#include <string>
using namespace std;

void GenerateGaps(stack<int> &gaps, const int size, string sequance_type = "Shell")
{
	if (sequance_type == "Shell")
		for (int i = 1; i < size; i *= 2)
		{
			gaps.push(i);
			//cout << i << " " ;
		}
}

void BubbleSort(vector<int> &arr)
{

	for (int i = 0; i < arr.size(); ++i)
		for (int j = 0; j < arr.size() - 1; ++j)
			if (arr[i] < arr[j])
				swap(arr[j], arr[i]);

}

void SelectionSort(vector<int> &arr)
{
	for(int i = 0; i < arr.size() - 1; ++i)
	{
		int min_i = i;
		for(int j = i + 1; j < arr.size(); ++j)
			if (arr[j] < arr[min_i])
				min_i = j;
		if (arr[min_i] != arr[i])
			swap(arr[min_i], arr[i]);
	}

}

void InsertionSort(vector<int> &arr, const int start_point = 0)
{
	for (int i = start_point; i < arr.size(); ++i)
	{
		int buff = arr[i];
		int j = i;
		while (j >= start_point && arr[j-start_point] > buff)
		{
			arr[j] = arr[j-start_point];
			j -= start_point;
		}
		arr[j] = buff;
	}
}

void ShellSort(vector<int> &arr)
{
	stack<int> gaps;
	GenerateGaps(gaps, arr.size());
	while (gaps.empty() != true)
	{
		//cout << i << " ";
		InsertionSort(arr, gaps.top());
		gaps.pop();
	//cout << endl;
	}
}

void GenerateArray(vector<int> &arr, const int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
		arr.push_back(rand() % 10 + 1);
}

void PrintArray(const vector<int> &arr)
{
	for(int z = 0; z < arr.size(); ++z)
		cout << " " << arr[z];	
	cout << endl;
}

void CountSort(vector<int> &arr, const int size)
{
	int k = 0;
	int a = 0;
	cout << "Enter diapason 1: "<< endl;
	cin >> k;
	cout << "Enter diapason 2: "<< endl;
	cin >> a;
	for (int i = 0; i < k; ++i)
	{
		arr[i] = 0;
	}
	for (int i = 0; i < arr.size(); ++i)
	{
		arr[a[i]] = arr[a[i]] + 1;
}

int main()
{

	int n;
	cout << "Enter n" << endl;
	cin >> n;
	vector<int> arr;
	GenerateArray(arr, n);
	//cout << "Previous array" << endl;
	//PrintArray(arr);
	//cout << "Sorted array" << endl;
	LARGE_INTEGER _start;
    LARGE_INTEGER _end;
    LARGE_INTEGER _f;
    double _algTime;
	QueryPerformanceCounter(&_start);
	//ShellSort(arr);
	//BubbleSort(arr);
	//SelectionSort(arr);
	//InsertionSort(arr);
	//PrintArray(arr);
	CountSort(arr);
	QueryPerformanceCounter(&_end);
	QueryPerformanceFrequency(&_f);
    _algTime = double(_end.QuadPart - _start.QuadPart) / _f.QuadPart;
	if (is_sorted(arr.begin(), arr.end()))
		cout << "Array is sorted" << endl;
	else
		cout << "Array not sorted";
	cout << "Sort time: " << _algTime << endl;
	cout << "Int size: " << sizeof(arr[0]) << endl;
	cout << "Array size: " << arr.size() << endl;
	system ("PAUSE");
	return 0;
}
