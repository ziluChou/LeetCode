#include <iostream>
#include <string>

using namespace std;

// 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};

int main()
{
    string s = "ababab";
    Solution solution;
    solution.repeatedSubstringPattern(s) == true ? cout << "Yes" << endl : cout << "False" << endl;
    return 0;
}