#include <stdio.h>

#define QueueLimit 10  //�� ���� �������� ��� �����

typedef int QueueElementType;

typedef struct {
	int Front, Rear, Count;
	QueueElementType Element[QueueLimit];;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

main(){

    QueueType MyQ;
    CreateQ(&MyQ);


    for(int i = 0; i < QueueLimit; i++){
        AddQ(&MyQ, i);
    }

    printf("---a---\n");
    TraverseQ(MyQ);
    printf("Front=%d Rear=%d Count=%d \n", MyQ.Front, MyQ.Rear, MyQ.Count);

    printf("---b---\n");
    QueueElementType x = 12;
    AddQ(&MyQ, x);
    TraverseQ(MyQ);
    printf("Front=%d Rear=%d Count=%d \n", MyQ.Front, MyQ.Rear, MyQ.Count);

    printf("---c---\n");
    RemoveQ(&MyQ, &x);
    TraverseQ(MyQ);
    printf("Removed Item=%d Front=%d Rear=%d Count=%d \n", x, MyQ.Front, MyQ.Rear, MyQ.Count);

    printf("---d---\n");
    x = 25;
    AddQ(&MyQ, x);
    TraverseQ(MyQ);
    printf("Front=%d Rear=%d Count=%d \n", MyQ.Front, MyQ.Rear, MyQ.Count);

    printf("---e---\n");
    x = 32;
    AddQ(&MyQ, x);
    TraverseQ(MyQ);
    printf("Front=%d Rear=%d Count=%d \n", MyQ.Front, MyQ.Rear, MyQ.Count);

    printf("---f---\n");
    while(!EmptyQ(MyQ)){
        RemoveQ(&MyQ, &x);
        TraverseQ(MyQ);
        printf("Removed Item=%d Front=%d Rear=%d Count=%d \n", x, MyQ.Front, MyQ.Rear, MyQ.Count);
    }

system("PAUSE");
return 0;
}

void TraverseQ(QueueType Queue) {

    int current = Queue.Front, itemsShown=0;
    printf("Queue:");
    if(EmptyQ(Queue))
        printf("Empty Queue");

    while(itemsShown < Queue.Count){
        if(current < QueueLimit){
            printf(" %d", Queue.Element[current]);
            itemsShown += 1;
            current += 1;
        }
        else{
            current = 0;
            while(itemsShown < Queue.Count){
                printf(" %d", Queue.Element[current]);
                itemsShown += 1;
                current += 1;
            }
        }
    }

	printf("\n");

}

void CreateQ(QueueType *Queue)
/*  ����������:  ���������� ��� ���� ����.
    ����������:  ���� ����
*/
{
    Queue->Count = 0;
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ����.
   ����������: True �� � ���� ����� ����, False �����������
*/
{
	return (Queue.Count == 0);
}

boolean FullQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ������.
   ����������: True �� � ���� ����� ������, False �����������
*/
{
	return (Queue.Count == QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����.
   ����������: ������� �� �������� Item ��� ��� ������ ���� ��� �����
                �� � ���� ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� ����.
   ������:     ������ ����� ���� �� � ���� ����� ����
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		Queue ->Count -= 1;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* �������:    ��� ���� Queue ��� ��� �������� Item.
   ����������: ��������� �� �������� Item ���� ���� Queue
                �� � ���� ��� ����� ������.
   ����������: ��� ������������� ����.
   ������:     ������ ������� ����� �� � ���� ����� ������
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
		Queue ->Count += 1;
	}
	else
		printf("Full Queue\n");
}
