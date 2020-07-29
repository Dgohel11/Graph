//Topological sort of Graph with Adjacency matrix



#include<bits/stdc++.h>
using namespace std;

int n,e;   

int g[100][100];

void makeAdjMatrix(int a[][2]){
    for( int i=0;i<n+1;i++ ){
        for( int j=0;j<n+1;j++ ){
            g[i][j] = 0;
        }
    }
    
    int k,l;
    for( int i=0;i<e;i++ ){
        k = a[i][0];
        l = a[i][1];
        
        g[k][l] = 1;
        //g[l][k] = 1; (DAG)
    }
}


void printG(){
    for( int i=0;i<n+1;i++ ){
        for( int j=0;j<n+1;j++ ){
            cout << g[i][j] <<" "; 
        }cout << endl;
    }
}



// Topo function :p

bool vis[100];
stack<int> s;

void topohelper(int a){
    vis[a] = true;
    for( int i=0;i<n+1;i++ ){
        if(g[a][i]==1 && !vis[i]) topohelper(i);
    }
    
    s.push(a);
}

void Topo(){
    
    for( int i=0;i<n+1;i++ ){
        if(vis[i]==false){
            topohelper(i);
        }
    }
    
    while(!s.empty()){
        cout << s.top()<<" ";
        s.pop();
    }
}




int main(){
    cin>>n>>e;
    int a[e][2];
    
    for( int i=0;i<e;i++ ){
        cin >> a[i][0] >> a[i][1] ;
    }
    
    makeAdjMatrix(a);
    //printG();
    
    Topo();

}
