#ifndef Habitat_H
#define Habitat_H
#include "Canli.h"
#include "Sinek.h"
#include "pire.h"
#include "Bitki.h"
#include "Bocek.h"

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"
struct Habitat
{
   

};
typedef struct Habitat* habitat;
int odeviBaslat();
void sayilari_harfa_cevir(char**,int**,int,int*);
void baslangic_durumu_yaz(char**,int,int*);
void war(char**,int**,int,int*);

#endif