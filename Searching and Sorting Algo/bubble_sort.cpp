#include <iostream>
#include <vector>
using namespace std;

// bubble sort
void bubbleSort(vector<int>& nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

int main()
{
    vector<int> nums = {4, 1, 9, 3, 2, 8, 5};

    bubbleSort(nums);

    // print the sorted array
    for (const int i : nums)
        cout << i << " ";
    cout << endl;

    return 0;
}

/*
Complexity
- Space: O(1)
- Time: O(n*n)
*/