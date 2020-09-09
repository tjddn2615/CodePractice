#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(),routes.end());
    
   int end = routes[0][1];
    
    for (auto route : routes) {
        if (route[0] > end) {
            answer++;
            end = route[1];
        }
        if (route[1] <= end) {
            end=route[1];
        }
        
    }
    
    
    return answer;
}