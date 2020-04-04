#include <string>
#include <vector>
#include <iostream>

using namespace std;

int visit[9];

vector<int> input;
int target_global=0;
int count=0;

void dfs(int start, int sum){
    
    int i;
    
    if( start == (input.size())){
        //cout << "sum " << sum << endl;
        if(sum == target_global){
            count++;
        }
        return;
    }
    
    
    for(i=0; i<2;i++){
        //인접 노드
        int x = input[start]; 
        if(i==0){ 
            int tmp = sum+x;
            dfs(start+1, tmp);
        }else{ 
            int tmp = sum-x;
            dfs(start+1, tmp);
        }
        
    }
    
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int i;
    for(i=0;i<numbers.size();i++){
        input.push_back(numbers[i]);
    }
    
    
    target_global=target;
    
    //cout << "before dfs" << endl;
    dfs(0,0);
    
    answer=count;
    
    return answer;
}