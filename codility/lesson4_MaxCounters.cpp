// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int maxv = 0;
    int cur_max = 0;
    vector<int> visit(N,0);
    
    
    for(int i = 0; i<A.size();i++){
        if(A[i] <= N){
            if(visit[A[i]-1] < maxv){
                visit[A[i]-1] = maxv;
            }
            
            visit[A[i]-1] += 1;    
            
            if(cur_max < visit[A[i]-1]){
                cur_max = visit[A[i]-1];
            }
        }
        else {
            maxv = cur_max;
        }
    }
    
    for(int i = 0; i<N;i++){
        if(visit[i] < maxv) {
            visit[i] = maxv;
        }
    }
    
    
    return visit;
    
    
    
    
}
