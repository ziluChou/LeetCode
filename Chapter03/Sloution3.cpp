#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// 编写一个算法来判断一个数 n 是不是快乐数。

// 「快乐数」 定义为：

// 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
// 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
// 如果这个过程 结果为 1，那么这个数就是快乐数。
// 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/happy-number
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int helper(int n) {
        int res = 0;
        while (n) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while (true) {
            set.insert(n);
            n = helper(n);
            if (n == 1) {
                return true;
            }
            if (set.find(n) != set.end()) {
                return false;
            }
            set.insert(n);
        }
    }
};

int main()
{
    Solution solution;
    bool flag = solution.isHappy(19);
    if (flag) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}