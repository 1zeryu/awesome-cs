#include<stdio.h>
#include<string.h>     
#include<stdbool.h>
#define READER_FILE "E:\\c\\reader.txt"
#define BOOK_FILE "E:\\c\\book.txt"
#define ADMIN_FILE "E:\\c\\admin.txt"
typedef struct book{
    int id;
    char name[20];
    int num;
}Book;
typedef struct reader{
    int id;
    char name[10];
    int bro_num;
    char bro_book[30][20];
}Reader;
typedef struct admin{
    char name[10];
}Admin;

Book books[100];
Reader readers[30];
Admin admins[10];
//书，读者，管理员的数量
int book_num = 0;
int reader_num = 0;
int admin_num = 0;
void init(){
    //打开文件，录入信息
    FILE *b_f = fopen(BOOK_FILE, "r");
    fscanf(b_f, "%d", &book_num);
    for(int i = 0; i < book_num; i++){
        fscanf(b_f,"%d %s %d", &books[i].id, books[i].name, &books[i].num);
    }
    FILE *r_f = fopen(READER_FILE, "r");
    fscanf(r_f, "%d", &reader_num);
    for(int i = 0; i < reader_num; i++){
        fscanf(r_f, "%d %s %d", &readers[i].id, readers[i].name, &readers[i].bro_num);
        for(int j = 0; j < readers[i].bro_num; j++){
            fscanf(r_f,"%s ", readers[i].bro_book[j]);
        }
    }
    FILE *a_f = fopen(ADMIN_FILE, "r");
    fscanf(a_f, "%d", &admin_num);
    for(int i = 0; i < admin_num; i++){
        fscanf(a_f, "%s", admins[i].name);
    }
    fclose(b_f);
    fclose(r_f);
    fclose(a_f);
}
void save(){
    FILE *b_f = fopen(BOOK_FILE, "w");
    fprintf(b_f, "%d\n", book_num);
    for(int i = 0; i < book_num; i++){
        fprintf(b_f,"%d %s %d\n", books[i].id, books[i].name, books[i].num);
    }
    FILE *r_f = fopen(READER_FILE, "w");
    fprintf(r_f, "%d\n", reader_num);
    for(int i = 0; i < reader_num; i++){
        fprintf(r_f, "%d %s %d\n", readers[i].id, readers[i].name, readers[i].bro_num);
        for(int j = 0; j < readers[i].bro_num; j++){
            fprintf(r_f,"%s", readers[i].bro_book[j]);
        }
        fprintf(r_f,"\n");
    }
    FILE *a_f = fopen(ADMIN_FILE, "w");
    fprintf(a_f, "%d\n", admin_num);
    for(int i = 0; i < admin_num; i++){
        fprintf(a_f, "%s\n", admins[i].name);
    }
    fclose(b_f);
    fclose(r_f);
    fclose(a_f);
}
//管理员的操作
void add_reader(){
    int temp = reader_num;
    printf("请输入读者的编号：");
    scanf("%d", &readers[temp].id);
    printf("请输入读者的姓名：");
    scanf("%s", readers[temp].name);
    readers[temp].bro_num = 0;
    reader_num++;
    printf("录入成功！");
    system("pause");
    system("cls");
}
void delete_reader(){
    int id, temp = -1;
    printf("请输入要删除读者的编号：");
    scanf("%d", &id);
    for(int i = 0; i < reader_num; i++){
        if(readers[i].id == id){
            temp = i;
            break;
        }
    }
    if(temp = -1){
        printf("不存在该读者，请再次确认！");
    }else{
        printf("你确定要删除该读者吗？\n");
        printf("1.确认 2.取消");
        int select;
        scanf("%d", &select);
        if(select == 1){
            for(int i = temp; i < reader_num - 1; i++){
                readers[i] = readers[i+1];
            }
            reader_num--;
        }
    }
    system("pause");
    system("cls");
}
void modify_reader(){
    int id, temp = -1;
    printf("请输入要修改读者的编号：");
    scanf("%d", &id);
    for(int i = 0; i < reader_num; i++){
        if(readers[i].id == id){
            temp = i;
            break;
        }
    }
    if(temp = -1){
        printf("不存在该读者，请再次确认！");
    }else{
        printf("请输入修改后读者的编号：");
        scanf("%d", &readers[temp].id);
        printf("请输入修改后读者的姓名：");
        scanf("%s", readers[temp].name);
        printf("修改成功！");
    }
    system("pause");
    system("cls");
}
void add_book(){
    int temp = book_num;
    printf("请输入图书的编号：");
    scanf("%d", &books[temp].id);
    printf("请输入图书的名字：");
    scanf("%s", books[temp].name);
    printf("请输入图书的本数：");
    scanf("%d", &books[temp].num);
    book_num++;
    printf("添加成功！");
    system("pause");
    system("cls");
}

void delete_book(){
    int id, temp = -1;
    printf("请输入要删除图书的编号：");
    scanf("%d", &id);
    for(int i = 0; i < reader_num; i++){
        if(books[i].id == id){
            temp = i;
            break;
        }
    }
    if(temp = -1){
        printf("不存在该图书，请再次确认！");
    }else{
        printf("你确定要删除该图书吗？\n");
        printf("1.确认 2.取消");
        int select;
        scanf("%d", &select);
        if(select == 1){
            for(int i = temp; i < book_num - 1; i++){
                books[i] = books[i+1];
            }
            book_num--;
        }
    }
    system("pause");
    system("cls");
}
void modify_book(){
     int id, temp = -1;
    printf("请输入要修改图书的编号：");
    scanf("%d", &id);
    for(int i = 0; i < reader_num; i++){
        if(books[i].id == id){
            temp = i;
            break;
        }
    }
    if(temp = -1){
        printf("不存在该图书，请再次确认！");
    }else{
        printf("请输入修改后图书的编号：");
        scanf("%d", &books[temp].id);
        printf("请输入修改后图书的名字：");
        scanf("%s", books[temp].name);
        printf("请输入修改后图书的本数：");
        scanf("%d", &books[temp].num);
        printf("修改成功!");
    }
    system("pause");
    system("cls");
}

void quit(){
    printf("欢迎您的下次使用！");
    system("pause");
    save();
}
void show_A(){
    int select = 1;
    while(select != 0){
        printf("---------\n");
        printf("欢迎进入图书管理系统，以下是可选的操作：\n");
        printf("1.读者信息录入 2.读者信息删除 3.读者信息修改\n");
        printf("4.图书信息录入 5.图书信息删除 6.图书信息修改\n");
        printf("0.退出\n");
        scanf("%d", &select);
        switch (select) {
        case 1:
            add_reader();
            break;
        case 2:
            delete_reader();
            break;
        case 3:
            modify_reader();
            break;
        case 4:
            add_book();
            break;
        case 5:
            delete_book();
            break;
        case 6:
            modify_book();
            break;
        case 0:
            quit();
            break;
        default:
            printf("输入错误，请重试");
            system("pause");
            system("cls");
            break;
        }
    }
}
void borrow_book(int flag){
    int id, temp = -1;
    printf("请输入要借的书的编号：");
    scanf("%d", &id);
    for(int i = 0; i < book_num; i++){
        temp = i;
        break;
    }
     if(temp = -1){
        printf("不存在该图书，请再次确认！");
    }else{
        if(books[temp].num == 0) printf("该书已被借完，抱歉！");
        else{
            printf("你确定要借出该书吗？\n");
            printf("1.确认 2.取消");
            int select;
            scanf("%d", &select);
            if(select == 1){
            int tem = readers[flag].bro_num;
            strcpy(readers[flag].bro_book[tem], books[temp].name);
            readers[flag].bro_num++;
            books[temp].num--;
            }
        }
    }
    system("pause");
    system("cls");
}

void return_book(int flag){
    char *name, temp = -1;
    printf("请输入你想还书的名字：");
    scanf("%s", name);
    for(int i = 0; i < readers[flag].bro_num; i++){
        if(strcmp(readers[flag].bro_book[i], name) == 0){
            temp = i;
            break;
        }
    }
    if(temp != -1){
        //在书库中找到该书
        for(int i = 0; i < book_num; i++){
            if(strcmp(name, books[i].name) == 0){
                books[i].num++;
                break;
            }
        }
        //从读者中拿走该书
        for(int i = temp; i < readers[flag].bro_num - 1; i++){
            strcpy(readers[flag].bro_book[i], readers[flag].bro_book[i+1]);
        }
        readers[flag].bro_num--;
    }else printf("你并没有该书，请再次确认!");
    system("pause");
    system("cls");
}

show_book_inf(int flag){
    printf("该书的编号为：%d\n", books[flag].id);
    printf("该书的名字为：%s\n", books[flag].name);
    printf("该书还有：%d本\n", books[flag].num);
    system("pause");
    system("cls");
}
void query_book(){
    int select, temp = -1;
    printf("你想以书名还是书的编号查？\n");
    printf("1.书名 2.编号\n");
    scanf("%d", &select);
    if(select == 1){
        printf("请输入书名：");
        char *name;
        scanf("%s", name);
        for(int i = 0; i < book_num; i++){
            if(strcmp(name, books[i].name) == 0){
                temp = i;
                break;
            }
        }
    }else{
        int id;
        scanf("%d", &id);
        for(int i = 0; i < book_num; i++){
            if(books[i].id == id){
               temp = i;
               break;
            }
        }
    }
    if(temp != -1){
        show_book_inf(temp);
    }else printf("图书室中没有该书，请重试");
    system("pause");
    system("cls");
}


void show_R(int flag){
     int select = 1;
    while(select != 0){
        printf("---------\n");
        printf("欢迎进入图书管理系统，以下是可选的操作：\n");
        printf("1.借书 2.还书 3.查询\n");
        printf("0.退出\n");
        scanf("%d", &select);
        switch (select) {
        case 1:
            borrow_book(flag);
            break;
        case 2:
            return_book(flag);
            break;
        case 3:
            query_book();
            break;
        case 0:
            quit();
            break;
        default:
            printf("输入错误，请重试");
            system("pause");
            system("cls");
            break;
        }
    }
}

bool isInA(char* name){
    for(int i = 0; i < admin_num; i++){
        if(strcmp(name, admins[i].name) == 0) return true;
    }
    return false;
}

int isInR(char* name){
    for(int i = 0; i < reader_num; i++){
        if(strcmp(name, readers[i].name) == 0) return i;
    }
    return -1;
}
int main(int argc, char *argv[]){
    //打开文件，做初始化操作
    init();
    //判断是管理员还是读者
    if(strcmp(argv[1], "-a") == 0){
        if(isInA(argv[2])){
            //打开管理员菜单
            show_A();
        }else printf("没有该用户名，请重试");
    }else if(strcmp(argv[1], "-u") == 0){
        int flag;
        if(flag = isInR(argv[2]) != -1){
            //打开读者菜单
            show_R(flag);
        }else printf("没有该用户名，请重试");
    }else printf("请输入“-a” 或 “-u” 表示你的身份");
    return 0;
}