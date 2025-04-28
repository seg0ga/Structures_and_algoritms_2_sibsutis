#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct Node {
    long long int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int count;
} Queue;

Node* createNode(long long int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;}

void initQueue(Queue* q) {
    q->head = q->tail = NULL;
    q->count = 0;}

void enqueue(Queue* q, long long int data) {
    Node* newNode = createNode(data);
    if (q->tail == NULL) {
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;}
    q->count++;}

void fillQueueAscending(Queue* q, int n) {
    for (int i = 1; i <= n; i++) {
        enqueue(q, i);}}

void fillQueueDescending(Queue* q, int n) {
    for (int i = n; i >= 1; i--) {
        enqueue(q, i);}}

void fillQueueRandom(Queue* q, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        enqueue(q, rand() % (2*n));}}

void freeQueue(Queue* q) {
    Node* current = q->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);}
    q->head = q->tail = NULL;
    q->count = 0;}

void MoveNode(Queue* dest, Queue* src, int* M) {
    if (src->head == NULL) return;
    Node* node = src->head;
    src->head = src->head->next;
    if (src->head == NULL) src->tail = NULL;
    src->count--;
    node->next = NULL;
    if (dest->tail == NULL) {
        dest->head = dest->tail = node;
    } else {
        dest->tail->next = node;
        dest->tail = node;}
    dest->count++;
    (*M)++;}

void Merge(Queue* a, int q, Queue* b, int r, Queue* c, int* M, int* C) {
    while (q > 0 && r > 0) {
        (*C)++;
        if (a->head->data <= b->head->data) {
            MoveNode(c, a, M);
            q--;
        } else {
            MoveNode(c, b, M);
            r--;}}
    
    while (q > 0) {
        MoveNode(c, a, M);
        q--;}
    
    while (r > 0) {
        MoveNode(c, b, M);
        r--;}}

void Split(Queue* S, Queue* a, Queue* b) {
    initQueue(a);
    initQueue(b);
    if (S->head == NULL) return;
    Node* slow = S->head;
    Node* fast = S->head->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;}}
    a->head = S->head;
    a->tail = slow;
    b->head = slow->next;
    b->tail = S->tail;
    Node* current = a->head;
    a->count = 0;
    while (current != NULL && current != b->head) {
        a->count++;
        current = current->next;}
    b->count = S->count - a->count;
    if (a->tail) a->tail->next = NULL;}

int MergeSort(Queue* S) {
    if (S->head == NULL || S->head->next == NULL) return 0;
    Queue a, b;
    Split(S, &a, &b);
    int M_left = MergeSort(&a);
    int M_right = MergeSort(&b);
    int M = 0, C = 0;
    Queue temp;
    initQueue(&temp);
    Merge(&a, a.count, &b, b.count, &temp, &M, &C);
    *S = temp;
    return M + C + M_left + M_right;}

int teor_C(int n) {
    return (int)(n * ceil(log2(n)));}

int teor_M(int n) {
    return (int)(n * ceil(log2(n))) + n;}

int teor(int n) {
    return teor_C(n) + teor_M(n);}

int main() {
    int sizes[] = {100, 200, 300, 400, 500};
    int num_sizes = sizeof(sizes)/sizeof(sizes[0]);
    
    printf(" _________________________________________\n");
    printf("|       |        |   Факт. значения M+C  |\n");
    printf("|   N   |  M+C   |-----------------------|\n");
    printf("|       | Теория | Убыв. | Случ. | Возр. |\n");
    printf("|_______|________|_______|_______|_______|\n");
    
    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int t = teor(n);
        int u, r, v;
        Queue q_dec;
        initQueue(&q_dec);
        fillQueueDescending(&q_dec, n);
        u = MergeSort(&q_dec);
        freeQueue(&q_dec);
        Queue q_rand;
        initQueue(&q_rand);
        fillQueueRandom(&q_rand, n);
        r = MergeSort(&q_rand);
        freeQueue(&q_rand);
        Queue q_inc;
        initQueue(&q_inc);
        fillQueueAscending(&q_inc, n);
        v = MergeSort(&q_inc);
        freeQueue(&q_inc);
        
        printf("|  %d  |  %4d  |  %4d |  %d |  %d |\n", n, t, u, r, v);
        printf("|_______|________|_______|_______|_______|\n");}}
