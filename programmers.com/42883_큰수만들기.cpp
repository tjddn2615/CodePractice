#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<int> st;
    int target_size = number.size()-k;
    
    int i;
    for(i=0;i<number.size();i++){
        int tmp = number[i] - '0';
        while(!st.empty() && k > 0){
            int st_top = st.top();
            if(st_top < tmp){
                st.pop();
                k--;
            }
            else{
                break;
            }
        }
        st.push(tmp);
    }
    
    while(st.size() != target_size) st.pop();
    
    while(!st.empty()){
        answer += to_string(st.top());
        st.pop();
    }
    
    reverse(answer.begin(),answer.end());
    
    return answer;
}