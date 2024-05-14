#ifndef Bitki_H
#define Bitki_H
#include "Canli.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"
struct Bitki
{
canli super;
char harf;
void (*yoket)();



};
typedef struct Bitki* bitki;
char* bitkiGorunum(const bitki );
bitki bitkioLustur(char harf);
void bitkiSilme(bitki);
#endif