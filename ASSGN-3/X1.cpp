#include <bits/stdc++.h>
using namespace std;

// ---------------------- 1. Nearest Smaller to Left ----------------------
vector<int> nearestSmallerToLeft(vector<int>& A) {
    stack<int> st;
    vector<int> ans;

    for (int x : A) {
        while (!st.empty() && st.top() >= x) st.pop();
        ans.push_back(st.empty() ? -1 : st.top());
        st.push(x);
    }
    return ans;
}

// ---------------------- 2. Min Stack ----------------------
class MinStack {
    stack<int> mainSt, minSt;

public:
    void push(int x) {
        mainSt.push(x);
        if (minSt.empty() || x <= minSt.top())
            minSt.push(x);
    }

    void pop() {
        if (mainSt.top() == minSt.top())
            minSt.pop();
        mainSt.pop();
    }

    int top() {
        return mainSt.top();
    }

    int getMin() {
        return minSt.top();
    }

    bool empty() {
        return mainSt.empty();
    }
};

// ---------------------- 3. Next Greater Element ----------------------
vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) st.pop();
        if (!st.empty()) ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

// ---------------------- 4. Daily Temperatures ----------------------
vector<int> dailyTemperatures(vector<int>& temp) {
    int n = temp.size();
    vector<int> ans(n, 0);
    stack<int> st; // indices

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && temp[st.top()] <= temp[i]) st.pop();
        if (!st.empty()) ans[i] = st.top() - i;
        st.push(i);
    }
    return ans;
}

// ---------------------- MAIN ----------------------
int main() {
    // 1. Nearest Smaller to Left
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> ns = nearestSmallerToLeft(A);
    cout << "Nearest Smaller to Left: ";
    for (int x : ns) cout << x << " ";
    cout << "\n";

    // 2. MinStack
    MinStack ms;
    ms.push(5); ms.push(3); ms.push(7); ms.push(2);
    cout << "Current Min in stack: " << ms.getMin() << "\n";
    ms.pop();
    cout << "After popping, Min: " << ms.getMin() << "\n";

    // 3. Next Greater Element
    vector<int> arr = {4, 5, 2, 25};
    vector<int> nge = nextGreaterElement(arr);
    cout << "Next Greater Elements: ";
    for (int x : nge) cout << x << " ";
    cout << "\n";

    // 4. Daily Temperatures
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = dailyTemperatures(temp);
    cout << "Daily Temperatures Wait: ";
    for (int x : res) cout << x << " ";
    cout << "\n";

    return 0;
}