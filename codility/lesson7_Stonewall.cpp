#include <stack>

int solution(vector<int> &H) {
    // write your code in C++14 (g++ 6.2.0)
    
    stack<int> st;
    int ans = 0;
    
    for(int i = 0; i < H.size(); i++) {
        
        while(!st.empty() && st.top() > H[i]) {
            cout << "pop " << st.top() << endl;
            st.pop();
        }
        if(st.empty() || st.top() < H[i]) {
            cout << "new push" << H[i] << endl;
            st.push(H[i]);
            ans++;
        }
        
    }
    
    return ans;
}