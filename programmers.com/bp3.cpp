#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    int i,j,k,l;
    
    
    for(i=111;i<1000;i++){
        //숫자 쪼개기
        int t1,t2,t3;
        t1=i/100; t2=(i%100)/10; t3=(i%10);
        vector<int> target;
        target.push_back(t1);target.push_back(t2);target.push_back(t3);
        //cout << endl;
        //cout<< "target: " << target[0] << target[1] << target[2] << endl;
        if(target[0]==0 || target[1]==0 || target[2]==0){
            continue;
        }
        if(target[0]==target[1] || target[0]==target[2] || target[2]==target[1]){
            continue;
        }
        
        int flag=0;
        for(j=0;j<baseball.size();j++){
            
            vector<int> number;
            int n1,n2,n3;
            //숫자 쪼개기
            n1=baseball[j][0]/100; n2=(baseball[j][0]%100)/10; n3=(baseball[j][0]%10);
            if(n1==0 || n2==0 || n3==0){
                continue;
            }
            if(n1==n2 || n3==n1 || n3==n2){
                continue;
            }
            number.push_back(n1);number.push_back(n2);number.push_back(n3);

            //cout << "number: " << number[0] << number[1] << number[2] << endl;
            
            
            //strike
            int str_cnt=0;
            for(k=0;k<3;k++){
                if(number[k]==target[k]){
                    str_cnt++;
                    //cout << "strike" << endl;
                }
            }
            if(str_cnt!=baseball[j][1]){
                flag=1;
                break;
            }

            //ball
            int ball_cnt=0;
            for(k=0;k<3;k++){
                for(l=0;l<3;l++){
                    if(k==l){
                        continue;
                    }
                   if(number[k]==target[l]){
                        ball_cnt++;
                        //cout << "ball" << endl;
                    }
                }
            }
            if(ball_cnt!=baseball[j][2]){
                flag=1;
                break;
            }
            
        }
        
        if(flag==0){
            answer++;
        }
        
        
    }
        
    
    
    
    
    
    
    
    
    return answer;
}