//Graph implementation via adjacency list

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
        for( ll j=0;j<g[i].size();j++ ){
            cout << g[i][j] <<" ";
        }cout << endl;
    }
}


int main(){
    cin>>n>>e;
    ll x,y;
    
    for( ll i=0;i<e;i++ ){
        cin >> x >> y;
        addedge(x,y);
    }
    
    printG();
    
    return 0;    
}
