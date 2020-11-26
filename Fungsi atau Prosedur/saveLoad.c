#include <stdio.h>
#include "ADT\mesinkata\mesinkata.h"

void savePlayer(char dir[]);
void loadPlayer(char dir[]);
void saveWahana(char dir[]);
void loadWahana(char dir[]);

void ItoS(char *S, int X, int *c);
void QtoS(char *S, QueueKata Q, int *c);
int NB(char S[]);


// Save and Load
//===================================================
void Save()
{
	savePlayer("save/playerSave.txt"); 
	saveWahana("save/wahanaSave.txt");
}

void Load()
{
	loadPlayer("save/playerSave.txt");
	loadWahana("save/wahanaSave.txt");
}

//===================================================


void savePlayer(char dir[])
{
	FILE *f;
	f = fopen(dir, "w");

	char wr[300];
	int c = 0;
	
	QtoS(wr, P.Name, &c);
	ItoS(wr, P.Money, &c);
	ItoS(wr, P.Wood, &c);
	ItoS(wr, P.Pos.Area, &c);
	ItoS(wr, P.Pos.x, &c);
	ItoS(wr, P.Pos.y, &c);

	
	printf("Saving Player Data...\n");
	if (c > 0 && f != NULL) 
	{ 
		fputs(wr, f);
		fputs("\n", f);
	}

	fclose(f);
}


void saveWahana(char dir[])
{
	FILE *f;
	f = fopen(dir, "w");
	printf("Saving Wahana Data...\n");
	for(int i = 0; i < NbWahana; i++)
	{
		char wr[300];
		int c = 0;

		QtoS(wr, W[i].Name, &c);
		ItoS(wr, W[i].Type, &c);
		ItoS(wr, W[i].Level, &c);
		ItoS(wr, W[i].Cost, &c);
		ItoS(wr, W[i].Pos.Area, &c);
		ItoS(wr, W[i].Pos.x, &c);
		ItoS(wr, W[i].Pos.y, &c);

		wr[c++] = '\0';


		if (c > 0 && f != NULL) 
		{ 
			fputs(wr, f);
			fputs("\n", f);
		}
	}

	fclose(f);
}



void loadPlayer(char dir[])
{
	FILE *f;
	f = fopen(dir, "r");

	if (f != NULL)
	{
		printf("Getting Player Data...\n");

		char wr[200];
		while( fgets ( wr, 200, f ) != NULL ) 
        { 
			char content[20];
			int x = 0;
			int j = 0;
			for (int i = 0; i < NB(wr); i++)
			{
				if (wr[i] != ',')
				{
					content[j++] = wr[i];
				}
				else
				{
					content[j++] = '\0';
					if (x == 0)
					{
						P.Name = SetQueueKata(content);
					}
					else if (x == 1)
					{
						int money;
						sscanf(content, "%d", &money);
						P.Money = money;
					}
					else if (x == 2)
					{
						int wood;
						sscanf(content, "%d", &wood);
						P.Wood = wood;
					}
					else if (x == 3)
					{
						int area;
						sscanf(content, "%d", &area);
						P.Pos.Area = area;
					}
					else if (x == 4)
					{
						int posx;
						sscanf(content, "%d", &posx);
						P.Pos.x = posx;
					}
					else if (x == 5)
					{
						int posy;
						sscanf(content, "%d", &posy);
						P.Pos.y = posy;
					}

					x++;
					j = 0;
				}
			}
			
		}

		fclose(f);
	}
	else
	{
		printf("File Not Found\n");
	}

	fclose(f);
}




void loadWahana(char dir[])
{
	FILE *f;
	f = fopen(dir, "r");

	if (f != NULL)
	{
		printf("Getting Wahana Data...\n");

		char wr[200];
		int cnt = 0;
		int banyakwahana = 0;
		while( fgets ( wr, 200, f ) != NULL ) 
        { 
			char content[20];
			int x = 0;
			int j = 0;
			for (int i = 0; i < NB(wr); i++)
			{
				if (wr[i] != ',')
				{
					content[j++] = wr[i];
				}
				else
				{
					content[j++] = '\0';
					if (x == 0)
					{
						W[cnt].Name = SetQueueKata(content);
					}
					else if (x == 1)
					{
						int type;
						sscanf(content, "%d", &type);
						W[cnt].Type = type;
					}
					else if (x == 2)
					{
						int level;
						sscanf(content, "%d", &level);
						W[cnt].Level = level;
					}
					else if (x == 3)
					{
						int cost;
						sscanf(content, "%d", &cost);
						W[cnt].Cost = cost;
					}
					else if (x == 4)
					{
						int area;
						sscanf(content, "%d", &area);
						W[cnt].Pos.Area = area;
					}
					else if (x == 5)
					{
						int posx;
						sscanf(content, "%d", &posx);
						W[cnt].Pos.x = posx;
					}
					else if (x == 6)
					{
						int posy;
						sscanf(content, "%d", &posy);
						W[cnt].Pos.y = posy;
					}

					x++;
					j = 0;
				}
			}

			cnt++;
		}

		NbWahana = cnt;
	}
	else
	{
		printf("File Not Found\n");
	}

	fclose(f);
}



void ItoS(char *S, int X, int *c)
{
	Kata K;
	char tmp[20]; 
    sprintf(tmp, "%d", X);
	SetKata(&K, tmp);

	for (int i = 0; i < K.Length; i++)
		S[(*c)++] = K.TabKata[i];
	
	S[(*c)++] = ',';
}

void QtoS(char *S, QueueKata Q, int *c)
{
	while(!IsEmpty(Q))
	{
		Kata K;
		DequeueKata(&Q, &K);
		for (int i = 0; i < K.Length; i++)
			S[(*c)++] = K.TabKata[i];	

		if (!IsEmpty(Q))
			S[(*c)++] = ' ';
	}
	S[(*c)++] = ',';
}

int NB(char S[])
{
	int n = 0;
	while(S[n] != '\0')
		n++;

	return n;
}

