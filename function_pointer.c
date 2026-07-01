#include <stdio.h> 
int add(int a, int b)
{
    return a + b;
}
int subtract(int a, int b)
{
    return a - b;
}
void calculate(int a, int b, int(*operation)(int, int))
{
    int temp = operation(a, b);
    printf("%d\n",temp);
}
int ascending(int a, int b)
{
    return a > b;
}
int descending(int a, int b)
{
    return a < b;
}
void sort(int *arry, int n, int (*compare)(int , int))
{
    //外层循环：需要排多少轮，最后一个不需要排所以是n-1，i代表已经排好的个数
    for (size_t i = 0; i < n - 1; i++)
    {
        //减去排好的个数，并且不能越界所以还要再减1
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if(compare(arry[j], arry[j + 1]))
            {
                int temp = arry[j];
                arry[j] = arry[j + 1];
                arry[j + 1] = temp;
            }
        }
        
    }   
}
void printf_arry(int *arry,int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ",*(arry + i));
    }
    printf("\n");
}
int main(void)
{
    int arr1[] = {5, 2, 9, 1, 6, 3};
    int arr2[] = {5, 2, 9, 1, 6, 3};
    int n = 6;
    sort(arr1, n, ascending);
    sort(arr2, n, descending);
    printf("ascending: ");
    printf_arry(arr1, n);
    printf("descending: ");
    printf_arry(arr2, n);    
    return 0;
}