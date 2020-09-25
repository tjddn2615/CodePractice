// you can use includes, for example:
#include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//카데인 알고리즘
//부분합들 중 최대 부분합 구하기

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    vector<int> first(A.size(), 0);
    vector<int> second(A.size(), 0);
    
    for(int i = 1 ; i < A.size()-1; i++) {
        
        first[i] = max(first[i-1] + A[i], 0);
        int index = A.size()-i-1;
        second[index] = max(second[index+1] + A[index], 0);
        
    }
    
    int maxv = 0;
    for(int i = 1 ; i < A.size()-1; i++) {
        maxv = max(first[i-1]+second[i+1], maxv);
    }
    
    return maxv;
}