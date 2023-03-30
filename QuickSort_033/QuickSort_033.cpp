#include <iostream>
using namespace std;

int arr[20];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
	while (true) {
		cout << "Masukan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;

	}
	cout << endl;
	cout << "\n====================" << endl;
	cout << "\nMasukan Elemen Array" << endl;
	cout << "\n====================" << endl;

	for (int i = 0; i < n; i++) {

		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}
void swap(int x, int y) {
	int temp;
	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high) {
	int pivot, i, j;
	if (low > high)										// Langkah 1
		return;
	pivot = arr[low];									// Langkah 2

	i = low + 1;										// Langkah 3
	j = high;											// Langkah 4


	while (i <= j) {									// Langkah 10
		while ((arr[i] <= pivot) && (i <= high)) {		// Langkah 5
			i++;										// Langkah 6
			cmp_count++;
		}
		cmp_count++;
		while ((arr[j] > pivot) && (j >= low))			// Langkah 7
		{
			j--;										// Langkah 8
			cmp_count++;
		}
		cmp_count++;									
														// Langkah 9

		if (i < j) {
			swap(i, j);
			mov_count++;
		}
	}
		if (low < j) {									// Langkah 11
			swap(low, j);							
			mov_count++;
	}
	q_short(low, j - 1);								// Langkah 12
	q_short(j + 1, high);								// Langkah 13

}

void display() {
	cout << "\n========================" << endl;
	cout << "Array yang sudah tersusun" << endl;
	cout << "\n========================" << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << "\n\nPerbandingan nomor: " << cmp_count << endl;
	cout << "Perpindahan data: " << mov_count << endl;
}

int main() {
	input();
	display();
	return 0;
}


