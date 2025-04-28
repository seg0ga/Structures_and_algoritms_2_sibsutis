#include <stdio.h>
#include <string.h>

#define SIZE 4

struct Contact {
    char name[50];
    char lastname[50];
    int age;
    int number;};

int lessByName(int a, int b, struct Contact contacts[]) {
    int cmp = strcmp(contacts[a].lastname, contacts[b].lastname);
    if (cmp != 0) return cmp < 0;
    return strcmp(contacts[a].name, contacts[b].name) < 0;}

int lessByNameAndAge(int a, int b, struct Contact contacts[]) {
    int cmp = strcmp(contacts[a].name, contacts[b].name);
    if (cmp != 0) return cmp < 0;
    return contacts[a].age < contacts[b].age;}

void printContacts(struct Contact contacts[], int index[], int size) {
    for (int i = 0; i < size; i++) {
        struct Contact c = contacts[index[i]];
        printf("%s %s, Возраст: %d, Номер: %d\n", c.lastname, c.name, c.age, c.number);}
    printf("\n");}

void printIndexArray(int index[], int size) {
    printf("Индексный массив:  ");
    for (int i = 0; i < size; i++) {
        printf("%d ", index[i]);}
    printf("\n");}

void sortIndex(struct Contact contacts[], int index[], int size, int (*less)(int, int, struct Contact[])) {
    for (int i = 1; i < size; i++) {
        int temp = index[i];
        int j = i - 1;
        while (j >= 0 && less(temp, index[j], contacts)) {
            index[j + 1] = index[j];
            j--;}
        index[j + 1] = temp;}}

int main() {
    struct Contact contacts[SIZE] = {
        {"Сергей", "Демин", 18, 8983},
        {"Петр", "Демин", 76, 1234},
        {"Андрей", "Синицын", 18, 4321},
        {"Андрей", "Куплинов", 19, 6666},};
    int index[SIZE];
    for (int i = 0; i < SIZE; i++) {
        index[i] = i;}

    printf("Исходный справочник:\n");
    printIndexArray(index, SIZE);
    printContacts(contacts, index, SIZE);

    sortIndex(contacts, index, SIZE, lessByName);
    printf("\nСортировка по фамилии и имени:\n");
    printIndexArray(index, SIZE);
    printContacts(contacts, index, SIZE);

    sortIndex(contacts, index, SIZE, lessByNameAndAge);
    printf("Сортировка по имени и возрасту:\n");
    printIndexArray(index, SIZE);
    printContacts(contacts, index, SIZE);
    
    return 0;
}
