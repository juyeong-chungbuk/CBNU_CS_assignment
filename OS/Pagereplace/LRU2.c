#include <stdio.h>
#include <string.h>
int count_access=0;
int count_read=0;
int count_write=0;
int count_hit=0;
int count_fault=0;

typedef struct LRU {
    int r; //0인지1인지 판단
    int count; //얼마나 오래 안쓰였는지 알기위한 변수
    int vpn; //해당 vpn
    char *str; //read 인지 write인지
    struct LRU *pre; //이전 숫자 가리킴
    struct LRU *next; //다음 숫자 가리킴
}LRU;
LRU *Head;

//같은 숫자가 없으면 맨 앞에 넣고, 있으면, 그 수를 없애고 맨 앞에 넣음 혹은 그 수를 맨 앞으로 이동

void LRU_Insert(LRU *frame, int vpn){
    LRU *ptr = frame;  //frame의 맨 앞에 숫자를 넣기 위해 가리키는 값
    LRU *newnode = (LRU*)malloc(sizeof(LRU));
    newnode->vpn = vpn;
    newnode->r = 0;
    newnode->count++; //초기화해주고
    ptr->pre = newnode;
    newnode->next = ptr; //맨앞에 삽입
    while(ptr->next != NULL){
        ptr->r = 0;
        ptr->count++;
        ptr = ptr->next;
    }
}

void LRU_delete(LRU *ptr, int vpn){
    LRU *dptr = ptr; //frame을 가리킴
    int max = 0;

    if(ptr->pre != NULL){ //ptr로 들어온 경우 같은 값이라서 일단 제거하는거.
        ptr->pre->next = ptr->next;
        ptr->next->pre = ptr->pre;
        ptr->pre = NULL;
        ptr->next = NULL;
    }
    else{ //frame으로 들어온 경우
        while(dptr->next != NULL){ //다음으로 넘기면서 
            if(dptr->count > max){ //최대count를 찾음
                max = dptr->count;
            }
            dptr = dptr->next;
        }
        while(dptr->pre != NULL){  //이전으로 돌아오면서 max와 일치하는 count가 있으면 그 값을 제거
            if(max == dptr->count){
                dptr->pre->next = dptr->next;
                dptr->next->pre = dptr->pre;
                dptr->pre = NULL;
                dptr->next = NULL;
            }
            dptr = dptr->pre;
        }
    }
}

int Find_Num(LRU *frame, int vpn){
    LRU *ptr = frame; //frame의 맨 앞에 숫자를 넣기 위해 가리키는 값

    while(ptr->next != NULL){
        if(ptr->vpn == vpn){ //같은 숫자가 있다면
            LRU_delete(ptr, vpn); //일단 제거
            LRU_Insert(frame, vpn);
            ptr->r = 1; //숫자가 참조됐다는 거니까 r비트를 1로 바꿈
            ptr->count = 0; //카운트도 0으로 초기화
            return ; //함수 종료시킴
        }
    }
    /*같은 숫자가 없다면*/
    LRU_delete(frame, vpn); //count 큰 값 제거
    LRU_Insert(frame, vpn);
    return ;
}

void main(){  
    int pf;
    FILE *fp;
    LRU *frame;
    int vpn;
    // char *str;
    frame = (LRU *)malloc(sizeof(LRU));
    Head = (LRU *)malloc(sizeof(LRU));
    /* 초기화 */
    frame->count = 0;
    frame->pre =NULL;
    frame->next = NULL;
    frame->str = (char)malloc(sizeof(char)*5);
    // str = (char)malloc(sizeof(char)*5);

    fp=fopen("a.list", "r"); 
    scanf("%d", &pf);
    frame = (int)malloc(sizeof(int) * pf); //입력받은 만큼 frame할당

    while(1){
        fscanf(fp, "%d", vpn); //숫자읽기
        Find_Num(frame, vpn); //숫자 있는지 찾기

        // fscanf(fp, "%s", frame->str); //문자열읽기
        // str = frame->str;
    }
}