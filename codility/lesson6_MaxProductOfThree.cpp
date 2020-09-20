// // you can use includes, for example:
// #include <algorithm>
// #include <queue>
// #include <cmath>
// // you can write to stdout for debugging purposes, e.g.
// // cout << "this is a debug message" << endl;

// bool compare(int a, int b){
//     return abs(a) > abs(b);
// }


// int solution(vector<int> &A) {
//     // write your code in C++14 (g++ 6.2.0)
    
//     sort(A.begin(), A.end(), compare);
    
//     int end = A.size()-1;

//     for(int i = 0; i < A.size(); i++) {
//         for(int j = i+1; j < A.size(); j++) {
//             for(int k = j+1; k < A.size(); k++) {
//                 if( A[i] * A[j] * A[k] > 0) {
//                     return (A[i] * A[j] * A[k]);
//                 }
//             }
//         }
//     }
    
//     return (A.at(end) * A.at(end-1) * A.at(end-2));
    
// }


// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int end = A.size() - 1;
    
    sort(A.begin(), A.end(), greater<int>());
    
    int plus = A.at(1) * A.at(2);
    int minus = A.at(end) * A.at(end-1);
    
    cout << "plus: " << plus << endl;
    cout << "minus: " << minus << endl;
    
    if(minus > plus) {
        if(A.at(0) < 0) {
            return plus * A.at(0);
        }else{
            return minus * A.at(0);
        }
    }
    else  {
        return plus * A.at(0);
    }
    
}