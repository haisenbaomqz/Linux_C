#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
   int *data;//数组所在位置
   int size;//目前数组大小
   int capacity;//数组容量
}DynamicArray;
/*
数组结构体也需要一个存储空间
*/
DynamicArray* create_array(int capacity)
{
    DynamicArray* arr = (DynamicArray*)malloc(sizeof(DynamicArray));
    if(arr == NULL)
    {
        printf("fail to create struct\n");
        return NULL;
    }
    //初始化最开始的数组容量
    arr->data = (int*)malloc(capacity * sizeof(int));
    //没有数据所以数组大小为0
    arr->size = 0;
    arr->capacity = capacity;
    printf("success to create array:%d\n",capacity);
    //返回存放数组信息结构体的地址
    return arr;
}
/*
    传参一定要用二级指针，因为要改变结构体地址，所以要用指针的地址
*/
void destroy_array(DynamicArray **arr)
{
    if(arr == NULL || *arr == NULL)
    {
        return;
    }

    if((*arr)->data != NULL)
    {
        //还要清除数组的地址
        free((*arr)->data);
        (*arr)->data = NULL;
    }
    free(*arr);
    *arr = NULL;
    printf("success to detroy arr\n");
}
/*
写入数据
*/
void push_back(DynamicArray *arr, int value)
{
    if(arr->size == arr->capacity)
    {
        //扩容两倍，倍数自定义
        arr->capacity = arr->capacity * 2;
        //开始扩容
        int *new_arr = (int*)realloc(arr->data,(arr->capacity) * sizeof(int));
        if(new_arr == NULL)
        {
            printf("fail\n");
        }
        arr->data = new_arr;
        printf("success to enlarge:%d\n",arr->capacity);
    }
    //写入数据
    arr->data[arr->size] = value;
    //数组实际大小递增
    arr->size++;
}
int* create_memory(int size)
{
    int* p = (int*)malloc(size * sizeof(int));
    if(p == NULL)
    {
        printf("fail to create\n");
        return NULL;
    }
    return p;
}
int* enlarge_memory(int* old_ptr, int size)
{
    int* temp = (int*)realloc(old_ptr, size);
    if(temp == NULL)
    {
        printf("fail to enlarge\n");
        return NULL;
    }
    old_ptr = temp;
    return old_ptr;
}
void safe_free(int** p)
{
    if(p == NULL || *p ==NULL)
    {
        return;
    }
    free(*p);
    *p = NULL;
}
int main(void)
{
    DynamicArray *array = create_array(2);
    push_back(array,1);
    push_back(array,2);
    push_back(array,3);
    push_back(array,4);
    push_back(array,5);
    for (size_t i = 0; i < array->size; i++)
    {
        printf("%d ", array->data[i]);
    }
    printf("\n");
    destroy_array(&array);
    if(array == NULL)
    {
        printf("success\n");
    }
    return 0;
}