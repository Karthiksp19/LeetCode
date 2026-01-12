class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;
        for (int i = 1; i < n; i++){
            int dx = abs(points[i - 1][0] - points[i][0]);
            int dy = abs(points[i - 1][1] - points[i][1]);
            count += max(dx, dy);
        }
        return count;
    }
};