class Solution {
public:
    bool isValid(vector<vector<char>> &board, int cr, int cc){
        for (int i = 0; i < cr; i++){
            if(board[i][cc] == 'Q') return false;
        }

        for (int j = 0; j < cc; j++){
            if(board[cr][j] == 'Q') return false;
        }

        for (int i = cr, j = cc; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }

        for (int i = cr,j = cc; i >= 0 && j < board.size(); i--, j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    int Queens(vector<vector<char>> &board, int cr){
        int count = 0;
        int n = board.size();
        if(cr == n){
            return 1;
        }

        for (int cc = 0; cc < n; cc++){
            if(isValid(board, cr, cc)){
                board[cr][cc] = 'Q';
                count += Queens(board, cr + 1);
                board[cr][cc] = '.';
            }
        }

        return count;
    }
    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        return Queens(board, 0);
    }
};