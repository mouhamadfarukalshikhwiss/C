#include "Habitat.h"
#include "Bitki.h"
#include "Sinek.h"
#include "pire.h"
#include "Bocek.h"
#include "Canli.h"
#include <ctype.h>
#include "conio.h"
habitat this;
int odeviBaslat() {
    FILE *file;
    char *line = NULL;
    int line_length = 0;
    int **sayilar_matrisi = NULL;
    int line_count = 0;
    char **harfler_matrisi = NULL;
    int *line_sizes = NULL;
    // Dosyayı açma işlemi
    file = fopen("Veri.txt", "r");
    if (!file) {
        fprintf(stderr, "Dosya açılamadı.\n");
        return EXIT_FAILURE;
    }

    // Dosyadan satırları okuma ve işleme
    while (getline(&line, &line_length, file) != -1) {
        // Satırı işleme ve veri dizisi oluşturma
        char *token = strtok(line, " \n");
        int size = 0;
        int *line_sayilar_matrisi = malloc(sizeof(int*));
        char *line_harfler_matrisi = malloc(strlen(line) + 1);
        if (!line_sayilar_matrisi || !line_harfler_matrisi) {
            fprintf(stderr, "Bellek ayrılamadı.\n");
            fclose(file);
            return EXIT_FAILURE;
        }

        // Satırdaki sayıları ve harfleri ayrıştırarak saklama
        while (token) {
            if (isdigit(token[0])) {
                line_sayilar_matrisi = realloc(line_sayilar_matrisi, (size + 1) * sizeof(int*));
                if (!line_sayilar_matrisi) {
                    fprintf(stderr, "Bellek genişletilemedi.\n");
                    fclose(file);
                    return EXIT_FAILURE;
                }
                line_sayilar_matrisi[size] = atoi(token);
            } else {
                line_harfler_matrisi[size] = token[0];
            }
            size++;
            token = strtok(NULL, " \n");
        }

        // Ana diziye satırı ekleme
        sayilar_matrisi = realloc(sayilar_matrisi, (line_count + 1) * sizeof(int *));
        harfler_matrisi = realloc(harfler_matrisi, (line_count + 1) * sizeof(char *));
        if (!sayilar_matrisi || !harfler_matrisi) {
            fprintf(stderr, "Bellek genişletilemedi.\n");
            fclose(file);
            return EXIT_FAILURE;
        }
        sayilar_matrisi[line_count] = line_sayilar_matrisi;
        harfler_matrisi[line_count] = line_harfler_matrisi;

        // Her satırın boyutunu kaydetme
        line_sizes = realloc(line_sizes, (line_count + 1) * sizeof(int*));
        if (!line_sizes) {
            fprintf(stderr, "Bellek genişletilemedi.\n");
            fclose(file);
            return EXIT_FAILURE;
        }
        line_sizes[line_count++] = size;
    }
    // Dosyayı kapat
    fclose(file);

    // Harflar_matris için bellek tahsisi
    harfler_matrisi = malloc(line_count * sizeof(char *));
    if (!harfler_matrisi) {
        fprintf(stderr, "Bellek ayrılamadı.\n");
        return EXIT_FAILURE;
    }

    sayilari_harfa_cevir(harfler_matrisi,sayilar_matrisi,line_count,line_sizes);
    printf("\n");
    printf("Savasi Baslamak Icin Her Hangi Bir Tusa Bas :");
    getch();
    war(harfler_matrisi,sayilar_matrisi,line_count,line_sizes);
    // Kullanılan belleği serbest bırak
    for (int i = 0; i < line_count; i++) {
        free(sayilar_matrisi[i]);
        free(harfler_matrisi[i]);
    }
    free(sayilar_matrisi);
    free(harfler_matrisi);
    free(line);

    return EXIT_SUCCESS;
}

  void sayilari_harfa_cevir(char**harfler_matrisi,int**sayilar_matrisi,int line_count,int*line_sizes){
int i=0;
    while ( i < line_count){ 
        harfler_matrisi[i] = malloc(line_sizes[i] * sizeof(char));
        for (int j = 0; j < line_sizes[i]; j++) {
            int value = sayilar_matrisi[i][j];
            if (!(value < 1) && !(value > 9)) {
                bitki b=bitkioLustur(value);  
                 harfler_matrisi[i][j] = *bitkiGorunum(b);  
                 bitkiSilme(b); 
            } else if (!(value < 10) && !(value > 20)) {
                 bocek bc = BocekOLustur(value);  
                 harfler_matrisi[i][j]=*bocekGorunum(bc);  
                 BOcekSilme(bc); 
            } else if (!(value < 21) && !(value > 50)) {
                 sinek s = sinkOLustur(value);  
                 harfler_matrisi[i][j] = *sinekGorunum(s);  
                 sinekSilme(s);  
            } else if (!(value < 51) && !(value > 99)) {
                 pir p = pireoLustur(value);  
                 harfler_matrisi[i][j] = *PireGorunum(p);  
                 pireSilme(p);  
            } else {
                harfler_matrisi[i][j] = ' ';
            }
        
            }
        i++;
    }
  
   baslangic_durumu_yaz(harfler_matrisi,line_count,line_sizes);
  }
void baslangic_durumu_yaz(char**harfler_matrisi,int line_count,int* line_sizes){
  printf("Baslangic durumu :\n");
    for (int i = 0; i < line_count; i++) {
        for (int j = 0; j < line_sizes[i]; j++) {
            printf("%c ", harfler_matrisi[i][j]);
        }
        printf("\n");
    }
}



void war(char** harflar,int** sayilar,int satir ,int* sutun){
    int a=0; 
    int b=0;
  for (int i = 0; i < satir; i++)
    {
        for (int j = 0; j < sutun[i]; j++)
        {
         if (i==0 && j==0)
         {
            j++;
         }
         if (harflar[a][b]==harflar[i][j])
         {
                if (sayilar[a][b]==sayilar[i][j])
                {
                    harflar[i][j]='X';
                    
                    
                }
                else if (sayilar[a][b] < sayilar[i][j])
                {
                    harflar[a][b]='X';
                    a=i;
                    b=j;
                }
                else 
                {
                    harflar[i][j]='X';
                }
                
                
                
         }
         else
         {
            if (harflar[a][b]=='S')
            {
                if (harflar[i][j]=='P')
                {
                    harflar[i][j]='X';
                }
                else if (harflar[i][j]=='C')
                {
                     harflar[i][j]='X'; 
                }
                else if ( harflar[i][j]=='B'){
                    harflar[a][b]='X';
                    a=i;
                    b=j;
                }
                
              
                
                
            }
            else if (harflar[a][b]=='B')
            {
                if (harflar[i][j]=='P')
                {
                     harflar[i][j]='X';
                }
                else if (harflar[i][j]=='S')
                {
                     harflar[i][j]='X';
                }
                else 
                {
                   harflar[a][b]='X';
                   a=i;
                   b=j;
                }
                
                
                
            }
            else if (harflar[a][b]=='C')
            {
                if (harflar[i][j]=='B')
                {
                     harflar[i][j]='X';
                }
                else if (harflar[i][j]=='P')
                {
                     harflar[i][j]='X';
                }
                else if (harflar[i][j]=='S')
                {
                    harflar[a][b]='X';
                    a=i;
                    b=j;
                }    
            }
            else if (harflar[a][b]=='P')
            {
                harflar[a][b]='X';
                a=i;
                b=j;
            }
            
            
         }

        }
        
    printf("\n");
    system("cls");
    printf("Son durum :\n");

     for (int i = 0; i < satir; i++)
    {
        for (int j = 0; j < sutun[i]; j++)
        {
            
            printf("%c ",harflar[i][j]);
        }
        printf("\n");
    }
}
  
    printf("%s : %c : (%i,%i)","Kazanan",harflar[a][b],a,b);
   
}































