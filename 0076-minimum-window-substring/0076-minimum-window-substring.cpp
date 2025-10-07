class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        int m = 0, count = 0;
        int maxl = INT_MAX, si  = -1;
        for (int i = 0; i < t.size(); i++){
            mp[t[i]]++;
            m++;
        }

        while (right  < n){
            if(mp[s[right]] > 0){
                count++;
            }
            mp[s[right]]--;

            while(count == m){
        cout << m;
                if(right - left + 1 < maxl){
                    maxl = right - left + 1;
                    si = left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0){
                    count--;
                }
                left++;

            }

            right++;
        }

        return si == -1 ? "" : s.substr(si , maxl);
    }
};