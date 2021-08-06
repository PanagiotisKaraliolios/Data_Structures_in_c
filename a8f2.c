#include <stdio.h>

#define StackLimit 15

typedef char StackElementType;   // � ����� ��� ���������  ��� �������
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

    StackElementType letter, letter2;
    StackType stack;
    CreateStack(&stack);
    boolean flag = TRUE, isPalindrome = FALSE;

    printf("Enter string:\n");
    while(flag){
        fflush(stdin);
        scanf("%c", &letter);
        if(letter != '#'){
            if(letter != 'C'){
                Push(&stack, letter);
            }
            else
                break;
        }
        else{
            flag = FALSE;
            break;
        }
    }

    while(flag){
        fflush(stdin);
        scanf("%c", &letter2);
        if(letter2 == '#' && !EmptyStack(stack)){
            isPalindrome = FALSE;
            break;
        }
        else if(letter2 == '#'){
            break;
        }
        if(!EmptyStack(stack)){
            Pop(&stack, &letter);
            if(!(letter2 == letter)){
                flag = FALSE;
                isPalindrome = FALSE;
            }
            else
                isPalindrome = TRUE;
        }
        else{
            isPalindrome = FALSE;
            flag = FALSE;
        }
    }

    if(isPalindrome)
        printf("TRUE\n");
    else
        printf("FALSE\n");


system("PAUSE");
return 0;

}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%c ",Stack.Element[i]);
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

