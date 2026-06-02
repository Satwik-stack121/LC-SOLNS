int min(int a, int b) {return a < b ? a : b;}
int max(int a, int b) {return a > b ? a : b;}

int function(int size1, int size2, int* ride1ST, int* ride1D, int* ride2ST, int*ride2D){
    int finish1=INT_MAX;
    for(int i=0; i<size1; i++){
        finish1 = min(finish1, ride1ST[i]+ride1D[i]);

    }

    int finish2=INT_MAX;
    for(int i=0; i<size2; i++){
        int absoluteStart = max(finish1, ride2ST[i]); 
        finish2 = min(finish2, absoluteStart + ride2D[i]);
    }
    return finish2;
}
int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {
    
    int landFirst = function(landStartTimeSize, waterStartTimeSize, landStartTime, landDuration, waterStartTime, waterDuration);
    int waterFirst = function(waterStartTimeSize, landStartTimeSize, waterStartTime, waterDuration, landStartTime, landDuration);
    
    return min(landFirst, waterFirst);
}
