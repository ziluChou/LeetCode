#include <iostream>
#include <string>

using namespace std;

// 给你两个字符串 haystack 和 needle ，
// 请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）
// 如果 needle 不是 haystack 的一部分，则返回  -1 
// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int strStr(string haystack, string needle) {
        // 这里没有返回值也可以正常运行
        haystack.find(needle) == string::npos ? -1 : haystack.find(needle);
    }
};

int main()
{
    string haystack = "leetcode";
    string needle = "tco";
    Solution solution;
    auto res = solution.strStr(haystack, needle);
    cout << res << endl;
    return 0;
}