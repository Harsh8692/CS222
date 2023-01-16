#include<bits/stdc++.h>
using namespace std;

void multiplication(int** a,int ra,int ca,int** b,int rb,int cb,int**c){
    int row = ra; int col=cb;
	int** p=(int **) malloc (sizeof(int*)*row) ;
	for (int i =0; i<row ; i++)
	*(p+i)=(int*) malloc (sizeof(int)*col) ;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            p[i][j]=0;
            for(int k=0;k<ca;k++){
                p[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            a[i][j]=p[i][j];
        }
    }
}

void expfunction(int** a,int b,int** c,int row,int col){//This function only calclates exponent if b is non zero
    int I[2][2]={{1,0},{0,1}};
    // static int count=0;
    // if(count==0){
    //     for(int i=0;i<2;i++){
    //         for(int j=0;j<2;j++){
    //             c[i][j]=a[i][j];//Starting value of a is stored in c
    //         }
    //     }
    // }
    // if(b==0){
    //     for(int i=0;i<2;i++){
    //         for(int j=0;j<2;j++){
    //             c[i][j]=I[i][j];
    //         }
    //     }
    //     return;
    // }
    expfunction(a,b/2,c,row,col);
    multiplication(a,2,2,a,2,2,c);
    if(b%2!=0){
        multiplication(a,2,2,a,2,2,c);
    }
}
void fun(int**a ,int b,int row,int col){
    // int I[][2]={{1,0},{0,1}};
    if(b==0){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==j){
                    a[i][j]=1;
                }
                else a[i][j]=0;
            }
        }
        return;
    }
    int** p=(int **) malloc (sizeof(int*)*row) ;
	for (int i =0; i<row ; i++)
	*(p+i)=(int*) malloc (sizeof(int)*col) ;
    expfunction(a,b,p,row,col);
    return;
}
int main(){
    int N=50;
    // int b[2][2]={{1,1},{1,0}};
    // int* c = &b[0][0];
    int row,col;
    cout<<"Enter the number of rows : "<<endl;
    cin>>row;
    cout<<"Enter the number of cols : "<<endl;
    cin>>col;
    int** d=(int **)malloc(sizeof(int*)*row);
    for(int i=0;i<row;i++){
        *(d+i)=(int *)malloc(sizeof(int)*col);
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>d[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        fun(d,i-1,2,2);
        cout<<"F("<<i<<") : "<<d[0][0]<<endl;
    }
    // int a[2][2]={{1,2},{3,4}};
    // int b[2][2]={{1,0},{0,1}};
    // int * k = &a[0][0];
    // int *l = &b[0][0];
    // int** c = multiplication(&(k),2,2,&(l),2,2);
    // for (int i =0; i<2 ; i ++, printf ( "\n" ) )
	// 	for (int j =0; j<2 ; j++)
	// 		printf ( "%d " , c [ i ] [ j ] ) ;
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// // int I[2][2]={{1,0}},{0,1};

// class Matrix {
//     public:    
//     int **m;
//     int row, col;
//     public:
//     Matrix(){
//         printf("Enter the no of rows in the matrix : ");
//         scanf("%d",&row);
//         printf("Enter the no of columns in the matrix : ");
//         scanf("%d",&col);
//         m = (int**)malloc(sizeof(int*)*row);
//         for (int i = 0; i < row; i++)
//         {
//             *(m+i)= (int*)malloc(sizeof(int)*col);
//         }
//         // initialize
//         for (int i = 0; i < row; i++)
//         {
//             for (int j = 0; j < col; j++)
//             {
//                 if(i==j)m[i][j]=1;
//                 else m[i][j]=0;
//             }
//         }   
//     }
//     void initialize(){
//         // printf("Enter the no of rows in the matrix : ");
//         // scanf("%d",&row);
//         // printf("Enter the no of columns in the matrix : ");
//         // scanf("%d",&col);
//         // m = (int**)malloc(sizeof(int*)*row);
//         // for (int i = 0; i < row; i++)
//         // {
//         //     *(m+i)= (int*)malloc(sizeof(int)*col);
//         // }
//         for (int i = 0; i < row; i++)
//         {
//             for (int j = 0; j < col; j++)
//             {
//                 printf("Enter the value at %d row and %d col in the matrix : ",i+1,j+1);
//                 scanf("%d" , &m[i][j]);
//             }
//         }
//     }
//     // This function prints matrix
//     void print(){
//         for (int i = 0; i < row; i++)
//         {
//             for (int j = 0; j < col; j++)
//             {
//                 printf("%d ",m[i][j]);
//             }
//             printf("\n");
//         }    
//     }
//     Matrix add(Matrix a){
//         Matrix temp;
//         for (int i = 0; i < row; i++)
//         {
//             for (int j = 0; j < col; j++)
//             {
//                 temp.m[i][j]=m[i][j]+a.m[i][j];
//             }
//         }
//         return temp;
//     }
//     ~Matrix(){
//         for (int i = 0; i < row; i++)
//         {
//             free(m[i]);
//         }
//         free(m);
//     }
//     Matrix exponentialPower(Matrix a,int n){
//         Matrix I;
//         if (n==0){
//             return I;
//         }
//         Matrix C = exponentialPower(a,n/2);
//         C.multiply(C);
//         if(n%2!=0){
//             return C.multiply(a);
//         }
//         else return C;

//     }
//     Matrix multiply(Matrix a){
//         Matrix m2;
//         for (int i = 0; i < row; i++)
//         {
//             for (int j = 0; j < a.col; j++)
//             {   
//                 m2.m[i][j] = 0;
//                 for (int k = 0; k < col; k++)
//                 {
//                     m2.m[i][j] += m[i][k]*a.m[k][j];
//                 }
                
//             }
            
//         }
//         return m2;
//     }
// };

// int main(){
//     int n=50;
//     Matrix A;
//     A.initialize();
//     for(int i =1;i<=n;i++){
//         Matrix C = C.exponentialPower(A,i-1);
//         cout<<"F("<<i<<") : "<<C.m[0][0]<<endl;
//     }
//     return 0;
// }