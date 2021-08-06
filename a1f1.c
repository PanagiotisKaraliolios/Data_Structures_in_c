#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define megisto_plithos 200          //μέγιστο πλήθος στοιχείων συνόλου

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);

void displayset(typos_synolou set, int firtNum, int secondNum);
boolean isPrime(int num);
void createPrimeSet(int num1, int num2, typos_synolou synoloPrwtwn);

int main()
{
    int firstNumber, lastNumber;
    typos_synolou synoloPrwtwnArithmwn;


    boolean validFirstNumber = FALSE;
    boolean validSecondNumber = FALSE;
    while(!validFirstNumber){
        printf("DWSE AKERAIO ARI8MO STO DIASTHMA 2-200: ");
        scanf("%d", &firstNumber);
        if(firstNumber >= 2 && firstNumber <= 200)
            validFirstNumber = TRUE;
        else
            printf("LATHOS ARITHMOS\n");
    }

    while(!validSecondNumber){
        printf("\nDWSE DEYTERO AKERAIO ARITHMO STO DIASTHMA 2-200 KAI MEGALYTERO APO TON PRWTO: ");
        scanf("%d", &lastNumber);
        if(lastNumber >= 2 && lastNumber <= 200 && firstNumber < lastNumber)
            validSecondNumber = TRUE;
        else
            printf("LATHOS ARITHMOS\n");
    }

    createPrimeSet(firstNumber, lastNumber, synoloPrwtwnArithmwn);
    displayset(synoloPrwtwnArithmwn, firstNumber, lastNumber);

system("PAUSE");
return 0;

}

boolean isPrime(int num)
{
     for (int i = 2; i < num; i++)
    {
        if (num % i == 0 && i != num)
            return FALSE;
    }
    return TRUE;
}

void createPrimeSet(int num1, int num2, typos_synolou synoloPrwtwn){
    Dimiourgia(synoloPrwtwn);
    stoixeio_synolou j;
    for(int i = num1; i < num2; i++){
        if(isPrime(i)){
            j = i;
            Eisagogi(j, synoloPrwtwn);
        }
    }
}

void displayset(typos_synolou set, int firtNum, int secondNum)
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

void Katholiko(typos_synolou synolo)
/* Δέχεται:     Ένα σύνολο.
   Λειτουργία: Δημιουργεί ένα σύνολο με όλα τα στοιχεία παρόντα,
                έτσι όπως ορίστηκε στο τμήμα δηλώσεων του προγράμματος.
   Επιστρέφει: Το καθολικό σύνολο που δημιουργήθηκε
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = TRUE;
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
