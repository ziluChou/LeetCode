#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作
//（push、pop、peek、empty）：

// 实现 MyQueue 类：

// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/implement-queue-using-stacks
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {

    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int res = stOut.top();
        stOut.pop();
        return res;
    }
    
    int peek() {
        int res = this->pop();
        stOut.push(res);
        return res;
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};


int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    cout << obj->peek();
    obj->pop();
    if (obj->empty()) {
        cout << "empty" << endl;
    } else {
        cout << "not empty" << endl;
    }
    return 0;
}