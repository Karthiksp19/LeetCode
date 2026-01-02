class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        int u = n / 2 + 1;
        int c = n / 2;
        unordered_map<int, int> m;
        for (int n : nums){
            if(m.find(n) != m.end()){
                m[n]++;
            }
            else{
                m[n] = 1;
            }
            if(m[n] == c) return n;
        }
        return -1;
    }
};