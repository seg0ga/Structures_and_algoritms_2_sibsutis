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
    for (int i=0;i<n;i++){
        a[i]=rand();}}

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

int Ub(long long int a[],int n){
    FillDec(a,n); return BubbleSort(a,n);}

int Vz(long long int a[],int n){
    FillInc(a,n); return BubbleSort(a,n);}

int Ub2(long long int a[],int n){
    FillDec(a,n); return ShakerSort(a,n);}
    
int Vz2(long long int a[],int n){
    FillInc(a,n); return ShakerSort(a,n);}

int main(){
    srand(time(NULL));
    int n1 = 100, n2 = 200, n3 = 300, n4 = 400, n5 = 500;
    int u1, u2, u3, u4, u5, u11, u21, u31, u41, u51;
    int v1, v2, v3, v4, v5, v11, v21, v31, v41, v51;
    int r1, r2, r3, r4, r5, r11, r21, r31, r41, r51;
    long long int a1[n1], a2[n2], a3[n3], a4[n4], a5[n5],a12[n1], a22[n2], a32[n3], a42[n4], a52[n5];


    u1 = Ub(a1, n1);
    u2 = Ub(a2, n2);
    u3 = Ub(a3, n3);
    u4 = Ub(a4, n4);
    u5 = Ub(a5, n5);
    v1 = Vz(a1, n1);
    v2 = Vz(a2, n2);
    v3 = Vz(a3, n3);
    v4 = Vz(a4, n4);
    v5 = Vz(a5, n5);
    u11 = Ub2(a12, n1);
    u21 = Ub2(a22, n2);
    u31 = Ub2(a32, n3);
    u41 = Ub2(a42, n4);
    u51 = Ub2(a52, n5);
    v11 = Vz2(a1, n1);
    v21 = Vz2(a2, n2);
    v31 = Vz2(a3, n3);
    v41 = Vz2(a4, n4);
    v51 = Vz2(a5, n5);
    FillRand(a1, n1);
    FillRand(a2, n2);
    FillRand(a3, n3);
    FillRand(a4, n4);
    FillRand(a5, n5);
    FillRand(a12, n1);
    FillRand(a22, n2);
    FillRand(a32, n3);
    FillRand(a42, n4);
    FillRand(a52, n5);
    
    r1 = BubbleSort(a1, n1);
    r11 = ShakerSort(a12, n1);
    r2 = BubbleSort(a2, n2);
    r21 = ShakerSort(a22, n2);
    r3 = BubbleSort(a3, n3);
    r31 = ShakerSort(a32, n3);
    r4 = BubbleSort(a4, n4);
    r41 = ShakerSort(a42, n4);
    r5 = BubbleSort(a5, n5);
    r51 = ShakerSort(a52, n5);

    printf(" _____________________________________________________________\n");
    printf("|       | Фактический M+С (Bubble) | Фактический M+С (Shaker) |\n");
    printf("|   N   |__________________________|__________________________|\n");
    printf("|       | Убыв.  |  Случ. |  Возр. | Убыв.  |  Случ. |  Возр. |\n");
    printf("|_______|________|________|________|________|________|________|\n");
    printf("|  100  |  %d |  %d |  %d  | %d  |  %d |   %d   |\n",u1,r1,v1,u11,r11,v11);
    printf("|_______|________|________|________|________|________|________|\n");
    printf("|  200  |  %d |  %d |  %d |  %d |  %d |  %d   |\n",u2,r2,v2,u21,r21,v21);
    printf("|_______|________|________|________|________|________|________|\n");
    printf("|  300  | %d | %d |  %d | %d |  %d |  %d   |\n",u3,r3,v3,u31,r31,v31);
    printf("|_______|________|________|________|________|________|________|\n");
    printf("|  400  | %d | %d |  %d | %d | %d |  %d   |\n",u4,r4,v4,u41,r41,v41);
    printf("|_______|________|________|________|________|________|________|\n");
    printf("|  500  | %d | %d | %d | %d | %d |  %d   |\n",u5,r5,v5,u51,r51,v51);
    printf("|_______|________|________|________|________|________|________|\n");}
