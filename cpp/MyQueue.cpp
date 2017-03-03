#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
         stack<int> tmp_s;
         int s_size = s.size();
        for (int i = 0; i < s_size-1; ++i) {
            tmp_s.push(s.top());
            s.pop();
        }
        int result = s.top();
        s.pop();
        int tmp_size = tmp_s.size();
        for (int i = 0; i < tmp_size; ++i) {
            s.push(tmp_s.top());
            tmp_s.pop();
        }
        return result; 
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> tmp_s;
        cout << "in peek, s.size:" << s.size() << endl;
        int size = s.size();
        for (int i = 0; i < size-1; ++i) {
 //           cout << "in loop. s.top:" << s.top() << endl;
            tmp_s.push(s.top());
            s.pop();
        }
//            cout << "s.top:" << s.top() << endl;
        int result = s.top();
        int tmp_size = tmp_s.size();
        for (int i = 0; i < tmp_size; ++i) {
            s.push(tmp_s.top());
            tmp_s.pop();
        }
        return result;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
private:
    stack<int> s;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main(int argc, char const *argv[])
{
    MyQueue obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    cout << "peek:" <<obj.peek() << endl;
    obj.pop();
    cout << "peek:" <<obj.peek() << endl;
    obj.pop();
    cout << "peek:" <<obj.peek() << endl;
    cout << obj.empty() << endl;
    cout << obj.pop() << endl;
    cout << obj.empty() << endl;
    return 0;
}
