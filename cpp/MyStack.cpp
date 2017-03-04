#include <queue>
#include <iostream>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
		return q.push(x);
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
		queue<int> tmp_q;
		int q_size = q.size();
		for (int i = 0; i < q_size - 1; ++i)
		{
			tmp_q.push(q.front());
			q.pop();
		}
		int ret = q.front();
		q.pop();
		int tmp_q_size = tmp_q.size();
		for (int i = 0; i < tmp_q_size; ++i) {
			q.push(tmp_q.front());
			tmp_q.pop();
		}
		return ret;
    }
    
    /** Get the top element. */
    int top() {
		queue<int> tmp_q;
		int q_size = q.size();
		for (int i = 0; i < q_size - 1; ++i)
		{
			tmp_q.push(q.front());
			q.pop();
		}
		int ret = q.front();
		q.pop();
		int tmp_q_size = tmp_q.size();
		for (int i = 0; i < tmp_q_size; ++i) {
			q.push(tmp_q.front());
			tmp_q.pop();
		}
		q.push(ret);
		return ret;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
		return q.empty();
    }
private:
	queue<int> q;

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
int main() {
	MyStack s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << s.top() << endl;
	cout << s.empty() << endl;
	cout << s.pop() << endl;
	cout << s.top() << endl;
	cout << s.empty() << endl;
	cout << s.pop() << endl;
	cout << s.top() << endl;
	cout << s.empty() << endl;
	return 0;
}
