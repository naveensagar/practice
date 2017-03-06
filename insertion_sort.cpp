/*
Created by Naveen Sagar
*/

#include <iostream>
using namespace std;

int main()
{
	int size;
	cout << "Please enter the size of the array: " ;
	cin >> size;
	int A[size];

	cout << "Please enter elements of the array: " << endl;
	for(int i = 0; i < size; i++)
	{
		cin >> A[i];
	}

	//insertion sort code 

	for(int j = 1; j < size; j++) {
		int key = A[j];
		int i = j - 1;
		while(i >= 0 && A[i] > key) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}

	cout << "The sorted array: " << endl;
	for(int i = 0; i < size; i++)
	{
		cout << A[i] << endl;
	}
	return 0;
}