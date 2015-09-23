#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#define Clear_stdin while (getchar() != '\n') ;

struct vara{
  char namn[64];
  char beskrivning[64];
  int pris;
  int antal;
  char platsbokstav;
  int platsnummer;


};
typedef struct vara vara_t;
struct lager{
  int antal_varor;
  vara_t *varor;

};


typedef struct lager lager_t;

bool bara_letters(char string[]){
  int i = 0;
  while(string[i] != '\0'){
    if ((isalpha(string[i]) == 0)){
      bool ar_undantag = false;
      const char undantag[] = {' ', ',', '.'};
      for (int k=0; k<sizeof(undantag); k++){
	if (string[i] == undantag[k]){
	  ar_undantag = true;
	}
      }
      if(!ar_undantag)
	return false;
    }
    i++;
  }
  return true;
}

void listaKorgen(lager_t *lager_kopia);

char ask_question_char(char *q, char *alt)
{
  char input = 0;

  printf("%s\n", q);
  do {
    if (input)
      {
        printf("Dålig inmatning '%c', pröva igen [%s]\n", input, alt);
        Clear_stdin;
      }

    input = toupper(getchar());
    ungetc(input, stdin); 

  } while (strchr(alt, input) == NULL);

  Clear_stdin;
  return input;
}
void kopieraLager (lager_t *lager, lager_t *lager_kopia){
  lager_kopia->antal_varor = lager->antal_varor;

  for(int i = 0; i < lager->antal_varor+1; ++i){
    strcpy(lager_kopia->varor[i].namn, lager->varor[i].namn);
    strcpy(lager_kopia->varor[i].beskrivning, lager->varor[i].beskrivning);
    lager_kopia->varor[i].pris = lager->varor[i].pris;
    lager_kopia->varor[i].antal = lager->varor[i].antal;
    lager_kopia->varor[i].platsnummer = lager->varor[i].platsnummer;
    lager_kopia->varor[i].platsbokstav = lager->varor[i].platsbokstav;
  }
}
void ask_question_string(char *q,char *indata){
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
  if((atoi(buffer) != 0) && (atoi(buffer) > 0)){ 
    return atoi(buffer); 
  } 
  else { 
    printf("felaktigt svar, ange ett positivt tal .\n"); 
    goto start; 
  } 
}

void printaVara(vara_t *vara){
  printf("Namn:%s\n", vara->namn);
  printf("Beskrivning:%s\n", vara->beskrivning);
  printf("Pris:%d\n", vara->pris);
  printf("Antal:%d\n", vara->antal);
  printf("Lagerindex:%c", vara->platsbokstav);
  printf("%d\n", vara->platsnummer);
}

void laggTillVara(lager_t *lager, lager_t *lager_kopia){ 
  vara_t vara;
  kopieraLager(lager, lager_kopia);
  ask_question_string("Mata in namnet på varan:", vara.namn); 
  ask_question_string("Mata in Beskrivningen på varan:", vara.beskrivning);
  vara.pris = ask_question_int("Mata in priset för varan:");
  vara.antal = ask_question_int("Mata in antalet av varan:");
  vara.platsbokstav=ask_question_char("Mata in platsbokstaven:","ABCDEFGHIJKLMNOPQRSTUVXYZÅÄÖ");
  vara.platsnummer = ask_question_int("Mata in platsnummer:");
  int c=0; 
  while(c<=lager->antal_varor){
    if (lager->antal_varor==0){
      lager->varor[lager->antal_varor]=vara; 
      lager->antal_varor = lager->antal_varor + 1;
      printaVara(&vara);
      return;
    }
    else if (lager->varor[c].platsbokstav==vara.platsbokstav && lager->varor[c].platsnummer==vara.platsnummer){
      if (strcmp (lager->varor[c].namn,vara.namn)==0){
	lager->varor[c].antal=vara.antal+lager->varor[c].antal;
	printaVara(&vara);
	return;
      }
      
      else {
	printf("platsen är tagen");
	return;
      }
    }
    c=c+1;
  }
  lager->varor[lager->antal_varor]=vara; 
  lager->antal_varor = lager->antal_varor + 1;
  printaVara(&vara);
}

void taBortVara(lager_t *lager,int val, lager_t *lager_kopia){
  kopieraLager(lager, lager_kopia);
  val = (ask_question_int("Mata in numret på varan du vill ta bort:")) -1;
  if(lager->antal_varor==0 || val > lager->antal_varor){
    puts("Inga varor eller fel index");
    return;
  }
  else if (val< lager->antal_varor){

    for (val; val<=lager->antal_varor ; val++){
      lager->varor[val] = lager->varor[val+1];
    }
  }
  
  lager->antal_varor = lager->antal_varor - 1 ;
}

void listaKorgenKillMe(lager_t *lager, int start, int slut){
  for (int c=start;c<slut ; c++){
    if (c>lager->antal_varor-1){
      return;
    }
    printf("%d  %s\n",c+1,lager->varor[c].namn); 
  }
}
void listaKorgen (lager_t *lager){
  int start = 0;
  bool lage = true;

  while(lage){
    listaKorgenKillMe(lager, start, start+20);
    char val = ask_question_char("Visa [F]ler sidor eller [A]vsluta eller visa [M]er info","FAM");
    if (val== 'F'){
      start=start+20;
    }
    else if (val== 'A'){
      lage=false;
    }
    else if (val == 'M') {
      int nummer = ask_question_int("Mata in det valda indexet:")-1;
      if(nummer < 0 || nummer >= lager->antal_varor){
	puts("Fel index my friend, no vara exist");
	lage=false;
      }
      else{
	
	printaVara(&lager->varor[nummer]);
      }
    }
  }
  

}
void redigeraVara(lager_t *lager, lager_t *lager_kopia){
  bool lage = true;
  kopieraLager(lager, lager_kopia);
  int val = ask_question_int("Mata in numret du vill ändra:");

  if(val==0 || val > lager->antal_varor){
    puts("Fel index");
    return;
  }
  while(lage){
    char input = ask_question_char ("Mata in det du vill modda \n[N]amn\n[B]eskrivningen\n[P]riset\n[L]agerhyllan\nAn[t]alet\neller[A]vbryta:","NBPLTA");
    
    if (input == 'N'){
      printf("Aktuellt namn: %s\n", lager->varor[val-1].namn);
      ask_question_string("Nytt namn:", lager->varor[val-1].namn);
    }
    else if (input == 'B'){
      printf("Aktuell beskrivning: %s\n", lager->varor[val-1].beskrivning);
      ask_question_string("Ny beskrivning:", lager->varor[val-1].beskrivning);
    }
    else if (input == 'P'){
      printf("Aktuellt pris: %d\n", lager->varor[val-1].pris);
      lager->varor[val-1].pris = ask_question_int("Nytt Pris:");
    }
    else if (input == 'T'){
      printf("Aktuellt antal: %d\n", lager->varor[val-1].antal);
      lager->varor[val-1].antal = ask_question_int("Nytt Antal:");
    }
    else if (input == 'L'){
      int c=0;
      bool lage2 = true;
      
      int nummer = ask_question_int("Mata in platsnummer:");
      char bokstav = ask_question_char("Mata in platsbokstav:", "ABCDEFGHIJKLMNOPQRSTUVXYZÅÄÖ");
      while(lage2){
	if (lager->antal_varor==0){
	  printf("Det finns inga inlagda varor ännu\n");
	  lage2 = false;
	}
	else if (lager->varor[c].platsbokstav==bokstav && lager->varor[c].platsnummer==nummer){
	  if (strcmp (lager->varor[c].namn, lager->varor[val-1].namn)==0){
	    lager->varor[c].antal += lager->varor[val-1].antal;
	    taBortVara(lager, val-1, lager_kopia);
	    lage2 = false;
	  }
	  else{
	    printf("platsen är tagen\n");
	    lage2 = false;
	  }
	}
	c=c+1;
	if(c>=lager->antal_varor){
	  lager->varor[val-1].platsbokstav = bokstav;
	  lager->varor[val-1].platsnummer = nummer;
	  lage2 = false;
	}
      }
    }
    else if (input == 'A'){
      return;
    }
  }
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
  vara_t varork[128];
  lager_t lager = {.antal_varor=0, .varor=varor};
 lager_t lager_kopia = {.antal_varor=0, .varor=varork};
  while(run){
    puts ("[L]ägga till en vara"); 
    puts ("[T]a bort en vara");
    puts ("[R]edigera vara");
    puts ("Ån[G]ra senaste ändrigen");
    puts ("Lista [H]ela varukorgen ");
    puts ("[A]vsluta");
    char input = ask_question_char("vad vill du göra idag?","LTRGHA");
    
    if (input == 'L'){
      laggTillVara (&lager, &lager_kopia);
    }
    else if (input == 'T'){
      taBortVara (&lager, 0, &lager_kopia);
    }
    else if (input == 'R'){
      redigeraVara (&lager, &lager_kopia);
    }
    else if (input == 'G'){
      kopieraLager(&lager_kopia, &lager);
    }
    else if (input == 'H'){
      listaKorgen (&lager);
    }
    else {
      run = byebye();
    }
  }
  return 0;
}


