#include <iostream>

using namespace std;

int main(){
	int i,j,k,test_case;
	int num;
	int arr[100][100];
	int check[100][100];
	int x;
	int start;
	int currentx,currenty;


	for(test_case=0;test_case<10;test_case++){
		cin>>num;
		x=0;start=0,currentx=0,currenty=0;

		for(i=0;i<100;i++){//initialize
			for(j=0;j<100;j++){
				check[i][j]=0;
			}
		}

		for(i=0;i<100;i++){//input
			for(j=0;j<100;j++){
				cin>>arr[i][j];
			}
		}

		for(i=0;i<100;i++){//find 2
			if(arr[99][i]==2){
				x=i;
			}
		}

		//move
		currentx=99;currenty=x;
		check[currentx][currenty]=1;
		while(currentx>0){
			if(arr[currentx][currenty-1]==1 && check[currentx][currenty-1]==0 && currenty > 0 && currentx >= 0 && currentx <= 99){
				currenty--;
			}else if(arr[currentx][currenty+1]==1 && check[currentx][currenty+1]==0 && currenty < 99 && currentx >= 0 && currentx <= 99){
				currenty++;
			}else{
				currentx--;
			}
			check[currentx][currenty]=1;
			//cout << currentx << " : " << currenty << endl;
		}
		start=currenty;

		cout <<"#"<<test_case+1<<" "<< start << endl;

	}

	return 0;

}
