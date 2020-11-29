/* file : tree.c */

#include <stdio.h>
#include "boolean.h"
#include "tree.h"
#include "..\mesinkata\mesinkar.h"

boolean IsTreeEmpty(Tree T)
{
	return T == NilTree;
}



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


Tree BuildBalanceTree(int n, int *in)
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca */
{
	if (n == 0)
	{
		return NilTree;
	}
	else
	{
		addressTree P;  
		AlokasiTree(&P, *in);
		(*in)++;

		if (P != NilTree)
		{
			int nl = n / 2;
			int nr = n - nl - 1;
			Tree L = BuildBalanceTree(nl, in);
			Tree R = BuildBalanceTree(nr, in);

			Left(P) = L;
			Right(P) = R;
		}
		

		return P;
	}
}


void BuildTreeFromString(Tree *T, char *st, int *idx)
 /* input dari string st */
{ 	
	(*idx)++; /* advance */
	printf("Test1\n");
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
	printf("Tree\n");
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




void PrintTreeLevel(Tree P, int h, int level)
{
	if (!IsTreeEmpty(P))
	{
		printf("%d\n", Info(P));

		if (!IsTreeEmpty(Left(P)))
		{
			for(int i = 0; i < h *level; i++)
				printf(" ");

			PrintTreeLevel(Left(P), h, level+1);
		}

		if (!IsTreeEmpty(Right(P)))
		{
			for(int i = 0; i < h *level; i++)
				printf(" ");
				
			PrintTreeLevel(Right(P), h, level+1);
		}
	}
}


void PrintTreeIndent(Tree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
{
	PrintTreeLevel(P, h, 1);
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
