#include <string>
#include <vector>
#include <queue>
#include <iostream>


using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int i,j;
    
    queue<int> q; //truck_weight,time_cnt
    
    int current_s=0;
    int current_e=0;
    int total_weight=0;
    vector<int> time; //truck들의 시간
    
    // for(i=0;i<truck_weights.size();i++){
    //     time.push_back(0);
    // }
    
    q.push(truck_weights[current_s]);
    time.push_back(1);
    total_weight+=truck_weights[current_s];
    current_s++;
    answer++;
    
    int tmp=truck_weights.size();
   // cout << "tmp " << tmp << endl; 
    while(current_e < truck_weights.size()){
        
        for(i=current_e;i<time.size();i++){
            if(time[i]>=bridge_length){
                //cout << "output: " << q.front() << endl;
                total_weight-=q.front();
                current_e++;
                q.pop();
            }
            time[i]+=1;        
        }
        
        if(total_weight+truck_weights[current_s]<=weight){
            //cout << "input: " << truck_weights[current_s] << endl;
            q.push(truck_weights[current_s]);
            time.push_back(1);
            total_weight+=truck_weights[current_s];
            current_s++;
        }
        
        answer++;
        //check
        
        // for(i=0;i<time.size();i++){
        //     cout << time[i] << ";";       
        // } cout << endl;
        
    }
    
    
    
    
    return answer;
}