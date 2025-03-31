#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char lastname[50];
    int age;
    int number;};

int sortKey = 1;  
int ascending = 1; 
int less1(struct Contact a, struct Contact b) {
    int result = 0;
    result=strcmp(a.lastname,b.lastname);
    if (result==0) {
        result=strcmp(a.name, b.name);}
    return result;}
int less2(struct Contact a, struct Contact b) {
    int result = 0;
    result=strcmp(a.lastname,b.lastname);
    if (result==0) {
        result=strcmp(a.name, b.name);}
    return -result;}
int less3(struct Contact a, struct Contact b) {
    int result = 0;
    result=a.age-b.age;
    if (result==0) {
        result=a.number-b.number;}
    return result;}
int less4(struct Contact a, struct Contact b) {
    int result = 0;
    result=a.age-b.age;
    if (result==0) {
        result=a.number-b.number;}
    return -result;}

void InsertSort1(struct Contact contacts[], int size) {
    for (int i=1;i<size;i++) {
        struct Contact temp=contacts[i];
        int j=i-1;
        while (j>=0 && less1(contacts[j],temp)>0) {
            contacts[j+1]=contacts[j];
            j--;}
        contacts[j+1]=temp;}}
void InsertSort2(struct Contact contacts[], int size) {
    for (int i=1;i<size;i++) {
        struct Contact temp=contacts[i];
        int j=i-1;
        while (j>=0 && less2(contacts[j],temp)>0) {
            contacts[j+1]=contacts[j];
            j--;}
        contacts[j+1]=temp;}}
void InsertSort3(struct Contact contacts[], int size) {
    for (int i=1;i<size;i++) {
        struct Contact temp=contacts[i];
        int j=i-1;
        while (j>=0 && less3(contacts[j],temp)>0) {
            contacts[j+1]=contacts[j];
            j--;}
        contacts[j+1]=temp;}}
void InsertSort4(struct Contact contacts[], int size) {
    for (int i=1;i<size;i++) {
        struct Contact temp=contacts[i];
        int j=i-1;
        while (j>=0 && less4(contacts[j],temp)>0) {
            contacts[j+1]=contacts[j];
            j--;}
        contacts[j+1]=temp;}}
void printContacts(struct Contact contacts[],int size) {
    for (int i=0;i<size;i++) {
        printf("Фамилия: %s, Имя: %s, Возраст: %d, Номер: %d\n",contacts[i].lastname, contacts[i].name, contacts[i].age, contacts[i].number);}
    printf("\n");}

int main() {
    struct Contact contacts[] = {
        {"Сергей", "Демин", 18, 89831},
        {"Петр", "Демин", 75, 89293},
        {"Михаил", "Синицын", 12, 89529},
        {"Андрей", "Кутенков", 49, 89050},};

    int size = 4;
    printf("Исходный справочник:\n");
    printContacts(contacts, size);
    printf("Ключ сортировки(0-Ф+И, 1-В+Н): ");
    scanf("%d", &sortKey);
    printf("Направление сортировки(1-по возр., 0-по убыв.): ");
    scanf("%d", &ascending);
    if (sortKey==0 && ascending==1){InsertSort1(contacts,size);}
    if (sortKey==0 && ascending==0){InsertSort2(contacts,size);}
    if (sortKey==1 && ascending==1){InsertSort3(contacts,size);}
    if (sortKey==1 && ascending==0){InsertSort4(contacts,size);}
    printf("Отсортированный список:\n");
    printContacts(contacts, size);
    return 0;
}
