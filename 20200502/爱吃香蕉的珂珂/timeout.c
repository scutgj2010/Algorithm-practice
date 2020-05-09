int compare(const void * a , const void * b)
{
    return *(int *)a - *(int *)b;
}

int minEatingSpeed(int* piles, int pilesSize, int H){
    int loopNum;
    int innerNum;
    long int counter;

    qsort(piles,pilesSize,sizeof(int),compare);
    if(pilesSize == H) {
        return piles[pilesSize-1];
    } 

    for(loopNum = 1; loopNum <= piles[pilesSize-1]; loopNum++) {
        counter = 0;
        for(innerNum = 0; innerNum < pilesSize ; innerNum++) {
            counter += piles[innerNum]/loopNum;
            if(piles[innerNum]%loopNum) {
                counter += 1;
            }
        }
        if(counter <= H) {
            return loopNum;
        }
    }
    return piles[0];
}