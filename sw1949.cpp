#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(){




	return 0;
}


int main(){


	int i,j,k;
	int T;


	cin >> T;


	for(i=0;i<T;i++){

		//input
		int n,k;
		int v_max=0; 
		int x_max, y_max;

		cin >> n;
		cin >> k;

		int input[8][8];
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				cin >> input[j][k];
				if(input[j][k]>v_max){
					v_max=input[j][k];
					x_max=k;
					y_max=j;
				}
			}
		}





	}//test case end


	return 0;
}