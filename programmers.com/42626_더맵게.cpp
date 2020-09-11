#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int find_average(vector<int> v) {
	int result = 0;
	int size = v.size();

	for (int i = 0; i < size; i++) {
		result += v[i];
	}
	return result/size;
}

int find_sc(vector<int> sc, int K) {
	int result = 0;

	for (int i = 0; i < sc.size(); i++) {
		if (sc[i] < K) {
			return 1;
		}
	}
	return 0;
}



int find_sc2(priority_queue<int, vector<int>, greater<int>> pq, int K) {
	int result = 0;

	while(!pq.empty()){
		if(pq.top() < K){
			return 1;
		}
		pq.pop();
	}
	return 0;
}


int solution(vector<int> scoville, int K) {
    int answer = 0;
    int cnt = 0;

    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(),scoville.end());
    int mix = K - 1;
    //while(find_sc2(pq, K)){
    while(pq.top() < K){
    	cnt ++;
    	if(pq.size() <= 1 ){
    		answer = -1;
    		break;
    	}

    	int first = pq.top(); pq.pop();
    	int second = pq.top(); pq.pop();

    	pq.push(first + second * 2);
    	//cout << mix << K << endl;
    }

    if(answer != -1) answer = cnt;

    return answer;
}

