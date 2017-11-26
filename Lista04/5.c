#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#define BIGNUM ULONG_MAX

typedef unsigned long int ulint;

ulint f1(ulint x){
    if (x/2 == 0) return 0;
    return (x%2)+f1(x/2);
}

ulint f2(ulint x){
    int cont;
    while (x){
        cont += x & 1;
        x = x >> 1;
    }
    return cont;
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