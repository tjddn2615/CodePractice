// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    for(int i = 0; i<A.size();i++){
        if(A[i] == X){
            return i;
        }
    }
}
