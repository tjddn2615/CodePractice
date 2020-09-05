#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

	int i,j,T,t;

	cin >> T;
	for(t=1;t<=T;t++){

		string origin;
		int str_len;
		int target;
		vector <string> v;

		cin >> target;
		cin >> origin;

		//v.push_back(origin);

		for(i=0;i<origin.size();i++){
			for(j=1;j<origin.size()-i+1;j++){
				v.push_back(origin.substr(i,j));
				//printf("%d %d : ", i, j);
				//cout << origin.substr(i,j) << endl;
			}
		}

		// for(i=0;i<v.size();i++){
		// 		cout << v[i] << endl;
		// }		

		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());


		// for(i=0;i<v.size();i++){
		// 		cout << v[i] << endl;
		// }	

		if (v.size()<=target){
			printf("#%d none\n", t);
		}else{
			printf("#%d %s\n", t, v[target-1].c_str());
		}



	}//T

	return 0;
}