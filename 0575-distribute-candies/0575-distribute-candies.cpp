class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        int count = 0;
        unordered_set<int> s;
        for (int i = 0; i < n; i++){
            if(count == n / 2) break;
            if(s.find(candyType[i]) == s.end()){
                s.insert(candyType[i]);
                count++;
            }
        }
        return count;
    }
};