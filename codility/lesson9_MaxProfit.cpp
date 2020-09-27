// you can use includes, for example:
#include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int size = A.size();
    vector<int> dp(size, 0);
    int minv = A[0];
    
    int max_profit = 0;
    
    for(int i = 1; i < size; i++){
        
        int tmp = A[i] - minv;
        
        if(minv > A[i]) {
            minv = A[i];
        }

        if(tmp > max_profit) {
            max_profit = tmp;
        }

    }
    
    
    
    return max_profit;
}