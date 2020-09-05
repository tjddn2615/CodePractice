#include <iostream>

using namespace std;

int main(){
	int test_case;
	int T;
	int array[100][100];
	int i,j;
	int horizontal[100]={0};
	int vertical[100]={0};
	int diagonal[2]={0};
	int max;


	for(test_case = 1; test_case <= 10; test_case++){
		for(i=0;i<100;i++){
			horizontal[i]=0;
			vertical[i]=0;
		}
		diagonal[0]=0;diagonal[1]=0;
		max=0;
		cin>>T;
		for(i=0;i<100;i++){
			for(j=0;j<100;j++){
				cin>>array[i][j];
			}
		}
		
		for(i=0;i<100;i++){//horizontal & vertical
			for(j=0;j<100;j++){
				horizontal[i]+=array[i][j];
				vertical[i]+=array[j][i];
			}
		}

		for(i=0;i<100;i++){//diagonal
			diagonal[0]+=array[i][i];
			diagonal[1]+=array[i][99-i];
		}

		max=horizontal[0];
		for(i=1;i<100;i++){//max
			if (horizontal[i]>max){
				max=horizontal[i];
			}
		}
		for(i=0;i<100;i++){//max
			if (vertical[i]>max){
				max=vertical[i];
			}
		}
		for(i=0;i<2;i++){//max
			if (diagonal[i]>max){
				max=diagonal[i];
			}
		}
		cout <<"#"<<test_case<<" "<< max<<endl;

	}
	return 0;

}