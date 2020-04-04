#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    int i,j;
    
    vector<int> input;
    vector<int> list;
    

    //string to int
    for(i=0;i<numbers.size();i++){
        input.push_back(numbers[i]-48);
        cout << numbers[i] << " ";
    }cout <<endl;
    

    //가능한 모든 숫자 구하기
    sort(input.begin(), input.end());
    do{
        int tmp=0;
	    for(i=0;i<input.size();i++){
            tmp+=input[i]*pow(10,i);
            //cout << "tmp: " << tmp << endl;
            list.push_back(tmp);
        }
       
	}while(next_permutation(input.begin(), input.end()));
    
    //중복제거
    sort(list.begin(), list.end());
    list.erase(unique(list.begin(),list.end()),list.end());
    
//     for(i=0;i<list.size();i++){
//         cout << list[i] << " ";
//     }cout << endl;
    
    //소수 확인
    for(i=0;i<list.size();i++){
        int flag=0;
        
        if(list[i]==1 || list[i]==0){
            continue;
        }
        if(list[i]==2){
            answer++;
            continue;
        }
        for(j=2;j<list[i];j++){
            if(list[i]%j==0){
                //cout << list[i] << " % " << j << " " << endl;
                flag=1;
                break;
            }
        }
        if(flag==0){
            //cout << "sosu! : " << list[i]<< " " << endl;
            answer++;
        }
    }cout << endl;
    
    
    
    
    return answer;
}