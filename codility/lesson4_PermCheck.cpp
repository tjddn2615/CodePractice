// you can use includes, for example:
#include <set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    set<int> s1;
    set<int> s2;
    
    for(int i = 0; i < A.size(); i++){
        
        s1.insert(i+1);
        
        if(s2.count(A[i])){
            return 0;
        }
        s2.insert(A[i]);
    }
    
    for(auto i = s1.begin(), j = s2.begin(); i != s1.end(), j != s2.end(); i++,j++){
        //cout << *i << " " << *j << endl;
        if(*i != *j){
            return 0;
        }
    }
    return 1;
    
}