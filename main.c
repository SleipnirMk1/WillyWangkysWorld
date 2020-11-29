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

int MAX_KESABARAN = 5;
int MAX_ANTRIAN = 5;


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
void RandomBroken(int idxWahana);
void PrintInfoPlayer();

void AntrianEmosiRising();

void KalimatToChar(Kalimat K, char *S);
void SpasiToUnderScore(char *S, int Max);
void savePlayer(char dir[]);
void saveWahana(char dir[]);

// ==============================================

int main()
{
	// PERSIAPANGAME();

	// CreateEmptyStackAction(&S);
	// MakeEmptyQueueAntrian(&A, 100);

	// generateAllConstant();

	generatePlayer();
	generateWahanaTersedia();
	generateWahanaYangDimiliki();

	// generateListMaterial();

	//printf("%f\n", P.Position.Y);
	// generatePosFromFile();
	// generateMatFromFile();
	// generateWahFromFile();
	// generateStaFromFile();

	
	// Tree T = generateWahanaUpgradeTree();
	// PrintTreeIndent(T, 2);

	saveGame();


	RUN = false;
	RUN_NEWGAME = false;
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
			RandomAntrian();
		}
		else if (KataSama(K, MoveA))
		{
			move(1);
			RandomAntrian();
		}
		else if (KataSama(K, MoveS))
		{
			move(2);
			RandomAntrian();
		}
		else if (KataSama(K, MoveD))
		{
			move(3);
			RandomAntrian();
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
					serve(input);
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
	P.Name = SetKalimat("Alstrukdat KWWW");

	Area(P.Position) = 1;
 	Absis(P.Position) = 4;
	Ordinat(P.Position) = 10;

	P.Money = 99999;
	MoneyDebt(P) = 0;

	P.Material.wood = 50;
	P.Material.iron = 50;
	P.Material.stone = 50;

	MaterialDebt(P).wood = 0;
	MaterialDebt(P).stone = 0;
	MaterialDebt(P).iron = 0;

	P.CurrentTime = MakeJAM(21, 0, 0);
	P.Day = 2;
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
				RandomAntrian();
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
				RandomAntrian();
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
				RandomAntrian();
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
				RandomAntrian();
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
void saveGame()
{
	printf("Saving...\n");
	savePlayer("save/playerSave.txt"); 
	saveWahana("save/wahanaSave.txt");
}

// void loadGame()
// {
// 	loadPlayer("save/playerSave.txt");
// 	loadWahana("save/wahanaSave.txt");
// }

void savePlayer(char dir[])
{
	FILE *f;
	f = fopen(dir, "w");
	

	if (f != NULL)
	{
		printf("Saving Player Data...\n");
		
		char name[250]; 
		KalimatToChar(P.Name, name);
		SpasiToUnderScore(name, 250);

		char Curr[20];
		sprintf(Curr, "%d", JAMToDetik(P.CurrentTime));

		char day[10];
		sprintf(day, "%d", P.Day);

		char posX[20];
		sprintf(posX, "%.0f", P.Position.X);
		char posY[20];
		sprintf(posY, "%.0f", P.Position.Y);
		char posA[20];
		sprintf(posA, "%d", P.Position.A);

		char money[10];
		sprintf(money, "%d", P.Money);

		char moneyDebt[10];
		sprintf(moneyDebt, "%d", P.MoneyDebt);

		char matWood[10];
		sprintf(matWood, "%d", P.Material.wood);
		char matStone[10];
		sprintf(matStone, "%d", P.Material.stone);
		char matIron[10];
		sprintf(matIron, "%d", P.Material.iron);

		char matDebtWood[10];
		sprintf(matDebtWood, "%d", P.MaterialDebt.wood);
		char matDebtStone[10];
		sprintf(matDebtStone, "%d", P.MaterialDebt.stone);
		char matDebtIron[10];
		sprintf(matDebtIron, "%d", P.MaterialDebt.iron);

		fputs(name, f);fputs(" ", f);
		
		fputs(Curr, f);fputs(" ", f);

		fputs(day, f);fputs(" ", f);
		
		fputs(posX, f);fputs(" ", f);

		fputs(posY, f);fputs(" ", f);

		fputs(posA, f);fputs(" ", f);

		fputs(money, f);fputs(" ", f);

		fputs(moneyDebt, f);fputs(" ", f);

		fputs(matWood, f);fputs(" ", f);
		fputs(matStone, f);fputs(" ", f);
		fputs(matIron, f);fputs(" ", f);

		fputs(matDebtWood, f);fputs(" ", f);
		fputs(matDebtStone, f);fputs(" ", f);
		fputs(matDebtIron, f);fputs("\n", f);
	}

	fclose(f);
}

void KalimatToChar(Kalimat K, char *S)
{
	int n = NbKata(K);
	
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		Kata kata;
		DequeueKalimat(&K, &kata);
		int j = 0;
		while (j < kata.Length && c < 250)
		{
			S[c++] = kata.TabKata[j++];
		}

		if(i != n-1)
			S[c++] = ' ';
	}
	S[c++] = '\0';
}

void SpasiToUnderScore(char *S, int Max)
{
	int i = 0;
	while(i < Max && S[i] != '\0')
	{
		if (S[i] == ' ')
			S[i] = '_';
		
		i++;
	}
}

void saveWahana(char dir[])
{
	FILE *f;
	f = fopen(dir, "w");
	
	
	if (f == NULL)
	{
		fclose(f);
		return;
	}

	printf("Saving Wahana Data...\n");
	for (int i = 0; i < NbElmtWahana(ListWahanaDimiliki); i++)
	{
		int type = Tipe(ElmtWahana(ListWahanaDimiliki, i));
		int cond = Condition(ElmtWahana(ListWahanaDimiliki, i));

		float posX = Lokasi(ElmtWahana(ListWahanaDimiliki, i)).X;
		float posY = Lokasi(ElmtWahana(ListWahanaDimiliki, i)).Y;
		int posA = Lokasi(ElmtWahana(ListWahanaDimiliki, i)).A;

		int usedamout = TotalNaik(ElmtWahana(ListWahanaDimiliki, i));
		int totProfit = TodayProfit(ElmtWahana(ListWahanaDimiliki, i));
		int usedtoday = TodayNaik(ElmtWahana(ListWahanaDimiliki, i));
		int profittoday = TodayProfit(ElmtWahana(ListWahanaDimiliki, i));


		char tipe[20];
		sprintf(tipe, "%d", type);

		char xpos[20];
		sprintf(xpos, "%d", (int)posX);
		char ypos[20];
		sprintf(ypos, "%d", (int)posY);
		char apos[20];
		sprintf(apos, "%d", (int)posA);

		char naikTotal[20];
		sprintf(naikTotal, "%d", usedamout);
		char profTotal[20];
		sprintf(profTotal, "%d", totProfit);
		char todayNaik[20];
		sprintf(todayNaik, "%d", usedtoday);
		char todayProfit[20];
		sprintf(todayProfit, "%d", profittoday);

		fputs(tipe, f); fputs(" ", f);
		fputs(xpos, f); fputs(" ", f);
		fputs(ypos, f); fputs(" ", f);
		fputs(apos, f); fputs(" ", f);
		fputs(naikTotal, f); fputs(" ", f);
		fputs(profTotal, f); fputs(" ", f);
		fputs(todayNaik, f); fputs(" ", f);
		fputs(todayProfit, f); fputs("\n", f);
	}
	

	fclose(f);
}


void saveAntrian(char dir[])
{
	if (!MAINPHASE)
		return;
	
	FILE *f; 
	f = open(dir, "w");

	if (f == NULL)
		return;

	printf("\nSaving Antrian...\n");

	QueueAntrian tmp = A;
	int n = NBElmtQueueAntrian(A);

	for (int i = 0; i < n; i++)
	{
		Antrian e;
		DequeueAntrian(&A, &e);
		
		int prio = e.prio;
		char pri[5];
		sprintf(pri, "%d", prio);

		fputs(pri, f); fputs(" ", f);

		for (int j = 0; j < NbElmtWahana(ListWahanaDimiliki); j++)
		{
			if (SearchBWahana(e.info, Tipe(ElmtWahana(ListWahanaDimiliki, i))))
			{
				fputs("1", f);
			}
			else
			{
				fputs("0", f);
			}

			if (j != NbElmtWahana(ListWahanaDimiliki)-1)
				fputs(" ", f);	
		}
		if (i != n-1)
			fputs("\n", f);
	}

	fclose(f);
}

void saveStack(char dir[])
{
	if (MAINPHASE)
		return;
	
	FILE *f; 
	f = open(dir, "w");

	if (f == NULL)
		return;

	printf("\nSaving Antrian...\n");

	StackAction tmp = S;
	
	StackAction tmp;
	CreateEmptyStackAction(&tmp);

	while(!IsEmptyStackAction(tmp))
	{
		Action a;
		PopAction(&tmp, &a);
		
		char name[250];
		KalimatToChar(ActionName(a), name);
		SpasiToUnderScore(name, 250);

		char type[20];
		for (int i = 0; i < ActionType(a).Length; i++)
		{
			type[i] = ActionType(a).TabKata[i];
		}
		type[ActionType(a).Length] = '\0';

		char time[20];
		sprintf(time, "%d", ActionTime(a));
		char amount[20];
		sprintf(amount, "%d", ActionAmount(a));
		char price[20];
		sprintf(price, "%d", ActionPrice(a));

		char matWood[20];
		sprintf(matWood, "%d", ActionMaterialCost(a).wood);
		char matStone[20];
		sprintf(matStone, "%d", ActionMaterialCost(a).stone);
		char matIron[20];
		sprintf(matIron, "%d", ActionMaterialCost(a).iron);
		
		char posx[20];
		sprintf(posx, "%d", (int)ActionPosition(a).X);
		char posy[20];
		sprintf(posy, "%d", (int)ActionPosition(a).Y);
		char posa[20];
		sprintf(posa, "%d", (int)ActionPosition(a).A);

		fputs(name, f); fputs(" ", f);
		fputs(type, f); fputs(" ", f);
		fputs(time, f); fputs(" ", f);
		fputs(amount, f); fputs(" ", f);
		fputs(price, f); fputs(" ", f);
		fputs(matWood, f); fputs(" ", f);
		fputs(matStone, f); fputs(" ", f);
		fputs(matIron, f); fputs(" ", f);
		fputs(posx, f); fputs(" ", f);
		fputs(posy, f); fputs(" ", f);
		fputs(posa, f); fputs("\n", f);
	}

	fclose(f);
}



void loadPlayer(char dir[])
{
	FILE *f;
	f = open(dir, "r");

	if (f == NULL)
	{
		printf("\nFile Not Found..\n");
		return;
	}

	
	char name[250];
	char time[20];
	char day[20];
	char posx[20];
	char posy[20];
	char posa[20];
	char money[20];
	char moneyDebt[20];
	char matWood[20];
	char matStone[20];
	char matIron[20];
	char matDebtWood[20];
	char matDebtStone[20];
	char matDebtIron[20];

	while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s", name, time, day, posx, posy, posa, money, moneyDebt, matWood, matStone, matIron, matDebtWood, matDebtStone, matDebtIron) != EOF)
	{
		UnderScoreToSpasi(name, 250);
		P.Name = SetKalimat(name);

		P.CurrentTime = DetikToJAM(atoi(time));
		P.Day = atoi(day);
		P.Position = MakePOINT((float)atoi(posx), (float)atoi(posy), atoi(posa));
		P.Money = atoi(money);
		P.MoneyDebt = atoi(moneyDebt);
		P.Material.wood = atoi(matWood);
		P.Material.stone = atoi(matStone);
		P.Material.iron = atoi(matIron);

		P.MaterialDebt.wood = atoi(matDebtWood);
		P.MaterialDebt.stone = atoi(matDebtStone);
		P.MaterialDebt.iron = atoi(matDebtIron);
	}

	fclose(f);
}

void loadWahana(char dir[])
{
	FILE *f;
	f = open(dir, "r");

	if (f == NULL)
	{
		printf("\nFile Not Found..\n");
		return;
	}

	char tipe[20];
	char xpos[20];
	char ypos[20];
	char apos[20];
	char naikTotal[20];
	char profTotal[20];
	char todayNaik[20];
	char todayProfit[20];
	
	int count = 0;

	ArrayWahana tmp;
	MakeEmptyWahana(&tmp);

	while(fscanf(f, "%s %s %s %s %s %s %s %s", tipe, xpos, ypos, apos, naikTotal, profTotal, todayNaik, todayProfit) != EOF)
	{
		int idxWahana = atoi(tipe)-1;

		WAHANA W = ElmtWahana(ListWahanaTersedia, idxWahana);

		W.Position = MakePOINT((float)atoi(xpos), (float)atoi(ypos), atoi(apos));

		W.UsedAmount = atoi(naikTotal);
		W.TotalProfit = atoi(profTotal);
		W.UsedToday = atoi(todayNaik);
		W.ProfitToday = atoi(todayProfit);

		AddAsLastElWahana(&tmp, W);
		count++;
	}

	if (count != 0)
	{
		ListWahanaDimiliki = tmp;
	}

	fclose(f);
}



void loadAntrian(char dir)
{
	FILE *f;
	f = open(dir, "r");

	if (f == NULL)
	{
		printf("\nFile Not Found..\n");
		return;
	}
}




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
	boolean can = 
	(
		Money(P) >= MoneyDebt(P) + Price(W) && 
		Material(P).wood >= MaterialDebt(P).wood + MaterialCost(W).wood &&
		Material(P).stone >= MaterialDebt(P).stone + MaterialCost(W).stone &&
		Material(P).iron >= MaterialDebt(P).iron + MaterialCost(W).iron
	);

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

	Tree T = generateWahanaUpgradeTree();

	if (Right(T) == NilTree || Left(T) == NilTree)
	{
		printf("\nTidak Ada Wahana Yang Dapat Dibangun!!\n");
		return;
	}

	int Target1 = Info(Left(T)) - 1;
	int Target2 = Info(Right(T)) - 1;

	boolean build = true;
	while(build)
	{
		printf("\nWahana Yang dapat dibangun : \n");
		printf("List : \n");
		printf("	- ");
		PrintKalimat(Nama(ElmtWahana(ListWahanaTersedia, Target1)));
		printf("\n");
		printf("	- ");
		PrintKalimat(Nama(ElmtWahana(ListWahanaTersedia, Target2)));
		printf("\n");
		
		printf("\nMasukkan Nama Wahana ('exit' untuk membatalkan build) : ");

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
			Kalimat K1 = Nama(ElmtWahana(ListWahanaTersedia, Target1));
			Kalimat K2 = Nama(ElmtWahana(ListWahanaTersedia, Target2));

			boolean available = false;
			int i = 0;
			if (IsEQKalimat(K1, K))
			{
				available = true;
				i = Target1;
			}
			else if (IsEQKalimat(K2, K))
			{
				available = true;
				i = Target2;
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

					P.MaterialDebt.wood += ActionMaterialCost(A).wood;
					P.MaterialDebt.stone += ActionMaterialCost(A).stone;
					P.MaterialDebt.iron += ActionMaterialCost(A).iron;

					PushAction(&S, A);

					MoneyDebt(P) += ListWahanaTersedia.TI[i].PriceCost;

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
	Tree W = BuildBalanceTree(NbElmtWahana(ListWahanaTersedia)+1, &info);
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
		
		MaterialDebt(P).wood += ActionMaterialCost(A).wood;
		MaterialDebt(P).stone += ActionMaterialCost(A).stone;
		MaterialDebt(P).iron += ActionMaterialCost(A).iron; 

		MoneyDebt(P) += Price(ElmtWahana(T_all_wahana, TargetUpgrade));

		PushAction(&S, A);	// Push ke stack

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

	if (i != -1 && P.Money >= MoneyDebt(P) + totalHarga && IsMasihAdaWaktu(TIME_BUY))
	{
		/* memasukkan ke stack */
		Action X;
		//JAM J;
		/* (masih pemisalan) membeli 1 material membutuhkan waktu 5 menit */
		//int lama = 5*KataToInteger(banyak);
		ActionName(X) = SetKalimat(nama.TabKata);
		SetKata(&ActionType(X), "buy");
		ActionTime(X)= TIME_BUY;
		ActionAmount(X) = KataToInteger(banyak);
		ActionPrice(X) = totalHarga;
		ActionPosition(X) = P.Position;
		MoneyDebt(P) += totalHarga;

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

	MoneyDebt(P) -= ActionPrice(A);

	if (KataSama(ACTION_BUILD, ActionType(A)) || KataSama(ACTION_UPGRADE, ActionType(A)))
	{
		MaterialDebt(P).wood -= ActionMaterialCost(A).wood;
		MaterialDebt(P).stone -= ActionMaterialCost(A).stone;
		MaterialDebt(P).iron -= ActionMaterialCost(A).iron;
	}

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

	Money(P) -= MoneyDebt(P);
	MoneyDebt(P) = 0;

	Material(P).wood -= MaterialDebt(P).wood;
	Material(P).stone -= MaterialDebt(P).stone;
	Material(P).iron -= MaterialDebt(P).iron;
	
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
	TotalNaik(W) = 0;
	TotalProfit(W) = 0;
	TodayNaik(W) = 0;
	TodayProfit(W) = 0;

	AddAsLastElWahana(&ListWahanaDimiliki, W);

	NbWahanaDimiliki += 1;

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
	MoneyDebt(P) = 0;

	RandomAntrian();
}


// // MAIN PHASE
// // ================================================================
/* ketika command serve di input langsung memnaggil prosedur serve */
/* nama wahana di input di prosedur serve */

void serve(Kalimat inputnamaWahana)
{
	POINT t = P.Position;
	if 
	(
		!IsAntrianPosition(MakePOINT(t.X+1, t.Y, t.A)) && 
		!IsAntrianPosition(MakePOINT(t.X, t.Y+1, t.A)) &&
		!IsAntrianPosition(MakePOINT(t.X-1, t.Y, t.A)) &&
		!IsAntrianPosition(MakePOINT(t.X, t.Y-1, t.A))
	)
	{
		printf("\nPlayer Tidak Berada di Sekitar Antrian\n");
		return;
	}

	if (IsEmptyQueueAntrian(A))
	{
		printf("\nAntrian Sedang Kosong!!\n");
		return;
	}

    /* Antiran punya posisition ? */
    /* pengecekan apakah player di dekat antrian belum */
    int idxWahanaDimiliki = 0;
    boolean adaWahana = false;
    while ((idxWahanaDimiliki<NbWahanaDimiliki) && !(adaWahana))
	{
        if(IsEQKalimat(inputnamaWahana, Nama(ElmtWahana(ListWahanaDimiliki, idxWahanaDimiliki))))
		{
            adaWahana = true;
        }
        else{
            idxWahanaDimiliki++;
        }
    }

	if (adaWahana && !Condition(ElmtWahana(ListWahanaDimiliki, idxWahanaDimiliki)))
	{
		printf("\nWahana Sedang Rusak!!\n");
		return;
	}

	if (adaWahana && Condition(ElmtWahana(ListWahanaDimiliki, idxWahanaDimiliki)))
	{
		
		Antrian e = Elmt(A, A.HEAD);
		ArrayWahana W = e.info;
		
		int idxWahanaAntrian = 0;
		boolean adaAntrian = false;
		while ((idxWahanaAntrian<NbElmtWahana(W)) && !(adaAntrian))
		{
			if(IsEQKalimat(inputnamaWahana, Nama(ElmtWahana(W, idxWahanaAntrian))))
			{
				adaAntrian = true;
			}
			else{
				idxWahanaAntrian++;
			}
		}

		if (adaAntrian)
		{
			//TulisIsiTabWahana(W);
			addMoney(&P, Profit(ElmtWahana(ListWahanaDimiliki, idxWahanaDimiliki)));
			TotalNaik(ElmtWahana(ListWahanaDimiliki, idxWahanaDimiliki)) += 1;
			TotalProfit(ElmtWahana(ListWahanaDimiliki, idxWahanaDimiliki)) += Profit(ElmtWahana(ListWahanaDimiliki, idxWahanaDimiliki));
			TodayNaik(ElmtWahana(ListWahanaDimiliki, idxWahanaDimiliki)) += 1;
			TodayProfit(ElmtWahana(ListWahanaDimiliki, idxWahanaDimiliki)) += Profit(ElmtWahana(ListWahanaDimiliki, idxWahanaDimiliki));
			addTime(&P, (long) PlayTime(ElmtWahana(ListWahanaDimiliki, idxWahanaDimiliki)));

			MoveLeftToIdx(&W, idxWahanaAntrian);

			DequeueAntrian(&A, &e);
			
			if (NbElmtWahana(W) != 0)
			{
				InfoAntrian(e) = W;
				PrioAntrian(e) -= 1;

				if (PrioAntrian(e) > 0)
					EnqueueAntrian(&A, e);
			}

			printf("\nServing ");
			PrintKalimat(inputnamaWahana);
			printf(" ...\n");

			RandomBroken(idxWahanaDimiliki);
		}
		else
		{
			printf("\nTidak ada Antrian yang dimaksud\n");
		}
	}
	else
	{
		printf("\nTidak ada Antrian yang dimaksud\n");
	}
}


void AntrianEmosiRising()
{
	if(NBElmtQueueAntrian(A) == 0 && !MAINPHASE)
		return;

	QueueAntrian tmp;
	MakeEmptyQueueAntrian(&tmp, 100);

	while(!IsEmptyQueueAntrian(A))
	{
		Antrian e;
		DequeueAntrian(&A, &e);
		PrioAntrian(e) -= 1;

		if (PrioAntrian(e) > 0)
		{
			EnqueueAntrian(&tmp, e);
		}
	}
	
	//PrintQueueAntrian(tmp);
	A = tmp;
}


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

		AntrianEmosiRising();
		RandomAntrian();
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
	
	AntrianEmosiRising();
	RandomAntrian();
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

			AntrianEmosiRising();
			RandomAntrian();
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
	if (NbWahanaDimiliki != 0 && NBElmtQueueAntrian(A) < MAX_ANTRIAN && MAINPHASE)
	{
		int minAntrianWahana = 1;
		int maxAntrianWahana = NbWahanaDimiliki;
		int MinNumber = 1;
		int MaxNumber = 10;
		
		srand(time(0));
		int adaAntri = rand() % (MaxNumber + 1 - MinNumber) + MinNumber;
		if (adaAntri > 3)
			return;
		
		srand(time(0));
		int n = rand() % (maxAntrianWahana + 1 - minAntrianWahana) + minAntrianWahana;
		printf("\n== Ada Antrian Masuk ==\n");

		if (n != 0)
		{
			ArrayWahana W;
			MakeEmptyWahana(&W);

			int i = 0;
			while(i < n)
			{
				int minimum_number = 0, max_number = NbWahanaDimiliki-1;
				
				srand(time(0));
				int idxWahana = rand() % (max_number + 1 - minimum_number) + minimum_number;

				if (!SearchBWahana(W, Tipe(ElmtWahana(ListWahanaDimiliki, idxWahana))))
				{
					AddAsLastElWahana(&W, ElmtWahana(ListWahanaDimiliki, idxWahana));
					i++;
				}
			}

			Antrian e;
			PrioAntrian(e) = MAX_KESABARAN;
			InfoAntrian(e) = W;

			EnqueueAntrian(&A, e);
		}
	}
}

void RandomBroken(int idxWahana)
{
	int MinNumber = 1;
	int MaxNumber = 10;
	srand(time(0));

	int broke = rand() % (MaxNumber + 1 - MinNumber) + MinNumber;

	if (broke <= 1)
	{
		Condition(ElmtWahana(ListWahanaDimiliki, idxWahana)) = false;
		printf("\nWahana ");
		PrintKalimat(ElmtWahana(ListWahanaDimiliki, idxWahana).Name);
		printf(" Telah Rusak!!\n");
	}
}


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
        printf("Total uang yang dibutuhkan : %d", MoneyDebt(P));
		printf("\n");
    }
    
    
    // if(JLT(Time(P),tutup) && JGT(Time(P),buka)){
    //     printf("Closing time : ");
    //     TulisJAM(tutup);
    //     printf("\n");
    // }

	if (MAINPHASE && NbElmtWahana(ListWahanaDimiliki) != 0 && NBElmtQueueAntrian(A) != 0)
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