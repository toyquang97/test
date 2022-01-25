#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nhanvien{
    char id[10];
    char name[40];
    float salary;
} Khaibao;
void nhapDs(Khaibao* p);

int main() {
    // Write C code here
    Khaibao* nv;
    nv = (Khaibao*)malloc(3*sizeof(Khaibao));
    for(int i = 0; i < 3; i++){
        nhapDs((nv+i));
    }
    for(int i = 0; i < 3; i++){
        printf("[nv]:[%d]\t",i);
        printf("[id]:[%s]\t",(nv+i)->id);
        printf("[name:[%s]\t",(nv+i)->name);
        printf("[salary]:[%2.3f]\n",((nv+i)->salary));
    }
    printf("Done!");
    return 0;
}

void nhapDs(Khaibao* p){
    printf("nhap id:\n");
    if(fgets(p->id,10,stdin)!=NULL){
        puts(p->id);
    }

    printf("nhap name:\n");
    if(fgets(p->name,40,stdin)!=NULL){
        puts(p->name);
    }
    printf("nhap luong: \n");
    char buffer[10];
    if(fgets(buffer,10,stdin)!=NULL){
        puts(buffer);
    }    
    p->salary = strtof(buffer,NULL);
    memset(buffer,'\0',10);
    printf("nhap ds xong\n");
    return ;
}