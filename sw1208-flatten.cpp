#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int num;
    int max, min;
    int i, j, k;
    int input[101];
    int count=0;
    

    for(i=0;i<10;i++){
        cin >> num;
        for(j=0;j<100;j++){
            cin >> input[j];
        } 
        sort(input,input+100);
        for(j=0;j<num;j++){//one flatten
            input[99]--;//=1;
            input[0]++;//=1;
            sort(input,input+100);
            if(input[99]-input[0]<=1){
                break;
            }
        }
        count=input[99]-input[0];
        cout <<"#"<<i+1<<" "<< count<<endl;
    }

    return 0;
}


