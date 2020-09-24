// you can use includes, for example:
#include <algorithm>
#include <map>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


int find_leader(vector<int> A, int start, int end) {
    
    map<int,int> m;
    int maxv=0;
    int maxa=-1;
    
    for(int i = start ;i < end; i++){
        if(m.count(A[i])){
            m[A[i]]++;
        }
        else {
            m.insert(make_pair(A[i], 1));
        }
        if(m[A[i]] > maxv) {
            maxv = m[A[i]];
            maxa = A[i];
        }
    }
    
    cout << "max: " << maxv << " " << maxa << endl;
    cout << end-start << endl;
    
    return maxv <= ((end-start)/2) ? -1 : maxa;
}



int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    int ans = 0;
    
    for(int i = 1 ;i < A.size(); i++){
        
        int tmp1 = find_leader(A, 0, i);
        int tmp2 = find_leader(A, i, A.size());
        
        cout << 0 << " " << i << " " << A.size() << endl; 
        cout << tmp1 << " " << tmp2 << endl;
        
        if(tmp1 == tmp2) {
            ans++;
        }
        
    }
    
    return ans;
    
}
