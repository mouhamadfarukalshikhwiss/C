#ifndef Canli_H
#define Canli_H
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"

 struct Canli
 {
      char harf;
      char* (*gorunum)();
      void (*yoket)();

    
 };
typedef struct Canli* canli;
canli canliOLustur(char harf);
void canliSilme(canli);

#endif
