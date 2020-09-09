#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

struct Edge {
    int src, dest;
    int value;
};
//vector<int> set(n,0);
vector<int> set;

int getParent(int x) {
    if(set[x] == x) {
        return x;
    }
    return set[x] = getParent(set[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a > b) {
        set[b] = a;
    }
    else{
        set[a] = b;
    }
}

int find(int a, int b){
    a = getParent(a);
    b = getParent(b);
    // cout << a << " " << b << endl;
    // cout << "parent: " << a << " " << b << endl;
    if(a == b) {
        return 1;
    }
    else {
        return 0;
    }
    
}

bool compare(vector<int> a, vector<int> b){
    if(a[2] > b[2]){
        return false;
    }
    else{
        return true;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    map<int, int> m;
    vector<vector<int>> graph(n,vector<int>(n,0));;
    
    //costs[i][0] i1 costs[i][1] i2 costs[i][2] cost
    sort(costs.begin(), costs.end(), compare);
    
    // for(int i = 0; i<costs.size();i++){
    //     cout << costs[i][0] << costs[i][1] << costs[i][2] << endl;
    // }
    
    vector<Edge> v;
	Edge edge;
    
    for(int i = 0; i<costs.size();i++){
        edge.src = costs[i][0];
        edge.dest = costs[i][1];
        edge.value = costs[i][2];
        v.push_back(edge);
    }
    
    for(int i =0; i < n;i++){
        set.push_back(i);
    }
    
    for(int i = 0; i < v.size();i++){
        //동일한 부모를 가르치지 않는 지 확인, 즉 사이클이 발생하지 않음을 확인
        if(find(v[i].src, v[i].dest) == 0) {
            answer += v[i].value;
            unionParent(v[i].src, v[i].dest);
        }
    }
    
    // for(int i =0; i < n;i++){
    //     cout << "s " << set[i] << endl;;
    // }
    
    return answer;
}