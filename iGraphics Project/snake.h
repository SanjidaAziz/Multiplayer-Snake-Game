#ifndef SNAKE_S
#define SNAKE_S

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <windows.h>
#include <mmsystem.h>
#include "iGraphics.h"
#include "bitmap_loader.h"
#include "Structs.h"



using namespace std;

Button but[10];
Snake newHead,newHead2;

int winner = 0;
//For game play
int box=25;

vector <Snake> snake;
vector <Snake> snake2;

Food food,food2,food3;

int score2=0;

//ball represents the current screen in game
int ball=-2;

//Menu sound location
char sound[]="necessary\\2.wav";

//Main menu buttons
char button[7][30]={"necessary\\but1s.bmp","necessary\\but5s.bmp","necessary\\but2s.bmp","necessary\\but3s.bmp","necessary\\but4s.bmp"};

char buttonBig[7][30]={"necessary\\but1b.bmp","necessary\\but5b.bmp","necessary\\but2b.bmp","necessary\\but3b.bmp","necessary\\but4b.bmp"};

//initial co ordinates oF the running text
int x=10,y=10;
//changing speed through x axis
int dx=10;




//Used these variables to store read data from file for Leaderboard page
FilePurpose playerName2[5];
char playerScore[5][20];
char playerName[5][100];

int Lines=0;

////wall
int wallLength1=800,wallLength2=700,wallWidth=10;

//after the death of the snakes it gameover will turn true
bool gameover=false;

int head=12,ip=10;
int a=15,b=10,a2=15,b2=10;
int eye1x=0,eye1y=0,s2eye1x=0,s2eye1y=0;
int eye2x=0,eye2y=0,s2eye2x=0,s2eye2y=0;
int score=0;

int snakeX=10,snakeY=10,speed=head,r=7,foodX=400,foodY=400;
int snake2X=10,snake2Y=10,r2=7,speed2=head,food2X=500,food2Y=300;


bool pause=false;

int flag=0;
int len=0;
int xinp=430,yinp=250;
void inputName()
{
	if (flag==0)
	{
		iSetColor(255,255,255);
		iRectangle(xinp,yinp,250,30);
	}
	else if (flag==1)
	{
		iSetColor(200,0,0);
		iRectangle(xinp,yinp,250,30);
		iText(xinp+20, yinp+10, playerName2[3].name,GLUT_BITMAP_TIMES_ROMAN_24);

	}

}


//The function plays the sound , which as location in the parameter
void playS(char a[])
{
	PlaySound(a,NULL,SND_ASYNC);
}


//The function stops any playing the sound 
void stopS()
{
	PlaySound(0,0,0);
}






void file(){
	
	int i=0;
	FILE *fptr = fopen("Save games\\save.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
    }
    
	while (fscanf(fptr,"%s %s",&playerName[i],&playerScore[i]) != EOF)
    {
		//printf ("%s %s\n", playerName[i],&playerScore[i]);
		i++;
    }
    fclose(fptr);

}

void fileWrite(){
	
	int i=0;
	FILE *fptr = fopen("Save games\\save.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
    }
    
	while (fscanf(fptr,"%s %d",&playerName2[i].name,&playerName2[i].score) != EOF)
    {
		printf ("%s %d\n", playerName2[i].name, playerName2[i].score);
		i++;
    }
	printf ("%s %d\n", playerName2[i].name, playerName2[i].score);
    fclose(fptr);
	FilePurpose temp;
	for(int i=0;i<=2;i++)
	{
		for(int j=i+1;j<=3;j++){
		if(playerName2[i].score<playerName2[j].score){
			temp=playerName2[i];
			playerName2[i]=playerName2[j];
			playerName2[j]=temp;
		}
		}
	}
	FILE *fp = fopen("Save games\\save.txt", "w");
	for(int i=0;i<3;i++){
	fprintf(fp, "%s %d\n",playerName2[i].name,playerName2[i].score);
	}
	len=0;
	playerName2[3].name[0]='\0';
    fclose(fp);

}

void gameSaveWrite(){
	
	int i=0;
	FILE *fptr = fopen("Save games\\save2.txt", "w");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
    }
	else
	{
    
	fprintf(fptr,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",snakeX,snakeY,speed,r,foodX,foodY,
		snake2X,snake2Y,r2,speed2,food2X,food2Y,head,ip,a,b,a2,b2,eye1x,eye1y,s2eye1x,s2eye1y,eye2x,eye2y,s2eye2x,s2eye2y,score,score2,food3.x,food3.y);
	
	}

	fclose(fptr);
//	int i=0;
	FILE *fptr2 = fopen("Save games\\save3(blue_snake).txt", "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file \n");
    }
	else
	{

			for(int i=0;i<=score;i++)
		{
			fprintf(fptr2,"%d %d\n",snake[i].x,snake[i].y);
				
		}
	}
	fclose(fptr2);

	FILE *fptr3 = fopen("Save games\\save3(black_snake).txt", "w");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
    }
	else
	{
		for(int i=0;i<=score2;i++)
		{
			fprintf(fptr2,"%d %d\n",snake2[i].x,snake2[i].y);
				
		}
	}
	fclose(fptr3);


}

void gameLoadRead(){
	
	int i=0;
	FILE *fptr = fopen("Save games\\save2.txt", "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
    }
	else
	{
    
	fscanf(fptr,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",&snakeX,&snakeY,&speed,&r,&foodX,&foodY,
		&snake2X,&snake2Y,&r2,&speed2,&food2X,&food2Y,&head,&ip,&a,&b,&a2,&b2,&eye1x,&eye1y,&s2eye1x,&s2eye1y,&eye2x,&eye2y,&s2eye2x,&s2eye2y,&score,&score2,&food3.x,&food3.y);
//	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",snakeX,snakeY,speed,r,foodX,foodY,
	//	snake2X,snake2Y,r2,speed2,food2X,food2Y,head,ip,a,b,a2,b2,eye1x,eye1y,s2eye1x,s2eye1y,eye2x,eye2y,s2eye2x,s2eye2y,score,score2,food3.x,food3.y);
	
	}

	fclose(fptr);

	FILE *fptr2 = fopen("Save games\\save3(blue_snake).txt", "r");
    if (fptr2 == NULL)
    {
        printf("Cannot open file \n");
    }
	else
	{

			for(int i=0;i<=score;i++)
		{
			int xx=0,yy=0;

			fscanf(fptr2,"%d %d\n",&xx,&yy);
			snake.push_back(Snake());
			snake[i].inp(xx,yy);
			printf("snake 1 : %d %d\n",snake[i].x,snake[i].y);
				
		}
	}
	fclose(fptr2);

	FILE *fptr3 = fopen("Save games\\save3(black_snake).txt", "r");
    if (fptr3 == NULL)
    {
        printf("Cannot open file \n");
    }
	else
	{
		for(int i=0;i<=score2;i++)
		{
			int xx=0,yy=0;

			fscanf(fptr3,"%d %d\n",&xx,&yy);
			snake2.push_back(Snake());
			snake2[i].inp(xx,yy);
			printf("snake 2 : %d %d\n",snake2[i].x,snake2[i].y);
				
		}
	}
	fclose(fptr3);


}

//initializes the buttons x and y axis on the menu screen

void initials(){
	for(int i=0,j=500;i<5;i++,j-=115){
		but[i].x=300;
		but[i].y=j;
	  
	}
	//erasing the whole elememts of a snake
	snake.clear();
	snake2.clear();

	snake.push_back(Snake()); 
	  snake[0].inp(19*box,10*box);

	  snake2.push_back(Snake()); 
	  snake2[0].inp(14*box,15*box);

  snakeX=10,snakeY=10,speed=head,r=7,foodX=400,foodY=400;
  snake2X=10,snake2Y=10,r2=7,speed2=head,food2X=500,food2Y=300;

  head=12,ip=10;
  a=15,b=10,a2=15,b2=10;
  eye1x=0,eye1y=0,s2eye1x=0,s2eye1y=0;
  eye2x=0,eye2y=0,s2eye2x=0,s2eye2y=0;
  score=0,score2=0;
	  gameover=false;
}

enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};


#endif