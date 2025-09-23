#include "graphics.h"


#include <stdlib.h>
#include <stdio.h>
#include <time.h>


char* lines[] = {"ПОСЛУШАЙТЕ!",
		"Ведь, если звезды зажигают -",
		"значит - это кому-нибудь нужно?",
		"Значит - кто-то хочет, чтобы они были?",
		"Значит - кто-то называет эти плевочки",
		"жемчужиной?",
		"",
		"И, надрываясь",
		"в метелях полуночной пыли,",
		"врывается к богу,",
		"боится, что опоздал,",
		"плачет,",
		"целует ему жилистую руку,",
		"просит -",
		"чтоб обязательно была звезда! -",
		"клянется -",
		"не перенесет эту беззвездную муку!",
		"",
		"А после",
		"ходит тревожный,",
		"но спокойный наружно.",
		"Говорит кому-то:",
		"«Ведь теперь тебе ничего?",
		"Не страшно?",
		"Да?!»",
		"",
		"Послушайте!",
		"Ведь, если звезды зажигают -",
		"значит - это кому-нибудь нужно?",
		"Значит - это необходимо,",
		"чтобы каждый вечер",
		"над крышами",
		"загоралась хоть одна звезда?!"
};
void planet(int width, int height, int size,int Color,bool has_sputnik = false,int background_color=1, bool has_ring=false) {
	setcolor(Color);
	circle(width, height, size);
	setfillstyle(1, background_color);
	floodfill(width, height, Color);
	if (has_sputnik) {
		
		setcolor(15);
		if (width % 2 == 0){ circle(width- size, height- size, size/3);
		setfillstyle(SOLID_FILL, 0);
		floodfill(width - size, height - size, 15);
	
		}
		else {
			circle(width+ size, height+ size, size / 3);
			setfillstyle(SOLID_FILL, 0);
			floodfill(width + size, height + size, 15);
	
		}
	}
	if (has_ring) {
		setcolor(8);
		ellipse(width, height, 0, 360, size + 5, size / 3);

	}
}


void star(int width, int height,int size=0,int Color=15) {
	int i_add = -1;
	putpixel(width, height, Color);
	putpixel(width - 1, height - 1, Color);
	putpixel(width + 1, height + 1, Color);
	putpixel(width - 1, height + 1, Color);
	putpixel(width + 1, height - 1, Color);
	if (size >= 10) i_add =0;
	int i = 0; 
	while (i != size) {
		putpixel(width , height - i, Color);
		putpixel(width + i, height , Color);
		putpixel(width - i, height , Color);
		putpixel(width, height + i, Color);
		if ((i_add<(size-10))&&(i_add != -1))  {
			putpixel(width - (i_add), height - (i_add), Color);
			putpixel(width + (i_add), height + (i_add), Color);
			putpixel(width - (i_add), height + (i_add), Color);
			putpixel(width + (i_add), height - (i_add), Color);
			i_add += 1;
	
		}
		
		i +=1;


	}
}
void drawUrsaMajor(int centerX, int centerY) {
	// Координаты звезд Большой Медведицы с учетом центра
	int stars[7][2] = {
			{centerX ,  centerY },
		{centerX + 110,   centerY + 10},     
		{centerX + 95,  centerY + 50}, 
		{centerX + 10,  centerY + 40},    
		{centerX + -50, centerY + -30}, 
		{centerX + -110, centerY + -40}, 
		{centerX + -170,  centerY + -42}     
	};

	//звезды созвездия
	for (int i = 0; i < 7; i++) {
		star(stars[i][0], stars[i][1], 6 + rand() % 4, COLOR(255, 255, 150 + rand() % 50));
	}

	//Соединяем звезды 
	setcolor(COLOR(180, 180, 100));
	setlinestyle(0, 0, 2);

	line(stars[0][0], stars[0][1], stars[1][0], stars[1][1]);
	line(stars[1][0], stars[1][1], stars[2][0], stars[2][1]);
	line(stars[2][0], stars[2][1], stars[3][0], stars[3][1]);
	line(stars[3][0], stars[3][1], stars[0][0], stars[0][1]);
	line(stars[0][0], stars[0][1], stars[4][0], stars[4][1]);
	line(stars[4][0], stars[4][1], stars[5][0], stars[5][1]);
	line(stars[5][0], stars[5][1], stars[6][0], stars[6][1]);

	
}
int main()
{
	srand(time(NULL));
	int total_lines = sizeof(lines) / sizeof(lines[0]);
	int current_line = 0;
	int width = 1200;
	int height = 600;
	int R = 222 + rand() % 55;
	int G = 222 + rand() % 55;
	int B = 200 + rand() % 55;
	int random_size = rand() % 20;
	int random_width = 100 + rand() % ((width-100) - 100);
	int random_height = 100 + rand() % ((height- 100) - 100);
	int star_speed = 7;
	initwindow(width, height, "First Sample");

	setactivepage(1);  // Рисуем на странице 1
	setvisualpage(0);   // Показываем страницу 0

	
	while (true) {
		// Рисуем на буферной странице

		cleardevice();
		
		random_width += star_speed;
		if (random_width % 2 != 0) random_height += star_speed/7; else random_height -= star_speed/7;
		if (random_width > width + 120) {
			random_width = -250;

		}
		for (int i = 0; i < 50; i++) {

			star(rand() % width, rand() % height, rand() % 20, COLOR(150 + rand() % 100, 150 + rand() % 100, 150 + rand() % 100));
		}
		
		drawUrsaMajor(500, height - 100);
		planet(random_width +150, random_height + 50, 35, COLOR(150 + rand() % (255 - 150), 100 + rand() % (200 - 100), rand() % 100), false, COLOR(rand() % 55, rand() % 55, rand() % 55));

		planet(random_width, random_height, 50, COLOR(150 + rand() % (255 - 150), 100 + rand() % (200 - 100), rand() % 100), true, COLOR(rand() % 55, rand() % 55, rand() % 55), true);
		planet(random_width + 250, random_height + 150, 40, COLOR(150 + rand() % (255 - 150), 100 + rand() % (200 - 100), rand() % 100), false, COLOR(rand() % 55, rand() % 55, rand() % 55), true);
		planet(random_width +150, random_height - 50, 10, COLOR(150 + rand() % (255 - 150), 100 + rand() % (200 - 100), rand() % 100), true, COLOR(rand() % 55, rand() % 55, rand() % 55));

		setcolor(WHITE);
		int y_pos = height - 200;
		for (int i = 0; i < 5 && current_line + i < total_lines; i++) {
			outtextxy(50, y_pos, lines[current_line + i]);
			y_pos += 40;
		}

		if (getactivepage() == 0) {
			setvisualpage(0);
			setactivepage(1);
		}
		else {
			setvisualpage(1);
			setactivepage(0);
		}
		if (kbhit()) {
			char key = getch();

			if (key == ' ') { // Пробел - следующая строка
				current_line++;
				if (current_line >= total_lines) {
					current_line = 0; // Начинаем заново
				}
			}
			else if (key == 27) { // ESC - выход
				break;
			}
			
		}
		delay(100);

	}
	return 0;
}
//
//#include "graphics.h"
//
//
//#include <stdlib.h>
//#include <stdio.h>
//#include <time.h>
//
//
//char* lines[] = { "ПОСЛУШАЙТЕ!",
//		"Ведь, если звезды зажигают -",
//		"значит - это кому-нибудь нужно?",
//		"Значит - кто-то хочет, чтобы они были?",
//		"Значит - кто-то называет эти плевочки",
//		"жемчужиной?",
//		"",
//		"И, надрываясь",
//		"в метелях полуночной пыли,",
//		"врывается к богу,",
//		"боится, что опоздал,",
//		"плачет,",
//		"целует ему жилистую руку,",
//		"просит -",
//		"чтоб обязательно была звезда! -",
//		"клянется -",
//		"не перенесет эту беззвездную муку!",
//		"",
//		"А после",
//		"ходит тревожный,",
//		"но спокойный наружно.",
//		"Говорит кому-то:",
//		"«Ведь теперь тебе ничего?",
//		"Не страшно?",
//		"Да?!»",
//		"",
//		"Послушайте!",
//		"Ведь, если звезды зажигают -",
//		"значит - это кому-нибудь нужно?",
//		"Значит - это необходимо,",
//		"чтобы каждый вечер",
//		"над крышами",
//		"загоралась хоть одна звезда?!"
//};
//void planet(int width, int height, int size, int Color, bool has_sputnik = false, int background_color = 1, bool has_ring = false) {
//	setcolor(Color);
//
//	circle(width, height, size);
//	setfillstyle(1, background_color);
//	floodfill(width, height, Color);
//	if (has_sputnik) {
//
//		setcolor(15);
//		if (width % 2 == 0) {
//			circle(width - size, height - size, size / 3);
//			setfillstyle(SOLID_FILL, 0);
//			floodfill(width - size, height - size, 15);
//
//		}
//		else {
//			circle(width + size, height + size, size / 3);
//			setfillstyle(SOLID_FILL, 0);
//			floodfill(width + size, height + size, 15);
//
//		}
//	}
//	if (has_ring) {
//		setcolor(8);
//		ellipse(width, height, 0, 360, size + 5, size / 3);
//
//	}
//}
//
//
//void star(int width, int height, int size = 0, int Color = 15) {
//	int i_add = -1;
//	putpixel(width, height, Color);
//	putpixel(width - 1, height - 1, Color);
//	putpixel(width + 1, height + 1, Color);
//	putpixel(width - 1, height + 1, Color);
//	putpixel(width + 1, height - 1, Color);
//	if (size >= 10) i_add = 0;
//	int i = 0;
//	while (i != size) {
//		putpixel(width, height - i, Color);
//		putpixel(width + i, height, Color);
//		putpixel(width - i, height, Color);
//		putpixel(width, height + i, Color);
//		if ((i_add < (size - 10)) && (i_add != -1)) {
//			putpixel(width - (i_add), height - (i_add), Color);
//			putpixel(width + (i_add), height + (i_add), Color);
//			putpixel(width - (i_add), height + (i_add), Color);
//			putpixel(width + (i_add), height - (i_add), Color);
//			i_add += 1;
//
//		}
//
//		i += 1;
//
//
//	}
//}
//void drawUrsaMajor(int centerX, int centerY) {
//	// Координаты звезд Большой Медведицы с учетом центра
//	int stars[7][2] = {
//			{centerX ,  centerY },
//		{centerX + 110,   centerY + 10},
//		{centerX + 95,  centerY + 50},
//		{centerX + 10,  centerY + 40},
//		{centerX + -50, centerY + -30},
//		{centerX + -110, centerY + -40},
//		{centerX + -170,  centerY + -42}
//	};
//
//	//звезды созвездия
//	for (int i = 0; i < 7; i++) {
//		star(stars[i][0], stars[i][1], 6 + rand() % 4, COLOR(255, 255, 150 + rand() % 50));
//	}
//
//	//Соединяем звезды 
//	setcolor(COLOR(180, 180, 100));
//	setlinestyle(0, 0, 2);
//
//	line(stars[0][0], stars[0][1], stars[1][0], stars[1][1]);
//	line(stars[1][0], stars[1][1], stars[2][0], stars[2][1]);
//	line(stars[2][0], stars[2][1], stars[3][0], stars[3][1]);
//	line(stars[3][0], stars[3][1], stars[0][0], stars[0][1]);
//	line(stars[0][0], stars[0][1], stars[4][0], stars[4][1]);
//	line(stars[4][0], stars[4][1], stars[5][0], stars[5][1]);
//	line(stars[5][0], stars[5][1], stars[6][0], stars[6][1]);
//
//
//}
//
//int width = 1200;
//int height = 600;
//int total_lines;
//int current_line = 0;
//int random_height;
//int star_speed = 7;
//
//
//
//void move_recursive(int x, int steps) {
//	
//	if (steps <= 0) {
//		getch();
//		
//		exit(0); return; }// выход
//
//	// Рисуем на буферной странице
//
//	cleardevice();
//
//	// Фоновые звезды
//	for (int i = 0; i < 50; i++) {
//		star(rand() % width, rand() % height, rand() % 20,
//			COLOR(150 + rand() % 100, 150 + rand() % 100, 150 + rand() % 100));
//	}
//
//	drawUrsaMajor(500, height - 100);
//
//	planet(x + 150, random_height + 50, 35,
//		COLOR(150 + rand() % 105, 100 + rand() % 100, rand() % 100),
//		false, COLOR(rand() % 55, rand() % 55, rand() % 55));
//
//	planet(x, random_height, 50,
//		COLOR(150 + rand() % 105, 100 + rand() % 100, rand() % 100),
//		true, COLOR(rand() % 55, rand() % 55, rand() % 55), true);
//
//	planet(x + 250, random_height + 150, 40,
//		COLOR(150 + rand() % 105, 100 + rand() % 100, rand() % 100),
//		false, COLOR(rand() % 55, rand() % 55, rand() % 55), true);
//
//	planet(x + 150, random_height - 50, 10,
//		COLOR(150 + rand() % 105, 100 + rand() % 100, rand() % 100),
//		true, COLOR(rand() % 55, rand() % 55, rand() % 55));
//
//	// Текст
//	setcolor(WHITE);
//	int y_pos = height - 200;
//	for (int i = 0; i < 5 && current_line + i < total_lines; i++) {
//		outtextxy(50, y_pos, lines[current_line + i]);
//		y_pos += 40;
//	}
//
//	
//	if (getactivepage() == 0) {
//		setvisualpage(0);
//		setactivepage(1);
//	}
//	else {
//		setvisualpage(1);
//		setactivepage(0);
//	}
//
//	if (kbhit()) {
//		char key = getch();
//		if (key == ' ') {
//			current_line++;
//			if (current_line >= total_lines) {
//				current_line = 0;
//			}
//		}
//		else if (key == 27) {
//			closegraph();
//			exit(0);
//		}
//	}
//
//	delay(100);
//
//	move_recursive(x + star_speed, steps - 1);
//}
//int main()
//{
//	int steps;
//	printf("Steps: ");
//	scanf("%d", &steps);
//
//	total_lines = sizeof(lines) / sizeof(lines[0]);
//	random_height = 100 + rand() % ((height - 100) - 100);
//
//	initwindow(width, height, "First Sample");
//	setactivepage(1);
//	setvisualpage(0);
//
//	move_recursive(50, steps);
//
//	closegraph();
//	getch();
//	return 0;
//}
