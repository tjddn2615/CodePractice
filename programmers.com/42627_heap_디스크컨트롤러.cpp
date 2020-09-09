#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int size = jobs.size();
    //pair로 할 경우 앞에 것을 기준으로 정렬 됨
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    sort(jobs.begin(),jobs.end());

    int cnt = 0; // 작업 완료수
    int time = 0; // 시간
    int overall = 0; //평균내기 위한 시간
    int jc = 0;

    while(cnt < size) {
        
        if(jc < size && jobs[jc][0] <= time){
            pq.push(make_pair(jobs[jc][1], jobs[jc][0])); 
            //cout << jc << " push " << jobs[jc][0] << jobs[jc][1] << endl;
            jc++;
            continue;
        }
        
        if(!pq.empty()){
            cout << time << " + " << pq.top().first << " - " << pq.top().second << endl;
            overall += (time + pq.top().first - pq.top().second);
            time += pq.top().first;
            cnt++;
            //cout << "t: " << time << endl;
            pq.pop();
        }
        else{
            time = jobs[jc][0];
            //cout << "times gone" << endl;
        }
    }
    
    cout << overall << endl;
    
    
    return overall/size;
}