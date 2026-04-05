class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size() * matrix[0].size() - 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            int r = mid / matrix[0].size();
            int l = mid % matrix[0].size();
            if(matrix[r][l] == target) {
                return true;
            } else if(matrix[r][l] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};
