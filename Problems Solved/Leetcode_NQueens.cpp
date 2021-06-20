class Solution {
public:
    
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int i=row, j=col;
        
        //check upper-left diagonal
        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        
        // check left side of current row
        i=row;
        j=col;
        
        while(j>=0)
        {
            if(board[i][j]=='Q')
                return false;
            j--;
        }
        
        //check lower-left diagonal
        i=row;
        j=col;
        while(i<n && j>=0)
        {
            if(board[i][j]=='Q')
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if(col==n)
        {
		// Queens placed in all the columns
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n)) // check its safe or not to place Queen on board[row][col]
            {
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col] = '.'; //Backtracking Step
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        
        string str (n, '.'); // init string with all '$'
        
        for(int i=0;i<n;i++)
            board[i] = str;
        
        solve(0,board,ans,n);
        
        return ans;
    }
};
