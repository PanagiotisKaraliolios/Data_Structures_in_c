#include <stdio.h>

#define StackLimit 41  // �� ���� �������� ��� �������, ���������� ��� �� 80
#define QueueLimit 41  //�� ���� �������� ��� �����
#define len 40

typedef char StackElementType;  // � ����� ��� ���������  ��� �������
                                //���������� ����� char

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


typedef char QueueElementType;


typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

main(){

    char str[len];
    for(int i=0; i<len; i++){
        str[i] = 0;
    }
    printf("Enter a string:");
    fgets (str, len, stdin);


    //printf("%s", str);

    StackType stack;
    CreateStack(&stack);
    StackElementType Selement;

    QueueType queue;
    CreateQ(&queue);
    QueueElementType Qelement;

    for(int i=0; i<len; i++){

        if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122)){
            Selement = str[i];
            Qelement = str[i];

            Push(&stack, Selement);
            AddQ(&queue, Qelement);
        }
    }

    printf("-------Stack of characters-------\n ");
    TraverseStack(stack);

    printf("-------Queue of characters-------\n");
    TraverseQ(queue);
    printf("\n");

    boolean flag = TRUE;
    QueueType queue2;
    CreateQ(&queue2);

    while(!EmptyQ(queue) || !EmptyStack(stack)){
        Pop(&stack, &Selement);
        RemoveQ(&queue, &Qelement);
        AddQ(&queue2, Qelement);
        if(Selement != Qelement){
            flag = FALSE;
        }
    }

    if(flag){
        TraverseQ(queue2);
        printf(" ACCEPTED\n");
    }
    else{
        TraverseQ(queue2);
        printf(" REJECTED\n");
    }



system("PAUSE");
return 0;
}

void CreateStack(StackType *Stack)
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* �������:    ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ����.
   ����������: True �� � Stack ����� ����, False �����������
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* �������:    ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* �������:    ��� ������ Stack ��� ��� �������� Item.
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������.
   ����������: ��� ������������� Stack.
   ������:     ������ ������� �������, �� � ������ Stack ����� ������
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* �������:    ��� ������ Stack.
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� Stack.
   ������:     ������ ����� ������� �� � Stack ����� ����
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void TraverseStack(StackType Stack)
{
    int i;
    for (i=Stack.Top;i>=0;i--) {
        printf("%c ",Stack.Element[i]);
    }
    printf("\n");
}

void CreateQ(QueueType *Queue)
/*  ����������:  ���������� ��� ���� ����.
    ����������:  ���� ����
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ����.
   ����������: True �� � ���� ����� ����, False �����������
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ������.
   ����������: True �� � ���� ����� ������, False �����������
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
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
	}
	else
		printf("Empty Queue");
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
	}
	else
		printf("Full Queue");
}

void TraverseQ(QueueType Queue) {
	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf(" %c", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	//printf("\n");
}
