#include <bits/stdc++.h>
using namespace std; 
using namespace std::chrono;

void swap(int* a,int *b){
    int temp =*(a);
    *(a)=*(b);
    *(b)=temp;
}
int fixPivot(int arr[],int st,int end){
    //if(st>end)return -1;
    if(st==end)return st;
    int p=arr[st];
    int i;
    int j;
    for(i=st+1;i<=end;i++){
        if(arr[i]>=p){
            break;
        }
    }
    for(j=end;j>st;j--){
        if(arr[j]<p){
            break;
        }
    }
    if(i>=j){
        swap(&arr[st],&arr[j]);
        return j;
    }
    else{
        swap(&arr[i],&arr[j]);
    }
    return fixPivot(arr,st,end);
}

void Quicksort(int arr[],int st,int end){
    if(st==end)return;
    int pvtindx=fixPivot(arr,st,end);
    if(pvtindx>st){
        Quicksort(arr,st,pvtindx-1);
    }
    if(pvtindx<end){
        Quicksort(arr,pvtindx+1,end);
        return;
    }
}
int main(){
    int k;
    cout<<"Enter the value of k : "<<endl;
    cin>>k;
    int* cis=(int*)malloc(k*sizeof(int));
    for(int i=1;i<=k;i++){
        cout<<"For i = "<<i<<" : "<<endl;
        int n = pow(2,i);
        int a[n];
        for(int j=0;j<n;j++){
            a[j]=rand()%1000;
        }
        
        auto startTime = high_resolution_clock::now();
        Quicksort(a,0,n-1);
        auto endTime = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(endTime-startTime);
        cout << "T("<<n<<") = "<< duration.count() << " microseconds" << endl;
        double ci = (duration.count())/(n*log2(n));
        cout<<"The value of T(n)/nlogn = "<<ci<<endl;
        cout<<"("<<i<<" "<<n<<" "<<duration.count()<<" "<<i*n<<" "<<ci<<")"<<endl;

        cis[i-1]=ci;
    }
    int sum1=0, sum2=0;
    for(int i=0;i<k;i++){
        sum1+=cis[i];
    }
    double expectedValue = (double)sum1/k;
    for(int i=0;i<k;i++){
        sum2+=(cis[i]-expectedValue)*(cis[i]-expectedValue);
    }
    double variance = (double)sum2/k;
    cout <<"Expected value of cis : "<<expectedValue<<endl;
    cout<<"Variance of cis : "<<variance<<endl;
    return 0;
}