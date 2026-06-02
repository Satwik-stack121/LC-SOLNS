int minimumIndex(int* capacity, int capacitySize, int itemSize){
    int best_index=-1;
    int min_capacity=INT_MAX;
    
    for (int i=0; i<capacitySize; i++){
        if (capacity[i]>=itemSize){
            if (capacity[i]<min_capacity){
                min_capacity= capacity[i];
                best_index=i;
            }
        }
    }
    
    return best_index;
}
