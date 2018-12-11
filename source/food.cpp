//food.cpp
#include "food.h"
#include "main.h"

//���ʳ���Ƿ񱻳�
bool foodEaten(int x, int y, float pacmanX, float pacmanY) {
	if (x >= pacmanX - 16.0 *cos(359 * M_PI / 180.0) && x <= pacmanX + 16.0*cos(359 * M_PI / 180.0)) {
		if (y >= pacmanY - 16.0*cos(359 * M_PI / 180.0) && y <= pacmanY + 16.0*cos(359 * M_PI / 180.0)) {
			return true;
		}
	}
	return false;
}

//����ʳ��
void drawFood(float pacmanX, float pacmanY) {
	deque<float> temp;
	//���ʳ���Ƿ�û�б��Ե�
	for (deque<float>::size_type i = 0; i < food.size(); i = i + 2) {
		if (!foodEaten(food.at(i)*squareSize, food.at(i + 1)*squareSize, pacmanX, pacmanY)) {
			temp.push_back(food.at(i));
			temp.push_back(food.at(i + 1));
		}
		else {
			points++;
		}
	}
	food.swap(temp);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 1.0);
	//����ʳ��
	for (deque<float>::size_type j = 0; j < food.size(); j = j + 2) {
		glVertex2f(food.at(j)*squareSize, food.at(j + 1)*squareSize);//����
	}
	glEnd();
}
