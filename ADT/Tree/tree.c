/* file : tree.c */

#include <stdio.h>
#include "tree.h"
#include "..\mesinkata\mesinkar.h"

void AlokasiTree(addressTree *P, infotypeTree X)
{ 
	*P=(addressTree) malloc(sizeof(Node));
 	if (*P != NilTree) 
	{
		Info(*P)=X;
		Left(*P)=NilTree;
		Right(*P)=NilTree;
	}
}
void BuildTree(Tree *T)
 /* dipakai jika input dari pita karakter */
{ 
	ADV();
 	if (CC==')')
 	{
		(*T)=NilTree;
	}else
 	{ 
		AlokasiTree(T,CC);
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
		(*T)=NilTree;
	}else
 	{	 
	 	AlokasiTree(T, st[*idx]);
		(*idx)++; /* advance */
	 	BuildTreeFromString(&Left(*T),st,idx);
	 	BuildTreeFromString(&Right(*T),st,idx);
	}
 	(*idx)++; /* advance */
}
void PrintTree(Tree T)
{ 
	if (T==NilTree)
	{
		 printf("()");
	}else
	{ 	printf("(%c",Info(T));
		PrintTree(Left(T));
		PrintTree(Right(T));
		printf(")");
	}
}

Tree SearchTreeNode(Tree P, infotypeTree X)
/* Mengirimkan node dari P yang berNilTreeai X */
{
   if (P == NilTree)
   {
      	return NilTree;
   }
   else if (Info(P) == X)
   {
    	return P;
   }
   else {
		if (SearchTreeNode(Left(P), X) != NilTree)
		{
			return (SearchTreeNode(Left(P), X));
		}
		else if (SearchTreeNode(Right(P), X) != NilTree)
		{
			return (SearchTreeNode(Right(P), X));
		}
		else
		{
			return NilTree;
		}
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
