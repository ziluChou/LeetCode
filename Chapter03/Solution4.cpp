#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

// 你可以按任意顺序返回答案

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/two-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> up;
        for (int i = 0; i < nums.size(); ++i) {
            if (up.find(target - nums[i]) != up.end()) {
                return vector<int>{i, up[target - nums[i]]};
            }
            up[nums[i]] = i;
        }
        return {0, 0};
    }
};

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution solution;
    auto res = solution.twoSum(nums, target);
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}