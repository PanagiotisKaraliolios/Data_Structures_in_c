#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Code, Priority;
}QueueElementType;

typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;

void TraverseQ(QueueType Queue);
void insert_prot(QueueType *Queue, QueueElementType Item);

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);

int main()
{
    int amount;
    QueueType Queue;
    QueueElementType Qelement;

    CreateQ(&Queue);

    printf("DWSE TO PLITHOS: ");
    scanf("%d",&amount);

    for (int i=1; i<=amount ; i++)
    {
        printf("DWSE TON KODIKO TOU %dou KOMVOU: ",i);
        scanf("%d",&Qelement.Code);

        printf("DWSE TO VATHMO TOU PROTERAIOTITAS TOU %dou KOMVOU: ",i);
        scanf("%d",&Qelement.Priority);

        insert_prot(&Queue,Qelement);
    }

    TraverseQ(Queue);


system("PAUSE");
return 0;
}

void insert_prot(QueueType *Queue, QueueElementType Item)
{
	QueuePointer NewPtr, TempPtr, PredPtr;

    NewPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    NewPtr->Data = Item;
    NewPtr->Next = NULL;

    if (Queue->Front==NULL)
    {
        Queue->Front=NewPtr;
    }
    else
    {

        TempPtr=Queue->Front;


        if (TempPtr->Data.Priority > NewPtr->Data.Priority)
        {
            NewPtr->Next = TempPtr;
            Queue->Front = NewPtr;
        }
        else
        {

            while ((TempPtr->Data.Priority < NewPtr->Data.Priority) && TempPtr->Next!=NULL)
            {
                TempPtr=TempPtr->Next;
            }

            NewPtr->Next = TempPtr->Next;
            TempPtr->Next = NewPtr;
        }
    }

}

void CreateQ(QueueType *Queue)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη ουρά.
   Επιστρέφει: Μια κενή συνδεδεμένη ουρά
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, false  διαφορετικά
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά Queue και ένα  στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στο τέλος της συνδεδεμένης ουράς Queue.
   Επιστρέφει: Την τροποποιημένη ουρά
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την  κορυφή της συνδεδεμένης ουράς,
                αν δεν είναι  κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη συνδεδεμένη ουρά.
   Έξοδος:     Μήνυμα κενής ουράς, αν η ουρά είναι  κενή
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}

void TraverseQ(QueueType Queue)
{
    QueuePointer CurrPtr;

    if (EmptyQ(Queue))
    {
        printf("EMPTY Queue\n");
    }
    else
    {
        printf("----------Priority Queue-------------");
        CurrPtr = Queue.Front;
        while ( CurrPtr!=Queue.Rear )
        {
            printf("\n%d %d",CurrPtr->Data.Priority, CurrPtr->Data.Code);
            CurrPtr = CurrPtr->Next;
        }
    }
    printf("\n");
}
