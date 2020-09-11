#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> strtok(string str, char delim = ' '){
	vector<string> ret;
	int prev=0;

	for(int i=0;i<str.size();i++){
		if(str[i] == delim){
			ret.push_back(str.substr(prev,i - prev));
			prev = i + 1;
		}
	}
	if (str.size() != prev) {
		ret.push_back(str.substr(prev, str.size() - prev));
	}

	return ret;
}


vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> m;

    for(int i = 0; i < record.size(); i++){
    	vector<string> tmp = strtok(record[i]);

    	if(tmp[0] == "Enter" || tmp[0] == "Change"){
    		//cout << m.count(tmp[1]) << endl;
    		if(m.count(tmp[1]) == 1){
    			//cout << tmp[0] << " ";
    			//cout << m.count(tmp[1]) << " " << m[tmp[1]] << " " << tmp[2] << endl;
    			m[tmp[1]] = tmp[2];
    		}else{
    			m.insert(make_pair(tmp[1], tmp[2]));	
    		}
    	}
    	//cout << tmp[0] << " | " <<tmp[1] << " | " <<tmp[2] << endl ;
    }


    for(int i = 0; i < record.size(); i++){
    	vector<string> tmp = strtok(record[i]);
    	string sentence = m[tmp[1]] + "님이 ";

    	if(tmp[0] == "Enter"){
    		sentence += "들어왔습니다.";
    	}
    	else if ((tmp[0] == "Leave")) {
    		sentence += "나갔습니다.";
    	}else if((tmp[0] == "Change")) {
    		continue;
    	}
    	//cout << sentence << endl;
    	answer.push_back(sentence);
    	//cout << m.find(tmp[1])->second << endl;
    }


    return answer;
}