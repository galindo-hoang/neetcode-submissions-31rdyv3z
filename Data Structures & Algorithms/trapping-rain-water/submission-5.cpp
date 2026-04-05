class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int,int>> s;
        for(int i = 0; i < height.size(); ++i) {
            if(s.empty() || (height[s.top().first] > height[i])) {
                s.emplace(i, 0);
            } else {
                int tmp = 0;
                pair<int, int> child = s.top();
                s.pop();
                while(!s.empty()) {
                    pair<int,int> cur = s.top();
                    if(height[cur.first] >= height[i]) {
                        tmp += (height[i] - height[child.first]) * (i - cur.first - 1) + child.second;
                        break;
                    } else {
                        s.pop();
                        tmp += (height[cur.first] - height[child.first]) * (i - cur.first - 1) + child.second;
                        child = cur;
                    }
                }
                if(s.empty()) {
                    tmp += child.second;
                }
                cout << i << " = " << tmp << endl;
                s.emplace(i, tmp);
            }
        }

        int res = 0;
        while(!s.empty()) {
            res += s.top().second;
            cout << s.top().first << " - " << s.top().second << endl;
            s.pop();
        }
        return res;
    }\
};
