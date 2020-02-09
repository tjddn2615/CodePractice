#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


int main(){

	int t,i,j,k;
	int num;
	int T;

	cin >> T;
	for(t=1;t<=T;t++){
		int num;
		int arr[6];
		char arr_tmp[6];

		//input
		cin >> arr_tmp;
		for(i=0;i<strlen(arr_tmp);i++){
			arr[i]=arr_tmp[i]-'0';
			cout <<i << endl;
		}
		cout <<arr[0] <<arr[1]<<arr[2];
		cin >> num;

		//selection sort에서 바꾸는 부분을 수정 요망 
		int swap_cnt=0;
		for(i=0;i<6;i++){
			int minn = arr[i];
			int location = i;
			for(int j=i+1;j<8;j++){
				if(minn<arr[j]){
					minn=arr[j];
					location=j;
				}
			}
			swap(arr[i],arr[location]);
			swap_cnt++;
			if(swap_cnt>=num){
				break;
			}
		}

		for(i=0;i<6;i++){
		//	cout << arr[i]<< " ";
		}
		cout << endl;

	}



	return 0;
}
