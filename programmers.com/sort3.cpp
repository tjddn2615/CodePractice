#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
        
    int i,j;
    
    
    int n=citations.size();
    
    
    
    for(i=n;i>-1;i--){
        int cited=0;
        for(j=0;j<n;j++){
            if(citations[j]>=i){
                cited++;
            }
        }
        if(cited>=i){
           // cout << "i: " << i << " | " << "cited: " << cited << endl;
            return i;   
        }
        
    }
    
    
    
    return answer;
}