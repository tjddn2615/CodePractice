#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    long long tmp = sqrt(n);
    //cout << tmp << endl;
    
    if(tmp < 0){
        return -1;
    }
    
    if(tmp*tmp == n){
        answer = (tmp+1)*(tmp+1);
    }else{
        return -1;
    }
    
    
    return answer;
}