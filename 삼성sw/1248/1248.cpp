//least common ancestor
//find paraent
//list parent
//compare

#include <iostream>
#include <vector>

using namespace std;
// vector<int> v;
// vector<vector<int> > v;

int bfs(int src){


    return 0;
}


int main(){
    int T;
    int t,i,j,k;

    cin >> T;
    for(t=1;t<=T;t++){
        int vec, edge, node1, node2;
        cin >> vec >> edge >> node1 >> node2;
        vector<vector<int> > adj(10001);
        int tmp,tmp1;
        for(i=0;i<edge*2;i++){
            cin >> tmp >> tmp1;
            adj[tmp].push_back(tmp1);
        }

        bfs(node1);
        bfs(node2);

    }

    return 0;
}
