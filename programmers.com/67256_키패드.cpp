#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> lp = {0, 0, 0, 1};
vector<int> rp = {0, 0, 0, 1};

int check_v(int n){
    if(n == 1 || n == 3 || n == 2){
        return 0;
    }else if(n == 4 || n == 6 || n == 5){
        return 1;
    }else if(n == 7 || n == 9 || n == 8){
        return 2;
    }else if(n == 0){
        return 3;
    }
}

string check_middle(vector<int> left, vector<int> right, int n, string hand) {

    vector<int> target;
    int l_pos, r_pos;

    if(n == 2){
        target.push_back(0);target.push_back(1);
    }
    else if(n == 5){
        target.push_back(1);target.push_back(1);
    }
    else if(n == 8){
        target.push_back(2);target.push_back(1);
    }
    else if(n == 0){
        target.push_back(3);target.push_back(1);
    }

    l_pos = abs(left[0] - target[0]) + abs(left[1] - target[1]);
    r_pos = abs(right[0] - target[0]) + abs(right[1] - target[1]);
    if (l_pos > r_pos) {
        return "R";
    } else if(l_pos < r_pos){
        return "L";
    } else {
        return hand=="right" ? "R" : "L";
    }

}


string solution(vector<int> numbers, string hand) {
    string answer = "";
    vector<int> left;
    vector<int> right;

    left.push_back(3);left.push_back(0);
    right.push_back(3);right.push_back(2);

    for(int i = 0;i<numbers.size();i++){
    
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            left[1]=0;
            left[0]=check_v(numbers[i]);
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            right[1]=2;
            right[0]=check_v(numbers[i]);
        }
        else if(numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0){
            string tmp = check_middle(left, right, numbers[i], hand);
            answer += tmp;
            if(tmp == "L"){
                left[1]=1;
                left[0]=check_v(numbers[i]);
            }else {
                right[1]=1;
                right[0]=check_v(numbers[i]);
            }
        }
    }
    
    return answer;
}