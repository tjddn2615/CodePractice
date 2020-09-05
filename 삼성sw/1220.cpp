#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {

	int input[101][101];

	for(int t=1;t<=10;t++){
		int tmp;
		cin >> tmp;
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				scanf("%d", &input[i][j]);
			}
		}

		// for(int i=0;i<100;i++){
		// 	for(int j=0;j<100;j++){
		// 		cout << input[i][j];
		// 	}
		// 	cout << endl;
		// }

		int count=0;
		for(int j=0;j<100;j++){
			int flag=0;
			for(int i=0;i<100;i++){
				
				if(input[i][j]==0){
					continue;
				}else if(input[i][j]==2 && flag==1){
					count++;
					flag=0;
				}else if(input[i][j]==2 && flag==0){
					continue;
				}else if(input[i][j]==1){
					flag=1;
				}
			}
		}
		cout << "#" << t << " " << count <<endl;
	}
	return 0;
}