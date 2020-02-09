#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int t;
	
	int i, j, k;

	for(t=1;t<=10;t++){
		int len;
		int origin[100];
		int order_num;
		int order_begin;
		int order_change_num;
		int order[10];


		cin >> len;
		for (i = 0; i < len; ++i){
			cin >> origin[i];
		}
		cin >> order_num;
		for (i = 0; i < order_num; ++i){
			char tmp;
			cin >> tmp >> order_begin >> order_change_num;
			
//			for(k=len-order_change_num;k>0;k--){//move
//				int sum=order_begin+k+order_change_num;
//				int sum2=order_begin+k;
//				origin[sum]=origin[sum2];
//			}
			
			for (j=order_begin; j<order_begin+order_change_num; j++){
				int tmp_num;
				if (j>=len){
					cin >> tmp_num;
				}else{
					for(k=len;k>j;k--){
						origin[k]=origin[k-1];
					}
					cin >> origin[j];	
				}
//				for (k = 0; k < len; ++k){
//					cout << origin[k] << " ";
//				}
//				cout << endl;
			}			
		}
	
		//order
		printf("#%d ", t);
		for (int i = 0; i < 10; ++i)
		{
			printf("%d ", origin[i]);
		}
		printf("\n");

	}

	return 0;
}
