#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int left = 0;
        int up = 0;
        int down = n -1;
        int right = n - 1;
        int curNum = 1;
        while (left <= right && up <= down) {
            for (int i = left; i <= right; ++i) {
                res[up][i] = curNum++;
            }
            up++;

            for (int i = up; i <= down; ++i) {
                res[i][right] = curNum++;
            }
            right--;

            for (int i = right; i >= left; --i) {
                res[down][i] = curNum++;
            }
            down--;

            for (int i = down; i >= up; --i) {
                res[i][left] = curNum++;
            }
            left++;
        }
        return res;
    }
};

int main()
{
    int n = 5;
    Solution solution;
    auto res = solution.generateMatrix(n);
    for (const auto& vec : res) {
        for (const auto & i : vec) {
            cout << i << " ";
            if (i < 10) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}