#include"pire.h"




pir pireoLustur(char harf){
pir this=(pir)malloc(sizeof(struct pire));
this->super = BocekOLustur(harf);
this->super->super->gorunum=&PireGorunum;
this->yoket=&pireSilme;
return this;
}

char* PireGorunum(const pir this){
    char* charf = (char *)malloc (2 * sizeof(char));
    charf[0] = 'P';
    return charf;
}


void pireSilme(pir this){
    if (this!=NULL)
    {
        free(this);
    }
    
}
