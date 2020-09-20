// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


// slice 만들시 2 혹은 3까지만 최소의 값이다.
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    double mini=0;
    double minv = 99999;
    
    for(int i = 0; i < A.size(); i++){
        
        double two;
        double three;
        if(i+1 < A.size()){
            two = (A[i] + A[i+1]) / 2.0;
        }
        if( i+2 < A.size()){
            three = (A[i] + A[i+1] + A[i+2]) / 3.0;
        }
        
        if(two < minv) {
            minv = two;
            mini = i;
        }
        if( three < minv){
            minv = three;
            mini =i;
        }
        
    }
    
    return mini;
    
}