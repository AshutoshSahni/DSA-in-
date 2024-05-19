#include <iostream>
#include <vector>
using namespace std;

//to swap the elements
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// selection sort 
void selection_sort(vector<int>& arr)
{
	int size = arr.size();

	for (int step = 0; step < size - 1; step++)
	{
		int smallest = step;
		for (int i = step + 1; i < size; i++)
		{
			if (arr[i] < arr[smallest])
				smallest = i;
		}

		swap(&arr[smallest], &arr[step]);
	}
}

// driver code
int main()
{
	vector<int> arr = {4, 2, 9, 1, 8, 0, 2, 5};
	selection_sort(arr);

	// print the sorted array
	for (const int n : arr)
		cout << n << " ";

	cout << endl;

	return 0;
}


/*

- Time Complexity: O(n*n)
- Space Complexity: O(n*n)

*/