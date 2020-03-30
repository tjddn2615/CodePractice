#include <iostream>
#include <stdlib.h>//abs()
#include <cmath>//pow()
#include <algorithm>//sort()
#include <vector>

using namespace std;

struct Edge {
	int src, dest;
	long long value;
};

int set_find(int node){

	int parent,
	

}





bool cmp(const Edge &  a, const Edge & b){
	if(a.value < b.value){
		return true;
	}
	return false;
}

int main(){

	int T,Test_case;
	int t,i,j;

	cin >> Test_case;
	for(T=1;T<=Test_case;T++){

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

		//input check
		cout << island_num << endl;
		for(i=0;i<island_num;i++){
			cout << island_pos[i][0] << endl;
		}
		for(i=0;i<island_num;i++){
			cout << island_pos[i][1] << endl;
		}
		cout << E << endl;



		//what I have to find:
		//E * L^2
		//제곱이라는 말은 
		// |x2-x1| + |y2-y1|
		// abs(x2-x1) + abs(y2-y1)

		//kruskal algorithm

		//every edge value input
		for(i=0;i<island_num;i++){
			for(j=i+1;j<island_num;j++){
				edge.src=i;
				edge.dest=j;
				edge.value = pow(abs(island_pos[i][0]-island_pos[j][0]),2) + pow(abs(island_pos[i][1]-island_pos[j][1]),2);
				v.push_back(edge);//v[i].src, v[i].dest, v[i].value
			}
		}

		//kruskal edge input check
			// for(i=0;i < v.size();i++){
			// 	cout << "test: " << v[i].src << " > " << v[i].dest << " = " << v[i].value << endl; 
			// }

		sort(v.begin(), v.end(), cmp);

		cout << "sorted" << endl;

		for(i=0;i<v.size();i++){
			cout << "test: " << v[i].src << " > " << v[i].dest << " = " << v[i].value << endl; 
		}

		//kruskal
		for(i=0;i<v.size();i++){

			int sset = set_find(v[i].src);
			int dset = set_find(v[i].dest);

			if(sset!=dset){
				//edge가 만나지 않으므로 합친다.
				sum+=v[i].value;
				set_union(sset,dset);
			}


		}


	}



	return 0;
}