class KthLargest {
public:
    vector<int> numsh;
    int kg;
    void minheapify(int i, vector<int>& numsh, int size){
        int smallest=i;
        int left= 2*i+1;
        int right = 2*i+2;

        if(left < size && numsh[smallest]> numsh[left]){
            smallest = left;
        }

        if(right < size && numsh[smallest] > numsh[right]){
            smallest = right;
        }

        if(smallest != i){
            swap(numsh[i] , numsh[smallest]);
            minheapify(smallest , numsh , size);
 
       }
    }
    void insertHeap(int val){
        numsh.push_back(val);
        int n = numsh.size();

        for (int i = n/2-1; i >= 0; i--){
            minheapify(i, numsh, n);
        }
    }

    void pop(){
        swap(numsh[0], numsh[numsh.size() - 1]);
        numsh.pop_back();
        int n = numsh.size();
        for(int i = n/2 - 1 ; i>=0 ; i--){
            minheapify(i , numsh , n);
        }
    }

    KthLargest(int k, vector<int>& nums) {
        kg = k;
        for(int i: nums){
            add(i);
        }
    }
    
    int add(int val) {
        if(numsh.size() < kg){
            insertHeap(val);
        }
        else if(val > numsh[0]){
            pop();
            insertHeap(val);
        }
        return numsh[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
