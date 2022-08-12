#include <stdio.h>

void printArray(int *arr, int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    putchar('\n');
}

int main()
{
    int nums3[15];
    int nums[10];
    int nums2[10];
    for(int i = 0; i<10; i++)
    {
        scanf("%d", nums+i);
    }

    /*for(int i = 0; i<10; i++)
    {
        printf("%d\n", *(nums+i));
    }*/

    printArray(nums, 10);

    return 0;
}