#include <iostream>

using namespace std;

int main(){
	int i,j,k,test_case;
	int num;
	int arr[100][100];
	int check[100][100];
	int start[100]={0};
	int start_num=0;
	int currentx=0;
	int currenty=0;

	int count=0;
	int min_count=999999;
	int min_pos=0;
	int pos;

	for(test_case=0;test_case<10;test_case++){
		cin>>num;
		start_num=0;
		min_count=999999;
		min_pos=0;
		for(i=0;i<100;i++){//input
			for(j=0;j<100;j++){
				cin>>arr[i][j];
			}
		}

		for(i=0;i<100;i++){//find start point
			if(arr[99][i]==1){
				start[start_num]=i;
				start_num++;
			}
		}

		/*for(i=0;i<start_num;i++){
			cout << start[i] << endl;
		}*/

		for(i=0;i<start_num;i++){
			//cout << "start!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			currentx=0,currenty=0;
			
			for(k=0;k<100;k++){//initialize
				for(j=0;j<100;j++){
					check[k][j]=0;
				}
			}

			//move
			currentx=99;currenty=start[i];
			check[currentx][currenty]=1;
			count=0;
			while(currentx>0){
				if(arr[currentx][currenty-1]==1 && check[currentx][currenty-1]==0 && currenty > 0){
					currenty--;
					//cout << "cury- " << currentx << " : " << currenty << endl;
				}else if(arr[currentx][currenty+1]==1 && check[currentx][currenty+1]==0 && currenty < 99){
					currenty++;
					//cout << "cury+ " << currentx << " : " << currenty << endl;
				}else{
					currentx--;
					//cout << arr[currentx][currenty-1] << ";" << check[currentx][currenty=1] << endl;
					//cout << "curx " << currentx << " : " << currenty << endl;
				}
				count++;
				check[currentx][currenty]=1;
				//cout << currentx << " : " << currenty << endl;
			}
			pos=currenty;
			//cout << "count = " << count << endl;
			if(min_count>count){
				//cout << "i : " << i << " / " << count << endl;
				min_count=count;
				min_pos=pos;
			}
		}
		//cout <<"#"<<test_case+1<<" "<< min_count << endl;
		cout <<"#"<<test_case+1<<" "<< min_pos << endl;

	}

	return 0;
}
