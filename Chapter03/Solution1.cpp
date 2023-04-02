#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/valid-anagram
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    bool isAnagram(string s, string t) {
        // 这道题可以用数组替代哈希表，因为字母只有26个
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> up;
        for (auto c : s) {
            up[c]++; 
        }
        for (auto c : t) {
            if (up.find(c) == up.end()) {
                return false;
            }
            up[c]--;
        }
        for (auto i : up) {
            if (i.second > 0) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string s = "anagram";
    string t = "nagaram";
    Solution solution;
    auto flag = solution.isAnagram(s, t);
    if (flag) {
        cout << "是字母异位词" << endl;
    } else {
        cout << "不是字母异位词" << endl;
    }
    return 0;
}