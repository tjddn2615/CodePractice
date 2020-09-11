#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;



int bfs (int start, vector<vector<bool>>& graph, vector<int>& dist) {

	queue<pair<int, int>> q;

	q.push(make_pair(start, 0));
	dist[start]=0;
	int maxv = 0;

	while(!q.empty()){
		int x = q.front().first;
		int level = q.front().second;
		//cout << x << " " << dist[x] << " " << level << endl;
		//dist[x] = dist[x]<0 ? level : min(dist[x], level);
		if(dist[x] > maxv) maxv=dist[x];

		for(int i = 0; i < graph.size(); i++){
			if(graph[x][i] && dist[i] == -1){
				q.push(make_pair(i, level+1));
				dist[i] = level+1;
				//cout << i << " " << level+1 << endl;
			}
		}
		q.pop();
	}

	return maxv;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<bool>> graph (n, vector<bool>(n, false));
	vector<int> dist;

    for(int i = 0;i < n;i++){
    	dist.push_back(-1);
    }

    for(auto e : edge){
    	graph[e[0]-1][e[1]-1] = true;
    	graph[e[1]-1][e[0]-1] = true;
    }


    int maxv = bfs(0, graph, dist);

    // cout << endl;

    // cout << endl;
    // for(int i = 0;i< n ; i ++){
    // 	for(int j = 0; j<n ; j++){
    // 		cout << graph[i][j] << " ";
    // 	}cout << endl;
    // }

    // for(int i = 0;i< dist.size() ; i ++){
    // 	cout << dist[i] << " ";
    // }cout << endl;

    //vector 최대값 algorithm 헤더 필요
    //int maxv = *max_element(dist.begin(), dist.end());

    for(int i = 0;i< dist.size() ; i ++){
    	if(dist[i] == maxv){
    		answer ++;
    	}
    }


    return answer;
}