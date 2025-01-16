#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void findPairSum(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            cout << "Pair found: (" << nums[i] << ", " << complement << ")" << endl;
        }
        // Store the number in the map
        numMap[nums[i]] = i;
    }
}

int main() {
    vector<int> nums = {2, 5, 7, 9, 11, 13, 16};
    int target = 18;

    cout << "Target Sum: " << target << endl;
    findPairSum(nums, target);

    return 0;
}
