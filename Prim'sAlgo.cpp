//Prim's Algorithm

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair

ll n,e;   
vector<pair<ll,ll>> g[100];

void addedge(ll a,ll b,ll w){    
    g[a].pb(mp(b,w));
    g[b].pb(mp(a,w));
}

void prims(){

    priority_queue<pair<ll,ll> ,vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    
    vector<ll> key(n,INT_MAX);
    vector<ll> parent(n,-1);
    vector<bool> vis(n,false);
    
    key[0] = 0;
    ll start = 0;
    
    q.push(mp(0,start));
    
    while(!q.empty()){
        
        ll u = q.top().second;
        q.pop();
        vis[u] = true;
        
        for( auto x:g[u] ){
            
            ll weight = x.second;
            ll dest = x.first;
            
            if(vis[dest] == false && weight < key[dest]){
                key[dest] = weight;
                q.push(mp(key[dest] , dest));
                parent[dest] = u;
            }
        }
    }
    
    ll sum = 0;
    for( ll i=0;i<n;i++ ){
        cout << parent[i] <<" "<< i << " "<< key[i]<<endl;
        sum+=key[i];
    }
    
    cout << sum << endl;
}
int main(){
    cin>>n>>e;
    ll x,y,w;
    
    for( ll i=0;i<e;i++ ){
        cin >> x >> y >> w;
        addedge(x,y,w);
    }
    
    prims();
    //printG();
    
    return 0;
}
