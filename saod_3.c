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

int BubbleSort(long long int a[],int n){
    int M=0,C=0;
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            C++;
            if (a[j]>a[j+1]){
                M=M+3;
                int t = a[i];
                a[i]=a[j];
                a[j]=t;}}}return M+C;}

void PrintMas(long long int a[], int n){
    for (int i=0;i<n;i++){
        printf("%lld ",a[i]);
    }printf("\n");}

int Ub(long long int a[],int n){
    FillDec(a,n); return BubbleSort(a,n);}

int Vz(long long int a[],int n){
    FillInc(a,n); return BubbleSort(a,n);}

int Rd(long long int a[],int n){
        FillRand(a,n); return BubbleSort(a,n);}

int main(){
    int n1=100,n2=200,n3=300,n4=400,n5=500;
    int u1,u2,u3,u4,u5;
    int v1,v2,v3,v4,v5;
    int r1,r2,r3,r4,r5;
    long long int a1[n1],a2[n2],a3[n3],a4[n4],a5[n5];

    int teor1=((3*(n1*n1-n1))/2)+((n1*n1-n1)/2);
    int teor2=((3*(n2*n2-n2))/2)+((n2*n2-n2)/2);
    int teor3=((3*(n3*n3-n3))/2)+((n3*n3-n3)/2);
    int teor4=((3*(n4*n4-n4))/2)+((n4*n4-n4)/2);
    int teor5=((3*(n5*n5-n5))/2)+((n5*n5-n5)/2);

    u1 = Ub(a1,n1);
    u2 = Ub(a2,n2);
    u3 = Ub(a3,n3);
    u4 = Ub(a4,n4);
    u5 = Ub(a5,n5);
    v1 = Vz(a1,n1);
    v2 = Vz(a2,n2);
    v3 = Vz(a3,n3);
    v4 = Vz(a4,n4);
    v5 = Vz(a5,n5);
    r1 = Rd(a1,n1);
    r2 = Rd(a2,n2);
    r3 = Rd(a3,n3);
    r4 = Rd(a4,n4);
    r5 = Rd(a5,n5);



    printf(" __________________________________________\n");
    printf("|       |  M+C  |      Фактический M+С     |\n");
    printf("|   N   |       |__________________________|\n");
    printf("|       |Теорет.| Убыв.  |  Случ. |  Возр. |\n");
    printf("|_______|_______|________|________|________|\n");
    printf("|  100  | %d |  %d |   %d |   %d |\n",teor1,u1,r1,v1);
    printf("|_______|_______|________|________|________|\n");
    printf("|  200  | %d |  %d |  %d |  %d |\n",teor2,u2,r2,v2);
    printf("|_______|_______|________|________|________|\n");
    printf("|  300  |%d | %d |  %d |  %d |\n",teor3,u3,r3,v3);
    printf("|_______|_______|________|________|________|\n");
    printf("|  400  |%d | %d | %d |  %d |\n",teor4,u4,r4,v4);
    printf("|_______|_______|________|________|________|\n");
    printf("|  500  |%d | %d | %d | %d |\n",teor5,u5,r5,v5);
    printf("|_______|_______|________|________|________|\n");}
