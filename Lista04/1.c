#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto{
    float x;
    float y;
    float z;
};

/*struct ponto *criaPonto(float x, float y, float z){
    struct ponto *p = (struct ponto*) malloc(sizeof(struct ponto));
    if(p!=NULL){
        p->x = x;
        p->y = y;
        p->z = z;
    }
    return p;
}*/

float distancia (struct ponto *p1, struct ponto *p2){
    float x, y, z;
    x = p2->x - p1->x;
    y = p2->y - p1->y;
    z = p2->z - p1->z;
    return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}

int main(){
    struct ponto *p1 = (struct ponto*) malloc(sizeof(struct ponto));
    struct ponto *p2 = (struct ponto*) malloc(sizeof(struct ponto));
    
    scanf("%f, %f, %f", &(p1->x), &(p1->y), &(p1->z));
    scanf("%f, %f, %f", &(p2->x), &(p2->y), &(p2->z));

    float resp = distancia(p1, p2);
    printf ("%.2f\n", resp);

    return 0;
}
