class Solution {
public:
    bool isOpp(char &pre, char &cur) {
        return (cur == '}' && pre == '{') || (cur == ']' && pre == '[') || (cur == ')' && pre == '(');
    }
    bool isValid(string s) {
        stack<char> pending;
        for(char &c: s) {
            if(c == '(' || c == '{' || c == '[') {
                pending.emplace(c);
            } else {
                if(pending.empty() || !isOpp(pending.top(), c)) {
                    return false;
                }
                pending.pop();
            }
        }
        return pending.empty();
    }
};
