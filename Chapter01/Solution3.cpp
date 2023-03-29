#include<iostream>
#include<vector>

using namespace std;

// 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

// 示例 1：

// 输入：nums = [-4,-1,0,3,10]
// 输出：[0,1,9,16,100]
// 解释：平方后，数组变为 [16,1,0,9,100]
// 排序后，数组变为 [0,1,9,16,100]

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/squares-of-a-sorted-array
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        int curIndex = len - 1;
        vector<int> result(len, 0);
        for (int i = 0, j = len - 1; i <= j;) {
            if (nums[i] * nums[i] < nums[j] * nums[j]) {
                result[curIndex--] = nums[j] * nums[j];
                j--;
            } else {
                result[curIndex--] = nums[i] * nums[i];
                i++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-1,1,2};
    auto res = solution.sortedSquares(nums);
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}