class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        auto maxSpan = [](vector<int>& bars) {
            sort(bars.begin(), bars.end());
            int best = 1, cur = 1;
            for (int i = 1; i < bars.size(); i++) {
                if (bars[i] == bars[i - 1] + 1) {
                    cur++;
                } else {
                    best = max(best, cur);
                    cur = 1;
                }
            }
            best = max(best, cur);
            return best + 1;
        };

        int h = maxSpan(hBars);
        int v = maxSpan(vBars);
        int side = min(h, v);
        return side * side;
    }
};
