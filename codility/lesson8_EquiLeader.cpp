
// you can use includes, for example:
// #include <algorithm>
#include <map>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int ans=0;
    
    map<int,int> m;
    int maxv=0;
    int maxi=-1;
    
    for(int i = 0 ;i < A.size(); i++){
        if(m.count(A[i])){
            m[A[i]]++;
        }
        else {
            m.insert(make_pair(A[i], 1));
        }
        if(m[A[i]] > maxv) {
            maxv = m[A[i]];
            maxi = A[i];
        }
    }
    
    if(maxv <= A.size()/2) {
        cout << "ERROR" << endl;
        return 0;
    }
    
    
    int count = 0;
    for(int i = 0 ;i < A.size()-1; i++){
        if(A[i] == maxi) {
            count ++;
            m[maxi]--;
        }
        
        cout << "index " << A.size()-(i+1) << " " << (i+1) << endl;
        cout << "div/2 " << (A.size()-(i+1))/2 << " " << (i+1)/2 << endl;
        cout << "count " << m[maxi] << " " << count << endl;
        cout << endl;
        if(m[maxi] > (double)(A.size()-(i+1))/2 && count > (i+1)/2){
            cout << "answer " << i << " increase" << endl;
            ans ++;
        }
    }
    
    return ans;
    
}
