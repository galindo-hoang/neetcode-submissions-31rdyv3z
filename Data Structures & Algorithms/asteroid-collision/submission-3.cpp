class Solution {
public:
    vector<int> asteroidCollision(vector<int> asteroids) {
        deque<int> pending;
        for (int &as: asteroids) {
            if (pending.empty() || as > 0 || pending.back() * as > 0) {
                pending.push_back(as);
            } else {
                bool isExplode = false;
                while (!pending.empty() && pending.back() * as < 0) {
                    const int tmp = pending.back();
                    pending.pop_back();
                    if (tmp + as >= 0) {
                        if (tmp + as > 0) pending.push_back(tmp);
                        isExplode = true;
                        break;
                    }
                }
                if (!isExplode) {
                    pending.push_back(as);
                }
            }
        }
        vector<int> res;
        while (!pending.empty()) {
            res.emplace_back(pending.front());
            pending.pop_front();
        }
        return res;
    }
};