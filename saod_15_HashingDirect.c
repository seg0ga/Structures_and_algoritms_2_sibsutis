#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

int insert(Node** table, int tableSize, int key) {
    int index = key % tableSize;
    Node* head = table[index];
    int collision = (head != NULL);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) exit(EXIT_FAILURE);
    newNode->key = key;
    newNode->next = head;
    table[index] = newNode;
    return collision;}

void freeTable(Node** table, int tableSize) {
    for (int i = 0; i < tableSize; i++) {
        Node* current = table[i];
        while (current) {
            Node* tmp = current;
            current = current->next;
            free(tmp);}}
    free(table);}

void generateRandomText(char* buffer, size_t size) {
    const char charset[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. 1234567890!@#$%^&*()_+-=[]{}|;\':\",./<>?~` Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. 1234567890!@#$%^&*()_+-=[]{}|;\':\",./<>?~` Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. 1234567890!@#$%^&*()_+-=[]{}|;\':\",./<>?~` Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum. 1234567890!@#$%^&*()_+-=[]{}|;\':\",./<>?~`";
    for (size_t i = 0; i < size - 1; i++) {
        buffer[i] = charset[rand() % (sizeof(charset) - 1)];}
    buffer[size - 1] = '\0';}

int main() {
    srand(time(NULL));
    int primes[] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 47,101};
    int primesCount = sizeof(primes) / sizeof(primes[0]);

    const size_t textSize = 100;
    char* text = (char*)malloc(textSize + 1);
    generateRandomText(text, textSize + 1);
    printf("\n Хеширование текста (1 КБ) методом прямого связывания \n");
    printf(" ______________________________________\n");
    printf("|Размер|Кол-во символов|Кол-во коллизий|\n");
    printf("|______|_______________|_______________|\n");

    for (int p = 0; p < primesCount; p++) {
        int tableSize = primes[p];
        Node** table = (Node**)calloc(tableSize, sizeof(Node*));

        int collisionCount = 0;
        for (size_t i = 0; i < textSize && text[i] != '\0'; i++) {
            collisionCount += insert(table, tableSize, (int)text[i]);}

        printf("|%4d  |%10zu     |%10d     |\n", tableSize, strlen(text), collisionCount);
        printf("|______|_______________|_______________|\n");
        freeTable(table, tableSize);
    }



    free(text);
    return 0;}
