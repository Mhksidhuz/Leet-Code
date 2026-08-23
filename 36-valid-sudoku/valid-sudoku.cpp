class Solution {
public:
    bool sudoku(vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int ch = '1';ch<='9';ch++){
                        if(possible(i,j,ch,board)){
                            board[i][j]=ch;
                            if(sudoku(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool possible(int row,int col,char ch,vector<vector<char>> &board){
        for(int i=0;i<9;i++){

            if(board[row][i]==ch) return false;

            if(board[i][col]==ch) return false;

            if(board[3*(row/3) + i/3][3*(col/3) +i%3]==ch) return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
            char ch = board[i][j];

            board[i][j]='.';
            if(!possible(i,j,ch,board)){
                return false;
            }
            board[i][j]=ch;
            }
         }
         return true;
    }
};