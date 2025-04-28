#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillRand(long long int a[], int n){
    srand(time(NULL));
    for (int i=0;i<n;i++){
        a[i]=rand()%100;}}

int ShellSort(long long int a[], int n) {
    int h=1;
    while (h<=n/3) {
        h=3*h+1;}

    while (h>0) {
        for (int i=h;i<n;i++) {
            long long int t=a[i];
            int j=i;
            while (j>=h) {
                if (a[j-h]>t) {
                    a[j]=a[j-h];
                    j-=h;
                } else {
                    break;}}
            a[j]=t;}
        h=(h-1)/3;}}


int BinarySearch1(long long int a[], int n, int X) {
    int L=0,R=n-1;
    int C=0;

    while (L<=R){
        int m=(L+R)/2;
        C++;
        if (a[m]==X) {
            break;
        }
        C++;
        if (a[m]<X) {
            L=m+1;
        }else{
            R=m-1;}
    }return C;}

int BinarySearch2(long long int a[], int n, int X) {
    int L=0;
    int R=n-1;
    int C=0;
    while (L<R) {
        int m=(L+R)/2;
        C++;
        if (a[m]<X) {
            L=m+1;
        } else {
            R=m;
        }
}
    C++;
    return C;
}
int main(){
    int n1=100,n2=200,n3=300,n4=400,n5=500,n6=600,n7=700,n8=800,n9=900,n10=1000,x=22;
    long long int a1[n1],a2[n2],a3[n3],a4[n4],a5[n5],a6[n6],a7[n7],a8[n8],a9[n9],a10[n10];
    int f1,f2,f3,f4,f5,f6,f7,f8,f9,f10;
    int s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
    FillRand(a1,n1);    FillRand(a6,n6);
    FillRand(a2,n2);    FillRand(a7,n7);
    FillRand(a3,n3);    FillRand(a8,n8);
    FillRand(a4,n4);    FillRand(a9,n9);
    FillRand(a5,n5);    FillRand(a10,n10);
    ShellSort(a1,n1);    ShellSort(a6,n6);
    ShellSort(a2,n2);    ShellSort(a7,n7);
    ShellSort(a3,n3);    ShellSort(a8,n8);
    ShellSort(a4,n4);    ShellSort(a9,n9);
    ShellSort(a5,n5);    ShellSort(a10,n10);

    f1=BinarySearch1(a1,n1,x);
    f2=BinarySearch1(a2,n2,x);
    f3=BinarySearch1(a3,n3,x);
    f4=BinarySearch1(a4,n4,x);
    f5=BinarySearch1(a5,n5,x);
    f6=BinarySearch1(a6,n6,x);
    f7=BinarySearch1(a7,n7,x);
    f8=BinarySearch1(a8,n8,x);
    f9=BinarySearch1(a9,n9,x);
    f10=BinarySearch1(a10,n10,x);
    s1=BinarySearch2(a1,n1,x);
    s2=BinarySearch2(a2,n2,x);
    s3=BinarySearch2(a3,n3,x);
    s4=BinarySearch2(a4,n4,x);
    s5=BinarySearch2(a5,n5,x);
    s6=BinarySearch2(a6,n6,x);
    s7=BinarySearch2(a7,n7,x);
    s8=BinarySearch2(a8,n8,x);
    s9=BinarySearch2(a9,n9,x);
    s10=BinarySearch2(a10,n10,x);



    printf(" _______________________________\n");
    printf("|       |           |           |\n");
    printf("|   N   |Сф 1 версия|Сф 2 версия|\n");
    printf("|_______|___________|___________|\n");
    printf("|  100  |      %d         %d    |\n",f1,s1);
    printf("|_______|_______________________|\n");
    printf("|  200  |      %d         %d    |\n",f2,s2);
    printf("|_______|_______________________|\n");
    printf("|  300  |      %d         %d    |\n",f3,s3);
    printf("|_______|_______________________|\n");
    printf("|  400  |      %d         %d    |\n",f4,s4);
    printf("|_______|_______________________|\n");
    printf("|  500  |      %d         %d    |\n",f5,s5);
    printf("|_______|_______________________|\n");
    printf("|  600  |      %d         %d    |\n",f6,s6);
    printf("|_______|_______________________|\n");
    printf("|  700  |      %d         %d    |\n",f7,s7);
    printf("|_______|_______________________|\n");
    printf("|  800  |      %d         %d    |\n",f8,s8);
    printf("|_______|_______________________|\n");
    printf("|  900  |      %d         %d    |\n",f9,s9);
    printf("|_______|_______________________|\n");
    printf("| 1000  |      %d         %d    |\n",f10,s10);
    printf("|_______|_______________________|\n");
}
