#include<stdio.h>
//前后指针
int partition(int begin, int end, int* a){
    int key = begin;//每次选取第一个数为基准数
    int pre = begin;//最后一个小于key值的位置
    int cur = begin + 1;
    while(cur <= end){
        if(a[cur] < a[key]){
            pre++;
            //判断他们之间是否连续，若不连续代表他们之间有大于key值的数,需与cur进行交换
            if(pre != cur){
                int temp = a[pre];
                a[pre] = a[cur];
                a[cur] = temp;
            }
        }
        cur++;
    }
    //此时pre右边没有大于key值的数，且是最后一个小于key值的位置
    int temp = a[key];
    a[key] = a[pre];
    a[pre] = temp;
    return pre;
}

void quickSort(int begin, int end, int* a){
    if(begin >= end) return;
    int mid = partition(begin, end, a);
    quickSort(begin, mid -1, a);
    quickSort(mid + 1, end,a);
}

int main(){
    printf("本程序模拟快速排序，请输入输入数的个数：");
    int num;
    scanf("%d", &num);
    int number[1000];
    printf("请输入数字：");
    for(int i = 0; i < num; i++){
        scanf("%d", &number[i]);
    }
    quickSort(0,num - 1, number);
    printf("排序后的数为：");
    for(int i = 0; i < num; i++){
        printf("%d ", number[i]);
    }
    system("pause");
    return 0;
}