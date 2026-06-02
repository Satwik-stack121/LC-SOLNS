int minPartitions(char* n) {
    int b = 0;
    for(int i = 0; n[i] != '\0'; i++){
        int digit = n[i] - '0';
        if(b< digit){
            b = digit;
        }
    }
    return b;
}
