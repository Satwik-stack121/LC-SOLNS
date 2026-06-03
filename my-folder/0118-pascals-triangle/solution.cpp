class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pTri;
        int n = 0;
        while(n < numRows){
            if(n!=0){
                vector<int> Row;
                vector<int> prevRow=pTri[n-1];
                int n2=0;
                while(n2 <= n){
                    if(n2==0 || n2==n){
                        Row.push_back(1);
                    }
                    else{
                        Row.push_back(prevRow[n2] + prevRow[n2-1]);
                    }
                    n2++;
                }
                pTri.push_back(Row);
            }
            else{
                pTri.push_back({1});
            }
            n++;
        }
        return pTri;
    }
};
