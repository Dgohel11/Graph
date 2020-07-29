//Kruskal's Algorithm 

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair

ll n,e;   

vector<pair<ll,pair<ll,ll>>> g;

void makegraph(ll a[][3]){    
    for( ll i=0;i<e;i++ ){
        g.pb( mp(a[i][2], mp(a[i][0], a[i][1])));
    }
}

class DSU{
    ll *parent,*rank;
    
public:
    
    DSU(){
        parent = new ll[n+1];
        rank = new ll[n+1];
        
        for( ll i=0;i<=n;i++ ){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    
    ll find(ll k){
        if(k == parent[k]) return k;
        find(parent[k]);
    }
    
    void uni(ll a,ll b){
        ll a1 = find(a);
        ll b1 = find(b);
        
        if(rank[a1] > rank[b1])parent[a1] = b1;
        else parent[b1] = a1;
        
        if(rank[a1] == rank[b1]) rank[b1]++;
        
    }
};

ll KruMST(){
    
    ll weight = 0;
    
    sort(g.begin(),g.end());
    
    DSU ds;
    
    for( ll i=0;i<e;i++ ){
        
        ll u = g[i].second.first;
        ll v = g[i].second.second;
        
        ll pu = ds.find(u);
        ll pv = ds.find(v);
        
        if(pu != pv){
            cout << u <<" "<< v << endl;
            weight += g[i].first;
            ds.uni(pu,pv);
        }
    }
    
    return weight;
}


int main(){
    cin>>n>>e;
    ll a[e][3];
    
    for( ll i=0;i<e;i++ ){
        cin >> a[i][0] >> a[i][1] >>a[i][2];
    }
    
    makegraph(a);
    
    ll ans = KruMST();
    
    cout << ans <<endl;
    
    return 0;    
}
