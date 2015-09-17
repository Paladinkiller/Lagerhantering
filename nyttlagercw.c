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
  vara_t *varor;
  int intindex;};
typedef struct lager lager_t;

char ask_question_char(char *q, char *alt)
{
  char input = 0;

  printf("%s [%s]\n", q, alt);
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

void ask_question_string(void){
  puts("FIXMEask_question_string");
}

void laggTillVara(lager_t *lager){
  vara_t vara;
  lager->antal_varor = lager->antal_varor + 1;

  ask_question_string();
}

void taBortVara(void){
  puts("FIXMEtaBortVara");
}
void redigeraVara(void){
  puts("FIXMEredigeraVara");
}
void listaKorgen(void){
  puts("FIXMElistaKorgen");
}
void angraSenaste(void){
  puts("FIXMEangraSenaste");
}
void byebye(void){
  puts("ByeBye have a nice day :)");
}
int main (int argc, char *argv[]){
  vara_t varor[128];
  lager_t lager = {.antal_varor=0, .max_varor=sizeof(varor)/sizeof(vara_t), .varor=varor, .intindex=0};
 start:
  puts ("[L]ägga till en vara"); 
  puts ("[T]a bort en vara");
  puts ("[R]edigera vara");
  puts ("Ån[G]ra senaste ändrigen");
  puts ("Lista [H]ela varukorgen ");
  puts ("[A]vsluta");
  char input = ask_question_char("vad vill du göra idag?","LlTtRrGgHhAa");

  if (input == 'L'){
    laggTillVara (&lager);
  }
  else if (input == 'T'){
    taBortVara ();
  }
  else if (input == 'R'){
    redigeraVara ();
  }
  else if (input == 'G'){
    angraSenaste ();
  }
  else if (input == 'H'){
    listaKorgen ();
  }
  else {
    char sndinput = ask_question_char("är du säker på att du vill avsluta?","JjNn");
      if (sndinput == 'J'){
	byebye();
      }
      else goto start;
    
	
  }

}
