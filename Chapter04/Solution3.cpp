#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int len = s.size();
        string res;
        for (int i = 0; i < len; ++i) {
            if (s[i] == ' ') {
                res += "%20";
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};

int main()
{
    string s = "We are happy.";
    Solution solution;
    string res = solution.replaceSpace(s);
    cout << res << endl;
    return 0;
}