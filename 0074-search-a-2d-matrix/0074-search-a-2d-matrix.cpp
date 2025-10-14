class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0, high = m * n - 1;

        while (low <= high){
            int mid = (low + high) / 2;
            int row = mid / n;
            int col = mid % n;
            int mid_ele = matrix[row][col];
            if (mid_ele == target){
                return true;
            }
            else if(mid_ele < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
};