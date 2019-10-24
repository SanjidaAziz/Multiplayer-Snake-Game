#ifndef BEFORE
#define BEFORE

# include "snake.h"
#include "iGraphics.h"
#include "bitmap_loader.h"

using namespace std;
string message="Press Space to continue";
Button but[10];

//For game play
int box=25,box2=25;

char background[]={"i\\ground3.bmp"};
bool gameover=false;

eDirection dir,dir2;
int snakeX=10,snakeY=10,score=0,speed=box,r=7,foodX=400,foodY=400;
int snake2X=10,snake2Y=10,r2=7,speed2=box2,food2X=500,food2Y=300;


Snake newHead,newHead2;
vector <Snake> snake;
vector <Snake> snake2;

Food food,food2;


/*bool collision(Snake s,const vector<Snake> &vect){
	for(unsigned int i=0;i<snake.size();i++){
		if(s.x == vect[i].x && s.y==vect[i].y)
			return true;
	}
	return false;
}
*/

void Logic(){
	//old head position
	snakeX = snake[0].x;
	snakeY = snake[0].y;


	//which direction
	switch(dir)
	{
	case LEFT:
		snakeX -= speed;
		break;
	case RIGHT:
		snakeX += speed;
		break;
	case UP:
		snakeY += speed;
		break;
	case DOWN:
		snakeY -= speed;
		break;
	default :
		break;

     }
	//if the snake eats the food
	if(snakeX-r<(food.x) && snakeY-r<(food.y) && (food.x) < (snakeX+box+r) && (food.y) < (snakeY+box+r))
	{
		score += 10;
		cout<<score<<endl;
		food.x=rand()%541+10;
		food.y=rand()%479+10;
	}else{
		// remove the tail
		snake.pop_back();
	}
	
	 //add new Head
	 newHead.x=snakeX;
	 newHead.y=snakeY;


	 if(snakeX<0 || snakeX >scrW || snakeY <0 || snakeY>scrH ){
		gameover=true;
	}
	 snake.insert(snake.begin(),newHead);
	
	
}
void Logic2(){
	//old head position
	snake2X = snake2[0].x;
	snake2Y = snake2[0].y;


	//which direction
	switch(dir2)
	{
	case LEFT:
		snake2X -= speed;
		break;
	case RIGHT:
		snake2X += speed;
		break;
	case UP:
		snake2Y += speed;
		break;
	case DOWN:
		snake2Y -= speed;
		break;
	default :
		break;

     }
	//if the snake eats the food
	if(snake2X-r<(food.x) && snake2Y-r<(food.y) && (food.x) < (snake2X+box+r) && (food.y) < (snake2Y+box+r))
	{
		score += 10;
		cout<<score<<endl;
		food.x=rand()%541+10;
		food.y=rand()%479+10;
	}else{
		// remove the tail
		snake2.pop_back();
	}
	
	 //add new Head
	 newHead2.x=snake2X;
	 newHead2.y=snake2Y;


	 if(snake2X<0 || snake2X >scrW || snake2Y <0 || snake2Y>scrH ){
		gameover=true;
	}
	 snake2.insert(snake2.begin(),newHead2);
	
	
}









//ball represents the current screen in game
int ball=-2;

//Menu sound location
char sound[]="necessary\\2.wav";

//Main menu buttons
char button[10][30]={"necessary\\but1s.bmp","necessary\\but2s.bmp","necessary\\but3s.bmp","necessary\\but4s.bmp"};

//initial co ordinates oF the running text
int x=10,y=10;
//changing speed through x axis
int dx=10;


#endif