#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,double n);
extern double var_online(double val,double ave,double square_ave,double n);

int main(void)
{
    double S, ave, square_ave, n=1, u, val;
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

        square_ave = ave_online(val * val, square_ave, n);
        S = var_online(val, ave, square_ave, n);
        ave = ave_online(val, ave, n);
        n++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    
    n--;

    u = S * n / (n-1);

    printf("sample mean : %.2lf\n", ave);
    printf("sample variance : %.2lf\n", S);
    printf("population mean (estimated) : %.2lf\n", ave);
    printf("population variance (estimated) : %.2lf\n", u);

    return 0;
}

extern double ave_online(double val,double ave,double n)
{
    double a;

    a = ave * (n - 1)/n + val / n;

    return a;
}

extern double var_online(double val,double ave,double square_ave,double n)
{
    double s;
    
    s = square_ave - ave_online(val, ave, n) * ave_online(val, ave, n);

    return s;
}