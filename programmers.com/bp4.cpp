#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    
    int i,j;
    
    for(i=0;i<5000;i++){
        for(j=0;j<5000;j++){
            if(brown+red==i*j){
                if((brown/2)+1 == i+j-1){
                    answer.push_back(i);
                    answer.push_back(j);
                    goto FINISH;
                }
            }
        }
    }
    FINISH:
    
    sort(answer.begin(),answer.end(), greater<int>());
    
    
    return answer;
}