#pragma once
//main.h
#ifndef _MAIN_H_
#define _MAIN_H_
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <deque>


#include <GL/glut.h>
using namespace std;

extern bool replay;         //����Ƿ�������Ϸ
extern bool over;             //�����Ϸ�Ƿ����
extern float squareSize;     //һ����Ԫ��С
extern float xIncrement;     // x����
extern float yIncrement;     // y����
extern int rotation;         // ����
extern float* monster1;     //��һ�����������ͷ���
extern float* monster2;     //�ڶ������������ͷ���
extern float* monster3;     //���������������ͷ���
extern float* monster4;     //���ĸ����������ͷ���
extern vector<int> border;     //ǽ����

//�ϰ������� (Ϊ��������Ϊ������)
extern vector<int> obstaclesTop;
extern vector<int> obstaclesMiddle;
extern vector<int> obstaclesBottom;
extern deque<float> food;
extern vector<vector<bool>> bitmap;     // 2dͼ�񣬿��ƶ�����
extern bool* keyStates;                 // ����״̬
extern int points;                         // �÷�
#endif
