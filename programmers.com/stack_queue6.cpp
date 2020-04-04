#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int i,j;
    
    for(i=0;i<prices.size();i++){
        
        for(j=i+1;j<prices.size();j++){
            if(prices[i]>prices[j] || j==prices.size()-1){
                cout << j << " - " << i << endl;
                answer.push_back(j-i);
                break;
            }
        }
        
    }
    answer.push_back(0);
    
    
    return answer;
}