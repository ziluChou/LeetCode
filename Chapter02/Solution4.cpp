#include<iostream>
#include<vector>

using namespace std;

// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
// 你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换） 
// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto left = head;
        auto right = head->next;
        left->next = swapPairs(right->next);
        right->next = left;
        return right;
    }
};

int main()
{
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);
    Solution solution;
    auto res = solution.swapPairs(node1);
    while (res) {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}