/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** rotate(char** boxGrid, int m, int n){
    char** output=malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        output[i]=malloc(m*sizeof(char));
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            output[j][m-i-1]=boxGrid[i][j];
        }
    }
    return output;
}

// void print(char**boxGrid, int m, int n){
//     for(int i=0;i<m;i++){
//         printf("%.*s", n ,boxGrid[i]);
//         printf("\n");
//     }
    
// }
char** rotateTheBox(char** boxGrid, int boxGridSize, int* boxGridColSize, int* returnSize, int** returnColumnSizes) {
    int m=boxGridSize;
    int n=boxGridColSize[0];
    for(int i=0;i<m;i++){
        int rptr=n-1;
        int lptr=n-1;

        while(lptr>=0){
            while(rptr>=0 && boxGrid[i][rptr]!='.'){
                rptr--;
            }
            if(rptr==-1){
                break;
            }
            if(lptr>rptr){
                lptr=rptr;
            }
            
            if(boxGrid[i][lptr]=='#' && boxGrid[i][rptr]=='.'){
                boxGrid[i][lptr]='.';
                boxGrid[i][rptr]='#';
            }
            
            if(boxGrid[i][lptr]=='*'){
                rptr=lptr;
            }
            lptr--;
        }
    }
    char** output=rotate(boxGrid, m, n);
    *returnSize=n;
    *returnColumnSizes=malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        (*returnColumnSizes)[i]=m;
    }
    // print(output,n,m);
    return output;
}


