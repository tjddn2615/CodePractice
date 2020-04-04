#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int number;
vector<vector<int>> com;
int visited[200]={0};


int bfs(int src){
    
    queue<int > q;
    
    q.push(src);
    visited[src]=1;
    
    
    
    while(!q.empty()){
        int x=q.front();
        
        visited[x]=1;
		q.pop();
        
        for(int i=0;i<com.size();i++){

			int next=com[i][x];
            
            //cout << "x: "<< x << " " << "next: " << next << endl;
            //cout <<" in bfs: " << endl;
        	// for(int j=0;j<3;j++){
        	// cout << visited[j] << " ";
        	// }cout << endl;
            
            if (next==1 && visited[i]==0){
				q.push(i);
			}else{
                continue;
            }
        }

    }
    return 0;
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    number=n;
    com=computers;
    
    int i;
    
    for(i=0;i<computers.size();i++){
        if(visited[i]==0){
            
            // cout <<" before bfs: " << endl;
            // for(int j=0;j<3;j++){
            //     cout << visited[j] << " ";
            // }cout << endl;
            bfs(i);
            answer++;
        }else{
            continue;
        }
    }
    
    
    
    return answer;
}