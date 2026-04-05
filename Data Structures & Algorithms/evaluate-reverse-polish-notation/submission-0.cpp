class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> pending;
        for(string &str: tokens) {
            if(str == "+") {
                int sec = pending.top();
                pending.pop();
                int first = pending.top();
                pending.pop();
                pending.emplace(sec + first);
            } else if(str == "*") {
                int sec = pending.top();
                pending.pop();
                int first = pending.top();
                pending.pop();
                pending.emplace(sec * first);
            } else if(str == "-") {
                int sec = pending.top();
                pending.pop();
                int first = pending.top();
                pending.pop();
                pending.emplace(first - sec);
            } else if(str == "/") {
                int sec = pending.top();
                pending.pop();
                int first = pending.top();
                pending.pop();
                pending.emplace(first / sec);
            } else {
                pending.emplace(stoi(str));
            }
        }
        return pending.top();
    }
};
