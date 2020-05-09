#define MAX(a, b) ((a) > (b) ? (a) : (b))
/* 计算最大堆中香蕉的个数 */
int maxCount(int* piles, int pilesSize)
{
    int max = 0; 
    for (int i = 0; i < pilesSize; i++) {
        max = MAX(max, piles[i]);
    }
    return max;
}

int EatingHoursBySpeed(int* piles, int pilesSize, int speed)
{
    int hours = 0;
    for (int i = 0; i < pilesSize; i++) {
        hours += piles[i] / speed + (piles[i] % speed != 0);
    }
    return hours;
}

int minEatingSpeed(int* piles, int pilesSize, int H)
{
    int pileMaxCount = maxCount(piles, pilesSize);
    
    int minSpeed = 1;
    int maxSpeed = pileMaxCount;
    while (minSpeed <= maxSpeed) {
        int midSpeed = (minSpeed + maxSpeed) / 2;
        int hours = EatingHoursBySpeed(piles, pilesSize, midSpeed);
        if (hours > H) {
            minSpeed = midSpeed + 1;
        } else {
            maxSpeed = midSpeed - 1;
        }
    }
    return minSpeed;
}