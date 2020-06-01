int numOfSubarrays(int* arr, int arrSize, int k, int threshold){
   int start;
   int end;
   int sum = 0;
   int num = 0;
   int loopNum;
   if(arrSize < k) {
       return 0;
   }
   for(loopNum = 0; loopNum < k; loopNum++) {
       sum += arr[loopNum];
   }
   for(start = 0, end = k; end < arrSize; start++,end++) {
      if(sum >= threshold * k) {
       //printf("%d,%d,%d\n",start,end-1,sum);
          num++;
      }
      sum = sum - arr[start] + arr[end];
   }
   if(sum >= threshold * k) {
       //printf("%d,%d,%d\n",start,end-1,sum);
       num++;
   }
   return num;
}