class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int , vector<int> , greater<int>> right;
    MedianFinder() {
        
          }
    
    void addNum(int num) {
        left.push(num);
        right.push(left.top());
        left.pop();

        if(right.size() > left.size()+1){
            int data=right.top();
            right.pop();
            left.push(data);
        }
    }
    
    double findMedian() {
        if(left.size() != right.size()){
            return right.top();
        }
        else{
            return double (right.top()+left.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
