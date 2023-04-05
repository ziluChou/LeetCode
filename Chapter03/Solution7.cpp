#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 
// 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 
// 请你返回所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/3sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; ++i) {
            if (nums[i] > 0) {
                return res;
            }
            // 错误去重a方法，将会漏掉-1,-1,2 这种情况
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
           // 正确去重方法
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = len - 1;
            while (left < right) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，
                // 从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
               if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
               } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
               } else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重复逻辑应该放在找到三元组之后进行
                    while (right > left && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    while (right > left && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    right--;
                    left++;
               }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution solution;
    auto res = solution.threeSum(nums);
    cout << res.size() << endl;
    for (auto vec : res) {
        for (auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}