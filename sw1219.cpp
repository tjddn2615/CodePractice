#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;


int input[100][100]={-1};


int bfs(int src){
	queue<int> q;
	int visited[100]={0};

	q.push(src);
	visited[src] = 1;

	while(!q.empty()){
		int current=q.front();
		q.pop();

		for(int next=0; next<101;next++){
			if(input[current][next] == 1 && visited[next]==0){
				visited[next]=1;
				//cout << current << "->" << next << endl;
				if(next==99){
					return 1;
				}
				q.push(next);
			}
		}

	}
	return 0;
}

int main(){

	int T;
	int test_case;
	int i,j;

	int len;
	int tmp1, tmp2;
	int flag;

	for(test_case=1;test_case<=10;test_case++){
		flag=0;
		for(i=0;i<100;i++){
			for(j=0;j<100;j++){
				input[i][j]=0;
			}
		}
		scanf("%d %d", &T, &len);
		for(i=0;i<len;i++){
			scanf("%d %d", &tmp1, &tmp2);
			input[tmp1][tmp2]=1;
		}
		flag=bfs(0);

		cout << "#" << test_case << " " << flag << endl;
	}	
	

	return 0;
}
