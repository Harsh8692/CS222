#include <bits/stdc++.h>
using namespace std; 
using namespace std::chrono;

void merge(int* a,int st,int end,int mid,int *b){
    int size = end-st+1;
    int i = st; int j = mid+1;
    int k =st;
    while(i<=mid&&j<=end){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;k++;
        }
        else{
            b[k]=a[j]; 
            j++;k++;
        }
    }
    if(j>end){
        while(i<=mid){
            b[k]=a[i];
            i++;k++;
        }
    }
    else if(i>mid){
        while(j<=end){
            b[k]=a[j];
            j++;k++;
        }
    }
    for(int l=st;l<=end;l++){
        a[l]=b[l];
    }
}
void mergeSort(int* a,int st,int end,int* b){
    if(st>=end)return;
    int mid = (st+end)/2;
    mergeSort(a,st,mid,b);
    mergeSort(a,mid+1,end,b);
    merge(a,st,end,mid,b);
}
void print(int *a, int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<", ";
    }
    cout<<endl;
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
        int b[n];
        for(int j=0;j<n;j++){
            a[j]=rand()%1000;
        }
        
        auto startTime = high_resolution_clock::now();
        mergeSort(a,0,n-1,b);
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