//BellmanFord Algorithm
//complexity O((n-1)*n*e) ~ O(n^3)

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair

ll n,e;   
vector<pair<ll,ll>> g[100];

void addedge(ll a,ll b,ll w){    
    g[a].pb(mp(b,w));
    //g[b].pb(mp(a,w));
}

//Bellmanford Algo

void BellmanFord(ll s){
    
    vector<ll> dis(n,INT_MAX);
    
    dis[0] = 0;
    
    for( ll i=1;i<=n-1;i++ ){
        for( ll p=0;p<n;p++ ){
            for(auto x:g[p]){
               ll u = p;
               ll v = x.first;
               ll w = x.second;
                
                if(dis[u]!=INT_MAX && dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                }
            }
        }
    }
    
    for( ll p=0;p<n;p++ ){
            for(auto x:g[p]){
               ll u = p;
               ll v = x.first;
               ll w = x.second;
                
                if(dis[u]!=INT_MAX && dis[v] > dis[u] + w){
                    cout <<"This graph contain neg cycle."<<endl;
                    return;
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
    
    BellmanFord(0);
    //printG();
    
    return 0;
}
