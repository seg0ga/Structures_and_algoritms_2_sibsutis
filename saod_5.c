#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillInc(long long int a[], int n){
    for (int i=0;i<n;i++){
        a[i]=i+1;}}

void FillDec(long long int a[], int n){
    int k = n;
    for (int i=0;i<n;i++){
        a[i]=k;
        k--;}}

void FillRand(long long int a[], int n){
    srand(time(NULL));
    for (int i=0;i<n;i++){
        a[i]=rand();}}
int SelectSort(long long int a[], int n){
    int M=0,C=0;
    for (int i=0;i<n-1;i++){
        int k = i;
        for (int j=i+1;j<n;j++){
            C++;
            if (a[k] > a[j]){
                k=j;}}
        M=M+3;
        int p = a[i];
        a[i]=a[k];
        a[k]=p;}
    return M+C;}
int BubbleSort(long long int a[],int n){
    int M=0,C=0;
    for (int i=0;i<n-1;i++){
        for (int j=1;j<n-i;j++){
            C++;
            if (a[j]<a[j-1]){
                M=M+3;
                int t = a[j];
                a[j]=a[j-1];
                a[j-1]=t;}}}return M+C;}        
int InsertSort(long long int a[], int n){
    int M=0, C=0;
    for (int i=1;i<n;i++) {
        long long int t=a[i];
        M++;
        int j=i-1;
        while (j>=0){
            C++;
            if (t<a[j]){
                a[j+1]=a[j];
                C++;;
                j--;}
            else{break;}}
        a[j+1]=t;
        M++;}
    return M+C;}
int ShakerSort(long long int a[], int n) {
    int M=0, C=0;
    int L = 0;
    int R = n-1;
    int k = n;
    do{
        for (int j=R;j>L;j--){
            C++;
            if (a[j]<a[j-1]){
                M=M+3;
                int t = a[j];
                a[j]=a[j-1];
                a[j-1]=t;
                k=j;}}
        L=k;
        for (int j=L;j<R;j++){
            C++;
            if (a[j]>a[j+1]){
                M=M+3;
                int t = a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                    k=j;}}
        R=k;} while (L<R);
    return M + C;}
void PrintMas(long long int a[], int n){
    for (int i=0;i<n;i++){
        printf("%lld ",a[i]);
    }printf("\n");}

int Ub_insert(long long int a[],int n){
    FillDec(a,n); return InsertSort(a,n);}
int Vz_insert(long long int a[],int n){
    FillInc(a,n); return InsertSort(a,n);}

int Rd_insert(long long int a[],int n){
    FillRand(a,n); return InsertSort(a,n);}
int Rd_select(long long int a[],int n){
    FillRand(a,n); return SelectSort(a,n);}
int Rd_bubble(long long int a[],int n){
    FillRand(a,n); return BubbleSort(a,n);}
int Rd_shaker(long long int a[],int n){
    FillRand(a,n); return ShakerSort(a,n);}

int teor(int n){return (((n*n-n)/2) +2*n-2) + ((n*n-n)/2);}

int main(){
    int n1=100,n2=200,n3=300,n4=400,n5=500;
    int u1,u2,u3,u4,u5;
    int v1,v2,v3,v4,v5;
    int r1,r2,r3,r4,r5;
    long long int a1[n1],a2[n2],a3[n3],a4[n4],a5[n5];

    int teor1=teor(n1);
    int teor2=teor(n2);
    int teor3=teor(n3);
    int teor4=teor(n4);
    int teor5=teor(n5);

    u1 = Ub_insert(a1,n1);
    u2 = Ub_insert(a2,n2);
    u3 = Ub_insert(a3,n3);
    u4 = Ub_insert(a4,n4);
    u5 = Ub_insert(a5,n5);
    v1 = Vz_insert(a1,n1);
    v2 = Vz_insert(a2,n2);
    v3 = Vz_insert(a3,n3);
    v4 = Vz_insert(a4,n4);
    v5 = Vz_insert(a5,n5);
    r1 = Rd_insert(a1,n1);
    r2 = Rd_insert(a2,n2);
    r3 = Rd_insert(a3,n3);
    r4 = Rd_insert(a4,n4);
    r5 = Rd_insert(a5,n5);


    printf(" __________________________________________\n");
    printf("|       |  M+C  |      Фактический M+С     |\n");
    printf("|   N   |       |__________________________|\n");
    printf("|       |Теорет.| Убыв.  |  Случ. |  Возр. |\n");
    printf("|_______|_______|________|________|________|\n");
    printf("|  100  | %d |  %d |  %d  |   %d  |\n",teor1,u1,r1,v1);
    printf("|_______|_______|________|________|________|\n");
    printf("|  200  | %d |  %d |  %d |   %d  |\n",teor2,u2,r2,v2);
    printf("|_______|_______|________|________|________|\n");
    printf("|  300  | %d |  %d |  %d |   %d  |\n",teor3,u3,r3,v3);
    printf("|_______|_______|________|________|________|\n");
    printf("|  400  |%d | %d |  %d |   %d |\n",teor4,u4,r4,v4);
    printf("|_______|_______|________|________|________|\n");
    printf("|  500  |%d | %d | %d |  %d  |\n",teor5,u5,r5,v5);
    printf("|_______|_______|________|________|________|\n");

    printf(" __________________________________________\n");
    printf("|       |          Фактический M+С         |\n");
    printf("|   N   |__________________________________|\n");
    printf("|       | Select| Bubble | Shaker | Insert |\n");
    printf("|_______|_______|________|________|________|\n");
    printf("|  100  |  %d |  %d |  %d |  %d  |\n",Rd_select(a1,n1),Rd_bubble(a1,n1),Rd_shaker(a1,n1),Rd_insert(a1,n1));
    printf("|_______|_______|________|________|________|\n");
    printf("|  200  | %d |  %d |  %d | %d  |\n",Rd_select(a2,n2),Rd_bubble(a2,n2),Rd_shaker(a2,n2),Rd_insert(a2,n2));
    printf("|_______|_______|________|________|________|\n");
    printf("|  300  | %d | %d |  %d | %d  |\n",Rd_select(a3,n3),Rd_bubble(a3,n3),Rd_shaker(a3,n3),Rd_insert(a3,n3));
    printf("|_______|_______|________|________|________|\n");
    printf("|  400  | %d | %d | %d |  %d |\n",Rd_select(a4,n4),Rd_bubble(a4,n4),Rd_shaker(a4,n4),Rd_insert(a4,n4));
    printf("|_______|_______|________|________|________|\n");
    printf("|  500  |%d | %d | %d | %d |\n",Rd_select(a5,n5),Rd_bubble(a5,n5),Rd_shaker(a5,n5),Rd_insert(a5,n5));
    printf("|_______|_______|________|________|________|\n");
}
