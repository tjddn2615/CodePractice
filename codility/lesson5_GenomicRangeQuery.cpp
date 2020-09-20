// you can use includes, for example:
#include <algorithm>
#include <iostream>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    
    vector<int> A(S.size() + 1, 0);
    vector<int> C(S.size() + 1, 0);
    vector<int> G(S.size() + 1, 0);
    
    vector<int> ans;
    
    int j = 1;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == 'A'){
            A[j]++;
        }
        else if(S[i] == 'C'){
            C[j]++;
        }
        else if(S[i] == 'G') {
            G[j]++;
        }
        A[j] += A[j-1];
        C[j] += C[j-1];
        G[j] += G[j-1];
        j++;
    }
    
    
    for(int i = 0; i < P.size(); i++){
        
        cout << P[1] << " " << Q[1] << endl;
        if(P[i]==Q[i]+1){
            if(S[P[i]] == 'A'){
                ans.push_back(1);
            }
            else if(S[P[i]] == 'C'){
                ans.push_back(2);
            }
            else if(S[P[i]] == 'G'){
                ans.push_back(3);
            }
            else {
                ans.push_back(4);                
            }
        }
        else if (A[P[i]] != A[Q[i]+1]) {
            ans.push_back(1);
        }
        else if(C[P[i]] != C[Q[i]+1]) {
            ans.push_back(2);
        }
        else if(G[P[i]] != G[Q[i]+1]) {
            ans.push_back(3);
        }
        else{
            ans.push_back(4);
        }
    }
    
    return ans;
}