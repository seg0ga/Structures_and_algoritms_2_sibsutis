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
int ShellSort(long long int a[], int n) {
    int M=0, C=0;
    int h=1;
    while (h<=n/3) {
        h=3*h+1;
    }

    while (h>0) {
        for (int i=h;i<n;i++) {
            long long int t=a[i];
            M++;
            int j=i;
            while (j>=h) {
                C++;
                if (a[j-h]>t) {
                    a[j]=a[j-h];
                    M++;
                    j-=h;
                } else {
                    break;
                }}
            a[j]=t;
            M++;}
        h=(h-1)/3;
    }return M + C;}

void PrintMas(long long int a[], int n){
    for (int i=0;i<n;i++){
        printf("%lld ",a[i]);
    }printf("\n");}

int Rd_insert(long long int a[],int n){
    FillRand(a,n); return InsertSort(a,n);}
int Rd_shell(long long int a[],int n){
    FillRand(a,n); return ShellSort(a,n);}


int main(){
    char *a = "1 4 13 40", *b= "1 4 13 40 121", *c="1 4 13 40 121 364";
    int n1=100,n2=200,n3=300,n4=400,n5=500;
    long long int a1[n1],a2[n2],a3[n3],a4[n4],a5[n5];
    int s1,s2,s3,s4,s5,i1,i2,i3,i4,i5;
    s1=Rd_shell(a1,n1);
    s2=Rd_shell(a2,n2);
    s3=Rd_shell(a3,n3);
    s4=Rd_shell(a4,n4);
    s5=Rd_shell(a5,n5);
    i1=Rd_insert(a1,n1);
    i2=Rd_insert(a2,n2);
    i3=Rd_insert(a3,n3);
    i4=Rd_insert(a4,n4);
    i5=Rd_insert(a5,n5);

    printf(" ___________________________________________\n");
    printf("|       |      h1..hm     |        |        |\n");
    printf("|   N   |    по формуле   | Insert |  Shell |\n");
    printf("|       |     Д. Кнута    |  Mф+Сф |  Мф+Сф |\n");
    printf("|_______|_________________|________|________|\n");
    printf("|  100  |    %s    |  %d  |  %d  |\n",a,i1,s1);
    printf("|_______|_________________|________|________|\n");
    printf("|  200  |  %s  |  %d |  %d  |\n",b,i2,s2);
    printf("|_______|_________________|________|________|\n");
    printf("|  300  |  %s  |  %d |  %d  |\n",b,i3,s3);
    printf("|_______|_________________|________|________|\n");
    printf("|  400  |%s|  %d |  %d |\n",c,i4,s4);
    printf("|_______|_________________|________|________|\n");
    printf("|  500  |%s| %d |  %d |\n",c,i5,s5);
    printf("|_______|_________________|________|________|\n");
}
