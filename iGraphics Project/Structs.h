#ifndef STRUCTS_S
#define STRUCTS_S


#include <stdio.h>
#include <stdlib.h>

//A structure for menu buttons
struct Button
{
	int x;
	int y;
	char z[20];
	Button(){}
	Button(int a,int b){x=a;y=b;}
} ;


struct Food{
	int x ;
	int y ;
	//srand((unsigned)time(null));
	Food(){
	x=rand()%801+49;
	y=rand()%601+49;
	}
	Food(int i,int j){
		x=i;
		y=j;
	}
	void inp(int i,int j){
		x=i;
		y=j;
	}
	void randomPos(){
		x=rand()%793+49;
		y=rand()%601+49;
	
	}
};


struct Snake{
	int x ;
	int y ;
	Snake(){}
	Snake(int i,int j){
		x=i;
		y=j;
	}
	void inp(int i,int j){
		x=i;
		y=j;
	}
};
struct FilePurpose{
	char name[30] ;
	int score ;
};

#endif