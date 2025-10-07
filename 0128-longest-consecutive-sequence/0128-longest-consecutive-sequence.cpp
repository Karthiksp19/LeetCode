class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            s.insert(nums[i]);
        }
        int maxlen = 0;

        for (auto it : s){
            if(s.find(it - 1) == s.end()){
                int len = 1;
                int x = it;
                cout << x ;
                while(s.find(x + 1) != s.end()){
                        x = x + 1;
                        len = len + 1;
                }

                maxlen = max(maxlen, len);
            }
        }

        return maxlen;
    }
};