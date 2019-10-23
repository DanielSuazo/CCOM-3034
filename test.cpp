#include<cstdio>
#include<iostream>
#include<ctime>

using namespace std;

int aa(int m, int n){
    if(m==0) return n+1;
    if(m>0 && n==0) return aa(m-1,1);
    if(m>0 && n>0) return aa(m-1, aa(m, n-1));
}
int main(){

    clock_t start;

    start = clock();

    aa(4, 3);

    cout << clock() - start << '\n';
}