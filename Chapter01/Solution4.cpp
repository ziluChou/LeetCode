#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;


// 给定一个含有 n 个正整数的数组和一个正整数 target 。

// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/minimum-size-subarray-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 
        int len = nums.size();
        int leftIndex = 0;
        int curSum = nums[leftIndex];
        if (curSum >= target) {
            return 1;
        }
        int res = INT_MAX;
        for (int rightIndex = 1; rightIndex < len; ++rightIndex) {
            curSum += nums[rightIndex];
            while (curSum >= target) {
                res = min(res, rightIndex - leftIndex + 1);
                curSum -= nums[leftIndex++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main()
{
    vector<int> nums = {2,3,1,2,4,3};
    vector<int> nums1 = {1,4,4};
    vector<int> nums2 = {1,1,1,1,1,1,1,1};
    int target = 7;
    int target1 = 4;
    int target2 = 11;
    Solution solution;
    cout << solution.minSubArrayLen(target, nums) << endl;;
    Solution solution1;
    cout << solution1.minSubArrayLen(target1, nums1) << endl;;
    Solution solution2;
    cout << solution2.minSubArrayLen(target2, nums2) << endl;;
    return 0;
}