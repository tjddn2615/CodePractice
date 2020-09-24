// you can use includes, for example:
#include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    
    stack<char> st;
    
    
    for(auto c : S) {
        if(c== '(') {
            st.push('(');
        } // ')';
        else if(!st.empty() && st.top() == '(' ) {
            st.pop();
        }
        else{
            st.push(')');
        }
    }
    
    return st.size()==0 ? 1 : 0;

}