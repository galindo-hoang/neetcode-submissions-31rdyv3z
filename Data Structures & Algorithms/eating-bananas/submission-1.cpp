class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = piles[0];
        for(int &i: piles) {
            // left = min(i, left);
            right = max(i, right);
        }
        int res = 0;
        while(left <= right) {
            int mid = (left + right) >> 1;
            int tmp = 0;
            for(int &i: piles) {
                tmp += (i / mid);
                if(i % mid != 0) ++tmp;
            }
            if(tmp <= h) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
