#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node **buckets;
    int size;
} HashTable;

HashTable *create_table(int size) {
    HashTable *t=malloc(sizeof(HashTable));
    t->size=size;
    t->buckets=calloc(size, sizeof(Node *));
    return t;
}

unsigned int hash(int key, int size) {
    unsigned int k=(unsigned int)key;
    k ^= (k >> 16);
    return k % size;
}

void insert(HashTable *t, int key, int value) {
    unsigned int idx=hash(key, t->size);
    Node *n=malloc(sizeof(Node));
    n->key=key;
    n->value=value;
    n->next=t->buckets[idx];
    t->buckets[idx]=n;
}

int find(HashTable *t, int key, int *out) {
    unsigned int idx=hash(key, t->size);
    Node *cur=t->buckets[idx];
    while (cur) {
        if (cur->key==key) { *out=cur->value; return 1; }
        cur=cur->next;
    }
    return 0;
}

void free_table(HashTable *t) {
    for (int i=0; i<t->size; i++) {
        Node *cur=t->buckets[i];
        while (cur) {
            Node *tmp=cur;
            cur=cur->next;
            free(tmp);
        }
    }
    free(t->buckets);
    free(t);
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    HashTable *t=create_table(numsSize * 2);
    int *result=NULL;

    for (int i=0; i<numsSize; i++) {
        int idx;
        if (find(t, nums[i], &idx)) {
            result=malloc(sizeof(int) * 2);
            result[0]=idx;
            result[1]=i;
            *returnSize=2;
            free_table(t);
            return result;
        }
        insert(t, target - nums[i], i);
    }

    free_table(t);
    *returnSize=0;
    return NULL;
}


