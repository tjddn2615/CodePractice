#include <cstdio>
#include <cstring>
 
using namespace std;
 
int main(){
 
    int cnt,t;
    char board[100][101];
    for(int T=1;T<=10;T++){
        scanf("%d",&t);
        cnt=1;
        for(int i=0;i<100;i++)
            scanf("%s",board[i]);
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                int tmp=1;
                for(int k=1;k<50;k++){
                    if(j-k>=0 && j+k<100 && board[i][j-k]==board[i][j+k]) tmp+=2;
                    else break;
                }
                if(tmp>cnt) cnt=tmp;
                if(board[i][j] == board[i][j+1]){
                    tmp=2;
                    for(int k=1;k<50;k++){
                        if(j-k>=0 && j+1+k<100 && board[i][j-k]==board[i][j+1+k]) tmp+=2;
                        else break;
                    }
                    if(tmp>cnt) cnt=tmp;
                }
                tmp=1;
                for(int k=1;k<50;k++){
                    if(i-k>=0 && i+k<100 && board[i-k][j]==board[i+k][j]) tmp+=2;
                    else break;
                }
                if(tmp>cnt) cnt=tmp;
                if(board[i][j] == board[i+1][j]){
                    tmp=2;
                    for(int k=1;k<50;k++){
                        if(i-k>=0 && i+1+k<100 && board[i-k][j]==board[i+1+k][j]) tmp+=2;
                        else break;
                    }
                    if(tmp>cnt) cnt=tmp;
                }
            }
        }
        printf("#%d %d\n",T,cnt);
    }
 
    return 0;
}