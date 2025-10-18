class Solution {
public:
    bool helper(int i, int j, int idx, string word, const vector<vector<char>>& board, vector<vector<bool>> & vis) {
        if (idx == word.size())  return true;
        int m = board.size();
        int n = board[0].size();

        if(i < 0 || i >= m || j < 0 || j >= n) return false;
        if (vis[i][j]) return false;
        if (word[idx] != board[i][j]) return false;

        vis[i][j] = true;


        bool up = helper(i - 1, j, idx + 1, word, board, vis);
        bool down = helper(i + 1, j, idx + 1, word, board, vis);
        bool left = helper(i, j - 1, idx + 1, word, board, vis);
        bool right = helper(i, j + 1, idx + 1 , word, board, vis);

        vis[i][j] = false;

        return up || down || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(helper(i, j, 0, word, board, vis)) return true;
            }
        }
        
        return false;
    }
};