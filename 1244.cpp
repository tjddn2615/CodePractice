#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

int arrtonum(int arr[], int arr_len){

	int first=arr[0];
	for(int i=1;i<arr_len;i++){
		first*=10;
		first+=arr[i];
	}
	return first;
}

int bfs(int arr[], int arr_len, int num){

	queue<pair<int, int> > q;
	queue<pair<int, int> > final;
	map<int> visited;
	// int first=arr[0];
	// for(int i=1;i<arr_len;i++){
	// 	first*=10;
	// 	first+=arr[i];
	// }
	int first=arrtonum(arr,arr_len);

	cout << "first" <<first << endl;

	q.push(make_pair(first,num));

	
	while(!q.empty() && q.front().second > 0){
		int origin=q.front().first;
		int level = q.front().second;
		q.pop();

		int changed[6];
		for(int i=arr_len-1;i>=0;i--){
			changed[i]=origin%10;
			origin/=10;
		}
		//cout << "origin" << changed[0] << changed[1] << changed[2] << endl;

		for(int i=0;i<arr_len;i++){
			for(int j=i;j<arr_len;j++){
				int tmp[6];
				copy(changed,changed+arr_len,tmp);	
				swap(tmp[i],tmp[j]);
				int tmp_num=arrtonum(tmp, arr_len);
				cout << "tmpnum" << tmp_num << endl;
				if(level-1>0){
					q.push(make_pair(tmp_num,level--)); //prevent iteration 
				}else{
					final.push(make_pair(tmp_num,level--));
				}
			}
		}

	}

	int max=0;
	while(!final.empty()){
		if(final.front().first>max){
			max=final.front().first;
			cout << "" << max << endl;
		}
		final.pop();
	}

	return 0;
}
 


int main(){

	int t,i,j,k;
	int num;
	int T;

	cin >> T;
	for(t=1;t<=T;t++){
		int num;
		int arr[6];
		int arr_len;
		char arr_tmp[6];

		//input
		cin >> arr_tmp;
		arr_len=strlen(arr_tmp);
		for(i=0;i<arr_len;i++){
			arr[i]=arr_tmp[i]-'0';
			cout <<i << endl;
		}
		//cout <<arr[0] <<arr[1]<<arr[2];
		cin >> num;

		int result = bfs(arr, arr_len, num);

		
		// int swap_cnt=0;
		// for(i=0;i<6;i++){
		// 	int minn = arr[i];
		// 	int location = i;
		// 	for(int j=i+1;j<8;j++){
		// 		if(minn<arr[j]){
		// 			minn=arr[j];
		// 			location=j;
		// 		}
		// 	}
		// 	swap(arr[i],arr[location]);
		// 	swap_cnt++;
		// 	if(swap_cnt>=num){
		// 		break;
		// 	}
		// }

		cout << "#" << t << " " << result << endl;

	}



	return 0;
}
