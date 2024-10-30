#include <bits/stdc++.h>
using namespace std;

int fib_rec(int n){
    if(n<=1) return n;
    return fib_rec(n-1) + fib_rec(n-2);
}

int fib_iter(int n){
    if(n<=1) return n;
    int a = 0;
    int b = 1;
    int c;
    for(int i=2;i<=n;i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c; 
}

int main(){

    cout<<fib_rec(5)<<' '<<fib_iter(5)<<'\n';

    return 0;
}