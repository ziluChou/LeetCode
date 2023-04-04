#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，
// 请你计算有多少个元组 (i, j, k, l) 能满足：

// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/4sum-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int len = nums1.size();
        unordered_map<int, int> up;
        int res = 0;
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                up[nums1[i] + nums2[j]]++;
            }
        }

        for (int i : nums3) {
            for (int j : nums4) {
                if (up.find(-(i + j)) != up.end()) {
                    res += up[-(i + j)];
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};
    Solution solution;
    auto res = solution.fourSumCount(nums1, nums2, nums3, nums4);
    cout << res << endl;
    return 0;
}