#include <iostream>
#include <stdlib.h>//abs()
#include <cmath>//pow()

using namespace std;

struct Edge {
	int src, dest;
	long long value;
};


int main(){

	int T;
	int t,i,j;


	for(T=1;T<=10;T++){

		int island_num;
		long long island_pos[1001][2];
		double E;

		vector<Edge> v;
		Edge edge;

		//input
		cin >> island_num;
		for(i=0;i<island_num;i++){
			cin >> island_pos[i][0];
		}
		for(i=0;i<island_num;i++){
			cin >> island_pos[i][1];
		}
		cin >> E;

		//what I have to find:
		//E * L^2
		//제곱이라는 말은 
		// |x2-x1| + |y2-y1|
		// abs(x2-x1) + abs(y2-y1)

		//kruskal algorithm

		//every edge value
		for(i=0;i<island_num;i++){
			for(j=i+1;j<island_num;j++){
				edge.src=i;
				edge.dest=j;
				edge.value = pow(abs(island_pos[i][0]-island_pos[j][0]),2) + pow(abs(island_pos[i][1]-island_pos[j][1]),2);
				v.push_back(edge);//v[i].src, v[i].dest, v[i].value
			}
		}


		for(i=0;i<island_num-1;i++){
			cout << "test: " << v[i].src << " > " << v[i].dest << " = " << v[i].src << endl; 
		}


	}



	return 0;
}