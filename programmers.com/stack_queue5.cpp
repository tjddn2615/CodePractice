#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <string>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<int> s;
    
    int i;
    
    const char* input = arrangement.c_str();
    
    
    //input check
    // for(i=0;i<arrangement.size();i++){
    //     cout <<input[i] << " ";
    // } cout << endl;
    
    int flag=0;
    for(i=0;i<arrangement.size();i++){
        if(input[i]=='('){
            s.push('(');
            flag=1;
        }else if(input[i]==')' && flag==1){
            s.pop();
            answer+=s.size();
            flag=0;
        }else if(input[i]==')' && flag==0){
            s.pop();
            answer+=1;
            flag=0;
        }
        
    }
    
    
    
    
    return answer;
}