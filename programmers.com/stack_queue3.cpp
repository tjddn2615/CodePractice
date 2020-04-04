#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> complete;
    int completed=0;
    int stacked=0;
    
    int i,j;
    
    int time_tmp=0;
    
    
    while(1){
        if(completed>=progresses.size()){
            break;
        }
        
        for(i=0;i<progresses.size();i++){
            if(progresses[i]>0){
                progresses[i]+=speeds[i];
            }
            if(progresses[i]>=100){
                stacked++;
                progresses[i]=-1;
                cout << "stacked++: " << stacked << endl;
            }
        }
        
        if(progresses[completed]==-1){
            cout << "completed: " << stacked << endl;
            
            
            //확인 후 넘겨짐
            int publish=0;
            for(i=completed;i<progresses.size();i++){
                if(progresses[i]==-1){
                    progresses[i]=-2;
                    publish++;
                }else{
                    break;
                }
            }
            answer.push_back(publish);
            stacked-=publish;
            completed+=publish;
        }else if(progresses[completed]==-2){
            completed++;
        }
        
        for(i=0;i<progresses.size();i++){
            cout << progresses[i] << " ";
        }cout << endl;
    }
    
    
    return answer;
}