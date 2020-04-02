#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> m;
    
    int i;
    
    for(i=0;i<participant.size();i++){
        //{a,b}
        m[participant[i]]++;
        // if(m.find(participant[i])==m.end())
        //     m.insert(make_pair(participant[i],1));
        // else
        //     m.find(participant[i])->second++;
        
    }
    
    for(i=0;i<completion.size();i++){
        m[completion[i]]--;
    }
    
    for(auto iter=m.begin();iter!=m.end();iter++){
        if(iter->second >=1 ){
            answer+=iter->first;
        }
    }
    
    
    
    
    return answer;
}