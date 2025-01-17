class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j,
                   int k, int m, int n) {
        if (k == word.size())
            return true;
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k])
            return false;
        char temp = board[i][j];
        board[i][j] = '\0';
        if (backtrack(board, word, i + 1, j, k + 1, m, n) ||
            backtrack(board, word, i - 1, j, k + 1, m, n) ||
            backtrack(board, word, i, j + 1, k + 1, m, n) ||
            backtrack(board, word, i, j - 1, k + 1, m, n))
            return true;
        board[i][j] = temp; // This is necessary as we need to revert the changes for another iteration's search as we are modifying in the original board array...
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (backtrack(board, word, i, j, 0, m, n))
                    return true;
            }
        }
        return false;
    }
};
