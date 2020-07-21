#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave);
extern double var_online(double val,double ave,double square_ave);
int n = 1;
double S, ave, square_ave;

int main(void)
{
    double u, val;
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
        ave = ave_online(val, ave);
        S = var_online(val, ave, square_ave);
        n++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    u = S * n / (n-1);

    printf("sample mean : %.2lf\n", ave);
    printf("sample variance : %.2lf\n", S);
    printf("population mean (estimated) : %.2lf\n", ave);
    printf("population variance (estimated) : %.2lf\n", u);

    return 0;
}

extern double ave_online(double val,double ave)
{
    double a=ave;

    a = ave * (n - 1)/n + val / n;

    return a;
}

extern double var_online(double val,double ave,double square_ave)
{
    double s, aa=ave, z=square_ave;

    aa = ave * (n-1)/n + val/n;

    z = square_ave * square_ave * (n-1) / n + val * val / n;
    
    s = z - aa * aa;
    printf("%lf, %lf, %lf, %lf\n", z, aa, square_ave, s);
    return s;
}