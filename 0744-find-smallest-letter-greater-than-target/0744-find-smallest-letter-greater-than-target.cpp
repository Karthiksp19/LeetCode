class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        char ch = target;
        for (int i = 0; i < n; i++){
            if(letters[i] > ch) {
                ch = letters[i];
                break;
            }
            if(i == n - 1) return letters[0];
        }
        return ch;
    }
};