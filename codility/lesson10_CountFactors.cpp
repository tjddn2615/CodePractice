// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    
    int ans = 0;
    
    for(int i = 1;i<=N;i++){
        if(N%i == 0) {
            ans++;
        }
    }
    
    return ans;
    
}