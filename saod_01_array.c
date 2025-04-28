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

void PrintMas(long long int a[], int n){
    for (int i=0;i<n;i++){
        printf("%lld ",a[i]);
    }printf("\n");}

void FillRand(long long int a[], int n){
    srand(time(NULL));
    for (int i=0;i<n;i++){
        a[i]=rand();}}

unsigned long long int CheckSum(long long int a[], int n){
    unsigned long long int summa;
    for (int i=0;i<n;i++){
        summa+=a[i];
    }return (unsigned long long int)summa;}

float RunNumber(long long int a[],int n){
    int seria=1;
    for (int i=0;i<n-1;i++){
        if (a[i]>a[i+1]){
            seria+=1;}}return seria;}

int main(){
    int n,ser,sus;
    long long int sr_ser=0;
    unsigned long long int sum;
    printf("Введите длину массива: ");
    scanf("%d", &n);
    long long int a[n];

    FillInc(a,n);
    PrintMas(a,n);
    sus = CheckSum(a,n);
    ser = RunNumber(a,n);
    printf("Контрольная сумма: %d \n",sus);
    printf("Количество серий: %d \n\n",ser);

    FillDec(a,n);
    PrintMas(a,n);
    sus = CheckSum(a,n);
    ser = RunNumber(a,n);
    printf("Контрольная сумма: %d \n",sus);
    printf("Количество серий: %d \n\n",ser);

    FillRand(a,n);
    PrintMas(a,n);
    sus = CheckSum(a,n);
    ser = RunNumber(a,n);
    printf("Контрольная сумма: %lld \n",sum);
    printf("Количество серий: %d \n\n",ser);
}
