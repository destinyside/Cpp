#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

int max(int a, int b){
    if(a>b){
        return a;
    } else {
        return b;
    }
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int mi = m-1;
    int ni = n-1;
    int ri = m + n - 1;
    while(mi >= 0 || ni >= 0){
        if(mi < 0){
            nums1[ri--] = nums2[ni--];
        } else if(ni < 0){
            nums1[ri--] = nums1[mi--];
        } else {
            nums1[ri--] = max(nums1[mi--], nums2[ni--]);
        }
    }
}

void printArr(int* nums, int numsSize){
        for(int i=0; i<numsSize; i++){
                printf("%d ",nums[i]);
        }
        printf("\n");
}

int* randomArr(int len) {
        srand((unsigned)time(0));
        int* tmp = malloc(sizeof(int) * len);
        for (int i = 0; i < len; i++) {
                tmp[i] = rand() % 100 +
                        1;
        }
        return tmp;
}

int* comp(const void* a, const void* b){
    if(*(int*)a > *(int*) b){
        return 1;
    } else {
        return -1;
    }
}

int main(int argc, char* argv[]){

	int len1 = 20;
	int* arr1 = randomArr(len1);
	int len2 = 10;
    int* arr2 = randomArr(len2);
	qsort(arr1, len1, sizeof(int), comp);
    qsort(arr2, len2, sizeof(int), comp);
    printArr(arr1, len1);
    printArr(arr2, len2);
    int arr1Size = len2;
    int arr2Size = len2;
    merge(arr1, arr1Size, len2, arr2, arr2Size, len2);
    printArr(arr1, len1);
    free(arr1);
    free(arr2);
	return EXIT_SUCCESS;
}
