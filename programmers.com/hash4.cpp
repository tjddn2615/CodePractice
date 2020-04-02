#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b){
    if(a.second<b.second)
        return false;
    return true;
}

bool cmp2(const pair<int, pair<string, int>> &a, const pair<int, pair<string, int>> &b){
    if(a.second.second<b.second.second){
        return false;
    }else if (a.second.second == b.second.second){
        if(a.first>b.first){
            return false;
        }else{
            return true;
        }
    }
    return true;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> count;
    vector<pair<string,int>> count_v;
    vector<pair<int,pair<string,int>>> index;
    
    int i,j;
    
    for(i=0;i<genres.size();i++){
        index.push_back(make_pair(i,make_pair(genres[i],plays[i])));
        count[genres[i]]+=plays[i];
    }
    
    for(auto iter=count.begin();iter!=count.end();iter++){
        //cout << iter->first << iter->second << "\n";
        string tmp_s=iter->first;
        int tmp_i=iter->second;
        count_v.push_back(make_pair(tmp_s, tmp_i));
    }
    
    
    //전체 크기
    sort(count_v.begin(),count_v.end(), cmp);
    
    //각자 크기
    sort(index.begin(),index.end(),cmp2);


    //큰것부터 count
    for(i=0;i<count_v.size();i++){
        int tmpcnt=0;

        for(j=0;j<index.size();j++){
            if(tmpcnt>=2){
                break;
            }
            if(count_v[i].first==index[j].second.first){
                //cout << index[j].first << endl;
                answer.push_back(index[j].first);
                tmpcnt++;
            }
        }
    }
    
    
    
    return answer;
}