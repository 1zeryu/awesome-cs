#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int* a = new int[32];
    int capacity=32;
    int length=0;
};

Stack* create_Stack();
void push(Stack* a,int num);
void show_Stack(Stack* a);
void pop(Stack* a);
bool isEmpty(Stack* a);
int top(Stack* a);

int main(void){
    Stack* a = create_Stack();
    push(a,1);
    push(a,2);
    pop(a);
    show_Stack(a);
    cout << top(a);
    return 0;
}

// 创建堆栈
Stack* create_Stack(){
    Stack* a = new Stack;
    return a;
}

void push(Stack* a,int num){
    if(a->length==a->capacity){
        cout << "你的堆栈已经超出预设内存空间" << endl;
        int capacity = a->capacity;
        a->a = new int[capacity*2];
        a->capacity *= 2;
        cout << "已经重新申请空间" << endl;
    }
    int index = a->length;
    a->a[index] = num;
    a->length += 1;
    return ;
}

void show_Stack(Stack* a){
    for(int i=0;i<a->length;i++){
        cout << a->a[i] << " ";
    }
    cout << endl;
    return ;
}

bool isEmpty(Stack* a){
    return a->length == 0;
}

void pop(Stack* a){
    if(isEmpty(a)){
        cout << "堆栈为空" << endl;
        return ;
    }
    else{
        int index = a->length-1;
        a->a[index] = 0;
        a->length -= 1;
    }
    return ;
}

int top(Stack* a){
    if(isEmpty(a)){
        cout << "堆栈为空" << endl;
        return 0;
    }
    else{
        return a->a[a->length-1];
    }
}