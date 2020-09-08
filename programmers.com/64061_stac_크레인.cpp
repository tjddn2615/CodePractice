#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int cnt = 0;
    stack<int> st;
    
    for(auto m : moves){
        for(int i = 0 ; i< board.size(); i++){ 
            bool exit_flag = false;
            for(int j = 0 ; j< board[i].size(); j++){
                if(m - 1 == j && board[i][j] != 0){
                    if(!st.empty() && st.top() == board[i][j]){
                        st.pop();
                        answer++;
                        exit_flag=true;
                        cout << board[i][j] << endl;
                        board[i][j] = 0;
                        //cout << "pop" << m << " " << i << j << endl;
                        break;
                    }
                    else{
                        st.push(board[i][j]); 
                        exit_flag=true;
                        cout << board[i][j] << endl;
                        board[i][j] = 0;
                        //cout << "pushed " << m  << " " << i << j << endl;
                        break;
                    }
                }
            }
            if(exit_flag){
                break;
            }
        }
    }
    
    // while(!st.empty()){
    //     cout << st.top() << endl;
    //     st.pop();
    // }
    
    
    return answer*2;
}