#include <iostream>
#include <queue>
using namespace std;

class Stack2Q {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (!q1.empty()) q1.pop();
    }

    int top() {
        if (!q1.empty()) return q1.front();
        return -1;
    }

    bool empty() {
        return q1.empty();
    }
};
class Stack1Q {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (!q.empty()) q.pop();
    }

    int top() {
        if (!q.empty()) return q.front();
        return -1;
    }

    bool empty() {
        return q.empty();
    }
};
int main() {
    Stack2Q s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    return 0;
}
