/*ADT JAM*/

 #ifndef __TREE_H__
 #define __TREE_H__
 
 #include <stdlib.h>
 
 #define Nil NULL
 #define Info(T) (T)->info
 #define Left(T) (T)->left
 #define Right(T) (T)->right
 
 typedef char infotype;
 typedef struct TNode *address;
 typedef struct TNode
 { 
 	infotype info;
 	address left;
 	address right;
 } Node;
 
 typedef address Tree;
 
 void Alokasi(address *P, infotype X);
 void BuildTree(Tree *T);
 void BuildTreeFromString(Tree *T, char *st, int *idx);
 void PrintTree(Tree T);
 Tree SearchTreeNode(Tree P, infotype X);
 
 #endif
