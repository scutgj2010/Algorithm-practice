/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int indexStart;
    int indexEnd;
    int * result;

    *returnSize = 0;
    
    for(indexStart = 0; indexStart < numbersSize; indexStart++) {
        for(indexEnd = indexStart + 1; indexEnd < numbersSize; indexEnd++) {
            if(numbers[indexStart] + numbers[indexEnd] == target) {
                *returnSize = 2;
                result = (int *)malloc(sizeof(int) * 2);
                result[0] = indexStart+1;
                result[1] = indexEnd+1;
                return result;                
            }
        }
    }
    return NULL;
}