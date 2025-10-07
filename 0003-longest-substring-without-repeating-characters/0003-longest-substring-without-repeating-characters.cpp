class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int n = s.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < 256; i++){
            mp[i] = -1;
        }

        int maxlen = 0;

        while (right < n){

            if(mp[s[right]] != -1){
                left = mp[s[right]];
            }
            mp[s[right]] = right + 1;

            int len = right - left + 1;
            maxlen = max(maxlen, len);

            right++;
        }

        return maxlen;
    }
};