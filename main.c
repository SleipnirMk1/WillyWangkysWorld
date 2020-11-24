#include <stdio.h>
#include <stdlib.h>
#include "ADT\mesinkata\mesinkata.h"

boolean RUN = true;

boolean MAINPHASE = false;
int DAY;

Kata NEW, LOAD, EXIT;
Kata BUILD, UPGRADE, BUY, UNDO, EXECUTE, MAIN;
Kata SERVE, REPAIR, DETAIL, OFFICE, PREPARE;
Kata SAVE, CONTINUE;
Kata W, A, S, D;
Kata DETAILS;

Kata ACTION_BUILD, ACTION_UPGRADE, ACTION_BUY;

void generateAllConstant();
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

void move(int dir);

int main()
{
	generateAllConstant();

	// generatePosFromFile();
	// generateMatFromFile();
	// generateWahFromFile();
	// generateStaFromFile();

	RUN = true;

	printf("NEW // LOAD // EXIT\n");
	boolean runned = false;
	boolean inputNew = true;
	while(inputNew)
	{
		QueueKata input = GetQueueKata();
		Kata K;
		DequeueKata(&input, &K);
		
		if (KataSama(K, EXIT))
		{
			RUN = false;
			inputNew = false;
		}
		else if (KataSama(K, NEW))
		{
			generateNewGame();
			inputNew = false;
			runned = true;
		}
		else if (KataSama(K, LOAD))
		{
			generateLoadGame();
			inputNew = false;
			runned = true;
		}
		else
		{
			printf("Perintah yang anda masukkan tidak tersedia!!!\n");
		}
	}

	while(RUN)
	{
		printf("Masukkan Perintah : ");

		QueueKata input = GetQueueKata();
		Kata K;
		DequeueKata(&input, &K);
		
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
			saveGame();
		}
		else if (KataSama(K, CONTINUE))
		{
			conti();
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
					serve();
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

	if (runned)
	{
		printf("Masukkan 'y' jika ingin melakukan SAVE GAME : ");
		char yy;
		scanf("%c", &yy);
		if (yy == 'y')
			saveGame();
	}

	printf("\n");
	printf("Thanks For Playing!!!\n");

	return 0;
}


void move(int dir)
{
	printf("Move To %d\n", dir);
}


// ================================================================
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

void saveGame()
{
	printf("Save Game!!\n");
}

void conti()
{
	printf("Continue\n");
}


// PREPARATION PHASE
// ================================================================
void build()
{
	printf("Build\n");
}

void upgrade()
{
	printf("Upgrade\n");
}

void buy()
{
	printf("Buy\n");
}

void undo()
{
	printf("Undo\n");
}

void execute()
{
	printf("Execute\n");
	MAINPHASE = true;
}

void prepareToMain()
{
	MAINPHASE = true;
}


// MAIN PHASE
// ================================================================
void serve()
{
	printf("Serve\n");
}

void repair()
{
	printf("Repair\n");
}

void detail()
{
	printf("Detail\n");
}

void office()
{
	printf("Office\n");
}

void mainToPrepare()
{
	MAINPHASE = false;
}