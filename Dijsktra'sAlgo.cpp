//Dijsktra's Algorithm

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

//Dijkstra's Algo

void Dij(ll s){
    
    priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>>> q;
    
    vector<ll> dis(n,INT_MAX);
    
    dis[0] = 0;
    
    q.push(mp(0,s));
    
    while(!q.empty()){
        ll u = q.top().second;
       
        q.pop();
        
        for( auto x:g[u] ){
            
            ll v = x.first;
            ll w = x.second;
            
            if( dis[v] > dis[u] + w ){
                dis[v] = dis[u] + w;
                q.push(mp(dis[v] , v));
            }
        }
        
    }
    
    for( ll i=0;i<n;i++ ){
        cout << i <<" "<<dis[i]<<endl;
    }

}


int main(){
    cin>>n>>e;
    ll x,y,w;
    
    for( ll i=0;i<e;i++ ){
        cin >> x >> y >> w;
        addedge(x,y,w);
    }
    
    Dij(0);
    //printG();
    
    return 0;
}
