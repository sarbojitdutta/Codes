class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9], cols[9], boxes[9];

        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                char ch = board[row][col];

                if (ch == '.') continue;

                int box = (row / 3) * 3 + (col / 3);

                if(rows[row].count(ch) || cols[col].count(ch) || boxes[box].count(ch)){
                    return false;
                }
                rows[row].insert(ch);
                cols[col].insert(ch);
                boxes[box].insert(ch);
            }
        }return true;
    }
};