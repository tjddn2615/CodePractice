// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void over(vector<int> & ans, int maxv){
    for(auto & a : ans){
        a = maxv;
    }
}



vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    vector<int> ans(N, 0);
    int maxv =0;
    
    
    for(int i = 0;i<A.size();i++){
        if(A[i] >=1 && A[i] <= N) {
            ans[A[i]-1]++;
            if(ans[A[i]-1] > maxv ){
                maxv = ans[A[i]-1];
            }
        }else{
            over(ans, maxv);
        }
    }
    
    return ans;
    
}
