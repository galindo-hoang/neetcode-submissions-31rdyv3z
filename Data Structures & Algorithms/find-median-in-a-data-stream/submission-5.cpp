class MedianFinder {
public:
    vector<int> store;
    double cur;
    MedianFinder() {
        cur = -1.0;
    }
    
    void addNum(int num) {
        if(store.size() == 0) {
            cur = 0.0;
            store.emplace_back(num);
            return;
        }
        int left = 0, right = store.size() - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(store[mid] >= num) {
                right = mid - 1;
            } else left = mid + 1;
        }
        cur += 0.5;
        store.insert(store.begin() + right + 1, num);
    }
    
    double findMedian() {
        if(fmod(cur, 1.0) != 0.0) {
            return (store[(int) cur] + store[(int) cur + 1]) / 2.0;
        } return store[(int) cur];
    }
};
