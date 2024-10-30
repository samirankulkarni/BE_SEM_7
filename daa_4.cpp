#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<char>> &a){
    int n = a.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    cout<<'\n';
}

bool isSafe(vector<vector<char>> &a,int i,int j){
    int n = a.size();
    for(int c=i-1;c>=0;c--) if(a[c][j] == 'Q') return false;
    for(int x=i,y=j;x>=0 && y>=0;x--,y--) if(a[x][y] == 'Q') return false;
    for(int x=i,y=j;x>=0 && y<n;x--,y++) if(a[x][y] == 'Q') return false;
    return true;
}

void fun(int i,int n,vector<vector<char>> &a){
    if(i >= n){
        print(a);
        return;
    }
    for(int j=0;j<n;j++){
        if(isSafe(a,i,j)){
            a[i][j] = 'Q';
            fun(i+1,n,a);
            a[i][j] = '-';
        }
    }
}

void solve(int n){
    vector<vector<char>> a(n,vector<char>(n,'-'));
    fun(0,n,a);
}

int main(){
    int n = 5;
    solve(n);

    return 0;
}