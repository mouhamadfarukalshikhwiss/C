#include "Bitki.h"




bitki bitkioLustur(char harf){
bitki this=(bitki)malloc(sizeof(struct Bitki));
this->super = canliOLustur(harf);
this->super->gorunum=&bitkiGorunum;
this->yoket=&bitkiSilme;
return this;
}

char* bitkiGorunum(const bitki this){
    char* charf = (char *)malloc (2 * sizeof(char));
    charf[0] = 'B';
    return charf;
}




void bitkiSilme(bitki this){
if (this!=NULL)
    {
        free(this);
    }

}