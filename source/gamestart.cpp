//gamestart.cpp
#include "gamestart.h"
#include "monster.h"
#include "createpacman.h"
#include "laberynth.h"
#include "main.h"
#include "gameover.h"
#include "food.h"
#include "gameresult.h"
#include "control.h"

//��ӭ����
void welcomeScreen() {
	glClearColor(0, 0.2, 0.4, 1.0);
	string message = "*************************************";
	string::iterator it = message.begin();
	glRasterPos2f(150, 200);
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
	message = "Pacman - by Muchenhen";
	glColor3f(1, 1, 1);
	glRasterPos2f(225, 250);
	it = message.begin();
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
	message = "*************************************";
	glRasterPos2f(150, 300);
	it = message.begin();
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
	message = "To control Pacman use A to go right, D to go left, W to go up and S to go down.";
	glRasterPos2f(50, 400);
	it = message.begin();
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
	message = "To start or restart the game, press the space key.";
	glRasterPos2f(170, 450);
	it = message.begin();
	while (it != message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
}

//��ʾ��Ļ��Ԫ��
void display() {
	if (points == 1) {
		over = false;
	}
	keyOperations();
	glClear(GL_COLOR_BUFFER_BIT);    //�����ɫ������(��ǰ������Ϊд��������ɫ����)
	gameOver();
	if (replay) {
		if (!over) {
			drawLaberynth();
			drawFood((1.5 + xIncrement) * squareSize, (1.5 + yIncrement) * squareSize);
			drawPacman(1.5 + xIncrement, 1.5 + yIncrement, rotation);
			updateMonster(monster1, 1);
			updateMonster(monster2, 2);
			updateMonster(monster3, 3);
			updateMonster(monster4, 4);
			drawMonster(monster1[0], monster1[1], 0.0, 1.0, 1.0); //cyan
			drawMonster(monster2[0], monster2[1], 1.0, 0.0, 0.0); //red
			drawMonster(monster3[0], monster3[1], 1.0, 0.0, 0.6); //magenta
			drawMonster(monster4[0], monster4[1], 1.0, 0.3, 0.0); //orange
		}
		else {
			resultsDisplay();
		}
	}
	else {
		welcomeScreen();
	}
	glutSwapBuffers();
}

//���ô���
void reshape(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glOrtho(0, 750, 750, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
