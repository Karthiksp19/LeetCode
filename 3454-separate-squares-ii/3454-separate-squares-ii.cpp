#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Event {
        double x, y1, y2;
        int type;
        bool operator<(const Event& other) const {
            return x < other.x;
        }
    };

    double unionArea(const vector<array<double,4>>& rects) {
        vector<Event> events;
        vector<double> ys;

        for (auto &r : rects) {
            events.push_back({r[0], r[2], r[3], 1});
            events.push_back({r[1], r[2], r[3], -1});
            ys.push_back(r[2]);
            ys.push_back(r[3]);
        }

        if (events.empty()) return 0.0;

        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());

        int m = ys.size();
        vector<int> cnt(m * 4, 0);
        vector<double> len(m * 4, 0.0);

        function<void(int,int,int,int,int,int)> update =
        [&](int node, int l, int r, int ql, int qr, int val) {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) {
                cnt[node] += val;
            } else {
                int mid = (l + r) / 2;
                update(node*2, l, mid, ql, qr, val);
                update(node*2+1, mid, r, ql, qr, val);
            }
            if (cnt[node] > 0) {
                len[node] = ys[r] - ys[l];
            } else if (l + 1 == r) {
                len[node] = 0.0;
            } else {
                len[node] = len[node*2] + len[node*2+1];
            }
        };

        sort(events.begin(), events.end());
        double area = 0.0;
        double prevX = events[0].x;

        for (auto &e : events) {
            double dx = e.x - prevX;
            area += dx * len[1];
            int y1 = lower_bound(ys.begin(), ys.end(), e.y1) - ys.begin();
            int y2 = lower_bound(ys.begin(), ys.end(), e.y2) - ys.begin();
            update(1, 0, m - 1, y1, y2, e.type);
            prevX = e.x;
        }

        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<array<double,4>> rects;
        double ymin = 1e18, ymax = -1e18;

        for (auto &s : squares) {
            double x = s[0], y = s[1], l = s[2];
            rects.push_back({x, x + l, y, y + l});
            ymin = min(ymin, y);
            ymax = max(ymax, y + l);
        }

        double total = unionArea(rects);
        double half = total / 2.0;

        double lo = ymin, hi = ymax;
        for (int i = 0; i < 60; i++) {
            double mid = (lo + hi) / 2.0;
            vector<array<double,4>> clipped;

            for (auto &s : squares) {
                double x = s[0], y = s[1], l = s[2];
                double h = min(l, max(0.0, mid - y));
                if (h > 0)
                    clipped.push_back({x, x + l, y, y + h});
            }

            if (unionArea(clipped) < half)
                lo = mid;
            else
                hi = mid;
        }

        return lo;
    }
};
