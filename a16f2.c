#include <stdio.h>

#define StackLimit 80  // �� ���� �������� ��� �������, ���������� ��� �� 80

typedef struct{
    int price;
    char size;
} FanelakiType;

typedef FanelakiType StackElementType;  // � ����� ��� ���������  ��� �������
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


int main(){

    StackType stack;
    CreateStack(&stack);
    FanelakiType fanelaki;
    int numOfItems;
    char desiredSize;


    printf("Give number of items ");
    scanf("%d", &numOfItems);

    printf("Give the items to store\n");
    for(int i = 0; i < numOfItems; i++){
        printf("Give price ");
        scanf("%d", &fanelaki.price);
        printf("Give size ");
        fflush(stdin);
        scanf("%c", &fanelaki.size);
        Push(&stack, fanelaki);
    }
    printf("Items in the box");
    TraverseStack(stack);

    printf("What size do you want? ");
    fflush(stdin);
    scanf("%c", &desiredSize);

    boolean found = FALSE;
    StackType tempStack;
    CreateStack(&tempStack);
    FanelakiType tempFanelaki, desiredFanelaki;

    int j = stack.Top;
    for(int i=0;i<=j;i++){
        Pop(&stack, &tempFanelaki);
        Push(&tempStack, tempFanelaki);

        if(tempStack.Element[tempStack.Top].size == desiredSize){
            found = TRUE;
            Pop(&tempStack, &desiredFanelaki);
            break;
        }
    }

    if(found)
        printf("Found the size %c\n", desiredSize);
    else
        printf("Not Found the size %c\n", desiredSize);

    printf("Items in the box");
    TraverseStack(stack);

    printf("Items out of the box");
    TraverseStack(tempStack);

    j = tempStack.Top;
    for(int i = 0; i <= j; i++){
        Pop(&tempStack, &tempFanelaki);
        Push(&stack, tempFanelaki);
    }

    printf("Items in the box");
    TraverseStack(stack);

    printf("Items out of the box");
    TraverseStack(tempStack);

    system("PAUSE");
    return 0;
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%c, %d\n",Stack.Element[i].size, Stack.Element[i].price);

    }
    printf("\n");
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
