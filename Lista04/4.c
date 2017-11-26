#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#define BIGNUM ULONG_MAX

typedef unsigned long int ulint;

ulint f1(ulint x){
    double resp;
    int down;
    resp = (log10 (x*1.0))/(log10 (2.0));
    down = floor(resp);
    if ((resp - down) == 0){
        return x;
    }
    return 0;
}

ulint f2(ulint x){
    if (x & x-1){
        return 0;
    }
    return x;
}

int main(){
    clock_t tempo_init, tempo_fim;
    double tempo_gasto;
    ulint soma = 0;
    
    tempo_init = clock();
    int i;
    for (i=0; i<BIGNUM; i++){
        soma += f1(i);
    }
    tempo_fim = clock();
    tempo_gasto = (double)(tempo_fim - tempo_init) / CLOCKS_PER_SEC;
    printf("Tempo gasto na versão normal: %lf\n", tempo_gasto);
    
    tempo_init = clock();
    for (i=0; i<BIGNUM; i++){
        soma += f2(i);
    }
    tempo_fim = clock();
    tempo_gasto = (double)(tempo_fim - tempo_init) / CLOCKS_PER_SEC;
    printf("Tempo gasto na versão bitwise: %lf\n", tempo_gasto);
    
    return 0;
}



//double to int
/*
#include <math.h>
#include <stdio.h>
int main(void)
{
   double number = 123.54;
   int down, up;
   down = floor(number);
   up = ceil(number);
   printf("original number     %5.2lf\n", number);
   printf("number rounded down %d\n", down);
   printf("number rounded up   %d\n", up);
   return 0;
}


*/