class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int x : nums){
            mp[x]++;
        }

        int maxl = 0;
        for(pair<int, int> x : mp){
            int key = x.first;
            if(mp.count(key + 1) != 0){
                maxl = max(maxl, mp[key] + mp[key + 1]);
            }
        }

        return maxl;
    }
};