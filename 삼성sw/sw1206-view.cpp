#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	int num=0;
	int building[1001];
    int sort_tmp[5];
    int i,j,k;
    int max1=-1, max2=-1;
    int count=0;
    int tmp_cal;



	for(i=0;i<10;i++){
		cin >> num;

        //input
        for(j=0;j<num;j++){
            cin >> building[j];
        }
        for(j=2;j<num-2;j++){
            for(k=0;k<5;k++){
                sort_tmp[k]=building[j-2+k];
            }
            sort(sort_tmp,sort_tmp+5);
            //count = same(sort_tmp);
            //cout << count;
            
            //cout << sort_tmp[0] << sort_tmp[1] << sort_tmp[2] << sort_tmp[3] << sort_tmp[4] << endl;
                
            tmp_cal = sort_tmp[4]-sort_tmp[3];
            if(tmp_cal>=1 && sort_tmp[4]==building[j]){
                count += (tmp_cal);
            }
		}
        cout << "#" << i+1 << " "<< count << endl;
        count=0;
	}

	return 0;
}

