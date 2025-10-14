class Solution {
public:
    bool isvalid(vector<string> &board, int cr, int cc){
        int n = board.size();
        for (int i = 0; i < cr; i++){
            if(board[i][cc] == 'Q') return false;
        }

        for (int i = 0; i < cc; i++){
            if(board[cr][i] == 'Q') return false;
        }

        for (int i = cr, j = cc; i >= 0 && j >=0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }

        for (int i = cr, j = cc; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void nqueen(vector<string> &board, vector<vector<string>> &ans, int cr, int n){
        if(cr == n){
            ans.push_back(board);
            return;
        }
        printf("%d %d", cr, 0);
        cout << endl;
        for (int cc = 0; cc < n; cc++){
            if(isvalid(board, cr, cc)){
                board[cr][cc] = 'Q';
                nqueen(board, ans, cr + 1, n);
                board[cr][cc] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        nqueen(board, ans, 0, n);
        return ans;
    }
};