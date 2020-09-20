// you can use includes, for example:
// #include <algorithm>
#include <set>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    set<int> s;
    
    for(int i = 0; i<A.size(); i++){
        if(A[i] < 0){
            continue;
        }else{
            s.insert(A[i]);
        }
    }
    
    
    int cnt = 1;
    for(auto i = s.begin(); i != s.end(); i++){
        if(*i == cnt){
            cnt++;
        }else{
            return cnt;
        }
    }
    
    if(cnt > 1){
        return cnt;
    }else{
        return 1;    
    }
    
    
}
