#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave);
extern double var_online(double val,double ave,double square_ave);
double S, ave, square_ave;

int main(void)
{
    int N=0;
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
    square_ave = 1;
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        ave = ave_online(val, ave);
        printf("square_ave1= %lf\n", square_ave);
        S = var_online(val, ave, square_ave);
        printf("square_ave = %lf\n", square_ave);
        N++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    
    u = S * N / (N-1);

    printf("sample mean : %.2lf\n", ave);
    printf("sample variance : %.2lf\n", S);
    printf("population mean (estimated) : %.2lf\n", ave);
    printf("population variance (estimated) : %.2lf\n", u);

    return 0;
}

extern double ave_online(double val,double ave)
{
    static int n=1; 
    double a=ave;

    a = ave * (n - 1)/n + val / n;
    n++;
    printf("%d, %lf\n", (n-1)/n, a);
    return a;
}

extern double var_online(double val,double ave,double square_ave)
{
    static double nn=1;
    double s, z=square_ave, v;
    printf("square_ave2 = %lf", square_ave);
    z = square_ave * square_ave * (nn-1) / nn;
    v = val * val /nn;

    square_ave = z + v;
    
    s = square_ave - ave * ave;
    nn++;
    printf("%lf, %lf, %lf, %lf, %lf, %lf\n", nn, z, v, (nn-1)/nn, square_ave, s);
    
    return s;
}