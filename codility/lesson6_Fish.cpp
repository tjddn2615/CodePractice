// you can use includes, for example:
#include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    
    stack<int> st;
    
    
    for(int i = 0 ; i < A.size(); i++) {
        RE:
        if(!st.empty() && B[st.top()] == 1 && B[i] == 0 && A[i] < A[st.top()]) {
            cout << "1 " << i << endl;
            continue;
        }
        else if(!st.empty() && B[st.top()] == 1 && B[i] == 0 && A[i] > A[st.top()]) {
            cout << "2 " << i << endl;
            st.pop();
            if(B[st.top() == 1]){
                cout << "RE" << endl;
                goto RE;
            }
            st.push(i);
        }
        else {
            cout << "3 " << i << endl;
            st.push(i);
        }
        
    }
    


    return st.size();
    
    
}
