#include <stdio.h>
#include <string.h>

void main(){
    int pf;
    int num;
    int i=0;
    int j=0;
    char str[6];
    int *slot;
    char *slot2;
    int count_access=0;
    int count_read=0;
    int count_write=0;
    int count_hit=0;
    int count_fault=0;

    FILE *fp;
    fp=fopen("access.list", "r");


    scanf("%d", &pf);
    slot = (int)malloc(sizeof(int) * pf);
    slot2 = (char)malloc(sizeof(char) * pf);

    while(1){
        fscanf(fp, "%d", num); //숫자읽기
        slot[i] = num;
        i++;
        for(j=0; j++; j<=i){
            if(strcmp((char)num, (char)slot[j])){
                count_hit++; //이미 있으면 hit
                break;
            }
        }
        if(j>i){
            count_fault++;
        }

        fscanf(fp, "%s", str); //문자열읽기
        *slot2 = str;
        if(feof(fp))break;
       
    }
    fclose(fp);

}