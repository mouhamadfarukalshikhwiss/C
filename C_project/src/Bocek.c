#include"Bocek.h"


bocek BocekOLustur(char harf){
bocek this=(bocek)malloc(sizeof(struct Bocek));
this->super = canliOLustur(harf);
this->yoket=&BOcekSilme;
this->super->gorunum=&bocekGorunum;
return this;
}
void BOcekSilme(bocek this){
if (this!=NULL)
{
    free(this);
}
}

char* bocekGorunum(const bocek this){
    char* charf = (char *)malloc (2 * sizeof(char));
    charf[0] = 'C';
    return charf;
}