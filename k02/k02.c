#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define mu_a 170.8
#define sigma_a 5.43
#define mu_b 169.7
#define sigma_b 5.5

extern double p_stdnorm(double y);

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1,y_a,y_b,p_a,p_b;

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
        y_a = (val - mu_a) / sigma_a;
        y_b = (val - mu_b) / sigma_b;

        p_a = p_stdnorm(y_a);
        p_b = p_stdnorm(y_b);

        L1 = L1 * p_a;
        L2 = L2 * p_b;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("Likelihood for A: %10.2e\n",L1);
    printf("Likelihood for B: %10.2e\n",L2);

    return 0;

}

double p_stdnorm(double y)
{
    return 1/sqrt(2*M_PI) * exp(-y*y/2);
}

