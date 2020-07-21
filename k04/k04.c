#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int id, idf, z=1, gender[15], i;
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
    scanf("%d", &id);

    for(i = 0; i < 15; i++){
        fscanf(fp1, "%d, %lf", &gender[i], &heights[i]);
    }

    i = 1;

    while(fgets(buf2,sizeof(buf2),fp2) != NULL){
        sscanf(buf2,"%d",&idf);
        
        if(id == idf){
            gender_num = gender[i];
            height = heights[i];
            z--;
        }
        else{
            i++;
            z++;
        }
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

    if(z == 14){
        printf("No data\n");
    }
    else{
        printf("ID : %d\n", id);
        if(gender_num == 1){
            printf("gender : Male\n");
        }
        else{
            printf("gender : Female\n");
        }
        printf("height : %4.1lf\n", height);
    }

    return 0;
}