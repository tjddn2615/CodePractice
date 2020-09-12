#include <vector>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

int bfs (int y, int x, vector<vector<int>>& visit, vector<vector<int>> picture, int color) {
	queue<pair<int,int>> q;
	int n_color = 1;

	//cout << "bfs start!!! " << y << " " << x << "                !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	q.push(make_pair(y,x));
	visit[y][x] = 1;

	while(!q.empty()){

		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();

		//cout << "cyx : " << cy << " " << cx << " " << picture[cy][cx] << endl;
		for(int i = 0;i < 4;i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			//cout << "dxy: " << dy[i] << " " << dx[i] << endl;
			if (nx >= 0 && nx < visit[0].size() && ny >= 0 && ny < visit.size()) {
					//cout << ny << " " << nx << endl;
					//cout << "visit : "  << visit[ny][nx] << endl;

				if (picture[ny][nx] == color && visit[ny][nx] == 0) {
					//cout << "nyx: " << ny << " " << nx << endl;
					//cout << "color : "  << color << " pic:" << picture[ny][nx] << endl;
					q.push(make_pair(ny,nx));
					visit[ny][nx] = 1;
					n_color++;
				}

			}
		}
	}

	return n_color;
}



// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer;
    int maxv = 0;
    int overall = 0;

    vector<vector<int>> visit(m, vector<int> (n, 0));

    for (int i = 0 ; i < picture.size(); i++) {
    	for (int j = 0 ; j < picture[i].size(); j++) {
    		//cout << "color : " << picture[i][j] << endl;
    		if (visit[i][j] == 0 && picture[i][j] != 0){
    			overall ++;
    			int tmp = bfs (i, j, visit, picture, picture[i][j]);
    			if(tmp > maxv){
    				maxv = tmp;
    			}
    		}
    	}
    }

    //cout << maxv << endl;

    answer.push_back(overall);
    answer.push_back(maxv);


    return answer;
}