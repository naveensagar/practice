#include <iostream>
using namespace std;


void Quicksort(int *, int, int);
int Partition(int *, int, int);

void Quicksort(int A[], int p, int r) {
	if(p < r) {
		int q = Partition(A, p, r);
			Quicksort(A, p, q - 1);
			Quicksort(A, q + 1, r);
		
	}
}

int Partition(int A[], int p, int r) {
	int x = A[r];
	int i = p - 1;
	for(int j = p; j <= r - 1; j++){
		if(A[j] <= x){
			i = i + 1;
			int k = A[j];
			A[j] = A[i];
			A[i] = k;
		}
	}
	int k = A[i+1];
	A[i+1] = A[r];
	A[r] = k;
	return i+1;
}

int main()
{
	//taking array's size
	int size;
	cout << "Enter the size of the array: " ;
	cin >> size;
	int A[size];

	//taking array elements from the command line
	cout << "Enter elements of the array: " << endl;
	for(int i = 0; i < size; i++)
	{
		cin >> A[i];
	}
	Quicksort(A, 0, size-1);
	//sorted array 
	cout << "The sorted array: " << endl;
	for(int i = 0; i < size; i++)
	{
		cout << A[i] << endl;
	}
	return 0;
}