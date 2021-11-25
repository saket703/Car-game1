#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
float x = 79,
y = 430,
car1 = 0,
car2 = 0,
car3 = 0,
car4 = 0,
car5 =  0,
car1x = 0,
car2x = 0,
car3x = 0,
car4x = 0,
car5x = 0;

float en=500;

int aa = 1,
bb = 0,
life = 3;

float speed = 10,score = 0,imp=81;

char score1[10000];

float carxPos = 100,

carxPos2 = 200,
carxPos3 = 300,
carxPos4 =400,
carxPos5 = 500;

union REGS in,out;
void endscreen()
{
	while(1)
	{
		cleardevice();
		setcolor(WHITE);
		settextstyle(1,0,7);
		outtextxy(190,200,"YOU WIN");
		delay(1500);
		cleardevice();
		delay(2000);
		settextstyle(1,0,5);
		outtextxy(130,100,"Special Thanks To");
		settextstyle(1,0,3);
		outtextxy(130,160,"Satish mamu & Vishal annaya");
		delay(2000);
		cleardevice();
		delay(2000);
		settextstyle(1,0,7);
		outtextxy(180,100,"Coded by");
		settextstyle(1,0,4);
		outtextxy(260,180,"Saket");
		delay(2000);
		break;
	}
}
void loading()
{
	while(1)
	{
		imp=imp+0.5;
		setcolor(WHITE);
		rectangle(80,400,540,420);
		setfillstyle(SOLID_FILL,CYAN);
		bar(81,401,imp,419);
		setcolor(WHITE);
		settextstyle(2,0,5);
		outtextxy(290,405,"LOADING");
		if(imp>=540)
		{
			break;
		}
	}
	cleardevice();
}

void exit1()
{
	setfillstyle(SOLID_FILL,8);
	rectangle(200,120,450,320);
	bar(200,120,450,320);
	while(1)
	{
		setcolor(WHITE);
		outtextxy(220,130,"Exit Game?");
		in.x.ax=1;
		int86(0x33,&in,&out);
		in.x.ax=3;
		int86(0x33,&in,&out);
		if(out.x.cx>220&&out.x.cx<290&&out.x.dx>250&&out.x.dx<300&&out.x.bx==1)
		{
			exit(1);
		}

		else if(out.x.cx > 360 && out.x.cx<430&&out.x.dx>250&&out.x.dx<300&&out.x.bx==1)
		{
			in.x.ax=2;
			int86(0x33,&in,&out);
			cleardevice();
			in.x.ax=1	;
			int86(0x33,&in,&out);
			break;
		}

		if(out.x.cx>220&&out.x.cx<290&&out.x.dx>250&&out.x.dx<300)
		{
			setcolor(RED);
			outtextxy(223,245,"Yes");
			rectangle(220,250,290,300);
		}

		else if(out.x.cx>360&&out.x.cx<430&&out.x.dx>250&&out.x.dx<300)
		{
			setcolor(RED);
			outtextxy(375,245,"No");
			rectangle(360,250,430,300);
		}

		else
		{
			rectangle(220,250,290,300);
			rectangle(360,250,430,300);
			outtextxy(223,245,"Yes");
			outtextxy(375,245,"No");
		}
	}
}



void help()
{

	while(1)
	{
		setcolor(WHITE);
		settextstyle(6,0,4);
		outtextxy(10,100,"Use 'a' to move left.");
		outtextxy(10,130,"Use 'd' to move right.");
		outtextxy(10,160,"Use 'x' to exit from the game.");
		outtextxy(10,190,"Be carefull when you press and hold 'a' or");
		outtextxy(10,220,"'d' because the car may slip.");
		outtextxy(10,250,"Dodge the other cars with 'a' and 'd'.");
		outtextxy(10,280,"Score 3000 to win the game.");
		outtextxy(10,400,"Good luck :) .");
		outtextxy(10,310,"You only have three lives so be carefull.");
		outtextxy(10,340,"The speed keeps increasing ,which makes the ");
		outtextxy(10,370,"game hard .");

		in.x.ax=1;
		int86(0x33,&in,&out);
		in.x.ax=3;
		int86(0x33,&in,&out);

		if(out.x.cx>=10&&out.x.cx<=140&&out.x.dx>=10&&out.x.dx<=40)
		{
			setcolor(RED);
			setlinestyle(1,1,THICK_WIDTH);
			rectangle(10,10,140,40);
			settextstyle(5,0,3);  //6 7
			outtextxy(10,0,"Main Menu");

		}

		else
		{
			settextstyle(5,0,3);  //6 7
			setcolor(WHITE);
			rectangle(10,10,140,40);
			outtextxy(10,0,"Main Menu");

		}

		in.x.ax=3;

		if(out.x.cx>=10&&out.x.cx<=140&&out.x.dx>=10&&out.x.dx<=40&&out.x.bx==1)
		{
			in.x.ax=2;
			int86(0x33,&in,&out);
			cleardevice();
			in.x.ax=1;
			int86(0x33,&in,&out);
			cleardevice();
			break;
		}
	}
}
void mainmenu()
{
	in.x.ax=4;
	int86(0x33,&in,&out);
	in.x.cx=0;
	in.x.dx=0;

	while(1)
	{
		in.x.ax=1;
		int86(0x33,&in,&out);
		in.x.ax=3;
		int86(0x33,&in,&out);
		setcolor(WHITE);
		setbkcolor(8);

		if(out.x.cx>=200&&out.x.cx<=420&&out.x.dx>=100&&out.x.dx<=150)
		{
			setlinestyle(1,1,THICK_WIDTH);
			setcolor(RED);
			rectangle(220,100,420,150);
			outtextxy(260,95,"P L A Y");
			setcolor(WHITE);
			rectangle(220,100+100,420,150+100);
			rectangle(220,100+200,420,150+200);
		}

		else if(out.x.cx>=200&&out.x.cx<=420&&out.x.dx>=200&&out.x.dx<=250)
		{
			setlinestyle(1,1,THICK_WIDTH);
			setcolor(RED);
			rectangle(220,200,420,250);
			outtextxy(260,100+95,"H E L P");
			setcolor(WHITE);
			rectangle(220,100,420,150);
			rectangle(220,100+200,420,150+200);
		}

		else if(out.x.cx>=200&&out.x.cx<=420&&out.x.dx>=300&&out.x.dx<=350)
		{
			setlinestyle(1,1,THICK_WIDTH);
			setcolor(RED);
			rectangle(220,300,420,350);
			outtextxy(260,200+95,"E X I T");
			setcolor(WHITE);
			rectangle(220,100,420,150);
			rectangle(220,100+100,420,150+100);
		}

		else
		{
			setlinestyle(1,1,THICK_WIDTH);
			setcolor(WHITE);
			rectangle(220,100,420,150);
			rectangle(220,100+100,420,150+100);
			rectangle(220,100+200,420,150+200);
			settextstyle(10,0,3);
			outtextxy(260,95,"P L A Y");
			outtextxy(260,100+95,"H E L P");
			outtextxy(260,100+195,"E X I T");
		}

		in.x.ax=3;
		int86(0x33,&in,&out);

		if(out.x.cx>=200&&out.x.cx<=420&&out.x.dx>=100&&out.x.dx<=150&&out.x.bx==1)
		{
			out.x.bx = 0;
			in.x.bx =0;
			int86(0x33, &in, &out);
			in.x.ax=2;
			int86(0x33,&in,&out);
			life=3;
			score=0;
			cleardevice();
			loading();
			break;
		}

		in.x.ax=3;
		int86(0x33,&in,&out);

		if(out.x.cx>=200&&out.x.cx<=420&&out.x.dx>=300&&out.x.dx<=350&&out.x.bx==1)
		{
			exit1();
		}

		in.x.ax=3;

		if(out.x.cx>=200&&out.x.cx<=420&&out.x.dx>=200&&out.x.dx<=250&&out.x.bx==1)
		{

			in.x.ax=4;
			int86(0x33,&in,&out);
			in.x.cx=0;
			in.x.dx=0;
			cleardevice();
			help();
		}
	}
}


void life3 ()
{       settextstyle(1,0,2);
	setlinestyle(0,1,NORM_WIDTH);
	setcolor(RED);
	arc (400, 460, 0, 180, 4);
	arc (409, 460, 0, 180, 4);
	line (395, 460, 405, 473);
	line (414, 460, 405, 473);
	arc (400 + 20, 460, 0, 180, 4);
	arc (409 + 20, 460, 0, 180, 4);
	line (395 + 20, 460, 405 + 20, 473);
	line (414 + 20, 460, 404 + 20, 473);
	arc (400 + 20 + 20, 460, 0, 180, 4);
	arc (409 + 20 + 20, 460, 0, 180, 4);
	line (395 + 20 + 20, 460, 405 + 20 + 20, 473);
	line (414 + 20 + 20, 460, 404 + 20 + 20, 473);

}
void life1 ()
{
	setcolor(RED);
	arc (400, 460, 0, 180, 4);
	arc (409, 460, 0, 180, 4);
	line (395, 460, 405, 473);
	line (414, 460, 404, 473);

}

void life2 ()
{
	setcolor(RED);
	arc (400, 460, 0, 180, 4);
	arc (409, 460, 0, 180, 4);
	line (395, 460, 405, 473);
	line (414, 460, 404, 473);
	arc (400 + 20, 460, 0, 180, 4);
	arc (409 + 20, 460, 0, 180, 4);
	line (395 + 20, 460, 405 + 20, 473);
	line (414 + 20, 460, 404 + 20, 473);

}

void lm()
{
	if(life==1)
	{
		life1();
	}

	if(life==2)
	{
		life2();
	}

	if(life==3)
	{
		life3();
	}

	if(life==0)
	{
		cleardevice();
		mainmenu();
	}
}

void player ()
{
	if(life==0)
	{
		mainmenu();
	}

	if (life == 1)
	{
		life1 ();
	}

	if (life == 3)
	{
		life3 ();
	}

	if (life == 2)
	{
		life2 ();
	}

	speed=score/100;
	settextstyle(1,0,1);
	score = score + 1;
	sprintf (score1, "%.2f", score);
	setfillstyle (SOLID_FILL, 8);
	bar (500, 440, 630, 480);
	outtextxy (500, 460, score1);
	setbkcolor (8);
	setfillstyle (INTERLEAVE_FILL, CYAN);
	setcolor (WHITE);
	bar (x - 15, y - 25, x + 15, y + 25);
	setfillstyle (SOLID_FILL, 7);

	if (aa == 1)
	{
		bb = x;
	}


	if (x + 15 > carxPos2 - 20 && y - 25 < car2x - 30 && x - 15 < carxPos2 + 20)
	{
		life = life - 1;
		cleardevice ();
		setfillstyle (INTERLEAVE_FILL, CYAN);
		delay (500);
		bar (x - 15, y - 25, x + 15, y + 25);
		lm();
		score = score + 1;
		outtextxy (500, 460, score1);
		delay (500);
		cleardevice ();
		delay (500);
		bar (x - 15, y - 25, x + 15, y + 25);
		lm();
		score = score + 1;
		outtextxy (500, 460, score1);
		delay (500);
		cleardevice ();
		delay (500);
		score = score + 1;
		bar (x - 15, y - 25, x + 15, y + 25);
		lm();
		outtextxy (500, 460, score1);
		delay (500);
		carxPos = 100, carxPos2 = 200, carxPos3 = 300, carxPos4 =400, carxPos5 = 500;
		y = 430, car1 = 0, car2 = 0, car3 = 0, car4 = 0, car5 = 0, car1x =0, car2x = 0, car3x = 0, car4x = 0, car5x = 0;
		aa = 1, bb = 0;

	}

	if (x + 15 > carxPos3 - 20 && y - 25 < car3x - 90 && x - 15 < carxPos3 + 20)
	{
		life = life - 1;
		cleardevice ();
		setfillstyle (INTERLEAVE_FILL, CYAN);
		delay (500);
		bar (x - 15, y - 25, x + 15, y + 25);
		lm();
		score = score + 1;
		outtextxy (500, 460, score1);
		delay (500);
		cleardevice ();
		delay (500);
		bar (x - 15, y - 25, x + 15, y + 25);
		lm();
		score = score + 1;
		outtextxy (500, 460, score1);
		delay (500);
		cleardevice ();
		delay (500);
		score = score + 1;
		bar (x - 15, y - 25, x + 15, y + 25);
		lm();
		outtextxy (500, 460, score1);
		delay (500);
		carxPos = 100, carxPos2 = 200, carxPos3 = 300, carxPos4 =400, carxPos5 = 500;
		y = 430, car1 = 0, car2 = 0, car3 = 0, car4 = 0, car5 = 0, car1x =0, car2x = 0, car3x = 0, car4x = 0, car5x = 0;
		aa = 1, bb = 0;

	}

	if (x + 15 > carxPos4 - 20 && y - 25 < car4x - 150 && x - 15 < carxPos4 + 20)
	{

		life = life - 1;
		cleardevice ();
		setfillstyle (INTERLEAVE_FILL, CYAN);
		delay (500);
		bar (x - 15, y - 25, x + 15, y + 25);
		lm();
		score = score + 1;
		outtextxy (500, 460, score1);
		delay (500);
		cleardevice ();
		delay (500);
		bar (x - 15, y - 25, x + 15, y + 25);
		lm();
		score = score + 1;
		outtextxy (500, 460, score1);
		delay (500);
		cleardevice ();
		delay (500);
		score = score + 1;
		bar (x - 15, y - 25, x + 15, y + 25);
		lm();
		outtextxy (500, 460, score1);
		delay (500);
		carxPos = 100, carxPos2 = 200, carxPos3 = 300, carxPos4 =400, carxPos5 = 500;
		y = 430, car1 = 0, car2 = 0, car3 = 0, car4 = 0, car5 = 0, car1x =0, car2x = 0, car3x = 0, car4x = 0, car5x = 0;
		aa = 1, bb = 0;
	}

	if (x + 15 > carxPos5 - 20 && y - 25 < car5x - 210 && x - 15 < carxPos5 + 20)
	{
		life = life - 1;
		cleardevice ();
		setfillstyle (INTERLEAVE_FILL, CYAN);
		delay (500);
		bar (x - 15, y - 25, x + 15, y + 25);
		lm();
		score = score + 1;
		outtextxy (500, 460, score1);
		delay (500);
		cleardevice ();
		delay (500);
		bar (x - 15, y - 25, x + 15, y + 25);
		lm();
		score = score + 1;
		outtextxy (500, 460, score1);
		delay (500);
		cleardevice ();
		delay (500);
		score = score + 1;
		bar (x - 15, y - 25, x + 15, y + 25);
		lm();
		outtextxy (500, 460, score1);
		delay (500);
		carxPos = 100, carxPos2 = 200, carxPos3 = 300, carxPos4 =400, carxPos5 = 500;
		y = 430, car1 = 0, car2 = 0, car3 = 0, car4 = 0, car5 = 0, car1x =
		0, car2x = 0, car3x = 0, car4x = 0, car5x = 0;
		aa = 1, bb = 0;
	}

	if (x + 15 > carxPos - 20 && y - 25 < car1x + 30 && x - 15 < carxPos + 20)
	{
		life = life - 1;
		cleardevice ();
		setfillstyle (INTERLEAVE_FILL, CYAN);
		delay (500);
		bar (x - 15, y - 25, x + 15, y + 25);
		lm();
		score = score + 1;
		setfillstyle (INTERLEAVE_FILL, CYAN);
		outtextxy (500, 460, score1);
		delay (500);
		cleardevice ();
		delay (500);
		bar (x - 15, y - 25, x + 15, y + 25);
		lm();
		score = score + 1;
		outtextxy (500, 460, score1);
		delay (500);
		cleardevice ();
		delay (500);
		score = score + 1;
		bar (x - 15, y - 25, x + 15, y + 25);
		lm();
		outtextxy (500, 460, score1);
		delay (500);
		carxPos = 100, carxPos2 = 200, carxPos3 = 300, carxPos4 =
		400, carxPos5 = 500;
		y = 430, car1 = 0, car2 = 0, car3 = 0, car4 = 0, car5 = 0, car1x =
		0, car2x = 0, car3x = 0, car4x = 0, car5x = 0;
		aa = 1, bb = 0;
	}

	if(x-15<0)
	{
		 x=15;
	}

	if(x+15>650)
	{
		x=x-15;
	}

	if (life == 0)
	{
		exit (1);
	}


	if (car1x > 475)
	{
		setfillstyle (SOLID_FILL, 8);
		bar (carxPos - 20, car1x - 30, carxPos + 20, car1x + 30);
		car1x = 0;
		carxPos = random (637);
		setcolor (8);
	}

	if (car2x > 535)
	{
		setfillstyle (SOLID_FILL, 8);
		bar (carxPos2 - 20, car2x - 90, carxPos2 + 20, car2x - 30);
		car2x = 0;
		carxPos2 = random (637);
	}

	if (car3x > 595)
	{
		setfillstyle (SOLID_FILL, 8);
		setcolor (8);
		bar (carxPos3 - 20, car3x - 150, carxPos3 + 20, car3x - 90);
		car3x = 0;
		carxPos3 = random (637);
	}

	if (car4x > 655)
	{
		setfillstyle (SOLID_FILL, 8);
		bar (carxPos4 - 20, car4x - 210, carxPos4 + 20, car4x - 150);
		car4x = 0;
		carxPos4 = random (637);
	}

	if (car5x > 715)
	{
		setfillstyle (SOLID_FILL, 8);
		bar (carxPos5 - 20, car5x - 270, carxPos5 + 20, car5x - 210);
		car5x = 0;
		carxPos5 = random (637);
	}

	if(score>=3000)
	{
		endscreen();
		cleardevice();
		mainmenu();
	}

	aa = 0;
	setfillstyle (SOLID_FILL, 8);
	setfillstyle (SOLID_FILL, 8);
	bar (carxPos - 20, car1x - 30, carxPos + 20, car1x + 30);
	bar (carxPos2 - 20, car2x - 90, carxPos2 + 20, car2x - 30);
	bar (carxPos3 - 20, car3x - 150, carxPos3 + 20, car3x - 90);
	bar (carxPos4 - 20, car4x - 210, carxPos4 + 20, car4x - 150);
	bar (carxPos5 - 20, car5x - 270, carxPos5 + 20, car5x - 210);
	setcolor (WHITE);
	car1x = car1x + speed;
	car2x = car2x + speed;
	car3x = car3x + speed;
	car4x = car4x + speed;
	car5x = car5x + speed;
	setfillstyle (LINE_FILL, RED);
	bar (carxPos - 20, car1x - 30, carxPos + 20, car1x + 30);
	setfillstyle (XHATCH_FILL, BROWN);
	bar (carxPos2 - 20, car2x - 90, carxPos2 + 20, car2x - 30);
	setfillstyle (LTSLASH_FILL, GREEN);
	bar (carxPos3 - 20, car3x - 150, carxPos3 + 20, car3x - 90);
	setfillstyle (WIDE_DOT_FILL, BLUE);
	bar (carxPos4 - 20, car4x - 210, carxPos4 + 20, car4x - 150);
	setfillstyle (CLOSE_DOT_FILL, YELLOW);
	bar (carxPos5 - 20, car5x - 270, carxPos5 + 20, car5x - 210);
	delay (20);
	delay (20);
}


void main ()
{
	int gdriver = DETECT, gmode;
	initgraph (&gdriver, &gmode, "c:\\turboc3\\bgi");
	mainmenu();
	randomize ();
	while (1)
	{
		if (kbhit ())
		{
			switch (getch ())
			{
				case 'a':
				setfillstyle (SOLID_FILL, 8);
				bar (x - 15, y - 25, x + 15, y + 25);
				x = x - 10;
				break;
				case 'd':
				setfillstyle (SOLID_FILL, 8);
				bar (x - 15, y - 25, x + 15, y + 25);
				x = x + 10;
				break;
				case 'p':
				settextstyle(1,0,2);
				setcolor(WHITE);
				outtextxy(240,240,"Game paused");
				getch();
				cleardevice();
				break;
				case 'x':
				cleardevice();
				mainmenu();
			}
		}

	player ();

	}
}
