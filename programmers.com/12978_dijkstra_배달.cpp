#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dist(51, 0);
//int dist[51];
const int INF = 987654321;

vector<pair<int,int>> adj[51];

void dijkstra(int N){
    for(int i = 1; i<=N ; i++){
        dist[i] = INF;
    }
    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(0,1));
    dist[1] = 0;    

    // int start = 1;
    // dist[start] = 0;
    // pq.push(make_pair(dist[start], start));
    
    while(!pq.empty()){
        int cost = (-pq.top().first);
        int node = (pq.top().second);
        pq.pop();
        
        //원래 값을 넘으면 계산 필요 X
        if(cost > dist[node]){
            continue;
        }
        
        for(int i = 0; i < adj[node].size(); i++){

            int next_node = adj[node][i].first;
            int next_cost = adj[node][i].second + cost;

            if(next_cost < dist[next_node]){
                cout << "connected" << endl;
                dist[next_node] = next_cost;
                pq.push(make_pair(-next_cost, next_node));
            }
        }
    }
}


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    // {   {} {}
    //     {} {} // 상하로 51개가 들어감 , 노드수 각 노드마다 연결된 최대 가능 노드 수가 51개
    //     {} {}
    // }
    
    for(int i = 0; i< road.size(); i++){
        int from, to, cost;
        from = road[i][0];
        to = road[i][1];
        cost = road[i][2];
        //cout << "input: " << from << " " << to << " " << cost << endl;
        adj[from].push_back(make_pair(to, cost));
        adj[to].push_back(make_pair(from, cost));
    }
    
    dijkstra(N);
    
    for(int i = 1;i <= N; i++){
        cout << dist[i] << " " << i << endl;
        if(dist[i] <= K){
            cout << "match" << i << endl;
            answer++;
        }
    }
    
    return answer;
}