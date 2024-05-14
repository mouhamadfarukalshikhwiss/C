#ifndef Sinek_H
#define Sinek_H
#include "Canli.h"
#include"Bocek.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"

struct Sinek
{
bocek super;
char harf;
void (*yoket)();

    
};

typedef struct Sinek* sinek;
char* sinekGorunum(const sinek);
sinek sinkOLustur(char harf);
void sinekSilme(sinek);

#endif