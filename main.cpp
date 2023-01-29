#include <iostream>
#include <stdio.h>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <conio.h> // pour la fonction kbhit
#include <windows.h>
using namespace std;
/*void HideCursor();              //The cursor is hidden
void gotoxy(int x, int y);*/

enum direction{Haut=1 , Bas, Gauche, Droite};

typedef struct Snk{
int tetex;
int tetey;
direction dir;
struct Snk *suivant;
}Snake;
typedef Snake* Serpent;

struct Map{
    int largeur;
    int longeur;
    int fruitx;
    int fruity;
};

struct joueur{
    int score;
    bool lose;

};

Map Map1; joueur Joueur1;
Serpent Snake1;

void ClearScreen()
{
COORD cursorPosition;
cursorPosition.X = 0;
cursorPosition.Y = 0;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void manipulation_fruit()
{
     srand(time(NULL));
     Map1.fruitx =rand()%(Map1.largeur-2)+1;
     Map1.fruity=rand()%(Map1.largeur-2)+1;
}

void snakeinit(){
     Snake1 = (Snake*) malloc(sizeof(Snake));
     Snake1->suivant = NULL;
     Snake1->tetex =Map1.largeur /2;
     Snake1->tetey =Map1.longeur /2;
}

void configuration_graphique()
{
     Map1.largeur =20; //=x=i
     Map1.longeur =40;
     manipulation_fruit();
     Joueur1.score =0;
     Joueur1.lose =false;
}

void graphe()
{    int i, j;
    ClearScreen();
   for(i=0; i<Map1.largeur;i++)
{
    for(j=0; j<Map1.longeur;j++)
    {
        if(i==0 || i==(Map1.largeur -1))
           printf("*");
        else if(j==0 || j==(Map1.longeur -1))
                printf("*");
        else if(i== Snake1->tetex && j== Snake1->tetey)
                printf(">");
        else if(i== Map1.fruitx && j== Map1.fruity)
                printf("@");
        else
                 printf(" ");

}
    printf("\n");
}
 printf("le score du joueur est: %d \n",Joueur1.score);
}

void cliquer()
{  char a;
   if(_kbhit()) {
    a= _getch();
    switch(a)
    {
        case 'z': Snake1->dir = Haut;
        break;
        case 's': Snake1->dir = Bas;
        break;
        case 'd': Snake1->dir = Droite;
        break;
        case 'q': Snake1->dir = Gauche;
        break;
        case 'x': exit(0);

    }
   }
}

void mouvement()
{
    switch(Snake1->dir)
    {
        case Haut: Snake1->tetex--;
        break;
        case Bas: Snake1->tetex++;
        break;
        case Droite: Snake1->tetey++;
        break;
        case Gauche: Snake1->tetey--;
        break;
    }
 if(Snake1->tetey >= Map1.longeur || Snake1->tetey <=0 || Snake1->tetex >= Map1.largeur || Snake1->tetex <= 0)
    Joueur1.lose= true;
 if(Snake1->tetex== Map1.fruitx && Snake1->tetey== Map1.fruity)
 {
     manipulation_fruit();
     Joueur1.score +=1;
 }
}


void agrandir(Serpent Snake1)
{


Serpent corps = (Serpent)malloc(sizeof(Snake));
while(Snake1->suivant != NULL)
{
    Snake1=Snake1->suivant;
}
Snake1->suivant=corps;
corps->suivant=NULL;
corps->dir=Snake1->dir;
switch(corps->dir)
{
case 'Haut':
    corps->tetex=Snake1->tetex+1;
    corps->tetey=Snake1->tetey;
    break;
case 'Droite':
    corps->tetex=Snake1->tetex;
    corps->tetey=Snake1->tetey+1;
    break;
case 'Bas':
    corps->tetex=Snake1->tetex-1;
    corps->tetey=Snake1->tetey;
    break;
case 'Gauche':
    corps->tetex=Snake1->tetex;
    corps->tetey=Snake1->tetey-1;
    break;
}
}
/*void dep_snake(){
*Serpent p = NULL;        //Work pointer
Serpent nexthead;        //The next snake head
int score = 0;
void snakemove()	    //Snake moves forward, U up, D down, L left, R right
{
    nexthead = (Snake*)malloc(sizeof(Snake));

switch(nexthead->dir)
{
case 'Haut':
      nexthead->tetey = Snake1->tetey - 1;  //Determine the next coordinate x,y of the new snake head
      nexthead->tetex = Snake1->tetex;
        break;
case 'Bas':
        nexthead->tetey = Snake1->tetey + 1;
        nexthead->tetex = Snake1->tetex;
      break;
case 'Gauche':
        nexthead->tetex = Snake1->tetex - 2;
        nexthead->tetey = Snake1->tetey;
        break;
case 'Droite':
        nexthead->tetex = Snake1->tetex + 2;
        nexthead->tetey = Snake1->tetey;
    break;
}
    nexthead->suivantz = Snake1;
    Snake1 = nexthead;
    p = Snake1;

    if (p->tetex == Map1.fruitx && p->tetey == Map1.fruity) //Determine whether the position of the snake head coincides with the position of the food
    {
        while (p)                       //Output end node
        {
            gotoxy(p->tetex, p->tetey);
            if (p == Snake1)
                printf("O");
            else
                printf("*");
            p = p->suivant;                //Because each movement creates a new head node and deletes a tail node,
        }                               //So to add a section of body, just don’t release the end node in this loop and output the end node once

        //generate_fruit(); //When encountering food, another food will be generated

        score++;
        gotoxy(32, 28);
        printf("%d", score);
    }
    else
    {
        while (p->suivant->suivant)           //Do not output the end node
        {
            gotoxy(p->tetex, p->tetey);
            if (p == Snake1)
                printf("O");
            else
                printf("*");
            p = p->suivant;
        }

        gotoxy(p->suivant->tetex, p->suivant->tetey);
        printf("  ");
        free(p->suivant);
        p->suivant = NULL;
    }

    p = Snake1;
    while (p)                       //If the food coordinates are refreshed to the snake, another food will be generated *
    {
        if (p->tetex == Map1.fruitx && p->tetey == Map1.fruity)
            manipulation_fruit();
        p = p->suivant;
    }
}*/



int main()
{
int pick;
  do
  {
    printf("\n\n\n\n\n\n\n");
    printf("\t\t _______  __    _  _______  ___   _  _______   \n");
    printf("\t\t|       ||  |  | ||   _   ||   | | ||       |  \n");
    printf("\t\t|  _____||   |_| ||  |_|  ||   |_| ||    ___|  \n");
    printf("\t\t| |_____ |       ||       ||      _||   |___   \n");
    printf("\t\t|_____  ||  _    ||       ||     |_ |    ___|  \n");
    printf("\t\t _____| || | |   ||   _   ||    _  ||   |___   \n");
    printf("\t\t|_______||_|  |__||__| |__||___| |_||_______|  \n");
    printf("\n\t\t              Press 1 to Play                \n");
    printf("\n\t\t              Press 2 to Quit                \n");
    printf("\t\t              Press X to Stop the game         \n");
    printf("\t\t              Pick: "); scanf("%d", &pick);
    if (pick != 1 && pick != 2)
      printf("Invalid! Choose again!");
    if (pick == 1)
    {
      system("CLS");

     configuration_graphique();
     snakeinit();
    while (!Joueur1.lose)
    {
        graphe();
        cliquer();
        mouvement();
        Sleep(100);
    }
         system("pause");

    }
  } while (pick != 2);
    return 0;
}
/*void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}*/
