#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        findSol(solutions, board, n, 0, 0);
        return solutions;
        
    }

    void findSol(vector<vector<string>>& solutions, vector<string>& cur, int N, int x, int Q)//solve for i, j coordinates recursively
    {
        if(Q == N)
        {
            solutions.emplace_back(cur);
            return;
        }
        for(int i=0;i<N;i++)
        {
            if(cur[x][i] == '.'){
                if(checkValid(cur, x, i))//possible position
                {
                    cur[x][i] = 'Q';//place queen on board
                    findSol(solutions, cur, N, x+1, Q+1);
                    cur[x][i] = '.';
                }
            }
        } 

        return ;  
    }

    bool checkValid(vector<string>& board, int x, int y)//check if queen can be placed there 
    {
        for(int i=0;i<x;i++)
        {
            if(board[i][y] == 'Q') return false;//check col
        }
        for(int i=x-1, j=y-1;i>-1 && j>-1;i--, j--)
        {
            if(board[i][j] == 'Q') return false;
        }
        for(int i=x-1, j=y+1;i>-1 && j<board.size();i--, j++)
        {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
};

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    Solution * sol = new Solution();
    int n;
    cout << "Dimensions and Queens: ";
    cin >> n;
    cout << '\n';
    vector<vector<string>> t = sol->solveNQueens(n);
    cout << "There are " << t.size() << " unique solutions!\n"; 
    for(int i=0;i<t.size();i++)
    {
        for(string s:t[i])
            cout << s << '\n';
        cout << "-----------" << '\n';
    }
    return 0;
}

