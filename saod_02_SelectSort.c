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
        a[i]=rand()%100;}}

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

int SelectSort2(long long int a[], int n){
    int M=0,C=0;
    for (int i=0;i<n-1;i++){
        int k = i;
        for (int j=i+1;j<n;j++){
            C++;
            if (a[k] > a[j]){
                k=j;}}
        if (i!=k){
            M=M+3;
            int p = a[i];
            a[i]=a[k];
            a[k]=p;}}
    return M+C;}

void PrintMas(long long int a[], int n){
    for (int i=0;i<n;i++){
        printf("%lld ",a[i]);
    }printf("\n");}

int main(){
    int n1=10,n2=100,i1,i2,i3,i4,i5,i6,u1,u2,u3,u4,u5,u6;
    long long int a1[n1],a2[n2];
    int teor1=(3*(10-1))+(10*10-10)/2;
    int teor2=(3*(100-1))+(100*100-100)/2;
    FillInc(a1,n1);
    i1 = SelectSort(a1,n1);
    FillInc(a1,n1);
    u1 = SelectSort2(a1,n1);
    FillDec(a1,n1);
    i2 = SelectSort(a1,n1);
    FillDec(a1,n1);
    u2 = SelectSort2(a1,n1);
    FillRand(a1,n1);
    i3 = SelectSort(a1,n1);
    FillRand(a1,n1);
    u3 = SelectSort2(a1,n1);
    FillInc(a2,n2);
    i4 = SelectSort(a2,n2);
    FillInc(a2,n2);
    u4 = SelectSort2(a2,n2);
    FillDec(a2,n2);
    i5 = SelectSort(a2,n2);
    FillDec(a2,n2);
    u5 = SelectSort2(a2,n2);
    FillRand(a2,n2);
    i6 = SelectSort(a2,n2);
    FillRand(a2,n2);
    u6 = SelectSort2(a2,n2);

    printf(" _______________________________________________________________\n");
    printf("|   N   |  M+C  |      Исходный M+С     |    Улучшенный M+С     |\n");
    printf("|       |       |_______________________|_______________________|\n");
    printf("|       |Теорет.| Убыв. | Случ. | Возр. | Убыв. | Случ. | Возр. |\n");
    printf("|_______|_______|_______|_______|_______|_______|_______|_______|\n");
    printf("|   10  |   %d  |  %d   |   %d  |   %d  |  %d   |  %d   |  %d   |\n",teor1,i2,i3,i1,u2,u3,u1);
    printf("|_______|_______|_______|_______|_______|_______|_______|_______|\n");
    printf("|  100  |  %d | %d  | %d  | %d  | %d  |  %d | %d  |\n",teor2,i5,i6,i4,u5,u6,u4);
    printf("|_______|_______|_______|_______|_______|_______|_______|_______|\n");
}
