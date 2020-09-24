// you can use includes, for example:
#include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

void printstack(stack<int> st) {
    
    while(!st.empty()) {
        cout << st.top() << " " ;
        st.pop();
    }cout << endl;
}



int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    
    stack<int> st;
    
    for(int i = 0 ; i < A.size(); i++) {
    
        bool flag = true;
        
        if(B[i] == 1) {
            st.push(i);
        }
        else if(B[i] == 0) {
            if(B[st.top()] == 1){
                while(!st.empty()) {
                    if(A[i] > A[st.top()] && B[st.top()] == 1) {
                        st.pop();
                    }
                    else if(B[st.top()] == 0){
                        break;
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    st.push(i);
                }
            }else {
                st.push(i);
            }
        }
    }
    


    return st.size();
}