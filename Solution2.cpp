#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。
// 输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int i : nums2) {
            if (nums_set.find(i) != nums_set.end()) {
                res.insert(i);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};

int main()
{
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    Solution solution;
    auto res = solution.intersection(nums1, nums2);
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}