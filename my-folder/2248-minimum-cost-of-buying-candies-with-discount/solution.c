int compare(const void *a, const void *b){
    int arg1= *(const int*)a;
    int arg2= *(const int*)b;
    return (arg1<arg2) - (arg1>arg2);
}

int minimumCost(int* cost, int costSize) {
    int op=0;
    qsort(cost, costSize, sizeof(int), compare);
    for(int i=0;i<costSize;i++){
            op += cost[i]*(i%3==2? 0 : 1);
    }
    return op;
}
// 0, 1, 2, 3, 4, 5, 6, 7, 8
// 2, 5, 8
// 2, 2, 2
// [9, 7, 6, 5, 2, 2]
// 9 + 7 + 5 + 2
