// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int sum1=0;
    
    for(int i = 0; i < A.size();i++){
        sum1+=i+1;
        sum1-=A[i];
    }
    sum1 += A.size()+1;
    
    return sum1;
    
}