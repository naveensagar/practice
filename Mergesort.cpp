#include <iostream>
using namespace std;


void TopDownSplitMerge(int *, int , int , int *);
void CopyArray(int *, int , int , int *);
void TopDownMerge(int *, int, int, int, int *);



void TopDownMergeSort(int A[], int B[], int n)
{
	CopyArray(A, 0, n, B);
	TopDownSplitMerge(B, 0, n, A);
}

void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
	if(iEnd - iBegin < 2)
		return;

	int iMiddle = (iEnd + iBegin) / 2 ;

	TopDownSplitMerge(A, iBegin, iMiddle, B);
	TopDownSplitMerge(A, iMiddle, iEnd, B);

	TopDownMerge(B, iBegin, iMiddle, iEnd, A);

	
}

void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
	int i = iBegin, j = iMiddle;
	for (int k = iBegin; k < iEnd; k++)
	{
		if(i < iMiddle && (j >= iEnd || A[i] <= A[j]))
		{
			B[k] = A[i];
			i = i + 1;
		}
		else 
		{
			B[k] = A[j];
			j = j + 1;
		}
	}

	
}

void CopyArray(int A[], int iBegin, int iEnd, int B[])
{
	for(int k = iBegin; k < iEnd; k++)
		B[k] = A[k];
}

int main()
{
	int size;
	cout << "Please enter the size of the array: " ;
	cin >> size;
	int A[size]; int B[size];

	cout << "Please enter elements of the array: " << endl;
	for(int i = 0; i < size; i++)
	{
		cin >> A[i];
	}
	
	TopDownMergeSort(A, B, size);

	cout << "The sorted array: " << endl;
	for(int i = 0; i < size; i++)
	{
		cout << A[i] << endl;
	}
	return 0;
}