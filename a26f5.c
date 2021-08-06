
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int AM;
    int Num;
    //char Name[20];
    //char Surname[20];
    //char Sex;
    //int Year;
    //float Grade;

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
int BuildBST(BinTreePointer *Root);
void writeNewStudents(BinTreePointer *Root, int *size);



main(){

    BinTreePointer Root;
    BinTreePointer LocPtr;
    CreateBST(&Root);
    BinTreeElementType element, searchStd;

    int nscan, Year;
    char Name[20], Surname[20], Sex, termch;
    float Grade;

    int size;

    printf("Q1. Build BST from a file\n");
    size = BuildBST(&Root);

    printf("Q2. Print size and BST\n");
    printf("Size = %d\n", size);
    printf("Nodes of BST\n");
    InorderTraversal(Root);

    printf("\nQ3. Write new students, update file and BST\n");
    writeNewStudents(&Root, &size);
    printf("Q4. Print size and BST\n");
    printf("Size = %d\n", size);
    printf("Nodes of BST\n");
    InorderTraversal(Root);
    printf("\nQ5. Search for a student\n");
    printf("Give student's code: ");
    scanf("%d", &searchStd.AM);

    boolean found;

    BSTSearch(Root, searchStd, &found, &LocPtr);

    if(found){

        FILE *f1;
        f1 = fopen("foitites.dat", "r");
        if(f1==NULL)
            printf("Can't open file\n");
        else{

            while(TRUE){
                nscan = fscanf(f1, "%d, %[^,], %[^,], %c, %d, %f%c", &element.AM, Name, Surname, &Sex, &Year, &Grade, &termch);

                if(nscan == EOF) break;
                if(element.AM == searchStd.AM){
                    printf("%d, %s, %s, %c, %d, %0.1f\n", element.AM, Name, Surname, Sex, Year, Grade);
                }
            }
        }
        fclose(f1);
    }
    else{
        printf("Student not found\n");
    }

    printf("Q6. Print size and BST\n");
    printf("Size = %d\n", size);
    printf("Nodes of BST\n");
    InorderTraversal(Root);

    printf("Q7. Print students with grades>=given grade\n");
    float givenGrade;
    printf("Give the grade: ");
    scanf("%f", &givenGrade);

    FILE *f1;
    f1 = fopen("foitites.dat", "r");
        if(f1==NULL)
            printf("Can't open file\n");
        else{

            while(TRUE){
                nscan = fscanf(f1, "%d, %[^,], %[^,], %c, %d, %f%c", &element.AM, Name, Surname, &Sex, &Year, &Grade, &termch);

                if(nscan == EOF) break;
                if(Grade >= givenGrade){
                    printf("%d, %s, %s, %c, %d, %0.1f\n", element.AM, Name, Surname, Sex, Year, Grade);
                }
            }
        }
        fclose(f1);

printf("\n");
system("PAUSE");
return 0;
}

int BuildBST(BinTreePointer *Root){

    BinTreeElementType foititis;
    int nscan, Year, i=0;
    char Name[20], Surname[20], Sex, termch;
    float Grade;

    FILE *f1;
    f1 = fopen("foitites.dat", "r");
    if(f1==NULL)
        printf("Can't open file\n");
    else{
        while(TRUE){
            nscan = fscanf(f1, "%d, %[^,], %[^,], %c, %d, %f%c", &foititis.AM, Name, Surname, &Sex, &Year, &Grade, &termch);

            if(nscan == EOF) break;
            foititis.Num = i;

            BSTInsert(&(*Root), foititis);
            i++;
        }
    }
    fclose(f1);

return i++;
}

void writeNewStudents(BinTreePointer *Root, int *size){

    BinTreeElementType Student;
    int Year, i=*size;
    char Name[20], Surname[20], Sex, Ans;
    float Grade;

    boolean cont = TRUE;

    FILE *f1;
    f1 = fopen("foitites.dat", "a");
    if(f1==NULL)
        printf("Can't open file\n");
    else{

        while(cont){
            printf("Give student's AM: ");
            scanf("%d", &Student.AM);

            printf("Give student's surname: ");
            scanf("%s", Surname);
            getchar();

            printf("Give student's name: ");
            scanf("%s", Name);
            getchar();

            printf("Give student's sex F/M: ");
            scanf("%c", &Sex);
            getchar();

            printf("Give student's registration year: ");
            scanf("%d", &Year);

            printf("Give student's grade: ");
            scanf("%f", &Grade);

            Student.Num = i;
            BSTInsert(&(*Root), Student);

            fprintf(f1, "%d,%s,%s,%c,%d,%0.1f\n", Student.AM, Name, Surname, Sex, Year, Grade);

            i++;
            printf("Size = %d\n\n", i);


            //printf("%d, %s, %s, %c, %d, %.1f\n", Student.AM, Name, Surname, Sex, Year, Grade);

            printf("Continue? Y/N: ");
            getchar();
            scanf("%c", &Ans);
            getchar();

            if(Ans == 'N' || Ans == 'n')
                cont = FALSE;
        }
    }
    fclose(f1);
    *size = i;
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
        if (Item.AM < LocPtr ->Data.AM)
            LocPtr = LocPtr ->LChild;
        else if (Item.AM > LocPtr ->Data.AM)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %d EINAI HDH STO DDA\n", Item.AM);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
 //       LocPtr ->Data = Item;
        LocPtr ->Data.AM = Item.AM;
        LocPtr ->Data.Num = Item.Num;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.AM < Parent ->Data.AM)
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
        if (KeyValue.AM < (*LocPtr)->Data.AM)
            *LocPtr = (*LocPtr)->LChild;
        else
            if (KeyValue.AM > (*LocPtr)->Data.AM)
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
        if (KeyValue.AM < (*LocPtr)->Data.AM) {
            TempParent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue.AM > (*LocPtr)->Data.AM) {
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
        printf("TO STOIXEIO %d DEN EINAI STO DDA\n", KeyValue.AM);
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
        printf("(%d, %d),",Root->Data.AM,Root->Data.Num);
        InorderTraversal(Root->RChild);
    }
}
