#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int input[101][101]={0};

int bfs(int src){
	int visited[101]={0};

	queue<int> q;
	queue<int> level;
	int last_level;

	q.push(src);
	visited[src]=0;
	level.push(1);

	while(!q.empty()){
		int current=q.front();
		int cur_level=level.front();
		q.pop();
		level.pop();

		for(int next=1; next<101;next++){
			if(input[current][next]==1 && visited[next]==0){
				visited[next]=cur_level;
				q.push(next);
				level.push(cur_level+1);
				last_level=cur_level+1;
			}
		}
	}

	int max_level=0;
	int max_node=0;
	for (int i = 0; i < 101; ++i){
		if(visited[i]>=max_level){
			max_level=visited[i];
			if (i>max_node){
//				printf("max_level: %d\n", max_level);
//				printf("max node changed from %d to %d\n", max_node, i);
				max_node=i;
			}
		}
	}
	// for (int i = 0; i < 101; ++i){
	// 	printf("%d:%d\n", i,visited[i]);
	// }
	return max_node;
}

int main(){

	int t,i,j,k;
	int start;
	int num;
	int tmp1,tmp2;

	for(t=1;t<=10;t++){
		memset(input, 0, sizeof(input));
		
		cin >> num >> start;
		for (i = 0; i < num/2; i++){
			cin >> tmp1;
			cin >> tmp2;
			input[tmp1][tmp2]=1;
		}
//		for (i = 0; i < 100; i++){
//			for(j=0;j<100;j++){
//				cout << input[i][j];
//			}
//			cout << endl;
//		}

		int ret=bfs(start);
		cout << "#" << t << " " << ret << endl;

	}
	return 0;
}
