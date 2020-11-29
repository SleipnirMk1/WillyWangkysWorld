#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "boolean.h"
#include "ADT\mesinkata\mesinkata.h"
#include "ADT\mesinkata\mesinkar.h"
#include "ADT\graph\graph.h"
#include "ADT\custom_adt\player.h"
#include "ADT\point\point.h"
#include "ADT\custom_adt\stackaction.h"
#include "ADT\custom_adt\arraywahana.h"
#include "ADT\custom_adt\wahana.h"
#include "ADT\queue\queueAntrian.h"
#include "ADT\jam\jam.h"
#include "ADT\Tree\tree.h"

// #define MAXSTACKACTION 100

#define MAX_SIZE_MAP 20



// Dalam Satuan menit
int TIME_BUILD = 120;
int TIME_BUY = 40;
int TIME_UPGRADE = 120;
int TIME_MOVE = 1;
int TIME_REPAIR = 20;

int REPAIR_COST = 40;


Player P;
Graph G;
StackAction S;
QueueAntrian A;

ArrayWahana ListWahanaDimiliki;
int NbWahanaDimiliki = 0;
ArrayWahana ListWahanaTersedia;
int NbWahanaTersedia = 0;


Kata ListNamaMaterial[10];
int ListHargaMaterial[10];
int NbMaterial = 0;


POINT officePosition;
POINT AntrianPosition;


boolean MAINPHASE = false;
boolean RUN_NEWGAME = true;
boolean RUN = true;
boolean OFFICE_MODE = false;

Kata NEW, LOAD, EXIT;
Kata BUILD, UPGRADE, BUY, UNDO, EXECUTE, MAIN;
Kata SERVE, REPAIR, DETAIL, OFFICE, PREPARE;
Kata SAVE, CONTINUE;
Kata MoveW, MoveA, MoveS, MoveD;
Kata DETAILS, REPORT, EXITS;

Kata ACTION_BUILD, ACTION_UPGRADE, ACTION_BUY;
Kata MATERIAL_WOOD, MATERIAL_IRON, MATERIAL_STONE;
Kata Info_Player;


// Defenition
// ============================================
void generateAllConstant();
void generatePlayer();
void generateWahanaTersedia();
void generateWahanaYangDimiliki();
void generateListMaterial();
void PrintListMaterial();
int SearchListMaterial(Kata Name);
void EXITGAME(int x);
void generateLoadGame();
void generateNewGame();
void saveGame();
void conti();

void generateMapMain();
void PrintMap();
void PrintBrokenWahana();
boolean IsAdaBroken();
boolean IsWahanaPosition(POINT P);
boolean IsAntrianPosition(POINT P);

void buy();
void undo();
void build();
void execute();
void executeBuild(Action A);
void executeUpgrade(Action A);
void executeBuy(Action A);


void upgrade();
void prepareToMain();

void serve();
void repair();
void detail();
void office();
void InOffice();
void DetailFromWahana(WAHANA Wahana);
void ReportFromWahana(WAHANA Wahana);
void mainToPrepare();

boolean IsWall(float X, float Y, int A);
boolean IsGerbang(float X, float Y, int A);
boolean IsOfficePosition(int A, float X, float Y);
void move(int dir);

void RandomAntrian();
void PrintListWahanaTersedia();
void PERSIAPANGAME();
ArrayWahana ReadWahanaInfo(char dir[]);

Tree generateWahanaUpgradeTree();

void PrintInfoPlayer();

// ==============================================

int main()
{
	PERSIAPANGAME();

	CreateEmptyStackAction(&S);
	MakeEmptyQueueAntrian(&A, 100);

	generateAllConstant();

	generatePlayer();
	generateWahanaTersedia();
	generateWahanaYangDimiliki();

	generateListMaterial();

	//printf("%f\n", P.Position.Y);
	// generatePosFromFile();
	// generateMatFromFile();
	// generateWahFromFile();
	// generateStaFromFile();

	
	// Tree T = generateWahanaUpgradeTree();
	// PrintTreeIndent(T, 2);


	RUN = true;
	RUN_NEWGAME = true;
	boolean runned = false;

	printf("NEW // LOAD // EXIT\n\n");
	
	while(RUN_NEWGAME)
	{
		printf("Masukkan perintah : ");
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
		generateMapMain();

		// printf("\n\n");
		// PrintVertex(P.Position);
		// printf("\n\n");


		Kalimat input = GetKalimat();
		Kata K;
		DequeueKalimat(&input, &K);

		if (KataSama(K, EXIT))
		{
			RUN = false;
		}
		else if (KataSama(K, Info_Player))
		{
			PrintInfoPlayer();
		}
		else if (KataSama(K, MoveW))
		{
			move(0);
		}
		else if (KataSama(K, MoveA))
		{
			move(1);
		}
		else if (KataSama(K, MoveS))
		{
			move(2);
		}
		else if (KataSama(K, MoveD))
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
					build();
				}
				else if (KataSama(K, UPGRADE))
				{
					upgrade();
				}
				else if (KataSama(K, BUY))
				{
					buy();
				}
				else if (KataSama(K, UNDO))
				{
					undo();
				}
				else if (KataSama(K, EXECUTE))
				{
					execute();
				}
				else if (KataSama(K, MAIN))
				{
					prepareToMain();
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
					repair();
				}
				else if (KataSama(K, DETAIL))
				{
					detail();
				}
				else if (KataSama(K, OFFICE))
				{
					office();
				}
				else if (KataSama(K, PREPARE))
				{
					mainToPrepare();
				}
				else
				{
					printf("Maaf, Perintah yang dimasukkan tidak tersedia pada Phase ini!!\n");
				}

			}

		}

		
	}


	// if (runned)
	// {
	// 	printf("Masukkan 'y' jika ingin melakukan SAVE GAME : ");
	// 	char yy;
	// 	scanf("%c", &yy);
	// 	if (yy == 'y');
	// 		//saveGame();
	// }

	printf("Thanks for playing... :D");

	return 0;
}


// 
// ================================================================
void PERSIAPANGAME()
{
	officePosition = MakePOINT(12, 3, 1);
	AntrianPosition = MakePOINT(1, 10, 1);

	POINT GB1_1 = MakePOINT(19,4,1);
	POINT GB1_2 = MakePOINT(0,4,2);
	Edge E1 = CreateEdge(GB1_1, GB1_2);

	POINT GB2_1 = MakePOINT(9,19,2);
	POINT GB2_2 = MakePOINT(9,0,4);
	Edge E2 = CreateEdge(GB2_1, GB2_2);

	POINT GB3_1 = MakePOINT(0,4,4);
	POINT GB3_2 = MakePOINT(19,4,3);
	Edge E3 = CreateEdge(GB3_1, GB3_2);

	POINT GB4_1 = MakePOINT(9,0,3);
	POINT GB4_2 = MakePOINT(9,19,1);
	Edge E4 = CreateEdge(GB4_1, GB4_2);

	AddEdge(&G, E1);
	AddEdge(&G, E2);
	AddEdge(&G, E3);
	AddEdge(&G, E4);
}


void generatePlayer()
{
	P.Name = SetKalimat("Alstrukdat");

	Area(P.Position) = 1;
 	Absis(P.Position) = 6;
	Ordinat(P.Position) = 6;

	P.Money = 99999;
	P.Debt = 0;

	P.Material.wood = 500;
	P.Material.iron = 500;
	P.Material.stone = 500;

	P.CurrentTime = MakeJAM(21, 0, 0);
	P.Day = 1;
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

	SetKata(&DETAILS, "Details");
	SetKata(&REPORT, "Report");
	SetKata(&EXITS, "Exit");

	SetKata(&MoveW, "w");
	SetKata(&MoveA, "a");
	SetKata(&MoveS, "s");
	SetKata(&MoveD, "d");


	SetKata(&ACTION_BUILD, "build");
	SetKata(&ACTION_UPGRADE, "upgrade");
	SetKata(&ACTION_BUY, "buy");

	SetKata(&MATERIAL_WOOD, "wood");
	SetKata(&MATERIAL_IRON, "iron");
	SetKata(&MATERIAL_STONE, "stone");

	SetKata(&Info_Player, "info");
}

void generateWahanaYangDimiliki()
{
	MakeEmptyWahana(&ListWahanaDimiliki);

	AddAsLastElWahana(&ListWahanaDimiliki, ElmtWahana(ListWahanaTersedia, 0));

	NbWahanaDimiliki = 1;
}

void generateWahanaTersedia()
{
	ListWahanaTersedia = ReadWahanaInfo("file/wahanainfo.txt");

	NbWahanaTersedia = NbElmtWahana(ListWahanaTersedia);
}

void generateNewGame()
{
	printf("New GAME!!\n");
}

void generateLoadGame()
{
	printf("Load GAME!!\n");
}



// Movement
// =================================================================================
boolean IsWall(float X, float Y, int A)
{
	return ((X == 0)|(X == 19)|(Y == 19)|(Y == 0))&&(!IsGerbang(X, Y, A));
}
boolean IsGerbang(float X, float Y, int A)
{
	if (A == 1)
		return ((X == 19) && (Y == 4))|((X == 9)&&(Y == 19));
	else if (A == 2)
		return ((X == 0) && (Y == 4))|((X == 9)&&(Y == 19));
	else if (A == 3)
		return ((X == 19) && (Y == 4))|((X == 9)&&(Y == 0));
	else if (A == 4)
		return ((X == 0) && (Y == 4))|((X == 9)&&(Y == 0));
}
void gerak(int X)
{
	POINT segment; 
	if (X == 0)
	{
		//printf("WW\n");
		if (!IsWall(Absis(P.Position),Ordinat(P.Position) - 1, Area(P.Position)))
		{
			segment = MakePOINT(Absis(P.Position),Ordinat(P.Position) - 1, Area(P.Position));
			if ((!IsWahanaPosition(segment)) && (!IsAntrianPosition(segment)))
			{

				if (!(IsGerbang(P.Position.X, P.Position.Y, P.Position.A) && P.Position.Y-1 < 0))
					Geser (&P.Position, 0, -1, 0);
				
				if(IsGerbang(Absis((P).Position),Ordinat((P).Position), Area((P).Position)))
				{
					POINT V;
					GetVEdge(G, P.Position, &V);

					(P).Position = V;
				}
				Time(P) = NextNDetik(Time(P), 60);
			}
		}
	}
	else if (X == 1)
	{
		//printf("AA\n");
		if (!IsWall(Absis(P.Position)-1,Ordinat(P.Position), Area(P.Position)))
		{
			segment = MakePOINT(Absis(P.Position)-1,Ordinat(P.Position), Area(P.Position));
			if ((!IsWahanaPosition(segment)) && (!IsAntrianPosition(segment)))
			{
				if (!(IsGerbang(P.Position.X, P.Position.Y, P.Position.A) && P.Position.X-1 < 0))
					Geser (&P.Position, -1, 0, 0);
				
				if(IsGerbang(Absis(P.Position),Ordinat((P).Position), Area((P).Position)))
				{
					POINT V;
					GetVEdge(G, (P).Position, &V);

					(P).Position = V;
				}
				Time(P) = NextNDetik(Time(P), 60);
			}
		}
	}
	else if (X == 2)
	{
		//printf("SS\n");
		if (!IsWall(Absis(P.Position),Ordinat(P.Position) + 1, Area(P.Position)))
		{
			segment = MakePOINT(Absis(P.Position),Ordinat(P.Position) + 1, Area(P.Position));
			if ((!IsWahanaPosition(segment)) && (!IsAntrianPosition(segment)))
			{
				if (!(IsGerbang(P.Position.X, P.Position.Y, P.Position.A) && P.Position.Y+1 > 19))
					Geser (&P.Position, 0, 1, 0);
				
				if(IsGerbang(Absis((P).Position),Ordinat((P).Position), Area((P).Position)))
				{
					POINT V;
					GetVEdge(G, (P).Position, &V);

					(P).Position = V;
				}
				Time(P) = NextNDetik(Time(P), 60);
			}
		}
	}
	else if (X == 3)
	{
		//printf("DD\n");
		if (!IsWall(Absis(P.Position) + 1,Ordinat(P.Position), Area(P.Position)))
		{
			segment = MakePOINT(Absis(P.Position) + 1,Ordinat(P.Position), Area(P.Position));
			if ((!IsWahanaPosition(segment)) && (!IsAntrianPosition(segment)))
			{
				if (!(IsGerbang(P.Position.X, P.Position.Y, P.Position.A) && P.Position.X+1 > 19))
					Geser (&P.Position, 1, 0, 0);

				if(IsGerbang(Absis((P).Position),Ordinat((P).Position), Area((P).Position)))
				{
					POINT V;
					GetVEdge(G, (P).Position, &V);

					(P).Position = V;
				}
				Time(P) = NextNDetik(Time(P), 60);
			}
		}
	}
}


void move(int dir)
{
	gerak(dir);
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



//================================================================
void PrintInfoPlayer()
{
	printf("Wood : %d\n", P.Material.wood);
	printf("Stone : %d\n", P.Material.stone);
	printf("Iron : %d\n", P.Material.iron);
}








// // PREPARATION PHASE
// // ================================================================
boolean IsMasihAdaWaktu(int t)
{
	long duration = JAMToDetik(P.CurrentTime) + (long)(t + TotalTimeAction(S)) * 60;

	JAM J = DetikToJAM(duration);

	if (Hour(J) >= 21)
	{
		return true;
	}
	else
	{
		if (Hour(J) < 9)
			return true;
		else
			return false;
	}
}


boolean CanBuild(WAHANA W)
{
	boolean can = (P.Money >= W.PriceCost && P.Material.wood >= W.MaterialCost.wood && P.Material.stone >= W.MaterialCost.stone && P.Material.iron >= W.MaterialCost.iron);
	
	can = can && IsMasihAdaWaktu(TIME_BUILD);

	return can;
}

void PrintListWahanaTersedia()
{
	for (int i = 0; i < NbWahanaTersedia; i++)
	{
		printf("%d. ", i+1);
		PrintKalimat(ListWahanaTersedia.TI[i].Name);
		printf("\n");
	}
	
}

void build ()
{
	printf("Build\n");

	boolean build = true;
	while(build)
	{
		printf("\nWahana Yang dapat dibangun : \n");
		PrintListWahanaTersedia();
		
		printf("\nMasukkan Nama Wahana : ");

		Kalimat K = GetKalimat();
		Kalimat K2 = K;
		Kata exitKata;
		DequeueKalimat(&K2, &exitKata);
		
		if(KataSama(exitKata, EXIT))
		{
			build = false;
			printf("\nPembangunan dibatalkan!!\n");
		}
		else
		{
			boolean available = false;
			int i = 0;
			while(i < NbWahanaTersedia && !available)
			{
				if (IsEQKalimat(K, ListWahanaTersedia.TI[i].Name))
					available = true;
				else
					i++;
			}

			if (!available)
			{
				printf("\nWahana yang dipilih tidak tersedia!!\n");
			}
			else
			{

				if (CanBuild(ListWahanaTersedia.TI[i]))
				{
					Action A;
					ActionName(A) = ListWahanaTersedia.TI[i].Name;
					SetKata(&ActionType(A), "build");
					ActionTime(A) = 100;
					ActionAmount(A) = 1;
					ActionPrice(A) = ListWahanaTersedia.TI[i].PriceCost;
					ActionPosition(A) = P.Position;

					ActionMaterialCost(A).wood = ElmtWahana(ListWahanaTersedia, i).MaterialCost.wood;
					ActionMaterialCost(A).stone = ElmtWahana(ListWahanaTersedia, i).MaterialCost.stone;
					ActionMaterialCost(A).iron = ElmtWahana(ListWahanaTersedia, i).MaterialCost.iron;

					PushAction(&S, A);

					P.Debt += ListWahanaTersedia.TI[i].PriceCost;

					printf("\nPerintah Build ");
					PrintKalimat(K);
					printf(" dimasukkan ke dalam Stack\n");

					build = false;
				}
				else
				{
					printf("\nTidak dapat melakukan pembangunan ");
					PrintKalimat(K);
					printf("\n");
				}
			}
		}
	}
	
}

int IdxWahanaSekitar(POINT P)
{
	boolean found = false;
	int i = 0;
	while (i < NbWahanaDimiliki && !found)
	{
		POINT P1 = MakePOINT(Absis(P), Ordinat(P)-1, Area(P));
		POINT P2 = MakePOINT(Absis(P)+1, Ordinat(P), Area(P));
		POINT P3 = MakePOINT(Absis(P), Ordinat(P)+1, Area(P));
		POINT P4 = MakePOINT(Absis(P)-1, Ordinat(P), Area(P));

		POINT PW = ListWahanaDimiliki.TI[i].Position;

		if (EQ(PW, P1))
			found = true;
		else if (EQ(PW, P2))
			found = true;
		else if (EQ(PW, P3))
			found = true;
		else if (EQ(PW, P4))
			found = true;
		else
			i++;
	}

	if (!found)
		return -1;
	else
		return i;
}


// Tree ReadWahana(char dir[])
// {
//     FILE *fp = fopen(dir,"r");

//     if (fp == NULL) {
//         printf("Error, could not load .txt file!\n");
//         exit(1);
//     }

//     char singleLine[128];
//     Tree T;
// 	int idx = 0;

//     while (!feof(fp))
//     {
//         fgets(singleLine, 128, fp);
// 		//printf("%s", singleLine);
// 		// printf("%c\n", singleLine[1]);
// 		// printf("%s\n", singleLine);
//         BuildTreeFromString(&T, singleLine, &idx);
//     }
// 	fclose(fp);
//     return T;
// }


// Membaca dari file seharusnya, klo ga ya buat tree sendiri
Tree generateWahanaUpgradeTree()
{
	int info = 0;
	Tree W = BuildBalanceTree(14+1, &info);
	//W = ReadWahana("file/wahanatree.txt");
	return W;
}

// Melayani Input jenis upgrade dengan melihat pohon upgrade
void CheckTreeUpgrade(Tree UpgradeTree, ArrayWahana T_built_wahana, ArrayWahana T_all_wahana, IdxType i_nearby, boolean *Upable, int *target1, int *target2)
{
	// Utk input tujuan upgrade
	Kalimat Q;

	// Fungsi mencari simpul yang sesuai dengan tipe wahana yg akan diupgrade
	Tree UpTarget = SearchTreeNode(UpgradeTree, Tipe(ElmtWahana(T_built_wahana, i_nearby)));
	//PrintTreeIndent(UpTarget, 4);
	// Jika ditemukan simpul yang sesuai
	if (UpTarget != NilTree)	
	{
		// Memastikan ada upgrade utk simpul
		if (Left(UpTarget) != NilTree && Right(UpTarget) != NilTree)
		{
			// Mencari informasi dari cabang upgrade wahana terpilih
			*target1 = Search1Wahana(T_all_wahana, Info(Left(UpTarget)) );
			*target2 = Search1Wahana(T_all_wahana, Info(Right(UpTarget)) );
			*Upable = true;			
		}
		// Tidak terdapat upgrade utk wahana
		else
		{
			*Upable = false;
		}
	}
	// Tidak ditemukan wahana dalam tree
	else
	{
		printf("Wahana tidak valid\n");
	}
}

// Melayani fungsi upgrade
void upgrade ()
{
	// Cek ada wahana di sekitar player, fungsi yg sudah ada tidak masalah
	int IsAdaWahanaSekitar = IdxWahanaSekitar(P.Position);

	if (IsAdaWahanaSekitar == -1)
	{
		printf("\nTidak ada wahana yang tersedia!!\n");
		return;	
	}

	boolean isUpgrading = true;

	// Menyingkat nama variabel
	int Idx_sekitar = IsAdaWahanaSekitar;	
	ArrayWahana T_built = ListWahanaDimiliki;
	//printf("%d", NbElmtWahana(T_built));

	// Harus mengakses informasi wahana dari database yang mencangkup semua wahana
	// Berbeda dengan database wahana yang tersedia utk dibangun
	ArrayWahana T_all_wahana = ListWahanaTersedia;

	// Mengakses pohon upgrade
	Tree UpTree;
	UpTree = generateWahanaUpgradeTree();
	//PrintTreeIndent(UpTree, 2);
	//printf("Test");

	boolean upgradeAble = true;
	IdxType TargetUp1;
	IdxType TargetUp2;
	CheckTreeUpgrade(UpTree, T_built, T_all_wahana, Idx_sekitar, &upgradeAble, &TargetUp1, &TargetUp2);

	if (!upgradeAble)
	{
		printf("\nTidak Dapat Mengupgrade Wahana!!\n");
		return;
	}

	boolean choice = false;
	int TargetUpgrade;

	while(isUpgrading && upgradeAble)
	{
		printf("\nSedang meng-upgrade wahana ");
		PrintKalimat(Nama(ElmtWahana(T_built, Idx_sekitar)));
		printf("\n");

		printf("List : \n");
		printf("    - ");
		PrintKalimat(Nama(ElmtWahana(T_all_wahana, TargetUp1)));
		printf("\n");
		printf("    - ");
		PrintKalimat(Nama(ElmtWahana(T_all_wahana, TargetUp2)));
		printf("\n");

		printf("\nIngin mengupgrade menjadi ('exit' untuk membatalkan) : ");

		Kalimat K = GetKalimat();
		Kalimat K2 = K;
		Kata exitKata;
		DequeueKalimat(&K2, &exitKata);

		if(KataSama(exitKata, EXIT))
		{
			choice = false;
			isUpgrading = false;
			printf("\nUpgrade dibatalkan\n");
		}
		else
		{
			// Jika cabang kiri
			if (IsEQKalimat(K, Nama(ElmtWahana(T_all_wahana, TargetUp1))))
			{
				// Pengecekan resource, sama seperti build
				if (CanBuild(ElmtWahana(T_all_wahana, TargetUp1)) )
				{
					choice = true;
					isUpgrading = false;
					TargetUpgrade = TargetUp1;
				}
				else
				{
					printf("\nSumber daya tidak mencukupi\n");
				}
				
			}
			// Jika cabang kanan
			else if (IsEQKalimat(K, Nama(ElmtWahana(T_all_wahana, TargetUp2)) ) )
			{
				// Pengecekan resource, sama seperti build
				if (CanBuild(ElmtWahana(T_all_wahana, TargetUp2)) )
				{
					choice = true;
					isUpgrading = false;
					TargetUpgrade = TargetUp2;
				}
				else
				{
					printf("\nSumber daya tidak mencukupi\n");
				}
			}
			// Pilihan cabang tidak tersedia
			else
			{
				printf("\nTidak terdapat upgrade tersebut\n");
			}

		}
	}

	if (choice)
	{
		Action A;
		ActionName(A) = Nama(ElmtWahana(T_all_wahana, TargetUpgrade));
		SetKata(&ActionType(A), "upgrade");	
		ActionTime(A) = TIME_UPGRADE;
		ActionAmount(A) = 1;
		ActionPrice(A) = Price(ElmtWahana(T_all_wahana, TargetUpgrade));	// harga uang
		
		// lokasi wahana lama, bisa utk rujukan ke wahana lama
		ActionPosition(A) = Lokasi(ElmtWahana(T_built, Idx_sekitar));	

		// Keperluan material
		Wood(ActionMaterialCost(A)) = Wood(MaterialCost(ElmtWahana(T_all_wahana, TargetUpgrade)));	// harga kayu
		Stone(ActionMaterialCost(A)) = Stone(MaterialCost(ElmtWahana(T_all_wahana, TargetUpgrade)));	// harga batu
		Iron(ActionMaterialCost(A)) = Iron(MaterialCost(ElmtWahana(T_all_wahana, TargetUpgrade)));		// harga besi
		
		PushAction(&S, A);	// Push ke stack

		P.Debt += Price(ElmtWahana(T_all_wahana, TargetUpgrade));

		printf("\nPerintah Upgrade ");
		PrintKalimat(Nama(ElmtWahana(T_all_wahana, TargetUpgrade)));
		printf(" dimasukkan ke dalam Stack\n");
	}
	
}

void generateListMaterial()
{
	FILE *material;
	material = fopen("file/material.txt", "r");

	while(fgetc(material) != '\n') //skip first line	baris pertama isinya "Material Harga"
        ;

	char mat[10];
	int harga;
	int i =0;
	Kata mater;
	while(feof(material) == 0){
		fscanf(material,"%s %d",&mat,&harga);
		SetKata(&mater,mat);
		ListNamaMaterial[i] = mater;
		ListHargaMaterial[i] = harga;
		i++;
	}

	NbMaterial = i;

	// printf("Dari .txt harusnya\n\n");

	// SetKata(&ListNamaMaterial[0], "wood");
	// SetKata(&ListNamaMaterial[1], "stone");
	// SetKata(&ListNamaMaterial[2], "iron");

	// ListHargaMaterial[0] = 50;
	// ListHargaMaterial[1] = 23;
	// ListHargaMaterial[2] = 100;

	// NbMaterial = 3;
}

void PrintListMaterial()
{
	for (int i = 0; i < NbMaterial; i++)
	{
		printf("%d. ", i+1);
		PrintKata(ListNamaMaterial[i]);
		printf("  |  ");
		printf("%d\n", ListHargaMaterial[i]);
	}
}

int SearchListMaterial(Kata Nama)
{
	boolean found = false;
	int i = 0;
	while (i < NbMaterial && !found)
		if (KataSama(ListNamaMaterial[i], Nama))
			found = true;
		else
			i++;
	
	if (!found)
		return -1;
	else
		return i;
}


void buy()
{
	printf("Material  |  Harga :\n");
	PrintListMaterial();

	printf("\nMaterial yang ingin dibeli : ");

	Kalimat input = GetKalimat();
	Kata banyak;
	Kata nama;
	DequeueKalimat(&input, &banyak);
	DequeueKalimat(&input, &nama);
    /* kalo kondisi input valid : */
    int i = SearchListMaterial(nama);
	int totalHarga = 0;
	if (i != -1)
    	totalHarga = ListHargaMaterial[i]* KataToInteger(banyak);

	//printf("%d\n", IsMasihAdaWaktu(TIME_BUY));

	if (i != -1 && P.Money >= P.Debt + totalHarga && IsMasihAdaWaktu(TIME_BUY))
	{
		/* memasukkan ke stack */
		Action X;
		//JAM J;
		/* (masih pemisalan) membeli 1 material membutuhkan waktu 5 menit */
		int lama = 5*KataToInteger(banyak);
		ActionName(X) = SetKalimat(nama.TabKata);
		SetKata(&ActionType(X), "buy");
		ActionTime(X)= lama;
		ActionAmount(X) = KataToInteger(banyak);
		ActionPrice(X) = totalHarga;
		ActionPosition(X) = P.Position;
		P.Debt += totalHarga;

		PushAction(&S,X);

		printf("Perintah Buy ");
		PrintKata(banyak);
		printf(" ");
		PrintKata(nama);
		printf(" dimasukkan ke dalam Stack\n");
	}
	else
	{
		printf("Tidak dapat melakukan pembelian!!!\n");
	}
    
}

void undo ()
{
	if (IsEmptyStackAction(S))
	{
		printf("Stack Kosong!!\n");
		return;
	}

	Action A;
	PopAction(&S, &A);

	P.Debt -= ActionPrice(A);

	printf("Menghapus Perintah ");
	PrintKata(ActionType(A));
	printf(" ");
	PrintKalimat(ActionName(A));
	printf(" dari Stack!!\n");
}

void execute()
{	
	 /* Kamus lokal */
    StackAction StackExecute;
	CreateEmptyStackAction(&StackExecute);
    Action A;

	P.Money -= P.Debt;
	P.Debt = 0;
	
    /*Algoritma*/
    if (!IsEmptyStackAction(S))
    {
        while (!IsEmptyStackAction(S))
        {
            PopAction(&S, &A);
            PushAction(&StackExecute, A);
        }
		printf("%d\n", NbElmtStackAction(StackExecute));
        while (!IsEmptyStackAction(StackExecute))
        {
            PopAction(&StackExecute, &A);
            if (KataSama(ACTION_BUILD, ActionType(A)))
            {
                executeBuild(A);
            }
            else if (KataSama(ACTION_UPGRADE, ActionType(A)))
            {
                executeUpgrade(A);
            }
            else
            {
                executeBuy(A);
            }
            
        }

    }
    prepareToMain();
}



void executeBuild(Action A)
{
	printf("Execute Build...\n");
	
	boolean found = false;
	int i = 0;
	while(i < NbWahanaTersedia && !found)
	{
		if (IsEQKalimat(Nama(ElmtWahana(ListWahanaTersedia, i)), ActionName(A)))
			found = true;
		else
			i++;
	}


	WAHANA W = ElmtWahana(ListWahanaTersedia, i);

	Condition(W) = true;
	Lokasi(W) = ActionPosition(A);

	AddAsLastElWahana(&ListWahanaDimiliki, W);

	NbWahanaDimiliki += 1;

	P.Material.wood -= ActionMaterialCost(A).wood;
	P.Material.iron -= ActionMaterialCost(A).iron;
	P.Material.stone -= ActionMaterialCost(A).stone;

	POINT t = P.Position;

	if (EQ(t, ActionPosition(A)))
	{
		if (
			!IsWall(t.X-1, t.Y, t.A) && 
			!IsWahanaPosition(MakePOINT(t.X-1, t.Y, t.A)) && 
			!EQ(officePosition, MakePOINT(t.X-1, t.Y, t.A)) && 
			!EQ(AntrianPosition, MakePOINT(t.X-1, t.Y, t.A))
			)
		{
			move(1);
		}
		else if (
			!IsWall(t.X, t.Y-1, t.A) &&
			!IsWahanaPosition(MakePOINT(t.X, t.Y-1, t.A)) && 
			!EQ(officePosition, MakePOINT(t.X, t.Y-1, t.A)) && 
			!EQ(AntrianPosition, MakePOINT(t.X, t.Y-1, t.A))
			)
		{
			move(0);
		}
		else if (
			!IsWall(t.X+1, t.Y, t.A) &&
			!IsWahanaPosition(MakePOINT(t.X+1, t.Y, t.A)) && 
			!EQ(officePosition, MakePOINT(t.X+1, t.Y, t.A)) && 
			!EQ(AntrianPosition, MakePOINT(t.X+1, t.Y, t.A))
			)
		{
			move(3);
		}
		else
		{
			move(2);
		}
	}
}

void executeUpgrade(Action A)
{
	printf("Execute Upgrade...\n");

	boolean foundOld = false;
	int idxOld = 0;
	while(idxOld < NbWahanaDimiliki && !foundOld)
	{
		if (EQ(Lokasi(ElmtWahana(ListWahanaDimiliki, idxOld)), ActionPosition(A)))
			foundOld = true;
		else
			idxOld++;
	}

	boolean foundNew = false;
	int idxNew = 0;
	while(idxNew < NbElmtWahana(ListWahanaTersedia) && !foundNew)
	{
		if (IsEQKalimat(Nama(ElmtWahana(ListWahanaTersedia, idxNew)), ActionName(A)))
			foundNew = true;
		else
			idxNew++;
	}
	
	if (!foundOld || !foundNew)
	{
		printf("\nUpgrade Failed...\n");
	}
	else
	{
		WAHANA W = ElmtWahana(ListWahanaTersedia, idxNew);
		Condition(W) = true;
		Lokasi(W) = Lokasi(ElmtWahana(ListWahanaDimiliki, idxOld));
		TotalNaik(W) = TotalNaik(ElmtWahana(ListWahanaDimiliki, idxOld));
		TotalProfit(W) = TotalProfit(ElmtWahana(ListWahanaDimiliki, idxOld));
		TodayNaik(W) = 0;
		TodayProfit(W) = 0;

		ElmtWahana(ListWahanaDimiliki, idxOld) = W;
	}
}

void executeBuy(Action A)
{
	printf("Execute Buy...\n");
	
	Kalimat NameOfAction = ActionName(A);
	Kata mat;
	DequeueKalimat(&NameOfAction, &mat);
	
	if (KataSama(mat, MATERIAL_WOOD))
		P.Material.wood += ActionAmount(A);
	else if(KataSama(mat, MATERIAL_IRON))
		P.Material.iron += ActionAmount(A);
	else
		P.Material.stone += ActionAmount(A);
}


void prepareToMain()
{
	if (!IsEmptyStackAction(S))
		printf ("// Tidak mengeksekusi perintah dari stack //\n");

	while (!IsEmptyStackAction(S))
	{
		Action A;
		PopAction(&S, &A); /*Kosongkan stack*/
	}
	

	P.CurrentTime = MakeJAM(9, 00, 00);

	MAINPHASE = true;
	P.Debt = 0;
	RandomAntrian();
}


// // MAIN PHASE
// // ================================================================
// void Serve(Kalimat Namawahana)
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


int IdxBrokenWahanSekitar(POINT P)
{
	boolean found = false;
	int i = 0;
	while (i < NbWahanaDimiliki && !found)
	{
		POINT P2 = MakePOINT(Absis(P)+1, Ordinat(P), Area(P));
		POINT P4 = MakePOINT(Absis(P)-1, Ordinat(P), Area(P));

		POINT PW = Lokasi(ElmtWahana(ListWahanaDimiliki, i));

		if (EQ(PW, P2) && !Condition(ElmtWahana(ListWahanaDimiliki, i)))
			found = true;
		else if (EQ(PW, P4) && !Condition(ElmtWahana(ListWahanaDimiliki, i)))
			found = true;
		else
			i++;
	}

	if (!found)
		return -1;
	else
		return i;
}


void repair()
{
	printf("Repair\n");

	int idx = IdxBrokenWahanSekitar(P.Position);

	if (idx != -1)
    {
		if (P.Money - REPAIR_COST < 0)
		{
			printf("Uang anda tidak cukup untuk melakukan repair!!\n");
			return;
		}
        printf("Memperbaiki ");
		PrintKalimat(Nama(ElmtWahana(ListWahanaDimiliki, idx)));
		printf("\n");
            
        Condition(ElmtWahana(ListWahanaDimiliki, idx)) = true;
		Money(P) -= REPAIR_COST;
		Time(P) = NextNDetik(Time(P), TIME_REPAIR*60);
        
    }
    else
    {
        printf("Tidak ada wahana yang rusak disekitar anda!!\n");
    }
}

void detail()
{
	int idx = IdxWahanaSekitar(P.Position);

	if (idx == -1)
	{
		printf("Tidak Ada Wahana di sekitar player!!\n");
		return;
	}

    printf("Nama Wahana: ");
	PrintKalimat(Nama(ElmtWahana(ListWahanaDimiliki, idx)));
	printf("\n");
    printf("Lokasi Wahana: ");
	PrintVertex(Lokasi(ElmtWahana(ListWahanaDimiliki, idx)));
	printf("\n");
    if(Condition(ElmtWahana(ListWahanaDimiliki, idx)))
		printf("Status : Berfungsi\n");
	else
		printf("Status : Rusak\n");
}

boolean IsOfficePosition(int A, float X, float Y)
{
	return Area(officePosition) == A && Absis(officePosition) == X && Ordinat(officePosition) == Y;
}

void office()
{
	printf("Office\n");
	POINT tmp = P.Position;
	if (EQ(P.Position, officePosition))
	{
		OFFICE_MODE = true;
		InOffice();
	}
	else
	{
		printf("Tidak Berada di sekitar Office!!\n");
	}
}

void InOffice()
{
	while(OFFICE_MODE)
	{
		printf("Masukkan perintah (Details/ Report / Exit) : ");
		Kalimat input = GetKalimat();

		Kata K;
		DequeueKalimat(&input, &K);

		if (KataSama(K, EXITS))
		{	
			printf("Exit dari Office");
			OFFICE_MODE= false;
		}
		else if (KataSama(K, DETAILS) || KataSama(K, REPORT))
		{
			printf("\nInfo wahana apa yang ingin Anda lihat: ");

			Kalimat nama = GetKalimat();
			WAHANA Wahana;
			int i = 0;
			boolean found = false;
			while (!found && i <= NbWahanaDimiliki)
			{
				if (IsEQKalimat(nama, Nama(ElmtWahana(ListWahanaDimiliki, i))))
				{
					found = true;
					Wahana = ElmtWahana(ListWahanaDimiliki, i);
				}
				else
				{
					i++;
				}
				
			}

			if (!found)
			{
				printf("Detail Wahana tidak ditemukan!!\n");
			}
			else
			{
				if (KataSama(K, DETAILS))
					DetailFromWahana(Wahana);
				else
					ReportFromWahana(Wahana);
				
				printf("\n");
			}
		}
		else
		{
			printf("Perintah tidak ada!!\n");
		}
	}
}


void DetailFromWahana(WAHANA Wahana)
{
    printf("Nama Wahana : ");
	PrintKalimat(Nama(Wahana));
	printf("\n");
    printf("Tipe Wahana: %d\n", Tipe(Wahana));
    if (Condition(Wahana))
    {
        printf("Kondisi Wahana: Tidak rusak");
    }
    else
    {
        printf("Kondisi Wahana: Rusak");   
    }

    printf("Biaya Pembangunan: %d\n", Price(Wahana));
    printf("Keperluan Kayu: %d\n", Wood(Wahana.MaterialCost));
    printf("Keperluan Batuan: %d\n", Stone(Wahana.MaterialCost));
    printf("Keperluan Besi: %d\n", Iron(Wahana.MaterialCost));
    printf("Lokasi Wahana: ");
	PrintVertex(Lokasi(Wahana));
	printf("\n");
    printf("Kapasitas Isi Wahana: %d\n", Kapasitas(Wahana));
    printf("Durasi Wahana: %d\n", PlayTime(Wahana));
    printf("Keuntungan tiap pelanggan: %d\n", Profit(Wahana));
    printf("Deskripsi Wahana: ");
	PrintKalimat(Deskripsi(Wahana));
	printf("\n");
    printf("Total penggunaan: %d\n", TotalNaik(Wahana));
    printf("Total keuntungan: %d\n", TotalProfit(Wahana));
    printf("Penggunaan hari ini: %d\n", TodayNaik(Wahana));
    printf("keuntungan hari ini: %d\n", TodayProfit(Wahana));
}


void ReportFromWahana(WAHANA Wahana)
{
    printf("Total Jumlah Pengunjung: %d\n", TotalNaik(Wahana));
    printf("Total Penghasilan: %d\n", TotalProfit(Wahana));
    printf("Total Jumlah Pengunjung Hari Ini: %d\n", TodayNaik(Wahana));
    printf("Total Jumlah Pengunjung Hari Ini: %d\n", TodayProfit(Wahana));
}


void mainToPrepare()
{
	MAINPHASE = false;
	CreateEmptyStackAction(&S);
	
	while(!IsEmptyQueueAntrian(A))
	{
		Antrian X;
		DequeueAntrian(&A, &X);
	}

	P.Day += 1;
	P.CurrentTime = MakeJAM(21, 0, 0);

	printf("Preparation Phase!!\n");
}



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




void RandomAntrian()
{	
	if (NbWahanaDimiliki != 0)
	{
		int minimum_number = 0, max_number = NbWahanaDimiliki-1;
		srand(time(0));

		for (int i = 0; i < 5; ++i)
		{
			int idxWahana = rand() % (max_number + 1 - minimum_number) + minimum_number;
			
			Antrian Q;
			InfoAntrian(Q) = Nama(ElmtWahana(ListWahanaDimiliki, idxWahana));
			PrioAntrian(Q) = 0;

			EnqueueAntrian(&A, Q);
		}
	}
}

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

void UnderScoreToSpasi(char *S, int max)
{
	int i = 0;
	while(S[i] != '\0' && i < max)
	{
		if (S[i] == '_')
			S[i] = ' ';
		
		i++;
	}
}


ArrayWahana ReadWahanaInfo(char dir[])
{
    FILE *fp = fopen(dir,"r");

    if (fp == NULL) {
        printf("Error, could not load .txt file!\n");
        exit(1);
    }

    ArrayWahana W;
    MakeEmptyWahana(&W);
    WAHANA X;

    char Nama[100];
    char Uang[16];
    char Wood[16];
    char Stone[16];
    char Iron[16];
    //char Mamank[16];
    char Kapasitas[16];
    char Durasi[32];
    char Profit[16];
    char Deskripsi[250];
    
    int countLine = 1;
    int tipeCount = 1;

    while(fscanf(fp, "%s %s %s %s %s %s %s %s %s", &Nama, &Uang, &Wood, &Stone, &Iron, &Kapasitas, &Durasi, &Profit, &Deskripsi) != EOF) {
        if (countLine >= 2)
        {
			UnderScoreToSpasi(Nama, 100);
			UnderScoreToSpasi(Deskripsi, 250);
			
            Nama(X) = SetKalimat(Nama);
            Tipe(X) = tipeCount;
            Price(X) = atoi(Uang);
            Wood(MaterialCost(X)) = atoi(Wood);
            Stone(MaterialCost(X)) = atoi(Stone);
            Iron(MaterialCost(X)) = atoi(Iron);
            //Mamank(MaterialCost(X)) = atoi(Mamank);
            Kapasitas(X) = atoi(Kapasitas);
            PlayTime(X) = atoi(Durasi);       // Konversi ke detik dulu mungkin, sekarang baru konversi ke integer, value di file detik
            Profit(X) = atoi(Profit);
            Deskripsi(X) = SetKalimat(Deskripsi);
            
            Lokasi(X) = MakePOINT(10,10,1); // Value Null utk lokasi wahana
			TotalNaik(X) = 0;
            TotalProfit(X) = 0;
            TodayNaik(X) = 0;
            TodayProfit(X) = 0;
            
            AddAsLastElWahana(&W, X);

			// PrintKalimat(X.Deskripsi);
			// printf("\n");
            ++tipeCount;
        }
        else
        {
            ++countLine;
        }
    }

	fclose(fp);

    return W;
}

void generateMapMain()
{
	JAM buka, tutup;
    buka = MakeJAM(9,00,00);
	tutup = MakeJAM(21, 00, 00);

	// if (MAINPHASE && IsEmptyQueueAntrian(A))
	// 	RandomAntrian();

	// if(JAMToDetik(Time(P)) - JAMToDetik(tutup) >= 0 && MAINPHASE)
	// {
	// 	mainToPrepare();
	// }
	// else if (Hour(Time(P)) >= 9 && JLT(Time(P), tutup) && JAMToDetik(Time(P)) - JAMToDetik(buka) >= 0 && !MAINPHASE)
	// {
	// 	prepareToMain();
	// }

	boolean Maen = JAMToDetik(Time(P)) < JAMToDetik(tutup) && JAMToDetik(Time(P)) >= JAMToDetik(buka);

	printf("\n\n");
    if(Maen){
        printf("MAIN PHASE DAY %d\n",Day(P));
    }
    else{
        printf("PREPARATION PHASE DAY %d\n",Day(P));
    }

    /*generating map */
    PrintMap(P);

    printf("\n");
	
	printf("Legend :\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("<, ^, v, > = Gerbang\n");
    printf("\n");
    printf("Name : ");
	PrintKalimat(P.Name);
	printf("\n");
    printf("Money : %d \n",Money(P));
    printf("Current time : ");
    TulisJAM(Time(P));
    printf("\n");

    if(Maen){
        printf("Closing time : ");
        TulisJAM(tutup);
        printf("\n");
        printf("Time remaining : ");
        CetakDurasi(Durasi(Time(P), tutup));
        printf("\n");
        /* buat prosedur print antrian */
    }
    else{
        printf("Opening time : ");
        TulisJAM(buka);
        printf("\n");
        printf("Time remaining : ");
        CetakDurasi(Durasi(Time(P),buka));
        printf("\n");
        printf("Jumlah aksi yang akan dilakukan : %d\n",(NbElmtStackAction(S)));
        printf("Total waktu yang dibutuhkan : %d", TotalTimeAction(S)); 
        printf("\n");
        printf("Total uang yang dibutuhkan : %d", P.Debt);
		printf("\n");
    }
    
    
    // if(JLT(Time(P),tutup) && JGT(Time(P),buka)){
    //     printf("Closing time : ");
    //     TulisJAM(tutup);
    //     printf("\n");
    // }

	if (MAINPHASE && NbElmtWahana(ListWahanaDimiliki) != 0)
	{
		printf("\n");
		PrintQueueAntrian(A);
		printf("\n");
	}

	printf("\n");
	if (IsAdaBroken())
	{
		PrintBrokenWahana();
	}
	printf("\n");
	if (IsOfficePosition(Area(P.Position), Absis(P.Position), Ordinat(P.Position)))
		printf("Masukkan Perintah (Masukkan 'office' untuk mengakses office) : ");
	else
		printf("Masukkan perintah : ");   
}


boolean IsAdaBroken()
{
	boolean found = false;
	int i = 0;
	while (i < NbWahanaDimiliki && !found)
	{
		if (!Condition(ElmtWahana(ListWahanaDimiliki, i)))
			found = true;
		else
			i++;
	}

	return found;
}

void PrintBrokenWahana()
{
	printf("Broken : ");
	for (int i = 0; i < NbWahanaDimiliki; i++)
	{
		if (!Condition(ElmtWahana(ListWahanaDimiliki, i)))
		{
			PrintKalimat(Nama(ElmtWahana(ListWahanaDimiliki, i)));
			printf(" | ");
		}
	}

	printf("\n");
}


boolean IsAntrianPosition(POINT P)
{
	return EQ(AntrianPosition, P);
}


boolean IsWahanaPosition(POINT P)
{
	boolean found = false;
	int i = 0;
	while (i < NbWahanaDimiliki && !found)
	{
		if (EQ(P, Lokasi(ElmtWahana(ListWahanaDimiliki, i))))
			found = true;
		else
			i++;
	}
		
	return found;
}

void PrintMap()
{
	int area = Area(P.Position);
	
	// Y
	for (int i = 0; i < MAX_SIZE_MAP; i++)
	{
		// X
		for (int j = 0; j < MAX_SIZE_MAP; j++)
		{
			POINT segment = MakePOINT((float)j, (float)i, area);

			if (EQ(segment, P.Position))
				printf("P");
			else if (IsWahanaPosition(segment))
			{
				printf("W");
			}
			else if (IsOfficePosition(Area(segment), Absis(segment), Ordinat(segment)))
			{
				printf("O");
			}
			else if (IsAntrianPosition(segment))
			{
				printf("A");
			}
			else if (IsWall(Absis(segment), Ordinat(segment), Area(segment)))
			{
				printf("*");
			}
			else if (IsGerbang(Absis(segment), Ordinat(segment), Area(segment)) && i == 0)
			{
				printf("^");
			}
			else if (IsGerbang(Absis(segment), Ordinat(segment), Area(segment)) && j == 0)
			{
				printf("<");
			}
			else if (IsGerbang(Absis(segment), Ordinat(segment), Area(segment)) && i == 19)
			{
				printf("v");
			}
			else if (IsGerbang(Absis(segment), Ordinat(segment), Area(segment)) && j == 19)
			{
				printf(">");
			}
			else if (IsGerbang(Absis(segment), Ordinat(segment), Area(segment)) && i == 19)
			{
				printf("v");
			}
			else if (IsGerbang(Absis(segment), Ordinat(segment), Area(segment)) && j == 19)
			{
				printf(">");
			}
			else
			{
				printf("-");
			}
		}
		printf("\n");
	}	
}