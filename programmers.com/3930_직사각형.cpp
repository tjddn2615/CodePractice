#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<vector<int> > vec) {
    vector<int> ans;
    map<int, int> m1, m2;
    
    for(auto v : vec) {
        
        if(m1.count(v[0]) < 0) {
            m1.insert(make_pair(v[0], 1));
        }else{
            m1[v[0]]++;
        }
        
        if(m2.count(v[1]) < 0) {
            m2.insert(make_pair(v[1], 1));
        }else{
            m2[v[1]]++;
        }
    }
    int x,y;
    for(auto i = m1.begin();i != m1.end(); i++){
        if(i->second == 1){
            x=i->first;
        }
    }
        for(auto i = m2.begin();i != m2.end(); i++){
        if(i->second == 1){
            y=i->first;
        }
    }

    ans.push_back(x);ans.push_back(y);
    
    return ans;
}