
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

} BinTreeElementType;                   /*� ����� ��� ��������� ��� ��� �����
                                        ����� struct */
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
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item.
   ����������:  ������� �� �������� Item ��� ���.
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���
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
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE
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
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���
                ��� ��� ������ ��� ������ �����.
   ����������: � Found ���� ���� TRUE, � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue ��� � Parent ������� ���� ������
                ����� ��� ������, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE.
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
/* �������:  ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
  ����������: ��������� �� ���� ���� ����� ��� ��� ��� �� �������� ��� ����
                KeyValue ��� ����� ������ ��� �������� ��������� ��� ���,
                �� ��� ����, ��� ��������� ��� �� ���.
  ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���.
*/
{

   BinTreePointer
   R,
   n,                   //������� ���� ����� ��� �������� ��� ���� KeyValue *)
   Parent,              // ������� ��� n � ��� nNext
   nNext,               // ����������������� �������� ��� n
   SubTree;             // ������� ���� ��������� ��� n
   boolean Found;       // TRUE AN TO �������� KeyValue EINAI ������� ��� ��� *)

     R=*Root;
     BSTSearch2(R, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %d DEN EINAI STO DDA\n", KeyValue.AM);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // ������ ���� �������� �� ��� ������
                 //���� ��� ���������������� ������� ��� ��� ������ ���
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* ��������� ��� ������������ ��� nNext ���� n ���
                ������ ��� n ���� �� ������� ���� ������� */
                n->Data = nNext->Data;
                n = nNext;
          } //����������� �� ��� ��������� ��� � ������ ���� �� ���� 1 �����
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
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("(%d, %d),",Root->Data.AM,Root->Data.Num);
        InorderTraversal(Root->RChild);
    }
}
