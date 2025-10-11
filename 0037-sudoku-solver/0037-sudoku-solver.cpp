class Solution {
public:
    bool valid(int cr, int cc, vector<vector<char>>& board, int digit) {
        for (int i = 0; i < 9; i++) {
            if (board[cr][i] == '0' + digit)
                return false;
        }

        for (int i = 0; i < 9; i++) {
            if (board[i][cc] == '0' + digit)
                return false;
        }

        int sr = (cr / 3) * 3;
        int sc = (cc / 3) * 3;
        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {
                if (board[i][j] == '0' + digit)
                    return false;
            }
        }

        return true;
    }

    bool sudoku(int cr, int cc, vector<vector<char>>& board) {
        if (cc == 9)
            return sudoku(cr + 1, 0, board);
        if (cr == 9)
            return true;

        if (board[cr][cc] != '.') {
            return sudoku(cr, cc + 1, board);;
        }

        for (int i = 1; i <= 9; i++) {
            if (valid(cr, cc, board, i)) {
                board[cr][cc] = '0' + i;
                if (sudoku(cr, cc + 1, board)) return true;
                board[cr][cc] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) { sudoku(0, 0, board); }
};