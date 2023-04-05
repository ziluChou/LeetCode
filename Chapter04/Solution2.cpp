#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void reverseChars(string &s, int left, int right) {
        if (right >= s.size()) {
            right = s.size() - 1;
        }
        while (left < right) {
            auto c = s[left];
            s[left] = s[right];
            s[right] = c;
            left++, right--;
        }
        return;
    }
    string reverseStr(string s, int k) {
        int len = s.size();
        for (int i = 0; i < len; i += 2 * k) {
            reverseChars(s, i, i + k - 1);
        }
        return s;
    }
};

int main()
{
    Solution solution;
    string s = "abcd";
    int k = 2;
    auto res = solution.reverseStr(s, 2);
    cout << res << endl;
    return 0;
}