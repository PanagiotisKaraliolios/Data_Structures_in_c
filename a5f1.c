#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define megisto_plithos 1000          //μέγιστο πλήθος στοιχείων συνόλου

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

void displayset(typos_synolou set);

boolean isFibonacci(int n, typos_synolou set);
void createFibonacciSet(int threshold, typos_synolou synoloFibonacci);

int main()
{

    int maxNumber, checkNumber;
    typos_synolou synoloFibonacci;
    boolean stop = FALSE;

    boolean validNumber = FALSE;
    while(!validNumber){
        printf("DWSE TON MEGISTO ARITHMO (STO DIASTHMA 2-1000): ");
        scanf("%d", &maxNumber);
        if(maxNumber >= 2 && maxNumber <= 1000)
            validNumber = TRUE;
        else if(maxNumber < 0)
            return 0;
        else
            printf("LATHOS ARITHMOS\n");
    }

    createFibonacciSet(maxNumber, synoloFibonacci);
    displayset(synoloFibonacci);

    while(!stop){
        printf("ENTER NUMBER TO CHECK: ");
        scanf("%d", &checkNumber);
        if(isFibonacci(checkNumber, synoloFibonacci) && checkNumber >= 0)
            printf("Fibonacci!\n");
        else if(!isFibonacci(checkNumber, synoloFibonacci) && checkNumber >= 0)
            printf("Not Fibonacci...!\n");
        else
            stop = TRUE;
    }

system("PAUSE");
return 0;
}

void createFibonacciSet(int threshold, typos_synolou synoloFibonacci){
    Dimiourgia(synoloFibonacci);
    int t1 = 0, t2 = 1, nextTerm = 1;
    stoixeio_synolou stoixeio;
    stoixeio = t1;
    Eisagogi(t1, synoloFibonacci);
    stoixeio = t2;
    Eisagogi(t2, synoloFibonacci);

    while(nextTerm <= threshold) {
        stoixeio = nextTerm;
        Eisagogi(stoixeio, synoloFibonacci);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
}

boolean isFibonacci(int n, typos_synolou set){

    return Melos(n, set);
}

void displayset(typos_synolou set)
{
	stoixeio_synolou i;

	for (i=0;i < megisto_plithos;i++)
	{
		if(Melos(i,set))
			printf(" %d",i);
	}
	printf("\n");
}

void Dimiourgia(typos_synolou synolo)
/* Λειτουργία: Δημιουργεί ένα σύνολο χωρίς στοιχεία, δηλαδή το κενό σύνολο.
   Επιστρέφει: Το κενό σύνολο
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Εισάγει το στοιχείο στο σύνολο.
   Επιστρέφει: Το τροποποιημένο σύνολο
*/
{
    synolo[stoixeio] = TRUE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* Δέχεται:    Ένα σύνολο και ένα στοιχείο.
   Λειτουργία: Ελέγχει αν το στοιχείο είναι μέλος του συνόλου.
   Επιστρέφει: Επιστρέφει TRUE αν το στοιχείο είναι μέλος του και FALSE διαφορετικά
*/
{
    return synolo[stoixeio];
}
