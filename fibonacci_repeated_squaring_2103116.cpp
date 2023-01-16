#include<bits/stdc++.h>
using namespace std;
 
void multiply(long long a[2][2], long long b[2][2])
{
    long long mul[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 2; k++)
                mul[i][j] += a[i][k]*b[k][j];
        }
    }
 
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            a[i][j] = mul[i][j]; 
}
 
long long exponentiation(long long F[2][2], int n)
{
    long long M[2][2] = {{1,1},{1,0}};
    if (n==1)
        return F[0][0] + F[0][1];
 
    exponentiation(F, n/2);
 
    multiply(F, F);
 
    if (n%2 != 0)multiply(F, M);

    return F[0][0] + F[0][1] ;
}

long long fibN3(int n)
{
    long long F[2][2] = {{1,1},{1,0}} ; 
    //Base cases
    if(n==0)
        return 0;
    if(n==1 || n==2)
        return 1;
 
    return exponentiation(F, n-2);
}

int main(){
    int n=50;
    for(int i=1;i<=n;i++){
        cout<<"F("<<i<<") : "<<fibN3(i)<<endl;
    }
    return 0;
}