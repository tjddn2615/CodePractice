// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    sort(A.begin(), A.end());
    
    bool flag = true;
    for(int i = 0 ; i < A.size(); i++) {
        for(int j = i+1; j < i+2; j++) {
            for (int k = j+1; k < j+2; k++) {
                flag = true;
                //cout << A[i] << " " << A[j] << " " << A[k] << endl;
                
                if(A[i] <= A[k] - A[j]) {
                    flag = false;
                }
                if(A[j] <= A[i] - A[k] ) {
                    flag = false;
                }
                if(A[i]<= A[j] - A[k] ) {
                    flag = false;
                }
                
                if(flag) {
                    return 1;
                }
            }
        }
    }
    
    
    return 0;
    
}