// you can use includes, for example:
#include <algorithm>
#include <stack>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    
    stack<char> st;
    
    
    for(auto c : S) {
        if( !st.empty() && c == ')' && '(' == st.top()){
            st.pop();
        }
        else if( !st.empty() && c == '}' && '{' == st.top()){
            st.pop();
        }
        else if( !st.empty() && c == ']' && '[' == st.top()){
            st.pop();
        }
        else{
            st.push(c);
        }
    }
    
    
    if(st.empty()){
        return 1;
    }
    else {
        return 0;
    }
    
}
