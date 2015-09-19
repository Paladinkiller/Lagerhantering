#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#define Clear_stdin while (getchar() != '\n') ;

struct lagerplats{
  char bokstav[64] ;
  int nummer;
};
typedef struct lagerplats lagerplats_t;
struct vara{
  char namn;
  char beskrivning;
  lagerplats_t lagerplats;
  int pris;
  int antal;
};
typedef struct vara vara_t;
struct lager{
  int max_varor;
  int antal_varor;
  vara_t *varor;
  int intindex;};
typedef struct lager lager_t;

bool bara_letters(char string[]){
  int i = 0;
  while(string[i] != '\0'){
    if (isalpha(string[i]) == 0){
      return false;
    }   
    i++;
  }
  return true;
}

char ask_question_char(char *q, char *alt)
{
  char input = 0;

  printf("%s\n", q);
  do {
    if (input)
      {
        printf("Bad input '%c', try again [%s]\n", input, alt);
        Clear_stdin;
      }

    input = toupper(getchar());
    ungetc(input, stdin); 

  } while (strchr(alt, input) == NULL);

  Clear_stdin;
  return input;
}

void ask_question_string(char q[],char indata[]){
  bool svar = false;
  while(!svar){
    printf("%s\n",q);
    gets(indata);
    if(bara_letters(indata)){
	svar = true;
    }
    else {
	printf("felaktigt svar, ange en sträng med bokstäver a-z .\n");
    }
  }
}
int ask_question_int(char *q){
  printf("%s\n",q);
  char buffer[sizeof(int)*8+1]; 
 start: 
  gets(buffer); 
  if(atoi(buffer) != 0){ 
    return atoi(buffer); 
  } 
  else { 
    printf("felaktigt svar, ange en siffra.\n"); 
    goto start; 
  } 
}

void visaVara(lager_t *lager){ 
  vara_t vara; 
  int lagerindex; 
  printf("%c\n", lager->varor[0].namn); 
  for (lagerindex = 0; lagerindex <= 19; lagerindex += 1){ 
    printf("%d.\t%d\n", lagerindex+1, lager->varor[lagerindex].namn); 
  } 
} 

void laggTillVara(lager_t *lager){ 
  vara_t vara; 
  lager->antal_varor = lager->antal_varor + 1; 
  ask_question_string("Mata in namnet på varan:", vara.namn); 
  ask_question_string("Mata in Beskrivningen på varan:", vara.beskrivning);
  vara.pris = ask_question_int("Mata in priset för varan:");
  vara.antal = ask_question_int("Mata in antalet av varan:");
  lager->varor[lager->antal_varor]=vara;
  printf("%c\n", lager->varor[1].namn);
  printf("%c\n", lager->varor[1].beskrivning);
  printf("%d\n", lager->varor[1].pris);
  printf("%d\n", lager->varor[1].antal);
}

void taBortVara(void){
  puts("FIXMEtaBortVara");
}
void redigeraVara(lager_t *lager){
  visaVara(lager);
}
void listaKorgen(void){
  puts("FIXMElistaKorgen");
}
void angraSenaste(void){
  puts("FIXMEangraSenaste");
}
bool byebye(void){
  char input = ask_question_char("är du säker på att du vill avsluta? [J]a/[N]ej?","NJ");
  if (input == 'J'){
    return false;
  }
  else {
    return true;
  }
}
int main (int argc, char *argv[]){
  bool run = true;
  vara_t varor[128];
  lager_t lager = {.antal_varor=0, .max_varor=sizeof(varor)/sizeof(vara_t), .varor=varor, .intindex=0};
  while(run){
    puts ("[L]ägga till en vara"); 
    puts ("[T]a bort en vara");
    puts ("[R]edigera vara");
    puts ("Ån[G]ra senaste ändrigen");
    puts ("Lista [H]ela varukorgen ");
    puts ("[A]vsluta");
    char input = ask_question_char("vad vill du göra idag?","LTRGHA");
    
    if (input == 'L'){
      laggTillVara (&lager);
    }
    else if (input == 'T'){
      taBortVara ();
    }
    else if (input == 'R'){
      redigeraVara (&lager);
    }
    else if (input == 'G'){
      angraSenaste ();
    }
    else if (input == 'H'){
      listaKorgen ();
    }
    else {
      run = byebye();
    }
  }
  return 0;
}


