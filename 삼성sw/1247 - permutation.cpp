#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct coor {
	int x;
	int y;
};
struct coor company;
struct coor house;
struct coor customer[10];
int cust_num;
int arr[10];


int main(){

	int t;
	int T;

	cin >> T;
	for(t=1;t<=T;t++){
		//initialization
		company.x=0;company.y=0;
		house.x=0;house.y=0;
		for(int i=0;i<10;i++){
			customer[i].x=0;customer[i].y=0;
		}
		cust_num=0;

		//input
		cin >> cust_num;
		cin >> company.x >> company.y;
		cin >> house.x >> house.y;
		for(int i=0;i<cust_num;i++){
			cin >> customer[i].x >> customer[i].y;
			arr[i]=i;
		}

		int com_dist[10], house_dist[10];
		int cus_dist[10][10];

		// (x1, y1)와 (x2, y2) 의 거리는?
		// |x1-x2| + |y1-y2|
		for(int i=0;i<cust_num;i++){
			com_dist[i]=abs(company.x-customer[i].x)+abs(company.y-customer[i].y);
			house_dist[i]=abs(house.x-customer[i].x)+abs(house.y-customer[i].y);
		}
		for(int i=0;i<cust_num;i++){
			for(int j=0;j<cust_num;j++){
				cus_dist[i][j]=abs(customer[i].x-customer[j].x)+abs(customer[i].y-customer[j].y);
				//cout << i << "," << j << " : " << cus_dist[i][j] << endl;
			}
		}

		int ans=999999999;
		do{
			int sum=0;
			sum+=com_dist[arr[0]];
			sum+=house_dist[arr[cust_num-1]];
			//cout << com_dist[arr[0]] << " " << house_dist[arr[cust_num-1]] << endl;
			for (int i = 0; i < cust_num-1; ++i){
			//	cout << arr[i] << ">" << arr[i+1] << " : " << cus_dist[arr[i]][arr[i+1]] << endl;
				sum+=cus_dist[arr[i]][arr[i+1]];
			}
			ans = min(ans, sum);
		}while(next_permutation(arr, arr+cust_num));

		cout << "#" << t << " " << ans <<  endl;

	}	


	return 0;
}
