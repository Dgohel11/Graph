//BFS using adjacency list

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair

ll n,e;   
vector<ll> g[100];

void addedge(ll a,ll b){    
    g[a].pb(b);
    g[b].pb(a);
}

void printG(){
    for( ll i=0;i<n;i++ ){
        cout << i <<" : ";
        for( ll j=0;j<(ll)g[i].size();j++ ){
            cout << g[i][j] <<" ";
        }cout << endl;
    }
}

//BFS function
void BFS(int s){
    bool vis[n+1] = {false};
    vis[s] = true;
    
    queue<ll> q;
    q.push(s);
    
    while(!q.empty()){
        ll k = q.front();
        cout << k <<" ";
        q.pop();
        
        for( ll j=0;j<g[k].size();j++ ){
            if(!vis[g[k][j]]){
                q.push(g[k][j]);
                vis[g[k][j]] = true;
            }
            
        }
    }
}

int main(){
    cin>>n>>e;
    ll x,y;
    
    for( ll i=0;i<e;i++ ){
        cin >> x >> y;
        addedge(x,y);
    }
    
    BFS(1);
    //printG();
    
    return 0;    
}
