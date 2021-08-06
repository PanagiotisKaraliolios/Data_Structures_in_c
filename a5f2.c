#include <stdio.h>

#define StackLimit 15

typedef int StackElementType;   // ο τύπος των στοιχείων  της στοίβας
                                //ενδεικτικά τύπος int
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);


int main(){

    StackElementType x, z;
    StackType stack, tempStack;
    CreateStack(&stack);
    CreateStack(&tempStack);
    int element;


    for(int i = 0; i < StackLimit; i++){
        z = i*10;
        Push(&stack, z);
    }

    TraverseStack(stack);

    printf("Give n-th element (n<=%d) ", (stack.Top-1)/2);
    scanf("%d", &element);

    //Question a
    Pop(&stack, &x);
    Pop(&stack, &x);

    printf("\n\nQuestion a: x=%d", x);
    TraverseStack(stack);

    //Question b
    Pop(&stack, &x);
    z = x;
    Pop(&stack, &x);
    Push(&stack, x);
    Push(&stack, z);

    printf("\n\nQuestion b: x=%d", x);
    TraverseStack(stack);

    //Question c
    for(int i = 0; i < element; i++){
        Pop(&stack, &x);
    }

    printf("\n\nQuestion c: x=%d", x);
    TraverseStack(stack);

    //Question d
    for(int i = 0; i < element; i++){
        Pop(&stack, &x);
        Push(&tempStack, x);
    }

    while(!EmptyStack(tempStack)){
        Pop(&tempStack, &z);
        Push(&stack, z);
    }

    printf("\n\nQuestion d: x=%d", x);
    TraverseStack(stack);

    //Question e
    while(!EmptyStack(stack)){
        Pop(&stack, &x);
        Push(&tempStack, x);
    }

    while(!EmptyStack(tempStack)){
        Pop(&tempStack, &z);
        Push(&stack, z);
    }

    printf("\n\nQuestion e: x=%d", x);
    TraverseStack(stack);

    //Question f
    while(stack.Top >= 2){
        Pop(&stack, &x);
        Push(&tempStack, x);
    }

    while(!EmptyStack(tempStack)){
        Pop(&tempStack, &z);
        Push(&stack, z);
    }

    printf("\n\nQuestion f: x=%d", x);
    TraverseStack(stack);

    //Question g
    while(!EmptyStack(stack)){
        Pop(&stack, &x);
        Push(&tempStack, x);
    }

    printf("\n\nQuestion g: x=%d", x);
    TraverseStack(stack);

    system("PAUSE");
    return 0;
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d ",Stack.Element[i]);
    }
    printf("\n");
}

void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}


