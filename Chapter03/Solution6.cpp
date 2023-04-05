#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

// 如果可以，返回 true ；否则返回 false 。

// magazine 中的每个字符只能在 ransomNote 中使用一次。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/ransom-note
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> chars(26, 0);
        for (auto c : magazine) {
            chars[c - 'a']++;
        }
        cout << endl;

        for (auto c : ransomNote) {
            if (--chars[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string ransomNode = "aa";
    string magazine = "aab";
    Solution solution;
    auto flag = solution.canConstruct(ransomNode, magazine);
    if (flag) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}