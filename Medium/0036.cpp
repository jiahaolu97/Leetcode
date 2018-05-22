//注意memset函数的用法！！  memset(内存起始地址，每个“字节”填入的char类型代表的二进制，字节数)   
//如果用memset(数组头,1,arrayLen*sizeof(int))   将会导致每个 int 被填入的值是 00000001 00000001 00000001 00000001 == 16843009
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int val[9];
        int map[9][9];
        for(int i=0;i<9;i++){
            vector<char> row = board[i];
            for(int j=0;j<9;j++){
                if(row[j]=='.') map[i][j] = -1;
                else{
                    int v = row[j] - '0';
                    map[i][j] = v;
                }
            }
        }
        for(int i=0;i<9;i++){
            memset(val,0,9*sizeof(int));
            for(int j=0;j<9;j++){
                if(map[i][j]==-1) continue;
                int pos = map[i][j] - 1;
                if(--val[pos]<-1) return false;
            }
        }
        for(int i=0;i<9;i++){
            memset(val,0,9*sizeof(int));
            for(int j=0;j<9;j++){
                if(map[j][i]==-1) continue;
                int pos = map[j][i] - 1;
                if(--val[pos]<-1) return false;
            }
        }
        for(int m=0;m<9;m++){
            int x = (m/3)*3;
            int y = (m%3)*3;
            memset(val,0,9*sizeof(int));
            for(int i=x;i<x+3;i++){
                for(int j=y;j<y+3;j++){
                    if(map[i][j]==-1) continue;
                    int pos = map[i][j] - 1;
                    if(--val[pos]<-1) return false;
                }
            }
        }
        return true;
    }
};
