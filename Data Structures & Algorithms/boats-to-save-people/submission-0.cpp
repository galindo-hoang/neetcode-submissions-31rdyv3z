class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1;
        int res = 0;
        while(left <= right) {
            if(left == right) {
                ++res;
                break;
            }
            if(people[right] + people[left] <= limit) {
                --right;
                ++left;
            } else {
                --right;
            }
            cout << left << " | " << right << endl;
            ++res;
        }
        return res;
    }
};