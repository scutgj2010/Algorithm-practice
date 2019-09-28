void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
     int * num = malloc(sizeof(int)*(nums1Size));
     int loopnum1 = 0;
     int loopnum2 = 0;
     int loopnum = 0;

     for(;(loopnum1<m)&&(loopnum2<n);)
     {
         if(nums1[loopnum1]>nums2[loopnum2])
         {
             num[loopnum] = nums2[loopnum2];
             loopnum2++;
         }
         else
         {
             num[loopnum] = nums1[loopnum1];
             loopnum1++;
         }
         loopnum++;
     }
    
     for(;loopnum1<m;loopnum1++,loopnum++)
     {
         num[loopnum] = nums1[loopnum1];
     } 
    
     for(;loopnum2<n;loopnum2++,loopnum++)
     {
         num[loopnum] = nums2[loopnum2];
     }   
     memcpy(nums1,num,sizeof(int)*(nums1Size));
     free(num);
}
