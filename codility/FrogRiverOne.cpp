// you can use includes, for example:
#include <algorithm>
#include <set>
#include <iostream>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    
    set<int> s;
    
    for(int i = 0; i< A.size();i++){
        if(!s.count(A[i])){
            s.insert(A[i]);
        }
        if(s.size() == X){
            return i;
        }
    }
    
    
    
    return -1;
    
    
    
    // write your code in C++14 (g++ 6.2.0)
}
