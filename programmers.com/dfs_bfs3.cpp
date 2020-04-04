#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int count=0;
vector<string> lists;
map<string,int> visited;

int bfs(string begin, string target){
    queue<pair<string, int>> q;

    q.push(make_pair(begin,0));
    
    while(!q.empty()){
        
        string str = q.front().first;
        int depth = q.front().second;
        visited[str]++;
        q.pop();
        
        for(int i=0; i<lists.size();i++){

            int same_cnt=0;
            for(int j=0;j<str.size();j++){
                if(str[j]==lists[i][j]){
                    same_cnt++;
                    //cout << "same_cnt: " << same_cnt << " " << str << " > " << lists[i] << endl;
                }    
            }

            if(same_cnt==str.size() && str==target){
                return depth;
            }
            if(same_cnt==str.size()-1 && visited[lists[i]]==0){
                //cout << "pushed: " << lists[i] << endl;
                q.push(make_pair(lists[i], depth+1));
            }

        }
    }
    
    return 0;
}




int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    lists=words;
    
    for(int i=0;i<words.size();i++){
        visited[words[i]]=0;
    }
    
    answer=bfs(begin,target);
    
    
    
    return answer;
}