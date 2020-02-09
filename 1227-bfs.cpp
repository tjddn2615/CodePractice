#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
 
using namespace std;
 
 
char input[100][100];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
 
 
int bfs(int src){
	//cout <<"bfs in"<< endl;
	queue<pair<int, int> > q;
	int visited[100][100]={0};

	for(int i=0;i<100;i++){
		visited[0][i]=1;
		visited[99][i]=1;
		visited[i][0]=1;
		visited[i][99]=1;
	}

	q.push(make_pair(1,1));
	visited[1][1] = 1;

	while(!q.empty()){
		int y=q.front().first;
		int x=q.front().second;
		visited[y][x]=1;
		q.pop();
		//cout <<y <<";" <<x <<endl;
		for(int i=0;i<4;i++){

			int nexty=y+dy[i];
			int nextx=x+dx[i];

			if (input[nexty][nextx]=='3')	{
				return 1;
			}

			if (input[nexty][nextx]=='0' && visited[nexty][nextx]==0){
				q.push(make_pair(nexty,nextx));	
			}
		}

	}
	return 0;
}
 
int main(){

	int T;
	int test_case;
	int i,j;

	int tmp1, tmp2;
	int flag;

	for(test_case=1;test_case<=10;test_case++){
		flag=0;
		cin >> T;
		memset(input, '0', 100*100);
		for(i=0;i<100;i++){
			cin >> input[i];
		}
		flag=bfs(0);

		cout << "#" << test_case << " " << flag << endl;
	}
	return 0;
}
