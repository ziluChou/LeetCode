#include<iostream>
#include<vector>

// 给你一个链表的头节点 head 和一个整数 val ，
// 请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }

        auto dummyHead = new ListNode(val - 1, head);
        auto left = dummyHead;
        auto right = head;
        while (right != nullptr) {
            if (right->val == val) {
                left->next = right->next;
                right = right->next;
            } else {
                left = right;
                right = right->next;
            }
        }
        return dummyHead->next;
    }
};

int main()
{
    ListNode* node7 = new ListNode(6, nullptr);
    ListNode* node6 = new ListNode(5, node7);
    ListNode* node5 = new ListNode(4, node6);
    ListNode* node4 = new ListNode(3, node5);
    ListNode* node3 = new ListNode(6, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    Solution solution;
    auto res = solution.removeElements(node1, 6);

    while (res != nullptr) {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}