int maxChunksToSorted(int* arr, int arrSize){
        //当遍历到第i个位置时，如果可以切分为块，那前i个位置的最大值一定等于i。
        //否则，一定有比i小的数划分到后面的块，那块排序后，一定不满足升序。
        int res = 0, max = 0;
        for (int i = 0; i < arrSize; i++){
            max = max > arr[i] ? max : arr[i];//统计前i个位置的最大元素
            if (max == i) {
                res++;
            }
        }
        return res;
}