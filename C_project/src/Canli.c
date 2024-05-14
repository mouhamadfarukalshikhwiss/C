#include"Canli.h"

canli canliOLustur(char harf){
canli this=(canli)malloc(sizeof(struct Canli));
this->yoket=&canliSilme;
this->harf=harf;
return this;
}
void canliSilme(canli this){

if (this!=NULL)
{
    free(this);
}

}