#ifndef pire_H
#define pire_H

#include "Bocek.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"
struct pire
{
    bocek super;
    void (*yoket)();


};
typedef struct pire* pir;
pir pireoLustur(char harf);
char* PireGorunum(const pir);
void pireSilme(const pir);

#endif