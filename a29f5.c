#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int amka, afm, age;
} BinTreeElementType;                   /*ο τύπος των στοιχείων του ΔΔΑ είναι
                                        τύπου struct */
typedef struct BinTreeNode *BinTreePointer;

 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);

main(){

    BinTreePointer Over60, Under60, LocPtr;
    BinTreeElementType AnItem;
    boolean flag = TRUE;
    char ans;

    CreateBST(&Over60);
    CreateBST(&Under60);

    while(flag){
        printf("Give AMKA: ");
        scanf("%d", &AnItem.amka);

        printf("Give AFM: ");
        scanf("%d", &AnItem.afm);

        printf("Give age: ");
        scanf("%d", &AnItem.age);

        if(AnItem.age<=60){
            BSTInsert(&Under60, AnItem);
        }
        else{
            BSTInsert(&Over60, AnItem);
        }


        printf("Continue Y/N: ");
        scanf(" %c",&ans);
        getchar();

        if(ans == 'N' || ans == 'n'){
            flag = FALSE;
        }
    }

    printf("\nPeople with age less-equal 60\n");
    InorderTraversal(Under60);
    printf("\n");

    printf("\nPeople with age greater than 60\n");
    InorderTraversal(Over60);
    printf("\n");


    for(int i=0; i<3; i++){

        printf("Give AMKA: ");
        scanf("%d", &AnItem.amka);

        printf("Give age: ");
        scanf("%d", &AnItem.age);

        boolean Found = FALSE;

        if(AnItem.age<60){
            BSTSearch(Under60, AnItem, &Found, &LocPtr);

            if(Found){
                if(LocPtr->Data.age == AnItem.age){
                    printf("The person with AMKA %d, AFM %d and age %d is in the catalog.\n", LocPtr->Data.amka, LocPtr->Data.afm, LocPtr->Data.age);
                }
                else{
                    printf("The person with AMKA %d has age %d. Different from the person you are looking for.\n", LocPtr->Data.amka, LocPtr->Data.age);
                }
            }
            else{
                printf("The person with AMKA %d and age %d not found.\n", AnItem.amka, AnItem.age);
                printf("The person with AMKA %d and age %d is Unknown.\n", AnItem.amka, AnItem.age);
            }
        }
        else{
            BSTSearch(Over60, AnItem, &Found, &LocPtr);
            if(Found){
                if(LocPtr->Data.age == AnItem.age){
                    printf("The person with AMKA %d, AFM %d and age %d is in the catalog.\n", LocPtr->Data.amka, LocPtr->Data.afm, LocPtr->Data.age);
                }
                else{
                    printf("The person with AMKA %d has age %d. Different from the person you are looking for.\n", LocPtr->Data.amka, LocPtr->Data.age);
                }
            }
            else{
                printf("The person with AMKA %d and age %d not found.\n", AnItem.amka, AnItem.age);
                printf("The person with AMKA %d and age %d is Unknown.\n", AnItem.amka, AnItem.age);
            }
        }



    }



system("PAUSE");
return 0;
}

void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item.amka < LocPtr ->Data.amka)
            LocPtr = LocPtr ->LChild;
        else if (Item.amka > LocPtr ->Data.amka)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %d EINAI HDH STO DDA\n", Item.amka);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
 //       LocPtr ->Data = Item;
        LocPtr ->Data.amka = Item.amka;
        LocPtr ->Data.afm= Item.afm;
        LocPtr ->Data.age= Item.age;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.amka < Parent ->Data.amka)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{
    boolean stop;

    *LocPtr = Root;
    stop = FALSE;
    while (!stop && *LocPtr != NULL)
    {
        if (KeyValue.amka < (*LocPtr)->Data.amka)
            *LocPtr = (*LocPtr)->LChild;
        else
            if (KeyValue.amka > (*LocPtr)->Data.amka)
                *LocPtr = (*LocPtr)->RChild;
            else stop = TRUE;
    }
   *Found=stop;
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του
                και τον πατέρα του κόμβου αυτού.
   Επιστρέφει: Η Found έχει τιμή TRUE, ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue και ο Parent δείχνει στον πατέρα
                αυτού του κόμβου, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE.
*/
{
    boolean stop;
    BinTreePointer TempParent;

    *LocPtr = Root;
    TempParent=NULL;
    stop = FALSE;
    while (!stop && *LocPtr != NULL)
    {
        if (KeyValue.amka < (*LocPtr)->Data.amka) {
            TempParent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue.amka > (*LocPtr)->Data.amka) {
                TempParent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else stop = TRUE;
    }
   *Found=stop;
   *Parent=TempParent;
}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* Δέχεται:  Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
  Λειτουργία: Προσπαθεί να βρει έναν κόμβο στο ΔΔΑ που να περιέχει την τιμή
                KeyValue στο πεδίο κλειδί του τμήματος δεδομένων του και,
                αν τον βρει, τον διαγράφει από το ΔΔΑ.
  Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του.
*/
{

   BinTreePointer
   R,
   n,                   //δείχνει στον κόμβο που περιέχει την τιμή KeyValue *)
   Parent,              // πατέρας του n ή του nNext
   nNext,               // ενδοδιατεταγμένος επόμενος του n
   SubTree;             // δείκτης προς υποδέντρο του n
   boolean Found;       // TRUE AN TO ΣΤΟΙΧΕΙΟ KeyValue EINAI ΣΤΟΙΧΕΟ ΤΟΥ ΔΔΑ *)

     R=*Root;
     BSTSearch2(R, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %d DEN EINAI STO DDA\n", KeyValue.amka);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // κόμβος προς διαγραφή με δύο παιδιά
                 //Βρες τον ενδοδιατεταγμένο επόμενο και τον πατέρα του
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* Αντιγραφή των περιεχομένων του nNext στον n και
                αλλαγή του n ώστε να δείχνει στον επόμενο */
                n->Data = nNext->Data;
                n = nNext;
          } //Συνεχίζουμε με την περίπτωση που ο κόμβος έχει το πολύ 1 παιδί
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("(%d,%d,%d)",Root->Data.amka, Root->Data.afm, Root->Data.age);
        InorderTraversal(Root->RChild);
    }
}
