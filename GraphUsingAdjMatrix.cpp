//Representation of  Graph using Adjacency matrix

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
        g[l][k] = 1;
    }
}


void printG(){
    for( int i=1;i<n+1;i++ ){
        for( int j=1;j<n+1;j++ ){
            cout << g[i][j] <<" "; 
        }cout << endl;
    }
}

int main(){
    cin>>n>>e;
    int a[e][2];
    int g[n+1][n+1];
    
    for( int i=0;i<e;i++ ){
        cin >> a[i][0] >> a[i][1] ;
    }
    
    makeAdjMatrix(a);
    printG();
    

}
