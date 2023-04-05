#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        int left = 0, right = len - 1;
        while (left < right) {
            auto c = s[left];
            s[left] = s[right];
            s[right] = c;
            left++, right--;
        }
        return;
    }
};

int main()
{
    vector<char> chars = {'a', 'b', 'c'};
    Solution solution;
    solution.reverseString(chars);
    for (auto c : chars) {
        cout << c;
    }
    return 0;
}