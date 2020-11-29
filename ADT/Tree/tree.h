/*ADT JAM*/

 #ifndef __TREE_H__
 #define __TREE_H__
 
 #include <stdlib.h>
 
 #define NilTree NULL
 #define Info(T) (T)->info
 #define Left(T) (T)->left
 #define Right(T) (T)->right
 
 typedef char infotypeTree;
 typedef struct TNode *addressTree;
 typedef struct TNode
 { 
 	infotypeTree info;
 	addressTree left;
 	addressTree right;
 } Node;
 
 typedef addressTree Tree;
 
 void AlokasiTree(addressTree *P, infotypeTree X);
 void BuildTree(Tree *T);
void BuildTreeFromString(Tree *T, char *st, int *idx);
 void PrintTree(Tree T);
 Tree SearchTreeNode(Tree P, infotypeTree X);
 
 #endif
