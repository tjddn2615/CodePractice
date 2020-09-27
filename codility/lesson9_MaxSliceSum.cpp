// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    vector<int> dp(A.size(), 0);
    int maxv = A[0];
    dp[0] = A[0];
    for(int i = 1 ; i< A.size(); i++) {
        dp[i] = max(A[i], A[i] + dp[i-1]);
        if(dp[i] > maxv) {
            maxv = dp[i];
        }
    }
    return maxv;
    
}