class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(is_sorted(s.begin(), s.end())) return 0;

        string t1 = s;
        string t2 = s;
        sort(t1.begin(), t1.end() - 1);
        sort(t2.begin() + 1, t2.end());

        if(is_sorted(t1.begin(), t1.end()) || is_sorted(t2.begin(), t2.end())) return 1;

        if(t1[0] < t1[n - 1]) return 2;
        if(t2[0] < t2[n - 1]) return 2;

        if(n > 2)  return 3;
        return -1;
    }
};