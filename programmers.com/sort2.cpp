#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b){
    string c = a + b;
    string d = b + a;
    if(stoi(c)<stoi(d))
        return false;
    return true;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> v;
    int i,j;
    
    for(int i=0;i<=1000;i++)
        v.push_back(to_string(i));
    sort(v.begin(),v.end(),cmp);
    
    int num[1001]={0,};
    for(int i=0;i<numbers.size();i++)
        num[numbers[i]]++;
    
    for(int i=0;i<=1000;i++)
        for(int j=0,k=stoi(v[i]);j<num[k];j++)
            answer += v[i];
    if(answer[0]=='0')
        return "0";
    return answer;
}