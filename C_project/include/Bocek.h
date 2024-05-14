#ifndef Bocek_H
#define Bocek_H
#include "Canli.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"

struct Bocek
{
canli super;
char harf;
void (*yoket)();

};
typedef struct Bocek* bocek;
bocek BocekOLustur(char harf);
char* bocekGorunum(const bocek);
void BOcekSilme(bocek);



#endif