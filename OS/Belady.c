#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Belady {
    int vpn; //해당 vpn
    int now; //현재 위치
}Belady;

Belady* frame;

int page[50000];
int pf;
int vpn = 0;
char operation[6];
int count_access = 0;
int count_read = 0;
int count_write = 0;
int count_hit = 0;
int frame_now = 0;
int num = 0;
int frame_size = 0;
int max = 0;
char operation[6];
int j = 0;

void Belady_Insert(int i, int check) {
    if (check == 1) {
        for (num = i + 1; num < 50000; num++) {
            if (page[num] == page[i]) //같은 값이 발견되면
                break; //멈추고
        }
        frame[frame_now].now = num - i; //현재 프레임에 넣음
    }
    else if (check == 2) {
        for (num = i + 1; num < 50000; num++) {
            if (page[num] == page[i])
                break;
        }
        frame[frame_size].vpn = page[i];
        frame[frame_size].now = num - i;
        frame_size++;
    }
    else {
        max = 0;
        for (j = 0; j < pf; j++)
            if (frame[j].now > frame[max].now)
                max = j;
        for (num = i + 1; num < 50000; num++)
        {
            if (page[num] == page[i])
                break;
        }
        frame[max].vpn = page[i];
        frame[max].now = num - i;
    }

}

void main() {
    FILE* fp;
    fp = fopen("access.list", "r");
    double result = 0;
    scanf("%d", &pf);

    frame = (Belady*)malloc(sizeof(Belady) * pf);

    while (fscanf(fp, "%d %s", &vpn, operation) != EOF) {
        count_access++;
        if (operation[0] == 'r') {
            count_read++;
        }
        else if (operation[0] == 'w') {
            count_write++;
        }     
        page[j++] = vpn;
    }

    for (int i = 0; i < 50000; i++){
        for (int k = 0; k < pf; k++) {
            frame[k].now--;
        }

        for (frame_now = 0; frame_now < pf; frame_now++){
            if (frame[frame_now].vpn == page[i]){
                Belady_Insert(i, 1); //같은 값이 있을 경우
                count_hit++;
                break;
            }
        }

        if (frame_now >= frame_size){ //프레임 꽉 찼을 때

            if (frame_size < pf){ //현재 들어온 개수가 입력한 개수보다 작을 경우
                Belady_Insert(i, 2);
            }
            else if (frame_size >= pf){ //현재 들어온 개수가 입력한 개수보다 클 경우
                Belady_Insert(i, 0);
            }
        }  
    }

    result = (((double)count_access - (double)count_hit) /(double)count_access) * 100;
    printf("Total number of access: %d\n", count_access);
    printf("Total number of read: %d\n", count_read);
    printf("Total number of write: %d\n", count_write);
    printf("Number of page hits: %d\n", count_hit);
    printf("Number of page faults: %d\n", count_access - count_hit);
    printf("Page fault rate: %d/%d = %.03lf %%", count_access - count_hit, count_access, result);
    fclose(fp);
}