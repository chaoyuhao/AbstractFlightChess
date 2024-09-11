#pragma once

#ifndef AFC_H_

#include<stdio.h>
#include<iostream>
#include<graphics.h>
#include<easyx.h>
#include<mmsystem.h>
#include<ctime>
#include<string>
#include<cmath>
#include<mmsystem.h>
#include<stdlib.h>
#include<vector>
//#define DEBUG
#pragma comment(lib, "winmm.lib")

using namespace std;

// function
void imageLoad();
void btnInit();
void corInit();
void resourceLoad();

int welcomePage();
int setting();
void about();

int playerRobot();
int characterChoose();

inline void gamePageDraw();
void winnerPageDraw();

int mainGame();
void showImgC(int);
int getDice();
bool circleAirplane(int, int);
void deleteCircle(int);
int getAirplane(int);
void eatAirplane(int, int, int);
int extraJump(int, int, int);
bool checkWin(int);
int getDiceR();
int getAirplaneR(int, int);

int getNextState(int);

void coor();
int godNeverThrowDice();

const int GRAPH_WIDTH = 1200;
const int GRAPH_HEIGHT = 800;

// variable
bool god_mode;
bool developer_mode;
bool record_document;

bool master_robot;
bool canvas_open;
bool robot_control[4];
bool player_control[4];
bool game_end;
bool character_selected[8];
int player_id[8], character_id[4];
int robot_num;
int player_num;
int least_go_out_number;
int ord[4];
int winner_id;

IMAGE background_welcomepage, background_about, background_setting;
IMAGE tick, wtick;
IMAGE player_robot, player_robot_ok;
IMAGE character_choose[8], choose_your_legend, selected_img;
IMAGE blank, character_normal[8], character_win[8], character_lose[8];
IMAGE chessboard, plane[4][5], wplane[4][5], airplanewin, wairplanewin;
IMAGE dice[7], nodice;

struct button {
	
	int upLeftx;
	int upLefty;
	int downRightx;
	int downRighty;
	bool rectangle;

	int centrex;
	int centrey;
	int radius;
	bool circle;

	bool btn_abolish;

	bool inButton(int x, int y) {
		if (btn_abolish) return false;
		if (rectangle)
			return (x > upLeftx && x < downRightx&& y < downRighty&& y > upLefty);
		if (circle)
			return ((x - centrex) * (x - centrex) + (y - centrey) * (y - centrey) < radius * radius);
	}
};
button start_btn, setting_btn, exit_btn, about_btn, music_btn;
button character_choose_btn[8], character_music_btn, character_exit_btn;
button player_btn[4], robot_btn[4], prok_btn;
button throw_dice, game_music_btn, game_exit_btn;
button plane_circle[4][4];
button as_exit_btn, as_music_btn;
button set_dice, set_mr, set_sr;
button win_exit_btn, win_music_btn;

struct cor {
	int x;
	int y;
};
cor map[100];
cor hangar[4][4];
cor ready[4];
cor wintrack[4][10];
cor sculptrue[4];
cor myturn, dice_p;

struct airplane {
	IMAGE* p;
	IMAGE* wp;
	int step;
	int winstep;
	bool in_hangar;
	bool in_ready;
	bool in_track;
	bool in_wintrack;
	bool is_win;
};

airplane air[4][4];

#endif // !AFC_H_
