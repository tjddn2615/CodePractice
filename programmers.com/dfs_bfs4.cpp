#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<string>> route;
vector<int> result;

int result_cnt=0;
vector<vector<int>> results;
vector<vector<string>> results_s;
vector<int> visit;

bool cmp(const vector<string> &a, const vector<string> &b){
    for(int i=0;i<a.size();i++){
        if(a[i]<b[i]) {
            return true;
        }else if(a[i]==b[i]){
            continue;
        }else{
            return false;
        }
    }
}


void dfs(int start, int depth){
    
    if(visit[start]>=1){
        return;
    }
    //cout << start <<endl;
    result.push_back(start);
    visit[start]=1;
    
    // FINAL CHECK
    if(depth==route.size()){
        //cout << "END!!!" <<endl;
        results.push_back(result);
        
        // for(int i=0;i<result.size();i++){
        //     cout << result[i] << " ";
        // }cout << endl;
    }
    
    
    
    for(int i=0; i<route.size();i++){
        if(route[i][0]==route[start][1]){
            dfs(i, depth+1);
        }
    }
    visit[start]=0;
    result.pop_back();
    
}//dfs end

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    route=tickets;
    
    for(int i=0;i<tickets.size()+1;i++){
        answer.push_back("ZZZ");
    }
    
    
    for(int i=0;i<tickets.size();i++){
        visit.push_back(0);
    }
    
    
    for(int i=0;i<tickets.size();i++){
        for(int j=0;j<tickets.size();j++){
            visit[j]=0;
        }
        if(tickets[i][0]=="ICN"){
            dfs(i, 1);
        }
    }
    
    //결과를 숫자에서 스트링으로
    for(int i=0; i< results.size();i++){
        vector<string> tmp;
        tmp.push_back(tickets[results[i][0]][0]);
        //cout << "start: " << tickets[results[i][0]][0] << " ";
        for(int j=0;j<results[i].size();j++){
            tmp.push_back(tickets[results[i][j]][1]);
            //cout << tickets[results[i][j]][1] << " ";
        }//cout << endl;
        results_s.push_back(tmp);
    }
    //결과 sort
    sort(results_s.begin(),results_s.end(),cmp);
    
    // for(int i=0;i<results_s.size();i++){
    //     for(int j=0;j<results_s[i].size();j++){
    //         cout << results_s[i][j] << " ";
    //     }cout << endl;
    // }
    
    
    answer=results_s[0];
    
    
    return answer;
}