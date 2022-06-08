#include<ncurses.h>
#include<iostream>
#include<string>
using namespace std;

int main(){
	initscr();
	printw("select option");
	noecho();
	
	//enemy and player stats
	int enemy_atack = 1;
	int player_atack = 2;
	int magic_atack = 3;
	int enemy = 20;
	int player = 100;
	int manna = 100;

	//funny menu things
	const char txt1[] = "sword attack";
	const char txt2[] = "magic atack";
	mvprintw(1,0,"enemy: %i",enemy);
	int ktory = 1;
	int znak;
	const short int min_wybor = 1;
	const short int max_wybor = 2;

	do{
		znak = getch();
		clear();
		//up
		if(znak == 'a' && ktory != min_wybor){
			ktory --;
		}
		//down
		else if(znak == 'z' && ktory != max_wybor){
			ktory++;
		}
		//if ENTER
		if(znak == 10){
			switch(ktory){
				//sword swing
				case 1:
					mvprintw(3,0,"you swing with your sword");
					enemy -= player_atack;
					player -= enemy_atack;
					break;
				//fireball
				case 2:
					if(manna >= 10){
					mvprintw(3,0,"you throw a fire ball");
					enemy -= magic_atack;
					player -= enemy_atack;
					manna -= 10;}
					else{
					mvprintw(3,0,"you don't have enough manna");}
					break;
			}
		//game over
		if(player <= 0){
			clear();
			mvprintw(0,0,"GAME OVER");
			getch();
			break;
		}
		//enemmy dead
		if(enemy <= 0 ){
			clear();
			int rand_enemy = rand()%2;
			mvprintw(1,0,"DEBUG: %i", rand_enemy);
			//find gnome
			if(rand_enemy == 0){
				mvprintw(0,0,"you killed an enemmy you wal down the dundego an meet a angry gnome [PRESS ANY KEY TO CONTINUE]");
				enemy += rand()%20;
				enemy_atack = 1;
			}
			//find skeleton
			else{
				mvprintw(0,0,"you killed an enemmy you walk down the dundegon and meet angry skeleton [PRESS ANY KEY TO CONETINUE]");
				enemy += rand()% 11 + 10;
				enemy_atack = 2;
			}
			//drop sequence
			int drop = rand()%2;
			if(drop == 0){
				mvprintw(1,0,"you find healing potion");
				player += 5;
			}
			else{
				mvprintw(1,0,"you find manna potion");
				manna += 5;
			}
			getch();
			clear();
			
		}
		}
		//print sequence
		mvprintw(2,0,"enemy hp: %i",enemy);
		mvprintw(0,0,"player hp: %i",player);
		mvprintw(1,0,"manna: %i",manna);
		switch(ktory){
			case 1:
				mvprintw(6,5,txt2);
				attron(A_REVERSE);
				mvprintw(5,5,txt1);
				break;
			case 2:
				mvprintw(5,5,txt1);
				attron(A_REVERSE);
				mvprintw(6,5,txt2);
				break;

		}
		attroff(A_REVERSE);
	}
	//ending
	while(ktory != 3 || znak !=10);
	move(9,0);
	endwin();
	return 0;
}
