class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxlen = 0;
        for (int i = 0; i < n; i++){
            vector<int> freq(26, 0);
            for(int j = i; j < n; j++){
                freq[s[j] - 'a']++;

                int common_f = 0;
                bool is_common = true;
                for (int k = 0; k < 26; k++){
                    if (freq[k] > 0){
                        if(common_f == 0) common_f = freq[k];
                        if(freq[k] != common_f) is_common = false;
                    }
                }

                if(is_common){
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }

        return maxlen; 
    }
};