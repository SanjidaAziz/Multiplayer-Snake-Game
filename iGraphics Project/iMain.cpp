# include "snake.h"

//blue head player 2
//black head player 1

//Screen width and Height
#define scrH 700
#define scrW 900
#define wall 25
string message="Press Space to continue";
//box2=25;

char background[]={"i\\ground3.bmp"};
char blood[3][30]={"img\\blood.bmp","img\\blood2.bmp","img\\blood3.bmp"};
char skyImage[20][30]={"img\\001.bmp","img\\002.bmp","img\\003.bmp","img\\004.bmp","img\\005.bmp","img\\006.bmp","img\\007.bmp","img\\008.bmp","img\\009.bmp","img\\010.bmp","img\\011.bmp","img\\012.bmp","img\\013.bmp","img\\014.bmp","img\\015.bmp","img\\016.bmp","img\\017.bmp","img\\018.bmp","img\\019.bmp","img\\020.bmp"};
int imgpos[20];
int bgimgpos[20];
char bgImage[30][30]={"img\\b001.bmp","img\\b002.bmp","img\\b003.bmp","img\\b004.bmp","img\\b005.bmp","img\\b006.bmp","img\\b007.bmp","img\\b008.bmp","img\\b009.bmp","img\\b010.bmp","img\\b011.bmp","img\\b012.bmp","img\\b013.bmp","img\\b014.bmp","img\\b015.bmp","img\\b016.bmp","img\\b017.bmp","img\\b018.bmp","img\\b019.bmp","img\\b020.bmp","img\\b021.bmp","img\\b022.bmp","img\\b023.bmp","img\\b024.bmp","img\\b025.bmp","img\\b026.bmp","img\\b027.bmp","img\\b028.bmp","img\\b029.bmp","img\\b030.bmp"};

int soundFlag=0;
int scene=0;
eDirection dir,dir2;

bool bigBut[4];

void imgposf()
{
	int i,j,k;
	for(i=0,j=0;i<20;i++){
		imgpos[i]=j;
		j+=35;
	}
	for(i=0,k=0;i<30;i++){		
		bgimgpos[i]=k;
		k+=30;
	}
}
void skyRendering()
{
	for(int i=0;i<20;i++)
		{
			iShowBMP(0,imgpos[i],skyImage[i]);
		}
		for(int i=0;i<20;i++)
		{
			imgpos[i]-=35;
		}
		for(int i=0;i<20;i++)
		{
			if(imgpos[i]<0)
			{
				imgpos[i]=665;
			}
		}
}

void backRendering() // menu page rendering
{
	for(int i=0;i<30;i++)
		{
			iShowBMP(bgimgpos[i],0,bgImage[i]);
		}
		for(int i=0;i<30;i++)
		{
			bgimgpos[i]-=30;
		}
		for(int i=0;i<30;i++)
		{
			if(bgimgpos[i]<0)
			{
				bgimgpos[i]=870;
			}
		}
}

bool collision(int x,int y,const vector<Snake> &vect){
	for(unsigned int i=0;i<vect.size();i++)
	{
		//printf("%f\n\n",sqrt((float)(x-vect[i].x)*(x-vect[i].x)+(y-vect[i].y)*(y-vect[i].y)));
		if(sqrt((float)(x-vect[i].x)*(x-vect[i].x)+(y-vect[i].y)*(y-vect[i].y)) <= 17.0)
			return true;
	}
	return false;
}


void Logic(){
	//old head position
	snakeX = snake[0].x;
	snakeY = snake[0].y;

	if (pause==false && gameover==false)
	{
		//which direction
		switch(dir)
		{
			case LEFT:
				snakeX -= speed;
				a=15;
				b=10;
				eye1x=snakeX-ip;
				eye1y=snakeY+ip-4;
				eye2x=snakeX-ip;
				eye2y=snakeY-ip+4;
				break;
			case RIGHT:
				snakeX += speed;
				a=15;
				b=10;
				eye1x=snakeX+ip;
				eye1y=snakeY+ip-4;
				eye2x=snakeX+ip;
				eye2y=snakeY-ip+4;
				break;
			case UP:
				snakeY += speed;
				a=10;
				b=15;
				eye1x=snakeX-ip+4;
				eye1y=snakeY+ip;
				eye2x=snakeX+ip-4;
				eye2y=snakeY+ip;
				break;
			case DOWN:
				snakeY -= speed;
				a=10;
				b=15;
				eye1x=snakeX-ip+4;
				eye1y=snakeY-ip;
				eye2x=snakeX+ip-4;
				eye2y=snakeY-ip;
				break;
			default :
				break;

		}
		//if the snake eats the food
		if(sqrt((float)(snakeX-food.x)*(snakeX-food.x)+(snakeY-food.y)*(snakeY-food.y)) <= 13.0)
		{
			score += 1;
			cout<<score<<endl;
			food.randomPos();
		}
		else if(sqrt((float)(snakeX-food2.x)*(snakeX-food2.x)+(snakeY-food2.y)*(snakeY-food2.y)) <= 13.0)
		{
			score += 1;
			cout<<score<<endl;
			food2.randomPos();
		}
		else if(sqrt((float)(snakeX-food3.x)*(snakeX-food3.x)+(snakeY-food3.y)*(snakeY-food3.y)) <= 13.0)
		{
			score += 1;
			cout<<score<<endl;
			food3.randomPos();
		}else{
	     // remove the tail
			snake.pop_back();
		}
	
		 //add new Head
		newHead.x=snakeX;
		newHead.y=snakeY;


		if(snakeX-head<wall || snakeX+head >scrW-wall || snakeY-head <wall || snakeY+head >scrH-wall || collision(snakeX,snakeY,snake2)) {
			//pause=true;
			gameover=true;
			winner=2;
		}
		snake.insert(snake.begin(),newHead);
	}
	
}
void Logic2(){
	//old head position
	snake2X = snake2[0].x;
	snake2Y = snake2[0].y;

	if (pause==false && gameover==false)

	{
	//which direction
	switch(dir2)
	{
		case LEFT:
			snake2X -= speed2;
			a2=15;
			b2=10;
			s2eye1x=snake2X-ip;
			s2eye1y=snake2Y+ip-4;
			s2eye2x=snake2X-ip;
			s2eye2y=snake2Y-ip+4;
			break;
		case RIGHT:
			snake2X += speed2;
			a2=15;
			b2=10;
			s2eye1x=snake2X+ip;
			s2eye1y=snake2Y+ip-4;
			s2eye2x=snake2X+ip;
			s2eye2y=snake2Y-ip+4;
			break;
		case UP:
			snake2Y += speed2;
			a2=10;
			b2=15;
			s2eye1x=snake2X-ip+4;
			s2eye1y=snake2Y+ip;
			s2eye2x=snake2X+ip-4;
			s2eye2y=snake2Y+ip;
			break;
		case DOWN:
			snake2Y -= speed2;
			a2=10;
			b2=15;
			s2eye1x=snake2X-ip+4;
			s2eye1y=snake2Y-ip;
			s2eye2x=snake2X+ip-4;
			s2eye2y=snake2Y-ip;
			break;
		default :
			break;
    }
	//if the snake eats the food
	if(sqrt((float)(snake2X-food.x)*(snake2X-food.x)+(snake2Y-food.y)*(snake2Y-food.y)) <= 13.0)
	{
		score2 += 1;
		cout<<score2<<endl;
		food.randomPos();
	}
	else if(sqrt((float)(snake2X-food2.x)*(snake2X-food2.x)+(snake2Y-food2.y)*(snake2Y-food2.y)) <= 13.0)
	{
			score2 += 1;
			cout<<score2<<endl;
			food2.randomPos();
	}
	else if(sqrt((float)(snake2X-food3.x)*(snake2X-food3.x)+(snake2Y-food3.y)*(snake2Y-food3.y)) <= 13.0)
	{
			score2 += 1;
			cout<<score2<<endl;
			food3.randomPos();
	}else{
		// remove the tail
		snake2.pop_back();
	}
	
	//add new Head
	newHead2.x=snake2X;
	newHead2.y=snake2Y;


	if(snake2X-head<wall || snake2X+head > scrW-wall || snake2Y-head <wall || snake2Y+head >scrH-wall || collision(snake2X,snake2Y,snake)){
		//pause=true;
		gameover=true;
		winner=1;
	}
	snake2.insert(snake2.begin(),newHead2);
	}
	
}

bool flagBut[5]={0,0,0,0,0};

//Main drawing function

void iDraw()
{
	
	iClear();

	if(ball==-2){

		//The starting page
		iSetColor(0,0,0);
		
		iShowBMP(0,0,"necessary\\1.bmp");
		iText2(300, 10, message,GLUT_BITMAP_TIMES_ROMAN_24);
		
	}
	else if(ball==-1)
	{		
		//The Menu Page

		//iShowBMP(0,0,"i\\2.bmp");
		backRendering();
		for(int i=0;i<5;i++)
		{
			if(flagBut[i]==1) iShowBMP2(but[i].x-25,but[i].y,buttonBig[i],0);
			else iShowBMP2(but[i].x,but[i].y,button[i],0);
		}

		if(bigBut[0]==true) iShowBMP2(825,620,"img\\mainPalyBig.bmp",0);
		else iShowBMP2(830,625,"img\\mainPaly.bmp",0);
		
		if(soundFlag==1) 
		{
			if(bigBut[1]==true) iShowBMP2(825,535,"img\\mainSoundOffBig.bmp",0);
			else iShowBMP2(830,540,"img\\mainSoundOff.bmp",0);
		}
		else if(soundFlag==0) 
		{
			if(bigBut[1]==true) iShowBMP2(825,535,"img\\mainSoundOnBig.bmp",0);
			else iShowBMP2(830,540,"img\\mainSoundOn.bmp",0);
			
		}


		iText(x, y, "Welcome to the snake game",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if(ball==0)
	{
		stopS();
		
		iShowBMP(0,0,background);
		iShowBMP2(0,0,"img\\wall.bmp",0);
	
		iSetColor(0,0,0);
		iSetColor(220,85,57);
	
		for(unsigned int i=0;i<snake.size();i++)
		{
			if(i==0)
			{
				iSetColor(14,77,146);
				//iPoint(snake[i].x,snake[i].y);
				iFilledCircle(snake[i].x,snake[i].y,head); //snake1 head
				iSetColor(255,255,255);
				iFilledCircle(eye1x,eye1y,2); //snake1 eye
				iFilledCircle(eye2x,eye2y,2); //snake1 eye
			}
			else
			{
				iSetColor(70,130,180); //light blue
				//iSetColor(241,251,31); //morning yellow
				iFilledEllipse(snake[i].x,snake[i].y,a,b); //snake1 body
				iSetColor(0,0,0);
				iPoint(snake[i].x+5,snake[i].y+1); //spot on skin
				iPoint(snake[i].x-2,snake[i].y+6); 
				iPoint(snake[i].x-8,snake[i].y-4); 				
			}
		}

		//////snake 2 draw...
		for(unsigned int i=0;i<snake2.size();i++)
		{
			if(i==0)
			{
				iSetColor(50,50,50);
				iFilledCircle(snake2[i].x,snake2[i].y,head);   //snake2 head
				iSetColor(255,0,0);
				iFilledCircle(s2eye1x,s2eye1y,2); //snake2 eye
				iFilledCircle(s2eye2x,s2eye2y,2);
			}
			else
			{
				iSetColor(100,100,100); //gray
				//iSetColor(10,222,29); //python green
				iFilledEllipse(snake2[i].x,snake2[i].y,a2,b2); //snake2 body
				iSetColor(255,0,0);
				iPoint(snake2[i].x+5,snake2[i].y+1);
				iPoint(snake2[i].x-2,snake2[i].y+6);   //spot on skin
				iPoint(snake2[i].x-8,snake2[i].y-4); 				
			}
		}

		//foods that help growing the snakes
		iSetColor(230,30,0);
		iFilledCircle(food.x,food.y,r);  // food1
		iSetColor(80,80,80);
		iFilledCircle(food2.x,food2.y,r);  //food2
		iSetColor(80,180,180);
		iFilledCircle(food3.x,food3.y,r);  //food2
		///////////////////////////////////////////

		iSetColor(0,0,0);
		if(pause==true) iText(250,350,"Press 'SPACE' when both palyers are ready",GLUT_BITMAP_TIMES_ROMAN_24);

		if(gameover==true)
		{
			iText(350,450,"GAME OVER!!!",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(300,350,"Press 'SPACE' to continue",GLUT_BITMAP_TIMES_ROMAN_24);
			if(winner==1) iShowBMP2(snake2X-26,snake2Y-26,blood[2],0);
			else if(winner==2) iShowBMP2(snakeX-26,snakeY-26,blood[2],0);
						
		}
	}
	else if(ball==1)
	{
		stopS();
		gameLoadRead();
		ball=0;
	}

	else if(ball==2)
	{
		//The leaderboard page
		stopS();
		iSetColor(0,0,0);
		iShowBMP(0,0,"img\\bg.bmp");
		iShowBMP2(0,0,"img\\score.bmp",0);
		iText(550, 50, "Press Space to back",GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(230,230,250);
		iFilledRectangle(405,345,255,250);
		iSetColor(0,0,0);
		int x=425,y=550;
		for(int i=0;i<3;i++)
		{		
			iText(x, y, playerName[i] ,GLUT_BITMAP_TIMES_ROMAN_24);
			iText(x+200, y,playerScore[i] ,GLUT_BITMAP_TIMES_ROMAN_24);
			y-=50;
		}
	}

	if(ball==3)
	{
		//The instructions page
		stopS();
		iSetColor(22,22,22);
		iShowBMP(0,0,"img\\ins1.bmp");
		iText(50, 100, "Press Space to back",GLUT_BITMAP_TIMES_ROMAN_24);		
	}

	if(ball==4)
	{
		//The quiting page
		exit(0);	
	}

	if (ball==5)
	{
		//game over page

		skyRendering();
		
		iSetColor(225,255,255);
		iText(375,440,"GAME OVER!!!",GLUT_BITMAP_TIMES_ROMAN_24);
		
		if(winner==1)
		{
			iText(205,300,"Blue snake is the Winner!! Congratulations!!!",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(205,260,"Enter winner's name:",GLUT_BITMAP_TIMES_ROMAN_24);
			playerName2[3].score=score;
			inputName();				
		}
		else if(winner==2)
		{
			iText(205,300,"Black snake is the Winner!! Congratulations!!!",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(205,260,"Enter winner's name:",GLUT_BITMAP_TIMES_ROMAN_24);
			playerName2[3].score=score2;
			inputName();				
		}
		iSetColor(225,255,255);
		iText(330, 100, "Press Enter to continue",GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(ball==6)
		//////Story page
	{
		
		if(scene==0)
		{
			iShowBMP(0,0,"img\\castlebg.bmp");
			iShowBMP2(550,200,"img\\scroll0.bmp",0);
		}
		if(scene==1)
		{
			iShowBMP(0,0,"img\\throne.bmp");
			iShowBMP2(0,0,"img\\William1.bmp",0);
			iShowBMP2(190,0,"img\\king.bmp",0);
			iShowBMP2(390,0,"img\\Andrew1.bmp",0);
			iShowBMP2(550,200,"img\\scroll1.bmp",0);
		}
		if(scene==2)
		{
			iShowBMP(0,0,"img\\throne.bmp");
			iShowBMP2(0,0,"img\\William2.bmp",0);
			iShowBMP2(190,0,"img\\king.bmp",0);
			iShowBMP2(390,0,"img\\Andrew2.bmp",0);
			iShowBMP2(550,200,"img\\scroll2.bmp",0);
		}
		if(scene==3)
		{
			iShowBMP(0,0,"img\\hunt.bmp");
			iShowBMP2(402,342,"img\\crown.bmp",0);
			iShowBMP2(10,20,"img\\William22.bmp",0);
			iShowBMP2(550,200,"img\\scroll3.bmp",0);
		}
		if(scene==4)
		{
			iShowBMP(0,0,"img\\fightbg.bmp");
			iShowBMP2(100,20,"img\\fighting.bmp",0);
			iShowBMP2(550,200,"img\\scroll4.bmp",0);
		}
		if(scene==5)
		{
			iShowBMP(0,0,"img\\fightbg.bmp");
			iShowBMP2(115,55,"img\\wizrd.bmp",0);
			iShowBMP2(390,95,"img\\smallBlueSnake.bmp",0);
			iShowBMP2(430,30,"img\\smallBlackSnake.bmp",0);
			iShowBMP2(515,190,"img\\scroll5.bmp",0);
		}
		if(scene==6)
		{
			iShowBMP(0,0,"img\\castlebg.bmp");
			iShowBMP2(0,200,"img\\snake.bmp",0);
			iShowBMP2(550,200,"img\\scroll6.bmp",0);
		}
		if(bigBut[2]==true) iShowBMP2(740,120,"img\\mainNextPageBig.bmp",0);
		else iShowBMP2(745,125,"img\\mainNextPage.bmp",0);

		if(bigBut[3]==true) iShowBMP2(640,120,"img\\mainPreviousPageBig.bmp",0);
		else iShowBMP2(645,125,"img\\mainPreviousPage.bmp",0);
		iText(615, 90, "Press Space to skip",GLUT_BITMAP_TIMES_ROMAN_24);
	}

}

void iPassiveMouse(int x, int y)
{
	if(ball==-1)
		{
			for(int i=0;i<5;i++)
			{
				if(x>=but[i].x && x<=but[i].x+243 && y>=but[i].y && y<=but[i].y+115)
				{
					flagBut[i]=1;
				}
				else flagBut[i]=0;
			}


		if(x>=835 && x<=835+60 && y>=630 && y<=630+60)
			bigBut[0]=true;
		else bigBut[0]=false;
	
		if(x>=835 && x<=835+60 && y>=540 && y<=540+60)			
			bigBut[1]=true;
		else bigBut[1]=false;
			
	}

	if(ball==6)
	{
		if(x>=735 && x<=735+60 && y>=125 && y<=125+60)
			bigBut[2]=true;
		else bigBut[2]=false;

		if(x>=635 && x<=635+60 && y>=125 && y<=125+60)
			bigBut[3]=true;
		else bigBut[3]=false;
	}
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(ball==-1)
		{
			for(int i=0;i<5;i++)
			{
				if(mx>=but[i].x && mx<=but[i].x+243 && my>=but[i].y && my<=but[i].y+115){
					ball=i;
				}
				
			}
			if(mx>=835 && mx<=835+60 && my>=630 && my<=630+60)
			{
				ball=6;
				scene=0;
				if(scene==0) PlaySound("Sound\\page1.wav",NULL,SND_ASYNC);
			}
			if(mx>=835 && mx<=835+60 && my>=540 && my<=540+60)
			{
				if(soundFlag==0) {soundFlag=1; stopS();}
				else if (soundFlag==1) 
				{
					soundFlag=0;
					PlaySound(sound,NULL,SND_LOOP | SND_ASYNC);
				}
			}
		}
		if(ball==5)
		{
			if(mx>=xinp && mx<= xinp+200 && my>=yinp && my<=yinp+30) 
				flag = 1;		
		}
		if (ball==6)
		{
			
			//PlaySound("Sound\\page1.wav",NULL,SND_LOOP | SND_ASYNC);
			if(scene>=0 && scene<=6)
			//while(scene<=0 && scene>=3)
			{
				if(mx>=735 && mx<=735+60 && my>=125 && my<=125+60)
				{

					scene+=1;
					if(scene==0) PlaySound("Sound\\page1.wav",NULL,SND_ASYNC);
					else if(scene==1) PlaySound("Sound\\page2.wav",NULL,SND_ASYNC);
					else if(scene==2) PlaySound("Sound\\page3.wav",NULL,SND_ASYNC);
					else if(scene==3) PlaySound("Sound\\page4.wav",NULL,SND_ASYNC);
					else if(scene==4) PlaySound("Sound\\page5.wav",NULL,SND_ASYNC);
					else if(scene==5) PlaySound("Sound\\page6.wav",NULL,SND_ASYNC);
					else if(scene==6) PlaySound("Sound\\page7.wav",NULL,SND_ASYNC);
					else if(scene==7) {ball=-1;PlaySound(sound,NULL,SND_LOOP | SND_ASYNC);scene=0;}

				}
				if(mx>=635 && mx<=635+60 && my>=125 && my<=125+60)
				{
					if(scene!=0)
					scene--;
					if(scene==0) PlaySound("Sound\\page1.wav",NULL,SND_ASYNC);
					else if(scene==1) PlaySound("Sound\\page2.wav",NULL,SND_ASYNC);
					else if(scene==2) PlaySound("Sound\\page3.wav",NULL,SND_ASYNC);
					else if(scene==3) PlaySound("Sound\\page4.wav",NULL,SND_ASYNC);
					else if(scene==4) PlaySound("Sound\\page5.wav",NULL,SND_ASYNC);
					else if(scene==5) PlaySound("Sound\\page6.wav",NULL,SND_ASYNC);
					else if(scene==6) PlaySound("Sound\\page7.wav",NULL,SND_ASYNC);


				}
			}

		}
		printf("x = %d, y= %d\n",mx,my);

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here		
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.	
*/
void iKeyboard(unsigned char key)
{

	if (ball==5)
	{
		PlaySound("sound\\up.wav",NULL,SND_ASYNC);
		if(flag == 1)
		{
			if(key=='\r')
			{			
				fileWrite();
				file();
				flag=0;
				initials();
				ball=2;				
			}
			
			if(key != '\b')
			{
				if(len<17)
				{
					playerName2[3].name[len]=key;
					len++;
					playerName2[3].name[len]='\0';
				}
			}
			else
			{
				if(len<=0) len=0;
				else len--;
				playerName2[3].name[len]='\0';
			}
		}
	}
	
	if(ball==0)
	{
		if(key == 'w' && dir != DOWN)
		{	
			//PlaySound("sound\\up.wav",NULL,SND_ASYNC);
			dir=UP;
			
		}
		else if(key == 'a' && dir != RIGHT )
		{	
			dir = LEFT;
			//PlaySound("sound\\left.wav",NULL,SND_ASYNC);
		}
		else if(key == 's' && dir != UP)
		{	
			dir=DOWN;
			//PlaySound("sound\\down.wav",NULL,SND_ASYNC);
		}
		else if(key == 'd' && dir != LEFT)
		{	
			dir=RIGHT;
			//PlaySound("sound\\right.wav",NULL,SND_ASYNC);
		}
		if(key == ' ')
		{			
			if (pause==true)
			{			
				pause=false;
			}
			else if (pause==false)
			{			
				pause=true;
			}			
		}
		if ( gameover==true)
		{
			if(key == ' ')
			{
				ball=5;
			}
		}
	}
	

	if (ball != 0 && ball != 5 && ball!=-2)
	{
		if(key == ' ')
		{
			ball=-1;
			if(ball!=6)
			{
				//if(soundFlag==0)
					PlaySound(sound,NULL,SND_LOOP | SND_ASYNC);
			}			
		}
	}
	else if(ball==-2)
	{
		if(key == ' ')
		{
			ball=6;
			PlaySound("Sound\\page1.wav",NULL,SND_ASYNC);
		}

	}

	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{
	if(key==GLUT_KEY_HOME && pause==true) {ball=-1; initials();PlaySound(sound,NULL,SND_LOOP | SND_ASYNC);}//when the running game is paused, 
												   //pressing the home button will shift to the main menu.
											   	   //To resume, simply press 'space'.

	
	if(ball==0)
	{		
		if(key == GLUT_KEY_UP && dir2 != DOWN)
		{
			dir2=UP;
		}
		else if(key == GLUT_KEY_DOWN && dir2 != UP)
		{
			dir2=DOWN;
		}
		else if(key == GLUT_KEY_LEFT && dir2 != RIGHT)
		{
			dir2=LEFT;
		}
		else if(key == GLUT_KEY_RIGHT && dir2 != LEFT)
		{
			dir2=RIGHT;
		}

		if(key == GLUT_KEY_F5)
		{	if(gameover==false)
			gameSaveWrite();
		}
	}
	else if(ball==6)
	{		
		
		
	   if(key == GLUT_KEY_LEFT )
		{
			if(scene!=0)
			scene--;
			if(scene==0) PlaySound("Sound\\page1.wav",NULL,SND_ASYNC);
			else if(scene==1) PlaySound("Sound\\page2.wav",NULL,SND_ASYNC);
			else if(scene==2) PlaySound("Sound\\page3.wav",NULL,SND_ASYNC);
			else if(scene==3) PlaySound("Sound\\page4.wav",NULL,SND_ASYNC);
			else if(scene==4) PlaySound("Sound\\page5.wav",NULL,SND_ASYNC);
			else if(scene==5) PlaySound("Sound\\page6.wav",NULL,SND_ASYNC);
			else if(scene==6) PlaySound("Sound\\page7.wav",NULL,SND_ASYNC);
		}
		else if(key == GLUT_KEY_RIGHT && dir2 != LEFT)
		{
			
			scene+=1;
			if(scene==0) PlaySound("Sound\\page1.wav",NULL,SND_ASYNC);
			else if(scene==1) PlaySound("Sound\\page2.wav",NULL,SND_ASYNC);
			else if(scene==2) PlaySound("Sound\\page3.wav",NULL,SND_ASYNC);
			else if(scene==3) PlaySound("Sound\\page4.wav",NULL,SND_ASYNC);
			else if(scene==4) PlaySound("Sound\\page5.wav",NULL,SND_ASYNC);
			else if(scene==5) PlaySound("Sound\\page6.wav",NULL,SND_ASYNC);
			else if(scene==6) PlaySound("Sound\\page7.wav",NULL,SND_ASYNC);
			else if(scene==7) {ball=-1;PlaySound(sound,NULL,SND_LOOP | SND_ASYNC);scene=1;}
		}
	}
}


//for the running text in main menu
void bcChange()
{
	x += dx;
	if(x > 600 || x < 0) dx = -dx;	
}

int main()
{
	
	//srand((unsigned)time(0));
	iInitialize(scrW, scrH, "snake");
		
	initials();
	file();
	
	iSetTimer(100,Logic);
	iSetTimer(100,Logic2);
	
	iSetTimer(100,bcChange);
	iSetTimer(100,inputName);
	
	imgposf();
	iStart();
	return 0;
}
