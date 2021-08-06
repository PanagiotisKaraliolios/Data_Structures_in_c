#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define HMax 9              /*     �� ������� ��� ������ HashTable
                                ���������� ��� �� 5 */
#define VMax 30             /*�� ������� ��� ������,
                                ���������� ��� �� 30 */
#define EndOfList -1        /* ������ ��� ����������� �� ����� ��� ������
                                ��� ��� ���� ��������� ��������� */

//typedef int ListElementType;  /*����� ��������� ��� �� �������� ��� ������ ���������� ����� int */

typedef char KeyType[30];

typedef struct {
	KeyType RecKey;
	char Name[10];
	char SurName[20];
	char PhoneNumber[10];
	int SpecialtyCode;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // ������� ������� ���� ��� ��������� ���������
    int Size;                // ������ �������� ��� ������ List
	int SubListPtr;          // D������� �� ��� �������� ���������
    int StackPtr;           // ������� ���� ��� ����� �������� ���� ��� ������ List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
int HashKey(KeyType Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,KeyType DelKey);
void Print_HashList(HashListType HList);
void PrintPinakes(HashListType HList);
void PrintListOfSynonyms(HashListType HList, KeyType key);
void BuildHashList(HashListType *HList);
int findAverage(KeyType Key);
void Search_HashList_By_Subject(HashListType HList, int code);



int main(){

    HashListType HList;
    ListElm AnItem;
    KeyType AKey;
    int Loc, Pred;
    char ch;

    printf("\n1. Create HashList\n");
    CreateHashList(&HList);
    BuildHashList(&HList);
    PrintPinakes(HList);


    printf("\n2. Insert new teacher\n");
    do{

        printf("Enter teacher's name: ");
        scanf("%s", &AnItem.Name);
        printf("Enter teacher's surname: ");
        scanf("%s", &AnItem.SurName);
        printf("Enter teacher's phone: ");
        scanf("%s", &AnItem.PhoneNumber);
        printf("Enter teacher's code: ");
        scanf("%d", &AnItem.SpecialtyCode);
        AnItem.Link=EndOfList;
        strcpy(AnItem.RecKey, "");
        strcat(AnItem.RecKey, AnItem.Name);
        strcat(AnItem.RecKey, " ");
        strcat(AnItem.RecKey, AnItem.SurName);
        AddRec(&HList, AnItem);
        printf("\nContinue Y/N: ");
        do{
            scanf("%c", &ch);
        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
    } while (toupper(ch)!='N');


    PrintPinakes(HList);


    printf("\n3. Delete a teacher\n");

    char name[10];
    char surname[20];


    printf("Enter teacher's name: ");
    scanf("%s", &name);
    printf("Enter teacher's surname: ");
    scanf("%s", &surname);
    strcpy(AKey, "");
    strcat(AKey, name);
    strcat(AKey, " ");
    strcat(AKey, surname);

    DeleteRec(&HList, AKey);

    PrintPinakes(HList);


    printf("\n4. Search for a teacher\n");

    printf("Enter teacher's name: ");
    scanf("%s", &name);
    printf("Enter teacher's surname: ");
    scanf("%s", &surname);
    strcpy(AKey, "");
    strcat(AKey, name);
    strcat(AKey, " ");
    strcat(AKey, surname);
    SearchHashList(HList, AKey, &Loc, &Pred);
    if(Loc!=-1)
        printf("[%s,%s,%d]\n", HList.List[Loc].RecKey, HList.List[Loc].PhoneNumber, HList.List[Loc].SpecialtyCode);
    else
        printf("DEN YPARXEI EGGRAFH ME KLEIDI %s\n", AKey);



    printf("\n5. Search by subject\n");
    int code;
    printf("Enter code: ");
    scanf("%d", &code);
    printf("List of teachers with subject code %d:\n", code);

    Search_HashList_By_Subject(HList, code);


system("PAUSE");
return 0;
}

void Search_HashList_By_Subject(HashListType HList, int code){

    for(int i=0; i<= HList.Size; i++){
        if (HList.List[i].SpecialtyCode == code){
            printf("%d:[%s,%s,%d]\n", i, HList.List[i].RecKey, HList.List[i].PhoneNumber, HList.List[i].SpecialtyCode);
        }
    }

}

void BuildHashList(HashListType *HList){

    ListElm AnItem;
    char termch;
    int nscan;

    FILE *f1;
    f1 = fopen("i4f6.txt", "r");
    if(f1==NULL)
        printf("Can't open file\n");
    else{

        while(TRUE){


            nscan = fscanf(f1, "%[^,],%[^,],%[^,],%d%c", AnItem.Name, AnItem.SurName, &AnItem.PhoneNumber, &AnItem.SpecialtyCode, &termch);
            AnItem.Link=EndOfList;
            strcpy(AnItem.RecKey, "");
            if(nscan == EOF) break;
            strcat(AnItem.RecKey, AnItem.Name);
            strcat(AnItem.RecKey, " ");
            strcat(AnItem.RecKey, AnItem.SurName);
            AddRec(&(*HList), AnItem);
        }
    }
    fclose(f1);
    }

void PrintListOfSynonyms(HashListType HList, KeyType key){
    int Loc, Pred;

    while(Pred!=-1){
        SearchHashList(HList,key,&Loc,&Pred);
        key = HList.List[Pred].RecKey;
    }

    do{
        printf("%d:[%s,%s]\n", Loc, HList.List[Loc].RecKey, HList.List[Loc].Name);
        Loc = HList.List[Loc].Link;
    }while(Loc!=-1);
}

void Print_HashList(HashListType HList)
{
    int i, SubIndex;

    printf("HASHLIST STRUCTURE with SYNONYM CHAINING\n");
    printf("========================================\n");

        printf("PINAKAS DEIKTWN STIS YPO-LISTES SYNWNYMWN EGGRAFWN:\n");
        for (i=0; i<HMax;i++)
            printf("%d| %d\n",i,HList.HashTable[i]);

        printf("OI YPO-LISTES TWN SYNWNYMWN EGGRAFWN:\n");
        for (i=0; i<HMax;i++)
        {
            SubIndex = HList.HashTable[i];
            while ( SubIndex != EndOfList )
            {
                printf("[%s, %s, %d]", HList.List[SubIndex].RecKey, HList.List[SubIndex].Name, HList.List[SubIndex].Link);
                printf(" -> ");
                SubIndex = HList.List[SubIndex].Link;
            } //* while *)
            printf("TELOS % dHS YPO-LISTAS\n", i);
        }

        printf("MEGE8OS THS LISTAS = %d\n", HList.Size);
        printf("========================================\n");
}

void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
    for (i=0; i<HMax;i++)
        printf("%d,",HList.HashTable[i]);

	printf("\nHash List\n");
    for (i=0;i<HList.Size;i++)
        printf("%d) %s, %d\n", i, HList.List[i].RecKey, HList.List[i].Link);
	printf("\n");
}

int HashKey(KeyType Key)
/* �������:    ��� ���� Key ���� ��������.
   ����������: ������� ��� ���� ��������������� HValue ��� �� ������ Key.
   ����������: ��� ���� ��������������� HValue
*/
{
	/*�� ��������� ��� �� KeyType ��� ����� ��������
	�� ������ �� ������������ ��������� �� ������ �� ������*/
	int average;
	average = findAverage(Key);
	return average%HMax;
}

int findAverage(KeyType Key){
    int average;
    char firstLetter;
    char lastLetter;
    firstLetter =toupper(Key[0]);
    lastLetter = toupper(Key[strlen(Key)-1]);
    average = (((int)firstLetter-64) + ((int)lastLetter-64))/2;

return average;
}

void CreateHashList(HashListType *HList)
/* ����������: ���������� ��� ���� HList.
   ����������: ��� ���� HList
*/
{
	int index;

	HList->Size=0;           //���������� ��� ���� �����
	HList->StackPtr=0;       //������� ��� ������ ��� ������� ��� ��������� ������

    /*����������� ��� ������ HashTable ��� ����� HList ���� ���� ��������� ���
        �� ���� �� ���� EndOfList (-1)*/
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

     //���������� ��� ������� ��� ��������� ������ ��� ����� HList
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}

boolean FullHashList(HashListType HList)
/* �������:    ��� ���� HList.
   ����������: ������� �� � ����� List ��� ����� HList ����� ������.
   ����������: TRUE �� � ����� List ����� ������, FALSE �����������.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ���� �������� ���������.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ��� ������������
                �������� ���� ��������
*/
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (strcmp(HList.List[Next].RecKey,KeyArg)==0)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,KeyType KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ��� ���� HList.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ���
                ������������ �������� ��� ��������� ���� ����� ������.
                �� ��� ������� ������� �� ������ KeyArg ���� Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* �������:    ��� ���� HList ��� ��� ������� InRec.
   ����������: ������� ��� ������� InRec ��� ����� List, �� ��� ����� ������,
                ��� ���������� �� ���� HList.
   ����������: ��� ������������� ���� HList.
   ������:     ������ ������� ������, �� � List ����� ������, �����������,
                �� ������� ��� ������� �� �� ���� ������,
                �������� ����������� ���������
*/
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{

			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,KeyType DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %s \n",DelKey);
	}
}

