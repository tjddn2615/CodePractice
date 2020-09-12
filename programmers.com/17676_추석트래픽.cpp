#include <string>
#include <vector>
#include <iostream>

#define abs(x) x<0 ? -x : x
#define epsilon 0.001


using namespace std;

//strtok() to vector
vector<string> strtok(string str, char delim = ' '){
	vector<string> ret;
	int prev=0;

	for(int i=0;i<str.size();i++){
		if(str[i] == delim){
			ret.push_back(str.substr(prev, i - prev));
			prev = i + 1;
		}
	}
	if (str.size() != prev) {
		ret.push_back(str.substr(prev, str.size() - prev));
	}

	return ret;
}


int solution(vector<string> lines) {
    int answer = 0;

    vector<vector<double>> t_list;

    //input 정리
    for(int i = 0;i < lines.size();i++){
        //쪼개진 문자열들을 벡터로 받음
    	vector<string> temp = strtok(lines[i]);
    	//cout << temp[0] << " | " << temp[1] << endl;
        
        //시간으로 쪼개서 초단위로 통일
        vector<string> time_str = strtok(temp[1],':');
        double s = stod(time_str[0]) * 3600 + stod(time_str[1]) * 60 + stod(time_str[2]);
        double t = stod(strtok(temp[2],'s')[0]);

        t_list.push_back({s - t + 0.001, s});
        //cout << s - t + 0.001 << " | " << s << endl;
    }

    for(int i = 0;i<t_list.size();i++){
    	double begin = t_list[i][1];
    	double end = begin+0.999;

    	int tmp=0;
    	for(int j = i;j<t_list.size(); j++){
    		if(abs(t_list[j][1] - begin) >= epsilon && abs(t_list[j][0] - end) <= epsilon){
    			//cout << begin << " | " << end;
    			tmp++;
    		}
    	}

    	if(answer < tmp){
    		answer  = tmp;
    	}
    }

    return answer;
}