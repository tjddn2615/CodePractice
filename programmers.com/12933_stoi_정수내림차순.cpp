#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string tmp = "";
    
    priority_queue<int, vector<int>, less<int>> pq;
    
    while (n != 0) {
        pq.push(n%10);
        n /= 10;
    }
    
    while(!pq.empty()){
        tmp += to_string(pq.top());
        //cout << tmp << endl;
        pq.pop();
    }
    
    
    return stol(tmp);
}