#include <iostream>
#include <ctime>
#include <chrono>
#include "course.h"
using namespace std;
using namespace chrono;

void fillArray(int Array[], int N) {
	srand(time(0));
	for (int i = 0; i < N; i++) {
		Array[i] = rand() % 200 - 100;
		if (Array[i] == -100) {
			Array[i] = 0;
		}
	}
}
void quickSort(int Array[], int end, int start) {
	int mid;
	int s = start;
	int e = end;
	mid = Array[(s + e) / 2];
	while (s < e) {
		while (Array[s] < mid) s++;
		while (Array[e] > mid) e--;
		if (s <= e) {
			swap(Array[s], Array[e]);
			s++;
			e--;
		}
	}
	if (start < e) quickSort(Array, e, start);
	if (s < end) quickSort(Array, end, s);
}

void timeForQuickSort()
{
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;
	const int N = 100;
	int array[N]{};
	fillArray(array, N);
	cout << "����������������� ������:: ";
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << "\n\n";

	start = steady_clock::now();
	quickSort(array, (N - 1), 0);
	end = steady_clock::now();

	cout << "��������������� ������: ";
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << "\n\n";

	result = duration_cast<nanoseconds>(end - start);
	cout << "����� ������� ����������: " << (result.count() / 1000000.0) << " ��" << "\n\n";

}

int binarySearch(int arr[], int value, int start, int end) {
	if (end >= start) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == value) {
			return mid;
		}

		if (arr[mid] > value) {
			return binarySearch(arr, value, start, mid - 1);
		}

		return binarySearch(arr, value, mid + 1, end);
	}

	return -1;
}

void searchMinMax() {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;

	const int N = 100;
	int Array[N]{};
	fillArray(Array, N);
	int mn = Array[0];
	int mx = Array[0];

	start = steady_clock::now();
	for (int i = 1; i < N; i++) {
		mn = min(mn, Array[i]);
		mx = max(mx, Array[i]);
	}
	end = steady_clock::now();

	cout << "����������� �������: " << mn << "\t" << "������������ �������: " << mx << "\n";

	result = duration_cast<nanoseconds>(end - start);
	cout << "����� ���������� ������������ � ������������� ��������� � ����������������� �������: " << (result.count() / 1000000.0) << " ��" << "\n";


	quickSort(Array, N - 1, 0);
	for (int i = 0; i < N; i++) {
		cout << Array[i] << " ";
	}
	start = steady_clock::now();
	mn = Array[0];
	mx = Array[N - 1];
	end = steady_clock::now();
	result = duration_cast<nanoseconds>(end - start);
	cout << "����� ���������� ������������ � ������������� ��������� � ��������������� �������: " << (result.count() / 1000000.0) << " ��" << "\n\n";
}


void averageValue()
{
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;

	const int N = 100;
	int unsortedArray[N]{};
	fillArray(unsortedArray, N);
	cout << "����������������� ������: \n";
	for (int i = 0; i < N; i++) {
		cout << unsortedArray[i] << " ";
	}
	cout << "\n";

	int mn = unsortedArray[0];
	int mx = unsortedArray[N - 1];
	int averageValue = round((mx + mn) / 2.0);

	cout << "������� ��������: " << averageValue << "\n";

	int count = 0;
	cout << "������� ������ �������� �������� � ����������������� �������: ";
	start = steady_clock::now();
	for (int i = 0; i < N; i++) {
		if (unsortedArray[i] == averageValue) {
			cout << i << " ";
			count++;
		}
	}
	end = steady_clock::now();

	result = duration_cast<nanoseconds>(end - start);
	cout << "\n" << "����� �������� ��������� ������ �������� �������� � ����������������� �������: " << (result.count() / 1000000.0) << " ��\n";

	quickSort(unsortedArray, N - 1, 0);
	cout << "\n" << "��������������� ������: " << "\n";
	for (int i = 0; i < N; i++) {
		cout << unsortedArray[i] << " ";
	}
	cout << "\n";

	cout << "������� ������ �������� �������� � ��������������� �������: ";
	start = steady_clock::now();
	count = 0;
	for (int i = 0; i < N; i++) {
		if (unsortedArray[i] == averageValue) {
			cout << i << " ";
			count++;
		}

	}
	end = steady_clock::now();

	result = duration_cast<nanoseconds>(end - start);
	cout << "\n" << "����� �������� ��������� ������ �������� �������� � ��������������� �������: " << (result.count() / 1000000.0) << " ��\n";
	cout << "����������: " << count << "\n";

}

void lessThanA(int value)
{
	const int N = 100;
	int array[N]{};
	fillArray(array, N);
	quickSort(array, N - 1, 0);
	int count;
	cout << "��������������� ������: ";
	for (int i = 0; i < N; i++) {
		cout << i << ": " << array[i] << "    ";
	}
	cout << "\n\n";

	int i = binarySearch(array, value, 0, N - 1), elem = value - 1;

	while (i == -1 && elem >= -99) {
		int i = binarySearch(array, --elem, 0, N - 1);
	}

	for (i = 0; i < N; i++) {
		if (array[i] >= value) {
			break;
		}
	}
	int res;
	if (value < -99) {
		res = 0;
	}
	else {
		res = i;
	}
	cout << "���������� ���������, ������� ��� a: " << res << "\n";
}

void moreThanB(int value) {
	const int N = 100;
	int array[N]{};
	fillArray(array, N);
	quickSort(array, N - 1, 0);

	cout << "��������������� ������: ";
	for (int i = 0; i < N; i++) {
		cout << i << ": " << array[i] << "    ";
	}
	cout << "\n\n";

	int i = binarySearch(array, value, 0, N - 1), elem = value + 1;
	while (i == -1 && elem <= 99) {
		i = binarySearch(array, ++elem, 0, N - 1);
	}

	for (i; i >= 0; i--) {
		if (array[i] <= value) {
			break;
		}
	}
	int res;
	if (value >= 99) {
		res = 0;
	}
	else if (value <= -101) {
		res = 100;
	}
	else {
		res = 100 - (i + 1);
	}

	cout << "���������� ��������� ������� ��� b: " << res << "\n";
}

void compareTime(int x) {
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;

	const int N = 100;
	int array[N] = {};
	fillArray(array, N);
	quickSort(array, N - 1, 0);

	cout << "��������������� ������: ";
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << "\n\n";

	bool isThere;
	start = steady_clock::now();
	binarySearch(array, x, 0, N - 1);
	end = steady_clock::now();
	isThere = binarySearch(array, x, 0, N - 1) != -1;

	cout << "���� �� � ������� �����: " << (isThere ? "����" : "����") << "\n";

	result = duration_cast<nanoseconds>(end - start);
	cout << "����� ��������� ������: " << (result.count() / 1000000.0) << " ��" << "\n";

	int i = 0;
	start = steady_clock::now();
	while (array[i] <= x) {
		if (array[i] == x) {
			break;
		}
		i++;
	}
	end = steady_clock::now();

	result = duration_cast<nanoseconds>(end - start);
	cout << "����� ���������: " << (result.count() / 1000000.0) << " ��" << "\n";

}

void replace(int i, int j)
{
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;

	const int N = 100;
	int array[N] = {};
	fillArray(array, N);

	for (int k = 0; k < N; k++) {
		if (k == i || k == j) {
			cout << "{" << array[k] << "} ";
		}
		else {
			cout << array[k] << ' ';
		}
	}
	cout << "\n\n";


	start = steady_clock::now();
	swap(array[i], array[j]);
	end = steady_clock::now();

	for (int k = 0; k < N; k++) {
		if (k == i || k == j) {
			cout << "{" << array[k] << "} ";
		}
		else {
			cout << array[k] << ' ';
		}
	}
	cout << "\n";

	result = duration_cast<nanoseconds>(end - start);
	cout << "\n" << "����� ������������ ���������: " << (result.count() / 1000000.0) << " ��\n";

}

//idz start


void idz(int array[], int x) {
	srand(time(0));
	const int N = 100;

	int countOdd = 0, countEven = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2 != 0 && abs(array[i]) % 2 != 0) {
			++countOdd;
		}
		else if (i % 2 == 0 && abs(array[i]) % 2 == 0) {
			++countEven;
		}
	}
	cout << "\n���������� �������� ��������� ������� �������� �������� � �����������: " << countOdd << "\n";
	cout << "���������� ������ ��������� ������� ������ �������� � ����������� �������: " << countEven << "\n\n";

	int cou = 0;
	int d = 0;
	for (int j = 1; j < 10; j++) {
		for (int i = 0; i < N; i++) {
			if (abs(array[i]) % j == 0) {
				++cou;
			}
		}
		++d;
		cout << "���������� ��������� ������ ��������� �� " << d << " � ����������� �������: " << cou << "\n";
		cou = 0;

	}
	cout << "\n";

	for (int i = 0; i < N; i++) {
		if (abs(array[i]) % 2 == 0) {
			array[i] = array[i] - x;
		}
	}

	for (int i = 0; i < N; i++) {
		if (abs(array[i]) % 2 != 0) {
			int k = array[i];
			array[i] = array[i] * (rand() % 10);
			if (array[i] == 0) {
				array[i] = k;
			}
		}
	}

	cout << "���������� ������: ";
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << "\n\n";

	int countOddM = 0, countEvenM = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2 != 0 && abs(array[i]) % 2 != 0) {
			++countOddM;
		}
		else if (i % 2 == 0 && abs(array[i]) % 2 == 0) {
			++countEvenM;
		}
	}
	cout << "\n���������� �������� ��������� ������� �������� �������� � ���������� �������: " << countOddM << "\n";
	cout << "���������� ������ ��������� ������� ������ �������� � ���������� �������: " << countEvenM << "\n\n";

	int couM = 0;
	int dM = 0;
	for (int j = 1; j < 10; j++) {
		for (int i = 0; i < N; i++) {
			if (abs(array[i]) % j == 0) {
				++couM;
			}
		}
		++dM;
		cout << "���������� ��������� ������ ��������� �� " << dM << " � ���������� �������: " << couM << "\n";
		couM = 0;

	}
	cout << "\n";
}

//idz end

void launch(char task) {
	switch (task) {
	case '1':
		timeForQuickSort();
		break;
	case '2':
		searchMinMax();
		break;
	case '3':
		averageValue();
		break;
	case '4':
		int a;
		cout << "������� ����� a: ";
		cin >> a;
		cout << "\n";
		lessThanA(a);
		break;
	case '5':
		int b;
		cout << "������� ����� b: ";
		cin >> b;
		cout << "\n";
		moreThanB(b);
		break;
	case '6':
		int n;
		cout << "������� ������� �����: ";
		cin >> n;
		cout << "\n";
		compareTime(n);
		break;
	case '7':
		int i, j;
		cout << "������� ������� ���������� ���������(i, j): ";
		cin >> i >> j;
		cout << "\n";
		if ((i > 99 || i < 0) || (j > 99 || j < 0)) {
			cout << "�������� ����.\n";
		}
		else {
			replace(i, j);
		}
		break;
	case '8':
		const int N = 100;
		int array[N] = {};
		int x;
		fillArray(array, N);
		cout << "������: " << "\n";
		for (int i = 0; i < N; i++) {
			cout << array[i] << " ";
		}
		cout << "\n������� �������� �� ������� ����� ��������� ��� ������ ��������: ";
		cin >> x;
		idz(array, x);
	}
}

void lab2() {
	setlocale(0, "");
	cout << "1) ������������� ������ ������� ����������� (�� �������� � ��������). ���������� �����, ����������� �� ����������.\n"
		<< "2) ����� ������������ � ����������� ������� �������. ���������� ����� ������ ���� ��������� � ��������������� ������� � �����������������.\n"
		<< "3) ������� ������� �������� (���� ����������, ����� ����� ���������) ������������� � ������������ �������� � ��������������� � �����������������.\n������� ������� ���� ���������, ������� ����� ����� ��������, � �� ����������. ������� ����� ������.\n"
		<< "4) ������� ���������� ��������� � ��������������� �������, ������� ������ ����� a, ������� ���������������� �������������.\n"
		<< "5) ������� ���������� ��������� � ��������������� �������, ������� ������ ����� b, ������� ���������������� �������������.\n"
		<< "6) ������� ���������� � ���, ���� �� ��������� ������������� ����� � ��������������� �������.\n ���������� ��������� ��������� ������. ��������� �������� ��� ������ � ������� ���������. (*)\n"
		<< "7) �������� ������� �������� �������, ������� ������� ������ ������������. ������� �������� ������.\n"
		<< "8) ���: ��������� ������ ������ ������� �� ��������� ��������, ������ �������� ������� �������� �� ��������� �������� �� 1 �� 9,\n ������� �� ����� ������� ������ ��������� ����� ������ ��������,\n ������� �������� ��������� ����� �������� ��������,\n ������� ���������� ���������, ������� ������ ������� �� ����� �� 1 �� 9.\n"
		<< "0) ����� �����\n";

	char task;
	while (true) {
		cout << "������� ����� �������: ";
		cin >> task;
		if (task == '0') {
			break;
		}
		else {
			launch(task);
		}

	}
	
}