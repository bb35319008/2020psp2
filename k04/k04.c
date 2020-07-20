#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    char id[9], idf[9];
    int z=1, gender[15], i=1;
    double gender_num, height, heights[15];
    char fname1[FILENAME_MAX], fname2[FILENAME_MAX];
    char buf2[256];
    FILE* fp1;
    FILE* fp2;

    printf("input the filename of sample height : ");
    fgets(fname1,sizeof(fname1),stdin);
    fname1[strlen(fname1)-1] = '\0';

    fp1 = fopen(fname1,"r");
    if(fp1==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("input the filename of sample ID : ");
    fgets(fname2,sizeof(fname2),stdin);
    fname2[strlen(fname2)-1] = '\0';

    fp2 = fopen(fname2,"r");
    if(fp2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("Which ID's data do you want? : ");
    scanf("%c", &id[9]);

    fscanf(fp1, "%d, %lf", &gender[16], &heights[16]);
    while(fgets(buf2,sizeof(buf2),fp2) != NULL){
        sscanf(buf2,"%c",&idf[9]);
        
        if(id[9] == idf[9]){
            gender_num = gender[i];
            height = heights[i];
        }
        else{
            i++;
            z++;
        }

        if(z == 14){
            printf("No data");   
        }

        if(fclose(fp2) == EOF){
            fputs("File close error\n",stderr);
            exit(EXIT_FAILURE);
        }

        if(fclose(fp1) == EOF){
            fputs("File close error\n",stderr);
            exit(EXIT_FAILURE);
        }

        printf("---\n");
        printf("ID : %c\n", id[9]);
        if(gender_num == 1){
            printf("gender : Male\n");
        }
        else{
            printf("gender : Female\n");
        }
        printf("height : %lf\n", height);

        return 0;
    }
}