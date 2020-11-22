/* file : tree.c */

#include "tree.h"
#include "mesinkar.h"

void Alokasi(address *P, infotype)
{ 
	*P=(address) malloc(sizeof(Node));
 	if (*P != Nil) 
	{
		Info(*P)=X;
		Left(*P)=Nil;
		Right(*P)=Nil;
	}
}
void BuildTree(Tree *T)
 /* dipakai jika input dari pita karakter */
{ 
	ADV();
 	if (CC==')')
 	{
		(*T)=Nil;
	}else
 	{ 
		Alokasi(T,CC);
		ADV();
		BuildTree(&Left(*T));
	 	BuildTree(&Right(*T));
	}
 	ADV();
}
void BuildTreeFromString(Tree *T, char *st, int *idx)
 /* input dari string st */
{ 	
	(*idx)++; /* advance */
	if (st[*idx]==')')
	{
		(*T)=Nil;
	}else
 	{	 
	 	Alokasi(T, st[*idx]);
		(*idx)++; /* advance */
	 	BuildTreeFromString(&Left(*T),st,idx);
	 	BuildTreeFromString(&Right(*T),st,idx);
	}
 	(*idx)++; /* advance */
}
void PrintTree(Tree T)
{ 
	if (T==Nil)
	{
		 printf("()");
	}else
	{ 	printf("(%c",Info(T));
		PrintTree(Left(T));
		PrintTree(Right(T));
		printf(")");
	}
}
 
 /*int main()
 { Tree T;
 int idx=0;*/
 
 /* test dari Pita */
 
 /*START();
 PrintTree(T);*/
 
 /* Test dari string yang diberikan sebagai ekspresi */
 
/* BuildTreeFromString(&T,"(A(B()())(C()()))",&idx);
 PrintTree(T);
 return 0;
 }*/
