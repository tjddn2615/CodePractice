// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int ans = 0;
    
    for(int i = 0; i < A.size(); i++ ){
        ans ^= A[i];
    }
    
    
    
    
    return ans;
}