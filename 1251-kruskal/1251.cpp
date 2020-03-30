#include <iostream>
#include <stdlib.h>//abs()
#include <cmath>//pow()
#include <algorithm>//sort()
#include <vector>

//https://mattlee.tistory.com/47


using namespace std;

int parent[1001];
int num[1001];

struct Edge {
	int src, dest;
	long long value;
};

int set_init(int n){

	int i;

	for(i=0;i<n;i++){
		parent[i]=-1;
		num[i]=1;
	}
}

int set_find(int node){

	int p, root, i=-1;
	
	for(i=node;(p=parent[i])>=0;i=p);

	root=i;

	for(i=node; (p=parent[i])>=0; i=p){
		parent[i]=root;
	}

	return root;
}

void set_union(int s1, int s2){

	if (num[s1] < num[s2]){
		parent[s1]=s2;
		num[s2] += num[s1];
	}else{
		parent[s2]=s1;
		num[s1] += num[s2];
	}


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
		// cout << island_num << endl;
		// for(i=0;i<island_num;i++){
		// 	cout << island_pos[i][0] << endl;
		// }
		// for(i=0;i<island_num;i++){
		// 	cout << island_pos[i][1] << endl;
		// }
		// cout << E << endl;


		//what I have to find:
		//E * L^2
		//제곱이라는 말은 
		// |x2-x1| + |y2-y1|
		// abs(x2-x1) + abs(y2-y1)

		//kruskal algorithm

		set_init(island_num);

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

		//cout << "sorted" << endl;
		// for(i=0;i<v.size();i++){
		// 	cout << "test: " << v[i].src << " > " << v[i].dest << " = " << v[i].value << endl; 
		// }

		//값
		long long sum=0;

		//kruskal
		for(i=0;i<v.size();i++){

			int sset = set_find(v[i].src);
			int dset = set_find(v[i].dest);

			//edge가 만나지 않으므로 합친다.
			if(sset!=dset){
				sum+=v[i].value;
				//cout << "sum: " << sum << endl;
				set_union(sset,dset);
			}
		}
		//cout << fixed;
		///cout.precision(0);
		//cout << "#" << T << " " << sum*E << endl;
		printf("#%d %.0lf\n", T, sum*E);

	}//test case



	return 0;
}
