#include<iostream>
#include<vector>

// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。 

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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto left = head;
        auto right = head->next;
        head->next = nullptr;
        while (right != nullptr) {
            auto next = right->next;
            right->next = left;
            left = right;
            right = next;
        }
        return left;
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
    auto res = solution.reverseList(node1);
    while (res) {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}