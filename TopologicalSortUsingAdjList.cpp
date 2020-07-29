//Topological sort using adjacency list

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair

ll n,e;   
vector<ll> g[100];

void addedge(ll a,ll b){    
    g[a].pb(b);
    //g[b].pb(a);
}

void printG(){
    for( ll i=0;i<n;i++ ){
        cout << i <<" : ";
        for( ll j=0;j<(ll)g[i].size();j++ ){
            cout << g[i][j] <<" ";
        }cout << endl;
    }
}


//TOPO function

bool vis[100];
stack<ll> s1;

void toposort(ll s){
    
    vis[s] = true;
    
    for( ll i=0;i<g[s].size();i++ ){
        if(!vis[g[s][i]]){
            toposort(g[s][i]);
        }
    }
    
    s1.push(s);
}

void Topo(){
    
    for( ll i=0;i<n+1;i++ ){
        if(!vis[i]){
            toposort(i);
        }
    }
    
    while(!s1.empty()){
        cout << s1.top() <<" ";
        s1.pop();
    }
}

int main(){
    cin>>n>>e;
    ll x,y;
    
    for( ll i=0;i<e;i++ ){
        cin >> x >> y;
        addedge(x,y);
    }
    
    Topo();
    //printG();
    
    return 0;    
}
