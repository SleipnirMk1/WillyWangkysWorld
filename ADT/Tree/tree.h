/*ADT JAM*/

 #ifndef __TREE_H__
 #define __TREE_H__
 
 #include <stdlib.h>
 #include "..\custom_adt\arraywahana.h"
 
 #define NilTree NULL
 #define Info(T) (T)->info
 #define Left(T) (T)->left
 #define Right(T) (T)->right
 
 typedef int infotypeTree;
 typedef struct TNode *addressTree;
 typedef struct TNode
 { 
 	infotypeTree info;
 	addressTree left;
 	addressTree right;
 } Node;
 
 typedef addressTree Tree;
 boolean IsTreeEmpty(Tree T);
 void AlokasiTree(addressTree *P, infotypeTree X);
 void BuildTree(Tree *T);
void BuildTreeFromString(Tree *T, char *st, int *idx);
 void PrintTree(Tree T);
 Tree SearchTreeNode(Tree P, infotypeTree X);


void PrintTreeLevel(Tree P, int h, int level);

void PrintTreeIndent(Tree P, int h);

Tree BuildBalanceTree(int n, int *in);

void PrintTreeUpgradeWahana(Tree T, ArrayWahana W, int type);


 
 #endif
