class Solution
{
private:
    bool isSafe(int r, int c, vector<string> board, int n)
    {

        for (int col = 0; col < n; col++)
        {
            if (col == c)
                continue;
            if (board[r][col] == 'Q')
                return false;
        }

        for (int row = 0; row < n; row++)
        {
            if (row == r)
                continue;
            if (board[row][c] == 'Q')
                return false;
        }

        int row = r + 1, col = c + 1;
        while (row < n && col < n)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col++;
        }

        row = r - 1, col = c - 1;
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        row = r + 1, col = c - 1;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        row = r - 1, col = c + 1;
        while (row >= 0 && col < n)
        {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col++;
        }
        return true;
    }

    void solve(int c, int n, vector<string> &board, vector<vector<string>> &ans)
    {
        if (c == n)
        {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (isSafe(i, c, board, n))
            {
                board[i][c] = 'Q';
                solve(c + 1, n, board, ans);
                board[i][c] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;

        solve(0, n, board, ans);
        return ans;
    }
};