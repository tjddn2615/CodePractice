#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

int max_level;



int dfs(int x, int y, int visited[][8], int input[][8], int k, int kflag, int level){

	if(level>max_level){
		max_level=level;
	}

	visited[y][x]=1;

	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];

		if(input[ny][nx] < input[y][x] && input[ny][nx]>0){
			cout << "next is " << nx << " " << ny << ": " << input[ny][nx] << endl;
			cout << "level is " << level << endl;
			dfs(nx,ny,visited,input,k,kflag,level+1);
		}else if(input[ny][nx]-k < input[y][x] && kflag==0 && input[ny][nx]-k >0){
			dfs(nx,ny,visited,input,k,1,level+1);
		}else{
			continue;
		}
	}



	return 0;
}


int main(){


	int i,j,k;
	int T;


	cin >> T;

	cout << T << endl;

	for(i=0;i<T;i++){

		//input
		int n,k;
		int v_max=0; 
		int loc_max[2];//0=y 1=x
		max_level=0;

		cin >> n;
		cin >> k;

		int input[8][8];
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				cin >> input[j][k];
				if(input[j][k]>v_max){
					v_max=input[j][k];
					loc_max[0]=j;
					loc_max[1]=k;
				}
			}
		}


		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
			cout << input[j][k] << " ";
			}
			cout << endl;
		}


		int visited[8][8]= {0};

		dfs(loc_max[1], loc_max[0], visited, input, k, 0, 0);

		cout << "#" << i+1 << " " << max_level+1 << endl;
	}//test case end


	return 0;
}