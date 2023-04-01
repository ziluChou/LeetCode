#include<iostream>
#include<vector>

using namespace std;

// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 快慢指针
        auto dummyHead = new ListNode(0, head);
        auto left = dummyHead;
        auto right = head;
        while (n--) {
            right = right->next;
        }
        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return dummyHead->next;
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
    auto res = solution.removeNthFromEnd(node1, 3);
    while (res) {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}