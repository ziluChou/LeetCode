#include<iostream>
#include<vector>

using namespace std;

// 给你两个单链表的头节点 headA 和 headB ，
// 请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        auto cur1 = headA, cur2 = headB;
        while (cur1 != nullptr || cur2 != nullptr) {
            if (cur1 == nullptr) {
                cur1 = headB;
            } else {
                cur1 = cur1->next;
            }
            if (cur2 == nullptr) {
                cur2 = headA;
            } else {
                cur2 = cur2->next;
            }
            if (cur1 == cur2) {
                return cur1;
            }
        }
        return nullptr;
    }
};

int main()
{
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    ListNode* node2_1 = new ListNode(2, node3);
    ListNode* node1_1 = new ListNode(1, node2_1);
    Solution solution;
    auto res = solution.getIntersectionNode(node1, node1_1);
    cout << res->val << endl;
    return 0;
}