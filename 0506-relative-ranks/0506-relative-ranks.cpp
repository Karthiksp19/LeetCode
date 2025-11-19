class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        int n = score.size();

        for (int i = 0; i < n; i++){
            pq.push({score[i], i});
        }

        vector<string> ans(n);
        int i = 1;
        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            int idx = tp.second;
            if(i == 1) ans[idx] = "Gold Medal";
            else if(i == 2) ans[idx] = "Silver Medal";
            else if(i == 3) ans[idx] = "Bronze Medal";
            else ans[idx] = to_string(i);
            i++;
        }

        return ans;
    }
};