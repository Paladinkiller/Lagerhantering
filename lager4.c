#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

struct lagerplats{
char bokstav;
int nummer;
};

typedef struct lagerplats lagerplats_t;

struct vara{
  char namn [128];
  char beskrivning [256];
  lagerplats_t lagerplats;
  int pris;
  int antal;
};

typedef struct vara vara_t; 

struct lager{
  
  int max_varor;
  int antal_varor;
  vara_t *varor;};  
typedef struct lager lager_t;

bool menyn(lager_t *lager);
void alternativPrint(void);
bool taInVal(lager_t *lager);
void laggTillVara(lager_t *lager);
void taBortVara(lager_t *lager);
void redigeraVara(void);
void listaKorgen(void);
void angraSenaste(void);
void lagerSkapning (void);
void visaVara(void);

int main (int argc, char *argv[]){
  vara_t varor[128];
  lager_t lager = {.antal_varor=0, .max_varor=sizeof(varor)/sizeof(vara_t), .varor=varor};
  bool lage = true;
  while(lage){
    lage = menyn (&lager);
  }
  return 0;
}



bool menyn (lager_t *lager) {
  alternativPrint();
  return taInVal(&lager);
}
void alternativPrint (void) {
  puts ("[L]ägga till en vara");
  puts ("[T]a bort en vara");
  puts ("[R]edigera vara");
  puts ("Ån[G]ra senaste ändrigen");
  puts ("Lista [H]ela varukorgen ");
  puts ("[A]vsluta");
}

bool taInVal (lager_t *lager){
  puts ("Välj ett av alternativen ovan");
  
  char b = toupper(getchar());
  while (getchar() !='\n');
  
  if (b == 'L'){
   laggTillVara (&lager);
  }
  else if (b == 'T'){
    taBortVara (&lager);
  }
  else if (b == 'R'){
    redigeraVara ();
  }
  else if (b == 'G'){
    angraSenaste ();
  }
  else if (b == 'H'){
    listaKorgen ();
  }
  else if (b == 'A'){
    start: 
    puts ("Är du säker på att du vill avsluta? [J]a eller[N]ej ");
    char a = toupper(getchar());
    while (getchar() !='\n');
    if (a == 'N') return true ;
    else if (a == 'J') return false;
    else goto start;
  }
  else {
    puts ("You don't deserve for rekt you typed");
    printf ("%c \n", b);
  }
  return true;
}



void laggTillVara(lager_t *lager){

  vara_t vara;
  puts("mata in namnet på varan");
  char buffer[1000];
  fgets (buffer, sizeof(buffer), stdin);
  strcpy(vara.namn, buffer);
  printf("%s\n",vara.namn);
  /*
  puts("mata in beskrivningen av varan");
  char vara.beskrivning;
  fgets (vara.beskrivning, sizeof(vara.beskrivning), stdin);

  puts("mata in priset");
  int vara.pris;
  scanf("%d",&vara.pris);

  puts("mata in hyllplatsbokstav");
  char lagerplats.bokstav;
  fgets (lagerplats.bokstav, sizeof(lagerplats.bokstav), stdin);

  puts("mata in hyllplatsnummer");
  char lagerplats.nummer;
  fgets (lagerplats.nummer, sizeof(lagerplats.nummer), stdin);

  puts("mata in antalet av varan");
  char vara.antal;
  scanf ("%d",&vara.antal);
  */
}

void taBortVara(lager_t *lager){
  printf("%s\n", &vara.namn);
  //visaVara() FIXME
  puts ("Ta bort varan? [J]a/[N]ej");
  char b = toupper(getchar());
  while (getchar() !='\n');

  if (b == 'J'){
    puts("fixmeRemoveitem");
      }
  else if (b == 'N'){
    puts("fixmeNej");
      }
  else {
    puts("Skriv Ja eller Nej");
      }
  // Måste få programmet att fastna i välja menyn här nu avbryts bara allt
}
void redigeraVara(void){
  /*
    visaVara() FIXME
    
  */
  char b = toupper(getchar());
  while (getchar() !='\n');

  puts ("[N]amn");
  puts ("[B]eskrivning");
  puts ("[P]ris");
  puts ("[L]agerhylla");
  puts ("An[t]al");
  puts ("Välj rad eller [a]vbryt:");

  if (b =='N'){
    puts("Fixme Name");
  }
  else if (b == 'B'){
    puts("Fixme Beskrivning");
  }
  else if (b == 'P'){
    puts("Fixme Pris");
  }
  else if (b == 'L'){
    puts("Fixme Lagerhylla");
      }
  else if (b == 'T'){
    puts("Fixme Antal");
      }
  else if (b == 'A'){
    puts("Fixme Avbryt");
      }
  else {
    redigeraVara ();
  }

}
void listaKorgen(void){
  /* for(int i = 0; i < 3; i++) {
 for(int j = 0; j < 3; j++) {
 printf("%d ", lager[i][j]);
 }
 printf("\n"); */
  puts ("REEEKT3"); 
}
void angraSenaste(void){
  puts ("REEEKT4");
}

void visaVara(void){
 
  /*
    Visa 20 första varorna i arrayen som en lista 1-20 
  */
  puts("Mata in Numret på varan du vill visa");
  int VisaVaran;
  scanf("%d",&VisaVaran);
  
  /* 
printf("%c\n",Namn);
printf("%c\n",Beskrivning);   
printf("%d\n",Pris);
printf("%c\n",Hyllplats);
printf("%d\n",Antal);
  */  
}


/*
A10
E10
F13
F14
G15
G16
H20
M36
W57



*/
