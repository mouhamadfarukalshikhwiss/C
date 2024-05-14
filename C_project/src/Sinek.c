#include "Sinek.h"



sinek sinkOLustur(char harf){
sinek this=(sinek)malloc(sizeof(struct Sinek));
this->super = BocekOLustur(harf);
this->super->super->gorunum=&sinekGorunum;
this->yoket=&sinekSilme;
return this;
}

char* sinekGorunum(const sinek this)
{
    char* charf = (char *)malloc (2 * sizeof(char));
    charf[0] = 'S';
    return charf;

}


void sinekSilme(sinek this){
    if (this != NULL) {
        free(this);
    }
}
