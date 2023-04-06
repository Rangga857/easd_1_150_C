// 1. Algorithma dibutuhkan untuk menyelesaikan karena mempermudah dan membantu kita dalam mengubah program yang lebih rumit menjadi sederhana. 
//    Tidak hanya itu, algorithma juga untuk menyelesaikan beberapa masalah dengan menggunakan komputer
// 2. Static dan Dynamic
// 3. fakor yang mempengaruhi efisiennya suatu program adalah urut tidaknya suatu data seperti yang sudah dijelaskan bawhwa jika menggunakan quick sort
//    dengan data yang sudah urut akan tidak efisien dll
// 4. Bubble sort
// 5. Yang termasuk ke dalam Quadratic adalah insertion sort, Sedangkan yang termasuk ke dalam Loglinear  adalah quicksort
// 6. 

#include <iostream>
using namespace std;

int raf[70];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
	while (true)
	{
		cout << "Masukkan panjang element Array : ";
		cin >> n;

		if (n <= 70)
			break;
		else
			cout << "\n Maksimum panjang array adalah 20" << endl;
	}
	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<<" << (i + 1) << ">>";
		cin >> raf[i];
	}
}

void swap(int x, int y)
{
	int temp;

	temp = raf[x];
	raf[x] = raf[y];
	raf[y] = temp;
}

void selection_sort(int low, int high)
{
	int pivot, i, ra;
	if (low > high)
		return;
	pivot = raf[low];

	i = low + 1;
	ra = high;

	while (i <= ra)
	{
		while ((raf[i] <= pivot) && (i <= high))
		{
			i++;
			cmp_count++;
		}
		cmp_count++;

		while ((raf[ra]> pivot) && (ra >= low))
		{
			ra--;
			cmp_count++;
		}
		cmp_count++;

		if (i < ra)
		{
			swap(i, ra);
			mov_count++;
		}
	}

	if (low < ra)
	{
		swap(low, ra);
		mov_count++;
	}
	selection_sort(low, ra - 1);
	selection_sort(ra + 1, high);
}

void display() {
	cout << "\n--------------" << endl;
	cout << "Sorted Array" << endl;
	cout << "\n--------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << raf[i] << " ";
	}
	cout << "\n\nNumer of comparasions: " << cmp_count << endl;
	cout << "Number of data movement: " << mov_count << endl;
}

int main()
{
	input();
	selection_sort(0, n - 1);
	display();
	system("pause");

	return 0;
}
