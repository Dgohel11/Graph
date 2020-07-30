//FloydWarshall Algorithm
//complexity O(e^3)

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

//FloydWarshall Algo

void FloydWarshall(){
    
    vector<vector<ll >> dist(n,vector<ll> (n,INT_MAX));
    
    for( ll i=0;i<n;i++ ){
        for( auto x:g[i] ){
            dist[i][x.first] = x.second;
        }
    }
  
    for( ll k=0;k<n;k++ ){
        for( ll i=0;i<n;i++ ){
            for( ll j=0;j<n;j++ ){
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }
        }
    }
    
    for( ll i=0;i<n;i++ ){
        for(ll j=0;j<n;j++ ){
            if(i == j)
                cout <<"0\t";
            else if(dist[i][j] == INT_MAX)
                cout << "INF\t";
            else
                cout <<dist[i][j]<<"\t";
        }cout << endl;
    }

}


int main(){
    cin>>n>>e;
    ll x,y,w;
    
    for( ll i=0;i<e;i++ ){
        cin >> x >> y >> w;
        addedge(x,y,w);
    }
    
    FloydWarshall();
    //printG();
    
    return 0;
}
