#include<iostream>
using namespace std;

//iterative version using while loop
//l is the leftmost of array, r is rightmost of array
int BinarySearch(int arr[], int l, int r, int x)
{
	int num = 0;
	while (l <= r)//still in the range of the array
	{
		int mid = l + (r - l) / 2;
		num = arr[mid];
		if (x < num)
		{
			r = mid - 1;
		}
		else if (x > num)
		{
			l = mid + 1;
		}
		else if (x == num)
		{
			return mid;
		}
	}
}

//recursive version
int binarySearch(int arr[], int l, int r, int x)
{
	int mid = l + (r - l) / 2;
	if (arr[mid] == x)
	{
		return mid;
	}
	else if (x < arr[mid])
	{
		return binarySearch(arr, l, mid - 1, x);
	}
	else if (x > arr[mid])
	{
		return binarySearch(arr, mid + 1, r, x);
	}
}

int main()
{
	int arr[] = { 2,3,4,10,40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 10;
	int index = binarySearch(arr, 0, n - 1, x);
	if (index == -1)
	{
		cout << "Element is not present in array" << endl;
	}
	else
	{
		cout << "Element is present at index: " << index << endl;
	}
	return 0;
}
