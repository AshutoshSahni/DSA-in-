#include <iostream>
#include <vector>
using namespace std;

// insertion sort
void insertion_sort(vector<int>& nums)
{
	int size = nums.size();

	for(int i = 1; i < size; i++)
	{
		int key = nums[i];
		int j = i - 1;
		
		while(j >= 0 && key < nums[j]) 
		{
			nums[j+1] = nums[j];
			--j;
		}
		nums[j+1] = key;
	}
}

int main()
{
	vector<int> nums = {1, 9, 2, 8, 3, 7, 4, 6, 5};

	insertion_sort(nums);

	for(const int n: nums)
		cout << n << " ";
	cout << endl;

	return 0;
}

/*
 - Time complexity: O(n*n)
 - Space Complexity: O(n)
*/
