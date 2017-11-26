#include <stdio.h>
#include <stdlib.h>

struct tempo{
    int min;
    int seg;
    int decSeg;
};

int decSeg (struct tempo *t1, struct tempo *t2){
    int decSeg;
    if(t1->decSeg > t2->decSeg){
        (t2->seg)--;
        t2->decSeg += 100;
        decSeg = t2->decSeg - t1->decSeg;
    }else{
        decSeg = t2->decSeg - t1->decSeg;
    }
    return decSeg;
}

int seg (struct tempo *t1, struct tempo *t2){
    int seg;
    if(t1->seg > t2->seg){
        (t2->min)--;
        t2->seg += 60;
        seg = t2->seg - t1->seg;
    }else{
        seg = t2->seg - t1->seg;
    }
    return seg;
}

struct tempo *resultante(struct tempo *t1, struct tempo *t2, struct tempo *tr){
    tr->decSeg = decSeg(t1, t2);
    tr->seg = seg(t1, t2);
    tr->min = t2->min - t1->min;
    return tr;
}

int main(){
    struct tempo *t1 = (struct tempo*) malloc(sizeof(struct tempo));
    struct tempo *t2 = (struct tempo*) malloc(sizeof(struct tempo));
    struct tempo *tr = (struct tempo*) malloc(sizeof(struct tempo));

    scanf("%dm %ds %d", &(t1->min), &(t1->seg), &(t1->decSeg));
    scanf("%dm %ds %d", &(t2->min), &(t2->seg), &(t2->decSeg));
    
    tr = resultante(t1, t2, tr);
    printf("%dm %ds %d\n", tr->min, tr->seg, tr->decSeg);
    
    return 0;
}
