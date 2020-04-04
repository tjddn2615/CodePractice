#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int i,j;
    
    queue<pair<int,int>> q;
    vector<int> sorted=priorities;
    
    sort(sorted.begin(),sorted.end(), greater<int>());
    
    for(i=0;i<sorted.size();i++){
        cout << sorted[i] << " ";
    }cout <<endl;
    
    for(i=0;i<priorities.size();i++){
        if(i==location){
            q.push(make_pair(priorities[i],1));
        }else{
            q.push(make_pair(priorities[i],0));
        }
    }
    
    int current=0;
    
    while(!q.empty()){
        if(q.front().first==sorted[current]){
            
            if(q.front().second==1){
                current++;
                return current;
            }
            
            //cout << "yes" << endl;
            current++;
            q.pop();
        }else{
            q.push(q.front());
            q.pop();
        }
        
    }
    //cout << "current " << current << endl;
    
    
    
    
    return answer;
}