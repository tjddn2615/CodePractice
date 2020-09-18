// you can use includes, for example:
#include <algorithm>
#include <cmath>
#include <numeric>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    //accumulate(vi1.begin(), vi1.end(), 1, multiplies<int>())
    //누적곱
    int sum = accumulate(A.begin(),A.end(),0);
    int left = 0;
    int right = sum;
    int minv = 999999;
    
    for(int i = 0 ; i < A.size()-1;i++) {
        left+=A[i];
        right-=A[i];
        //cout << abs(right-left) << endl;
        if(minv > abs(right-left)){
            minv = abs(right-left);
            //cout << "changed: " << maxi << endl;
        }
    }
    return minv;
}
