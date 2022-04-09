/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int *p_res = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0;

    for(int i = 0; i < numsSize; i++) {
        int pos = (nums[i] & 0x7fffffff)-1;

        if (nums[pos] & 0x80000000) {
            p_res[*returnSize] = pos+1;
            (*returnSize)++;
            continue;
        }

        nums[pos] |= 0x80000000;
    }
    return p_res;
}