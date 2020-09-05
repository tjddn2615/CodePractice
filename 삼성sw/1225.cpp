#include <cstdio>
#include <iostream>

int main(){

	int num;
	int input[8];


	for(int t=1;t<=10;t++){
		
		scanf("%d", &num);
		for(int i=0;i<8;i++){
			scanf("%d", &input[i]);
		}

		while(1){
			int tmp[8];
			for(int i=1;i<=5;i++){
				for(int j=0;j<7;j++){
					tmp[j]=input[j+1];	
				}
				tmp[7]=input[0]-i;
				for(int j=0;j<8;j++){
					input[j]=tmp[j];	
				}
				if(input[7]<=0){
					input[7]=0;
					printf("#%d", t);
					for(int j=0;j<8;j++){
						printf(" %d", input[j]);
					}
					printf("\n");
					break;
				}
			}
			if(input[7]<=0){
				break;
			}
		}
	}
	return 0;
}
