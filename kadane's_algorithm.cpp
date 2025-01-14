#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int currSum = 0, maxSum = INT_MIN;
    for (int val : nums) {
        currSum += val;
        maxSum = std::max(currSum, maxSum);
        if (currSum < 0) {
            currSum = 0;  // Reset currSum when it's negative
        }
    }

    std::cout << "The maximum subarray sum is: " << maxSum << std::endl;

    return 0;
}
