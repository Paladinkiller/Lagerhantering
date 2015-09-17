#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
struct lagerplats{
char bokstav [64];
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
void redigeraVara(lager_t *lager);
void listaKorgen(lager_t *lager);
void angraSenaste(lager_t *lager);
void visaVara(lager_t *lager);
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
return taInVal(lager);
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
laggTillVara (lager);
}
else if (b == 'T'){
taBortVara (lager);
}
else if (b == 'R'){
redigeraVara (lager);
}
else if (b == 'G'){
angraSenaste (lager);
}
else if (b == 'H'){
listaKorgen (lager);
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
/* if(lager.antal <1024)
{
lager.varor[lager.vara.antal] = vara;
lager.vara.antal +=1;
return true;
}
*/
vara_t vara;
puts("mata in namnet på varan");
char buffer[128];
fgets (buffer, sizeof(buffer), stdin);
strcpy(vara.namn, buffer);

puts("mata in beskrivningen på varan");
char buffer2[256];
fgets (buffer2, sizeof(buffer2), stdin);
strcpy(vara.beskrivning, buffer2);

puts("mata in priset på varan");
int buffer3;
scanf("%d",&buffer3);
vara.pris = buffer3;

puts("mata in lagerplatsens bokstavsindex för varan");
char buffer4[64];
fgets (buffer4, sizeof(buffer4), stdin);
strcpy(vara.lagerplats.bokstav, buffer4);

puts("mata in lagerplatsens nummerindex för varan");
int buffer5;
scanf("%d",&buffer5);
vara.lagerplats.nummer= buffer5;

puts("mata in antalet av varan");
int buffer6;
scanf("%d",&buffer6);
vara.antal = buffer6;
lager->varor[lager->antal_varor]=vara;
}
void taBortVara(lager_t *lager){
  /*
printf("%s\n", lager->varor[0].namn);
printf("%s\n", lager->varor[0].beskrivning);
printf("%d\n", lager->varor[0].pris);
printf("%d\n", lager->varor[0].lagerplats.nummer);
printf("%d\n", lager->varor[0].antal);
printf("%d\n", lager->antal_varor);
visaVara() FIXME
*/
visaVara(lager);

  /*
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
  */
}
void redigeraVara(lager_t *lager){

  //visaVara() FIXME

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
redigeraVara (lager);
}
}
void listaKorgen(lager_t *lager){
/* for(int i = 0; i < 3; i++) {
for(int j = 0; j < 3; j++) {
printf("%d ", lager[i][j]);
}
printf("\n"); */
puts ("REEEKT3");
}
void angraSenaste(lager_t *lager){
puts ("REEEKT4");
}
void visaVara(lager_t *lager){
int lagerindex;

for (lagerindex = 0; lagerindex <= 19; lagerindex += 1);
  printf("%s\n", lager->varor[lagerindex].namn);

if ((lager->antal_varor) > 20){
puts("Vill du visa [F]ler varor eller mata in [n]ummer för varan");
puts("tryck [a] för att avbryta");
char b = toupper(getchar());
while (getchar() !='\n');
  if (b == 'F'){
  for (lagerindex += 1 ; lagerindex <= 39; lagerindex += 1);
  printf("%s\n", lager->varor[lagerindex].namn);
  }
  else if (b == 'A'){
  alternativPrint(); //kanske blir fel håll ett öga
  }
  else {
  puts("Mata in nummret för varan");
  int indexvara;
  scanf("%d",&indexvara);
  printf("%s\n", lager->varor[(indexvara-1)].namn);
  printf("%s\n", lager->varor[(indexvara-1)].beskrivning);
  printf("%d\n", lager->varor[(indexvara-1)].pris);
  printf("%s\n", lager->varor[(indexvara-1)].lagerplats.bokstav);
  printf("%d\n", lager->varor[(indexvara-1)].lagerplats.nummer);
  printf("%d\n", lager->varor[(indexvara-1)].antal); 
  }
 }
else {
puts("mata in numret för varan");
int indexvara;
scanf("%d",&indexvara);
printf("%s\n", lager->varor[(indexvara-1)].namn);
printf("%s\n", lager->varor[(indexvara-1)].beskrivning);
printf("%d\n", lager->varor[(indexvara-1)].pris);
printf("%s\n", lager->varor[(indexvara-1)].lagerplats.bokstav);
printf("%d\n", lager->varor[(indexvara-1)].lagerplats.nummer);
printf("%d\n", lager->varor[(indexvara-1)].antal);
 }
}


    
    
    
			      
