#include<iostream>
#include<vector>

using namespace std;

// 给定一个链表的头节点  head
// 返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 快慢指针
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        auto slow = head;
        auto fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                auto index1 = fast;
                auto index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
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
    node5->next = node2;
    
    Solution solution;
    auto res = solution.detectCycle(node1);
    if (res == nullptr) {
        cout << "没有环" << endl;
    } else {
        cout << "有环：" << res->val << endl;
    }
    return 0;
}