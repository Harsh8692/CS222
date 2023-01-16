#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

long long fib(int n){
    if(n==0||n==1)return n;
    else return fib(n-1)+fib(n-2);
}
int main(){
    int N = 50;
    long long value;
    for(int i=1;i<=N;i++){
        cout<<"For i = "<<i<<":"<<endl;
        auto startTime = high_resolution_clock::now();
        value = fib(i);
        auto endTime = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(endTime-startTime);
        cout<<"n = "<<i<<" log(Fn) = "<<log2(fib(i))<<endl;
        cout<<"n = "<<i<<" log(T(n)) = "<<log2(duration.count())<<" microseconds"<<endl;
    }
    return 0;
}