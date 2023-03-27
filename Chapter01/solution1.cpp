#include<iostream>
#include<vector>

// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/binary-search
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (target < nums.front() || nums.back() < target) {
            return -1;
        }
        // 二分 左闭右闭区间
        int len = nums.size();
        int left = 0, right = len -1;
        int mid = 0;
        while (left <= right) {
        mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    cout << "heloo" << endl;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    Solution solution;
    cout << solution.search(nums, target) << endl;
    return 0;
}