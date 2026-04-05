class MinStack {
public:
    stack<pair<int, int>> pending;
    MinStack() {

    }
    
    void push(int val) {
        cout << val << endl;
        if(pending.empty()) {
            pending.emplace(val, val);
        } else {
            int tmp = val;
            if(tmp > pending.top().second) {
                tmp = pending.top().second;
            }
            pending.emplace(val, tmp);
        }
        cout << pending.size() << endl;
    }
    
    void pop() {
        pending.pop();
    }
    
    int top() {
        return pending.top().first;
    }
    
    int getMin() {
        return pending.top().second;
    }
};
