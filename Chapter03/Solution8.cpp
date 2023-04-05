#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target
// 请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] 
// （若两个四元组元素一一对应，则认为两个四元组重复）：

// 0 <= a, b, c, d < n
// a、b、c 和 d 互不相同
// nums[a] + nums[b] + nums[c] + nums[d] == target
// 你可以按 任意顺序 返回答案 

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/4sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; ++i) {
                // 去重
                if (nums[i] > target && nums[i] >= 0) {
                    return res;
                }

                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
            for (int j = i + 1; j < len; ++j) {
                // 去重
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
                    return res;
                }
                
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;;
                }

                int left = j + 1;
                int right = len - 1;
                while (left < right) {
                    // 这里防止溢出
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target) {
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left+1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right -1]) {
                            right--;
                        }
                        left++;
                        right--;
                    }
                }

            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    Solution solution;
    auto res = solution.fourSum(nums, target);
    cout << "res.size: " << res.size() << endl;
    for (auto vec : res) {
        for (auto i : vec) {
            cout << i << " "; 
        }
        cout << endl;
    }
    cout << "hello" << endl;
    return 0; 
}