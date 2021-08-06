#include <stdio.h>

#define StackLimit 15

typedef int StackElementType;   // � ����� ��� ���������  ��� �������
                                //���������� ����� int
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
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ����.
   ����������: True �� � Stack ����� ����, False �����������
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* �������: ��� ������ Stack ��� ��� �������� Item.
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������.
   ����������: ��� ������������� Stack.
   ������: ������ ������� �������, �� � ������ Stack ����� ������
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* �������: ��� ������ Stack.
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� Stack.
   ������:  ������ ����� ������� �� � Stack ����� ����
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}


