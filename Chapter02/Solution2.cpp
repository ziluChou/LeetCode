#include<iostream>

using namespace std;

// 你可以选择使用单链表或者双链表，设计并实现自己的链表。

// 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。

// 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

// 实现 MyLinkedList 类：

// MyLinkedList() 初始化 MyLinkedList 对象。
// int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
// void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
// void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
// void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
// void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/design-linked-list
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class MyLinkedList {
public:
    // 定义链表结构
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val),next(nullptr){}
        LinkedNode(int val, LinkedNode* next):val(val),next(next){}
    };

    MyLinkedList() {
        size = 0;
        dummyHead = new LinkedNode(0, nullptr);
    }
    
    int get(int index) {
        if (index >= size) {
            return -1;
        }
        auto cur = dummyHead;
        index++;
        while (index--) {
            cur = cur->next;
        }
        return cur->val; 
    }
    
    void addAtHead(int val) {
        dummyHead->next = new LinkedNode(val, dummyHead->next);
        size++;
    }
    
    void addAtTail(int val) {
        if (size == 0) {
            dummyHead->next = new LinkedNode(val);
        } else {
            auto pre = dummyHead;
            auto cur = dummyHead->next;
            while(cur != nullptr) {
                pre = cur;
                cur = cur->next;
            }
            pre->next = new LinkedNode(val);
        }
        size++;
        return;    
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            return addAtHead(val);
        }
        if (index == size) {
            return addAtTail(val);
        }
        if (index > size) {
            return;
        }
        auto pre = dummyHead;
        auto cur = dummyHead->next;
        while (index--) {
            pre = cur;
            cur = cur->next;
        }
        auto node = new LinkedNode(val, cur);
        pre->next = node;
        size++;
        return;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        auto pre = dummyHead;
        auto cur = dummyHead->next;
        while (index--) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        size--;
        return;
    }

private:
    int size;
    LinkedNode* dummyHead;
};

int main()
{
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    int param_1 = obj->get(1);
    cout << param_1 << endl;
    obj->deleteAtIndex(1);
    int param_2 = obj->get(1);
    cout << param_2 << endl;
    return 0;
}