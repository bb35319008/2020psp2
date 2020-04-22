#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave);
extern double var_online(double val,double ave,double square_ave);
int n = 1;
double ave = 0, val, s, A, S, square_ave;

int main(void)
{
    double u;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        A = ave_online(val, ave);
        S = var_online(val, ave, square_ave);
        n++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    u = S * n / (n-1);

    printf("Sample's average is %.2f, Sample's variance is %.2f.\n", A, S);
    printf("Population's average is %.2f, Population's variance is %.2f.\n", A, u);

    return 0;
}

extern double ave_online(double val,double ave)
{
    ave = ave * (n - 1)/n + val / n;
    return ave;
}

extern double var_online(double val,double ave,double square_ave)
{
    A = ave_online(val, ave);

    square_ave = square_ave * (n-1) / n + (double)pow(val, 2 / n);
    
    s = square_ave - (double)pow(A, 2);

    return s;
}