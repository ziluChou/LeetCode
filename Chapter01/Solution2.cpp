#include<iostream>
#include<vector>

using namespace std;

// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/remove-element
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 快慢指针，快指针在前面遍历，慢指针在后面保留结果
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); ++fastIndex) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

int main()
{
    vector<int> nums = {3, 2, 2, 3};
    Solution solution;
    int res = solution.removeElement(nums, 3);
    cout << res << endl;
    return 0;
}