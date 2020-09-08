#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num;

bool compare(string str1, string str2){
    
    if(str1[num] > str2[num]){
        return false;
    }
    else if(str1[num] == str2[num]){
        return str1 > str2 ? false : true;
    }
    else{
        return true;
    }
    
}


vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    num = n;
    
    sort(strings.begin(), strings.end(), compare);
    
    
    
    return strings;
}