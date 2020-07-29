#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(int x) {
    bool answer = true;
    
    int origin=x;
    int flag=0;
    int sum=0;
    
    while(1){
        
        if(x%10==x){
            sum+=x;
            break;
        }
        sum+=(x%10);
        x/=10;
    }
    
    if(origin%sum==0){
        answer=true;
    }else{
        answer=false;
    }
    
    return answer;
}