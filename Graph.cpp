#include<bits/stdc++.h>
using namespace std;

vector<int> graph[1000005];
bool visited[1000005];
long nodes;
void dfs(int n){
    nodes++;
    visited[n]=true;
    for(vector<int>::iterator  i=graph[n].begin();i!=graph[n].end();i++){
        if(!visited[*i]){
            dfs(*i);
        }
    }
    
}
int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        int x;
        int y;
        long cost=0;
        cin >> n >> m >> x >> y;
        for(int a1 = 0; a1 < m; a1++){
            int p;
            int q;
            cin >> p >> q;
            graph[p].push_back(q);
            graph[q].push_back(p);
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                nodes=0;
                dfs(i);
                cost=cost+x;
            if(x<y)
                cost += (nodes-1)*x;
            else
                cost += (nodes-1)*y;
            }
        }
        for(int i=1;i<=n;i++){
            graph[i].clear();
            visited[i]=false;
        }
        cout<<cost<<endl;
    }
    return 0;
}
