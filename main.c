#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "ADT\mesinkata\mesinkata.h"
#include "ADT\mesinkata\mesinkar.h"
#include "ADT\graph\graph.h"
#include "ADT\custom_adt\player.h"
#include "ADT\point\point.h"

// #define MAXSTACKACTION 100

// typedef struct
// {
// 	int Wood;
// 	int Stone;
// 	int Ruby;
// } Material;

// typedef struct
// {
// 	Kalimat Name;
// 	int Money;
// 	Material Mat;
// 	Point Pos;
// } Player;

// typedef struct
// {
// 	Kalimat Name;
// 	int Cost;
// 	Material Mat;
// 	Point Pos;
// 	boolean BrokenStatus;
// } Wahana;


// typedef struct 
// {
// 	Kalimat Name;
// 	Kata Type;
// 	int Time;
// 	int Amount;
// 	Point Pos;
// } Action;

// typedef struct
// {
// 	Action A[MAXSTACKACTION];
// 	int TOP;
// } StackAction;


Player P;
Graph G;



boolean MAINPHASE = false;
boolean RUN_NEWGAME = true;
boolean RUN = true;
boolean OFFICE_MODE = false;

Kata NEW, LOAD, EXIT;
Kata BUILD, UPGRADE, BUY, UNDO, EXECUTE, MAIN;
Kata SERVE, REPAIR, DETAIL, OFFICE, PREPARE;
Kata SAVE, CONTINUE;
Kata W, A, S, D;
Kata DETAILS;

Kata ACTION_BUILD, ACTION_UPGRADE, ACTION_BUY;

// Graph G;
// Wahana W;
// Player P;

// Point officePoint;

// StackAction A;


// Defenition
// ============================================
void generateAllConstant();
void generatePlayer();
void EXITGAME(int x);
void generateLoadGame();
void generateNewGame();
void saveGame();
void conti();

void buy();
void undo();
void build();
void execute();
void upgrade();
void prepareToMain();

void serve();
void repair();
void detail();
void office();
void mainToPrepare();

boolean IsWall(float X, float Y, int A);
boolean IsGerbang(float X, float Y, int A);
void move(int dir);

// ==============================================

int main()
{
	generateAllConstant();

	generatePlayer();

	// generatePosFromFile();
	// generateMatFromFile();
	// generateWahFromFile();
	// generateStaFromFile();

	RUN = true;
	RUN_NEWGAME = true;

	printf("NEW // LOAD // EXIT\n");
	boolean runned = false;
	while(RUN_NEWGAME)
	{
		Kalimat input = GetKalimat();
		Kata K;
		DequeueKalimat(&input, &K);
		
		if (KataSama(K, EXIT))
		{
			EXITGAME(1);
		}
		else if (KataSama(K, NEW))
		{
			//generateNewGame();
			RUN_NEWGAME = false;
			runned = true;
		}
		else if (KataSama(K, LOAD))
		{
			//generateLoadGame();
			RUN_NEWGAME = false;
			runned = true;
		}
		else
		{
			printf("Perintah yang anda masukkan tidak tersedia!!!\n");
		}
	}

	while(RUN)
	{
		PrintVertex(P.Position);
		printf("\n");
		printf("Masukkan Perintah : ");

	
		Kalimat input = GetKalimat();
		Kata K;
		DequeueKalimat(&input, &K);

		if (KataSama(K, EXIT))
		{
			RUN = false;
		}
		else if (KataSama(K, W))
		{
			move(0);
		}
		else if (KataSama(K, A))
		{
			move(1);
		}
		else if (KataSama(K, S))
		{
			move(2);
		}
		else if (KataSama(K, D))
		{
			move(3);
		}
		else if (KataSama(K, SAVE))
		{
			//saveGame();
		}
		else if (KataSama(K, CONTINUE))
		{
			//conti();
		}
		else
		{
			// PREPARATION PHASE
			if (!MAINPHASE)
			{
				if (KataSama(K, BUILD))
				{
					//build();
				}
				else if (KataSama(K, UPGRADE))
				{
					//upgrade();
				}
				else if (KataSama(K, BUY))
				{
					//buy();
				}
				else if (KataSama(K, UNDO))
				{
					//undo();
				}
				else if (KataSama(K, EXECUTE))
				{
					//execute();
				}
				else if (KataSama(K, MAIN))
				{
					//prepareToMain();
				}
				else
				{
					printf("Maaf, Perintah yang dimasukkan tidak tersedia pada Phase ini!!\n");
				}
			}
			// MAIN PHASE
			else
			{
				if (KataSama(K, SERVE))
				{
					//serve();
				}
				else if (KataSama(K, REPAIR))
				{
					//repair();
				}
				else if (KataSama(K, DETAIL))
				{
					//detail();
				}
				else if (KataSama(K, OFFICE))
				{
					//office();
				}
				else if (KataSama(K, PREPARE))
				{
					//mainToPrepare();
				}
				else
				{
					printf("Maaf, Perintah yang dimasukkan tidak tersedia pada Phase ini!!\n");
				}

			}

		}

		
	}


	if (runned)
	{
		printf("Masukkan 'y' jika ingin melakukan SAVE GAME : ");
		char yy;
		scanf("%c", &yy);
		if (yy == 'y');
			//saveGame();
	}

	printf("Thanks for playing... :D");

	return 0;
}



boolean IsWall(float X, float Y, int A)
{
	return ((X == 0)|(X == 19)|(Y == 19)|(Y == 0))&&(!IsGerbang(X, Y, A));
}
boolean IsGerbang(float X, float Y, int A)
{
	if (A == 1)
		return ((X == 19) && (Y == 4))|((X == 9)&&(Y == 9));
	else if (A == 2)
		return ((X == 0) && (Y == 4))|((X == 9)&&(Y == 9));
	else if (A == 3)
		return ((X == 19) && (Y == 4))|((X == 9)&&(Y == 0));
	else if (A == 4)
		return ((X == 0) && (Y == 4))|((X == 9)&&(Y == 0));
}
void gerak(int X)
{
	if (X == 0)
	{
		if (!IsWall(Absis(P.Position),Ordinat(P.Position) + 1, Area(P.Position)))
		{
			Geser (&P.Position, 0, 1, 0);
			if(IsGerbang(Absis((P).Position),Ordinat((P).Position), Area((P).Position)))
			{
				POINT V;
				GetVEdge(G, P.Position, &V);

				(P).Position = V;
			}
		}
	}
	else if (X == 1)
	{
		if (!IsWall(Absis(P.Position)-1,Ordinat(P.Position), Area(P.Position)))
		{
			Geser (&P.Position, -1, 0, 0);
			if(IsGerbang(Absis(P.Position),Ordinat((P).Position), Area((P).Position)))
			{
				POINT V;
				GetVEdge(G, (P).Position, &V);

				(P).Position = V;
			}
		}
	}
	else if (X == 2)
	{
		if (!IsWall(Absis(P.Position),Ordinat(P.Position) - 1, Area(P.Position)))
		{
			Geser (&P.Position, 0, -1, 0);
			
			if(IsGerbang(Absis((P).Position),Ordinat((P).Position), Area((P).Position)))
			{
				POINT V;
				GetVEdge(G, (P).Position, &V);

				(P).Position = V;
			}
		}
	}
	else if (X == 3)
	{
		if (!IsWall(Absis(P.Position) + 1,Ordinat(P.Position), Area(P.Position)))
		{
			Geser (&P.Position, 1, 0, 0);
			if(IsGerbang(Absis((P).Position),Ordinat((P).Position), Area((P).Position)))
			{
				POINT V;
				GetVEdge(G, (P).Position, &V);

				(P).Position = V;
			}
		}
		
	}
}


void move(int dir)
{
	gerak(dir);
}

// ================================================================
void generatePlayer()
{
	Area(P.Position) = 1;
 	Absis(P.Position) = 1;
	Ordinat(P.Position) = 1;
}

void generateAllConstant()
{
	SetKata(&NEW, "new");
	SetKata(&LOAD, "load");
	SetKata(&EXIT, "exit");

	SetKata(&BUY, "buy");
	SetKata(&UNDO, "undo");
	SetKata(&MAIN, "main");
	SetKata(&BUILD, "build");
	SetKata(&UPGRADE, "upgrade");
	SetKata(&EXECUTE, "execute");

	SetKata(&SERVE, "serve");
	SetKata(&REPAIR, "repair");
	SetKata(&DETAIL, "detail");
	SetKata(&OFFICE, "office");
	SetKata(&PREPARE, "prepare");

	SetKata(&SAVE, "save");
	SetKata(&CONTINUE, "continue");
	SetKata(&DETAILS, "details");

	SetKata(&W, "w");
	SetKata(&A, "a");
	SetKata(&S, "s");
	SetKata(&D, "d");


	SetKata(&ACTION_BUILD, "build");
	SetKata(&ACTION_UPGRADE, "upgrade");
	SetKata(&ACTION_BUY, "buy");
}

void generateNewGame()
{
	printf("New GAME!!\n");
}

void generateLoadGame()
{
	printf("Load GAME!!\n");
}


// void conti()
// {
// 	printf("Continue\n");
// }

// // SAVE LOAD
// // ==================================================================
// void saveGame()
// {
// 	printf("Saving...\n");
// 	savePlayer("save/playerSave.txt"); 
// 	saveWahana("save/wahanaSave.txt");
// }

// void loadGame()
// {
// 	loadPlayer("save/playerSave.txt");
// 	loadWahana("save/wahanaSave.txt");
// }

// void savePlayer(char dir[])
// {
// 	FILE *f;
// 	f = fopen(dir, "w");

// 	char wr[300];
// 	int c = 0;
	
// 	QtoS(wr, P.Name, &c);
// 	ItoS(wr, P.Money, &c);
// 	ItoS(wr, P.Mat.Wood, &c);
// 	ItoS(wr, P.Mat.Stone, &c);
// 	ItoS(wr, P.Mat.Ruby, &c);
// 	ItoS(wr, P.Pos.Area, &c);
// 	ItoS(wr, P.Pos.x, &c);
// 	ItoS(wr, P.Pos.y, &c);

	
// 	printf("Saving Player Data...\n");
// 	if (c > 0 && f != NULL) 
// 	{ 
// 		fputs(wr, f);
// 		fputs("\n", f);
// 	}

// 	fclose(f);
// }

// void saveWahana(char dir[])
// {
// 	FILE *f;
// 	f = fopen(dir, "w");
// 	printf("Saving Wahana Data...\n");
// 	for(int i = 0; i < NbWahana; i++)
// 	{
// 		char wr[300];
// 		int c = 0;

// 		QtoS(wr, W[i].Name, &c);
// 		ItoS(wr, W[i].Type, &c);
// 		ItoS(wr, W[i].Level, &c);
// 		ItoS(wr, W[i].Cost, &c);
// 		ItoS(wr, W[i].Pos.Area, &c);
// 		ItoS(wr, W[i].Pos.x, &c);
// 		ItoS(wr, W[i].Pos.y, &c);

// 		wr[c++] = '\0';


// 		if (c > 0 && f != NULL) 
// 		{ 
// 			fputs(wr, f);
// 			fputs("\n", f);
// 		}
// 	}

// 	fclose(f);
// }

// void loadPlayer(char dir[])
// {
// 	FILE *f;
// 	f = fopen(dir, "r");

// 	if (f != NULL)
// 	{
// 		printf("Getting Player Data...\n");

// 		char wr[200];
// 		while( fgets ( wr, 200, f ) != NULL ) 
//         { 
// 			char content[20];
// 			int x = 0;
// 			int j = 0;
// 			for (int i = 0; i < NB(wr); i++)
// 			{
// 				if (wr[i] != ',')
// 				{
// 					content[j++] = wr[i];
// 				}
// 				else
// 				{
// 					content[j++] = '\0';
// 					if (x == 0)
// 					{
// 						P.Name = SetKalimat(content);
// 					}
// 					else if (x == 1)
// 					{
// 						int money;
// 						sscanf(content, "%d", &money);
// 						P.Money = money;
// 					}
// 					else if (x == 2)
// 					{
// 						int wood;
// 						sscanf(content, "%d", &wood);
// 						P.Mat.Wood = wood;
// 					}
// 					else if (x == 3)
// 					{
// 						int stone;
// 						sscanf(content, "%d", &stone);
// 						P.Mat.Stone = stone;
// 					}
// 					else if (x == 4)
// 					{
// 						int ruby;
// 						sscanf(content, "%d", &ruby);
// 						P.Mat.Ruby = ruby;
// 					}
// 					else if (x == 5)
// 					{
// 						int area;
// 						sscanf(content, "%d", &area);
// 						P.Pos.Area = area;
// 					}
// 					else if (x == 6)
// 					{
// 						int posx;
// 						sscanf(content, "%d", &posx);
// 						P.Pos.x = posx;
// 					}
// 					else if (x == 7)
// 					{
// 						int posy;
// 						sscanf(content, "%d", &posy);
// 						P.Pos.y = posy;
// 					}

// 					x++;
// 					j = 0;
// 				}
// 			}
			
// 		}

// 		fclose(f);
// 	}
// 	else
// 	{
// 		printf("File Not Found\n");
// 	}

// 	fclose(f);
// }

// void loadWahana(char dir[])
// {
// 	FILE *f;
// 	f = fopen(dir, "r");

// 	if (f != NULL)
// 	{
// 		printf("Getting Wahana Data...\n");

// 		char wr[200];
// 		int cnt = 0;
// 		int banyakwahana = 0;
// 		while( fgets ( wr, 200, f ) != NULL ) 
//         { 
// 			char content[20];
// 			int x = 0;
// 			int j = 0;
// 			for (int i = 0; i < NB(wr); i++)
// 			{
// 				if (wr[i] != ',')
// 				{
// 					content[j++] = wr[i];
// 				}
// 				else
// 				{
// 					content[j++] = '\0';
// 					if (x == 0)
// 					{
// 						W[cnt].Name = SetKalimat(content);
// 					}
// 					else if (x == 1)
// 					{
// 						int type;
// 						sscanf(content, "%d", &type);
// 						W[cnt].Type = type;
// 					}
// 					else if (x == 2)
// 					{
// 						int level;
// 						sscanf(content, "%d", &level);
// 						W[cnt].Level = level;
// 					}
// 					else if (x == 3)
// 					{
// 						int cost;
// 						sscanf(content, "%d", &cost);
// 						W[cnt].Cost = cost;
// 					}
// 					else if (x == 4)
// 					{
// 						int area;
// 						sscanf(content, "%d", &area);
// 						W[cnt].Pos.Area = area;
// 					}
// 					else if (x == 5)
// 					{
// 						int posx;
// 						sscanf(content, "%d", &posx);
// 						W[cnt].Pos.x = posx;
// 					}
// 					else if (x == 6)
// 					{
// 						int posy;
// 						sscanf(content, "%d", &posy);
// 						W[cnt].Pos.y = posy;
// 					}

// 					x++;
// 					j = 0;
// 				}
// 			}

// 			cnt++;
// 		}

// 		NbWahana = cnt;
// 	}
// 	else
// 	{
// 		printf("File Not Found\n");
// 	}

// 	fclose(f);
// }

// void ItoS(char *S, int X, int *c)
// {
// 	Kata K;
// 	char tmp[20]; 
//     sprintf(tmp, "%d", X);
// 	SetKata(&K, tmp);

// 	for (int i = 0; i < K.Length; i++)
// 		S[(*c)++] = K.TabKata[i];
	
// 	S[(*c)++] = ',';
// }

// void QtoS(char *S, Kalimat Q, int *c)
// {
// 	while(!IsEmptyKalimat(Q))
// 	{
// 		Kata K;
// 		DequeueKalimat(&Q, &K);
// 		for (int i = 0; i < K.Length; i++)
// 			S[(*c)++] = K.TabKata[i];	

// 		if (!IsEmptyKalimat(Q))
// 			S[(*c)++] = ' ';
// 	}
// 	S[(*c)++] = ',';
// }

// int NB(char S[])
// {
// 	int n = 0;
// 	while(S[n] != '\0')
// 		n++;

// 	return n;
// }



// // PREPARATION PHASE
// // ================================================================
// boolean CanBuild(Wahana W)
// {
// 	return (P.Mat.Wood >= W.Mat.Wood && P.Mat.Stone >= W.Mat.Stone && P.Mat.Ruby >= W.Mat.Ruby);
// }

// void build (StackAction *S, Wahana *W, ListWahana W1)
// {
// 	printf("Build\n");

// 	boolean build = true;
// 	while(build)
// 	{
// 		printf("Ingin Membangun apa?\n");
// 		PrintListWahana();
// 		Kalimat K = GetKalimat();
// 		Kalimat K2 = K;
// 		Kata exitKata;
// 		DequeueKalimat(&K2, &exitKata);
		
// 		if(KataSama(exitKata, EXIT))
// 		{
// 			build = false;
// 			printf("Pembangunan dibatalkan!!\n");
// 		}
// 		else
// 		{
// 			boolean available = false;
// 			int i = 0;
// 			while(i < NbWahana(W1) && !available)
// 			{
// 				if (IsEQKalimat(K, W1[i]))
// 					available = true;
// 				else
// 					i++;
// 			}

// 			if (!available)
// 			{
// 				printf("Wahana yang dipilih tidak tersedia!!\n");
// 			}
// 			else
// 			{

// 				if (CanBuild(W1[i]))
// 				{
// 					Action A;
// 					ActionName(A) = K;
// 					ActioneType(A) = BUILDTYPE;
// 					ActionTime(A) = BUILDTIME;
// 					ActionAmount(A) = 1;
// 					ActionPos(A) = Player.Pos;

// 					Push(S, A);

// 					printf("Perintah Build ");
// 					PrintKalimat(K);
// 					printf(" dimasukkan ke dalam Stack\n");

// 					build = false;
// 				}
// 				else
// 				{
// 					printf("Tidak dapat melakukan pembangunan ");
// 					PrintKalimat(K);
// 					printf("\n");
// 				}
// 			}
// 		}
// 	}
	
// }

// void upgrade()
// {
// 	printf("Upgrade\n");
// }

// void buy()
// {
// 	printf("Buy\n");
// }

// void Undo (StackAction *S)
// {
// 	Action A;
// 	Pop(S, &A);

// 	printf("Menghapus Perintah ");
// 	PrintKata(ActionType(A));
// 	printf(" ");
// 	PrintKata(ActionName(A));
// 	printf(" dari Stack!!\n");
// }

// void execute(StackAction *S)
// {
// 	printf("Execute\n");
	
// 	 /* Kamus lokal */
//     Stack StackExecute;
//     Action A;

//     /*Algoritma*/
//     if (!IsEmpty(*S))
//     {
//         while (!IsEmpty(*S))
//         {
//             Pop(S, &A);
//             Push(&StackExecute, A);
//         }
//         while (!IsEmpty(StackExecute))
//         {
//             Pop(&StackExecute, &A);
//             if (KataSama(ACTION_BUILD, TYPE(A)))
//             {
//                 executeBuild(A);
//             }
//             else if (KataSama(ACTION_UPGRADE, TYPE(A)))
//             {
//                 executeUpgrade(A);
//             }
//             else
//             {
//                 executeBuy(A);
//             }
            
//         }

//     }
//     maen();
// }

// void prepareToMain()
// {
// 	MAINPHASE = true;
// }


// // MAIN PHASE
// // ================================================================
// void Serve(Player *Player, Queue *Q, Kalimat Namawahana)
// {
//     printf("//\tServing Costumer\t//\n");
//     infotype del;
//     Dequeue(Q,&del);
//     *Player.money = *Player.money + Namawahana.cost // ??
//     // Time nya maju

// 	boolean found = false;
// 	int i = 0;
// 	while (i < NBWahana(W) && !found)
// 		if (IsEQKalimat(W[i].Name, Namawahana))
// 			found = true;
// 		else
// 			i++;
	

// 	RandomBroken(i);
// }

// void repair()
// {
// 	printf("Repair\n");
// }

// void detail()
// {
// 	printf("Detail\n");
// }

// void office()
// {
// 	printf("Office\n");
// }

// void mainToPrepare()
// {
// 	MAINPHASE = false;
// }



void EXITGAME(int x)
{
	if (x == 0)
	{
		// Exit Office
		OFFICE_MODE = false;
	}
	else if(x == 1)
	{
		RUN = false;
		RUN_NEWGAME = false;
		OFFICE_MODE = false;
	}
}




// void RandomAntrian(Antrian *A, Wahana W)
// {
// 	for (int i = 0; i < MaxAntrian; ++i)
// 	{
// 		idxWahana = random(0, NbWahana(W));

// 		Antri Q;
// 		AntriName(Q) = W[idxWahana].Name;
// 		AntriPrio(Q) = 5;

// 		Enqueue(A, Q);
// 	}
// }

// void RandomBroken(int idxWahana)
// {
// 	int broke = random(0, 5);

// 	if (broke >=4 && broke <= 5)
// 	{
// 		(*W)[idxWahana].Status = BROKESTATUS;
// 		printf("Wahana ");
// 		PrintKalimat((W)[idxWahana].Name)
// 		printf(" Telah Rusak!!");
// 	}
// }


// void ReadMaterial(char addressFile[], int *wood, int *stone, int *iron, int *mamank) {

//     FILE *fp = fopen(addressFile,"r");

//     if (fp == NULL) {
//         printf("Error, could not load .txt file!\n");
//         exit(1);
//     }

//     char charA[128];
//     char charB[128];
//     int temp[4];
//     int i = 0;
//     int countLine = 1;

//     while(fscanf(fp, "%s %s", &charA, &charB) != EOF) {
//         if (countLine >= 2) {
//             temp[i] = atoi(charB);
//             ++i;
//         } else {
//             ++countLine;
//         }
//     }

//     *wood = temp[0];
//     *stone = temp[1];
//     *iron = temp[2];
//     *mamank = temp[3];

//     fclose(fp);
// }

// void WriteMaterial(char addressFile[], int wood, int stone, int iron, int mamank) {

//     FILE *fp = fopen(addressFile,"w");

//     fprintf(fp, "Material Harga\n");
//     fprintf(fp, "Wood %d\n", wood);
//     fprintf(fp, "Stone %d\n", stone);
//     fprintf(fp, "Iron %d\n", iron);
//     fprintf(fp, "mamank %d\n", mamank);

//     fclose(fp);
// }

// void geneateMapMain(Player P, Stack Aksi)
// {
//     JAM buka, tutup;
//     buka = MakeJAM(9,0,0);
//     tutup = MakeJam(21,0,0);
//     if(JLT(Time(P),tutup) && JGT(Time(P),buka)){
//         printf("Main phase Day %d\n",Day(P));
//     }
//     else{
//         printf("Preparation phase Day %d\n",Day(P));
//     }
//     /*generating map */
//     printMap(P);

//     printf("Legend :\n");
//     printf("A = Antrian\n");
//     printf("P = Player\n");
//     printf("W = Wahana\n");
//     printf("O = Office\n");
//     printf("<, ^, v, > = Gerbang\n");
//     printf("\n");
//     printf("Name : %s \n",Name(P));
//     printf("Money : %d \n",Money(P));
//     printf("Current time : ")
//     TulisJAM(Time(P));
//     printf('\n');

//     if(JLT(Time(P),tutup) && JGT(Time(P),buka)){
//         printf("Closing time : ");
//         TulisJAM(tutup);
//         printf("\n");
//         printf("Time remaining : ");
//         cetakDurasi(Durasi(Time(P),tutup));
//         printf("\n");
//         /* buat prosedur print antrian */
//     }
//     else{
//         printf("Opening time : ");
//         TulisJAM(buka);
//         printf("\n");
//         printf("Time remaining : ");
//         cetakDurasi(Durasi(Time(P),buka));
//         printf("\n");
//         printf("Jumlah aksi yang akan dilakukan : %d\n",(Top(Aksi)+1));
//         printf("Total waktu yang dibutuhkan : "); TulisJAM(HitungTime(Aksi));
//         printf("\n");
//         printf("Total uang yang dibutuhkan : ",HitungMoney(Aksi));
//     }
    
    
//     if(JLT(Time(P),tutup) && JGT(Time(P),buka)){
//         printf("Closing time : ");
//         TulisJAM(tutup);
//         printf("\n")
//     }

//     printf("Masukkan perintah : \n");
// }