#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int size=0;
vector<int> origins;
vector<int> results;

void dfs(int start, int sum, int cnt){
    
    int flag=0;
    sum+=origins[start];
    // cout << "start: "<< start << endl;
    // cout << "origins[start]: "<< origins[start] << endl;
    // cout << "sum: "<< sum << endl;
    
    if(cnt > 2){
        return;
    }
    
    for(int i=2; i<sum;i++){
        if(sum%i==0){
            //소수 아님
            flag=1;
            break;
        }
    }
    
    if(flag==0 && sum >=2 && cnt >=2){   
        //cout << "answer: "<< sum << " " << cnt << endl;
        results.push_back(sum);
    }
    
    for(int i=start+1; i<size;i++){
        dfs(i,sum, cnt+1);
    }
    
}


int solution(vector<int> nums) {
    int answer = -1;    
    
    for(int i=0;i<nums.size();i++){
        origins.push_back(nums[i]);
    }
    
    size=nums.size();
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    for(int i=0; i<nums.size();i++){
        //cout << "new start with " << nums[i] << endl;
        dfs(i,0,0);        
    }

    unique(results.begin(),results.end());
    answer=results.size();
    
    return answer;
}