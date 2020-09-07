#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string answerS = s;
    stack<string> st;

    //단위
    for (int i = 1; i < (s.size() / 2)+1; i++) {
        //하나씩 확인
        
        string answerSt = "";
        for (int j = 0; j < s.size(); j+=i) {
            string tmp = s.substr(j, i);//j부터 시작해서 i만큼

            int cnt = j + i;
            int num_item=1;
            if(j<s.size()-i){
                while (tmp == s.substr(cnt, i)) {
                    //cout << tmp << " " << s.substr(cnt,i) << endl;
                    num_item++;
                    //cout << num_item << endl;
                    cnt += i;
                }
            }
            
            
            if(num_item > 1){
                answerSt = answerSt + to_string(num_item) + tmp;
                j+=(num_item-1)*i;
            }
            else{
                //cout << "add: " << tmp << endl;
                answerSt = answerSt + tmp;
            }
        }
        
        //cout << "St: " << answerSt << endl;
        //cout << "answerSt: " << answerSt.size() <<  " answerS: " << answerS.size() << endl;
        if (answerSt.size() <= answerS.size()) {
            answerS = answerSt;
            //cout << "answerS: " << answerS << endl;
        }

    }
    cout << answerS << endl;
        
    return answerS.size();
}