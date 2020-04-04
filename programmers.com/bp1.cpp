#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first<b.first)
        return true;
    return false;
}


vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int,int>> tmp;
    
    vector<int> first = {1,2,3,4,5};
    vector<int> second = {2,1,2,3,2,4,2,5};
    vector<int> third = {3,3,1,1,2,2,4,4,5,5};
    
    int i,j;
    int cnt_1=0,cnt_2=0,cnt_3=0;
    
    for(i=0;i<answers.size();i++){
        if(first[i%5]==answers[i]){
            cnt_1++;
        }
        if(second[i%8]==answers[i]){
            cnt_2++;
        }
        if(third[i%10]==answers[i]){
            cnt_3++;
        }
    }
    
    tmp.push_back(make_pair(cnt_1,1));
    tmp.push_back(make_pair(cnt_2,2));
    tmp.push_back(make_pair(cnt_3,3));
    
    sort(tmp.begin(),tmp.end(),cmp);
    
    //check
    for(i=0;i<3;i++){
        cout << tmp[i].first << " ";
    }cout << endl;
    
    
    int top;
    top=tmp[2].first;
    for(i=0;i<3;i++){
        if(tmp[i].first==top){
            answer.push_back(tmp[i].second);
        } 
    }
    
    
    return answer;
}