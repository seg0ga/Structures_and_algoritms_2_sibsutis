#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BASE 256

typedef struct Node {
    unsigned int value;
    struct Node* next;
} Node;

typedef struct {
    Node* Head;
    Node* Tail;
} Queue;

Node* createNode(unsigned int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) exit(EXIT_FAILURE);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;}

Node* generateRandomList(int size, int bytes) {
    Node* head = NULL;
    Node* tail = NULL;
    unsigned int maxValue = (bytes == 2) ? 0xFFFF : 0xFFFFFFFF;
    for (int i = 0; i < size; i++) {
        unsigned int value = rand() % maxValue;
        Node* node = createNode(value);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;}}
    return head;}

Node* generateSortedList(int size, int descending, int bytes) {
    Node* head = NULL;
    Node* tail = NULL;
    unsigned int start = (bytes == 2) ? 0x1000 : 0x10000000;
    for (int i = 0; i < size; i++) {
        unsigned int value = descending ? (start + size - i) : (start + i);
        Node* node = createNode(value);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;}}
    return head;}

void freeList(Node* head) {
    Node* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);}}

long calculateM(int L, int m, int n) {
    return (long)L * (n);}

void DigitalSort(Node** headPtr, int L) {
    Queue Q[BASE];
    Node* head = *headPtr;
    
    for (int j = L-1; j >= 0; j--) {
        for (int i = 0; i < BASE; i++) {
            Q[i].Head = NULL;
            Q[i].Tail = NULL;}
        
        Node* p = head;
        while (p != NULL) {
            unsigned char d = (p->value >> (8*j)) & 0xFF;
            Node* next = p->next;
            
            if (Q[d].Head == NULL) {
                Q[d].Head = Q[d].Tail = p;
            } else {
                Q[d].Tail->next = p;
                Q[d].Tail = p;}
            p->next = NULL;
            p = next;}

        head = NULL;
        Node* tail = NULL;
        for (int i = 0; i < BASE; i++) {
            if (Q[i].Head != NULL) {
                if (head == NULL) {
                    head = Q[i].Head;
                    tail = Q[i].Tail;
                } else {
                    tail->next = Q[i].Head;
                    tail = Q[i].Tail;}}}}
    
    *headPtr = head;}

void printTableRow(int n, long m1, long m2, long m3, long m4, int isLeft) {
    if (isLeft) {
        printf("|%3d|%5ld |%5ld  |%5ld  |%5ld  |      ", 
               n, m1, m2, m3, m4);
    } else {
        printf("|%3d|%5ld |%5ld  |%5ld  |%5ld  |\n", 
               n, m1, m2, m3, m4);
        printf("|___|______|_______|_______|_______|      |___|______|_______|_______|_______|\n");}}

void runExperiments() {
    int sizes[] = {100, 200, 300, 400, 500};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    
    printf("\n        2-байтовые числа                            4-байтовые числа\n");
    printf(" __________________________________        __________________________________\n");
    printf("| N |M теор|Mф убыв|Mф случ|Mф возр|      | N |M теор|Mф убыв|Mф случ|Mф возр|\n");
    printf("|___|______|_______|_______|_______|      |___|______|_______|_______|_______|\n");
    
    for (int s = 0; s < numSizes; s++) {
        int n = sizes[s];
        
        Node *listDesc2 = generateSortedList(n, 1, 2);
        Node *listRand2 = generateRandomList(n, 2);
        Node *listAsc2 = generateSortedList(n, 0, 2);
        long M2 = calculateM(2, BASE, n);

        Node *listDesc4 = generateSortedList(n, 1, 4);
        Node *listRand4 = generateRandomList(n, 4);
        Node *listAsc4 = generateSortedList(n, 0, 4);
        long M4 = calculateM(4, BASE, n);
        
        printTableRow(n, M2, M2, M2, M2, 1);
        printTableRow(n, M4, M4, M4, M4, 0);

        freeList(listDesc2);
        freeList(listRand2);
        freeList(listAsc2);
        freeList(listDesc4);
        freeList(listRand4);
        freeList(listAsc4);}}

int main() {
    srand(time(NULL));
    runExperiments();
    return 0;}
