#include <stdio.h>

#define QueueLimit 4  //το όριο μεγέθους της ουράς

typedef struct {
    int ArrivalTime, StayTime, StartTime, EndTime;
} QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);
void ReadTime(QueueType *Queue);
QueueType TimesInQueue(QueueType *Queue);
void DisplayInfo(char Qname[], QueueType *Queue);

main(){

    char WaitQname[10] = "WaitQ";
    char ServedQname[10] = "ServedQ";
    QueueType WaitQ, ServedQ;
    CreateQ(&WaitQ);
    CreateQ(&ServedQ);
    ReadTime(&WaitQ);

    DisplayInfo(WaitQname, &WaitQ);
    ServedQ = TimesInQueue(&WaitQ);
    DisplayInfo(WaitQname, &WaitQ);

    DisplayInfo(ServedQname, &ServedQ);


system("PAUSE");
return 0;
}

void DisplayInfo(char Qname[], QueueType *Queue){

    if(EmptyQ((*Queue)))
        printf("%s Queue is Empty\n", Qname);
    else{
        printf("%s Queue\n", Qname);
        printf("Client         Start   End   Arrival    Stay\n");
        TraverseQ((*Queue));

    }
}

QueueType TimesInQueue(QueueType *Queue){
    QueueType ServedQ;
    CreateQ(&ServedQ);
    QueueElementType PreviousCustomer, CurrentCustomer;



    while(!EmptyQ((*Queue))){

        RemoveQ(&(*Queue), &CurrentCustomer);
        if(EmptyQ(ServedQ)){
            CurrentCustomer.StartTime = CurrentCustomer.ArrivalTime;
            CurrentCustomer.EndTime = CurrentCustomer.ArrivalTime + CurrentCustomer.StayTime;
            AddQ(&ServedQ, CurrentCustomer);
            PreviousCustomer = CurrentCustomer;

        }
        else{

            CurrentCustomer.StartTime = PreviousCustomer.EndTime;
            CurrentCustomer.EndTime = CurrentCustomer.StartTime + CurrentCustomer.StayTime;
            AddQ(&ServedQ, CurrentCustomer);
            PreviousCustomer = CurrentCustomer;
        }
    }


return ServedQ;
}

void ReadTime(QueueType *Queue){
    QueueElementType Customer;
    int i = 1;

    while(!FullQ((*Queue))){
        printf("Give: arrival time,stay time for client %d:", i);
        scanf("%d, %d", &Customer.ArrivalTime, &Customer.StayTime);
        Customer.StartTime = -1;
        Customer.EndTime = -1;
        AddQ(&(*Queue), Customer);
        i++;
    }
}

void TraverseQ(QueueType Queue) {
	int current, i = 1;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("Client %-2d      %-2d      %-2d    %-2d         %-2d\n", i, Queue.Element[current].StartTime, Queue.Element[current].EndTime, Queue.Element[current].ArrivalTime, Queue.Element[current].StayTime);
		current = (current + 1) % QueueLimit;
		i++;
	}
	printf("\n");
}

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit; ;
	}
	else
		printf("Full Queue");
}
