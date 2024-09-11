#define _CRT_SECURE_NO_WARNINGS
#include"afc.h"
//#define DEBUG
using namespace std;

int main() {

// Welcome to Abstract Flight Chess
// Author: cyh 
// Student ID: 221240013

// If you want to develop, you can use developer mode.
// In this mode you can get the location of your mouse.
// Left click to record your mouse location.
// Right click to skip this part. (¿Ï¶¨²»ÊÇÒòÎªÎÒÀÁµÃÐ´¶àÏß³Ì)
// true -> open developer mode
	developer_mode = false;


// If you want to determine every dice you throw, you can use god mode.
// In this mode you can determine your dice number.
// Type the number in the console when the dice is twisting.
// true -> open god mode
	god_mode = false;


// If you want a document to write down the process of the game, you can record document.
// When you exit the game, 
// this program will generate a file called "afc.out".
// Remember to copy it as fast as possible if you want to save it.
// true -> open document recording
	record_document = false;


// DEBUG is the required function.
// Obviously, you will be the god.
// But you can't be the developer at the same time, 
// and the document won't be recorded yet.
// Because the developer mode could destory your game experience.
// What you can do has been described above.
#ifdef DEBUG 
	developer_mode = false;
	god_mode = true;
	record_document = false;
#endif

	// Now, just compile the program and enjoy the game!
	
	resourceLoad();

	int state = getNextState(0);

	return 0;
}



void coor() {
	cout << "coordinate getting mode, right click to continue" << endl;
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			setfillcolor(RED);
			solidcircle(m.x, m.y, 10);
			/*BeginBatchDraw();
			putimage(m.x, m.y, &plane[0][4], SRCAND);
			putimage(m.x, m.y, &wplane[0][4], SRCPAINT);
			EndBatchDraw();*/
			cout << endl;
			break;
		case WM_RBUTTONDOWN:
			cout << "\rBegin this page                                 " << endl;
			return;
		case WM_MOUSEMOVE:
			cout << "\r                                             \r";
			cout << m.x << ' ' << m.y;
		}
	}
	return;
}

void winnerPageDraw() {

	BeginBatchDraw();
	putimage(0, 0, &character_win[winner_id]);
	EndBatchDraw();
	
	if (developer_mode) coor();

	bool pause_cd = false;
	mciSendString(L"open victory.mp3", NULL, 0, NULL);
	mciSendString(L"play victory.mp3 repeat", NULL, 0, NULL);
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			cout << "click" << endl;
			if (win_exit_btn.inButton(m.x, m.y)) {
				cout << "back to welcome page" << endl;
				mciSendString(L"stop victory.mp3", NULL, 0, NULL);
				return;
			}
			if (win_music_btn.inButton(m.x, m.y)) {
				cout << "music" << endl;
				if(pause_cd) mciSendString(L"play victory.mp3 repeat", NULL, 0, NULL);
				else mciSendString(L"stop victory.mp3", NULL, 0, NULL);
				pause_cd = !pause_cd;
			}
		}
	}

	return;
}

void btnInit() {

	// start: 458 345   754 416
	start_btn.upLeftx = 458;
	start_btn.upLefty = 345;
	start_btn.downRightx = 754;
	start_btn.downRighty = 416;
	start_btn.rectangle = true;

	// setting: 459 459   754 531
	setting_btn.upLeftx = 458;
	setting_btn.upLefty = 459;
	setting_btn.downRightx = 754;
	setting_btn.downRighty = 531;
	setting_btn.rectangle = true;

	// exit: 459 569   754 644
	exit_btn.upLeftx = 458;
	exit_btn.upLefty = 569;
	exit_btn.downRightx = 754;
	exit_btn.downRighty = 644;
	exit_btn.rectangle = true;

	// about: 459 683   754 754
	about_btn.upLeftx = 458;
	about_btn.upLefty = 683;
	about_btn.downRightx = 754;
	about_btn.downRighty = 754;
	about_btn.rectangle = true;

	// music: 41 46    r = 30
	music_btn.centrex = 41;
	music_btn.centrey = 46;
	music_btn.radius = 30;
	music_btn.circle = true;

	//	542 244  670 369
	character_choose_btn[0].upLeftx = 542;
	character_choose_btn[0].upLefty = 244;
	character_choose_btn[0].downRightx = 670;
	character_choose_btn[0].downRighty = 369;
	character_choose_btn[0].rectangle = true;

	//	695 247    818 369
	character_choose_btn[1].upLeftx = 695;
	character_choose_btn[1].upLefty = 247;
	character_choose_btn[1].downRightx = 818;
	character_choose_btn[1].downRighty = 369;
	character_choose_btn[1].rectangle = true;

	//	844 246    967 369
	character_choose_btn[2].upLeftx = 844;
	character_choose_btn[2].upLefty = 246;
	character_choose_btn[2].downRightx = 967;
	character_choose_btn[2].downRighty = 369;
	character_choose_btn[2].rectangle = true;

	//  994 248     1118 371
	character_choose_btn[3].upLeftx = 994;
	character_choose_btn[3].upLefty = 248;
	character_choose_btn[3].downRightx = 1118;
	character_choose_btn[3].downRighty = 371;
	character_choose_btn[3].rectangle = true;

	//	582 401		707 525
	character_choose_btn[4].upLeftx = 582;
	character_choose_btn[4].upLefty = 401;
	character_choose_btn[4].downRightx = 707;
	character_choose_btn[4].downRighty = 525;
	character_choose_btn[4].rectangle = true;

	//	732 402		855 524
	character_choose_btn[5].upLeftx = 732;
	character_choose_btn[5].upLefty = 402;
	character_choose_btn[5].downRightx = 855;
	character_choose_btn[5].downRighty = 524;
	character_choose_btn[5].rectangle = true;

	//	881 400		1003 523
	character_choose_btn[6].upLeftx = 881;
	character_choose_btn[6].upLefty = 400;
	character_choose_btn[6].downRightx = 1003;
	character_choose_btn[6].downRighty = 523;
	character_choose_btn[6].rectangle = true;

	//	1031 401	1152 521
	character_choose_btn[7].upLeftx = 1031;
	character_choose_btn[7].upLefty = 401;
	character_choose_btn[7].downRightx = 1152;
	character_choose_btn[7].downRighty = 521;
	character_choose_btn[7].rectangle = true;

	//1054 748  	r = 30
	character_music_btn.centrex = 1054;
	character_music_btn.centrey = 748;
	character_music_btn.radius = 30;
	character_music_btn.circle = true;

	//1132 748		r = 30
	character_exit_btn.centrex = 1132;
	character_exit_btn.centrey = 748;
	character_exit_btn.radius = 30;
	character_exit_btn.circle = true;

	// 412 247		522 349 // x+164
	// 577 249		685 352 
	// 740 247		847 348
	// 903 247		1012 350
	for (int i = 0; i < 4; i++) {
		player_btn[i].upLeftx = 412 + (164 * i);
		player_btn[i].downRightx = 522 + (164 * i);
		player_btn[i].upLefty = 248;
		player_btn[i].downRighty = 350;
		player_btn[i].rectangle = true;
	}
	
	// 413 394
	for (int i = 0; i < 4; i++) {
		robot_btn[i].upLeftx = 412 + (164 * i);
		robot_btn[i].downRightx = 522 + (164 * i);
		robot_btn[i].upLefty = 394;
		robot_btn[i].downRighty = 496;
		robot_btn[i].rectangle = true;
	}

	//453 533	749 608
	prok_btn.upLeftx = 453;
	prok_btn.upLefty = 533;
	prok_btn.downRightx = 749;
	prok_btn.downRighty = 608;
	prok_btn.rectangle = true;

	// throw dice
	//887 303 a = 230
	throw_dice.upLeftx = 887;
	throw_dice.upLefty = 303;
	throw_dice.downRightx = 1117;
	throw_dice.downRighty = 533;
	throw_dice.rectangle = true;

	//117 39
	game_music_btn.centrex = 117;
	game_music_btn.centrey = 39;
	game_music_btn.radius = 30;
	game_music_btn.circle = true;
	
	//37 38
	game_exit_btn.centrex = 37;
	game_exit_btn.centrey = 38;
	game_exit_btn.radius = 30;
	game_exit_btn.circle = true;

	//39 45		r = 30
	as_exit_btn.centrex = 39;
	as_exit_btn.centrey = 121;
	as_exit_btn.radius = 30;
	as_exit_btn.circle = true;
	
	//38 121	r = 30
	as_music_btn.centrex = 39;
	as_music_btn.centrey = 45;
	as_music_btn.radius = 30;
	as_music_btn.circle = true;

	//915 204		985 278
	set_dice.upLeftx = 915;
	set_dice.upLefty = 204;
	set_dice.downRightx = 985;
	set_dice.downRighty = 278;
	set_dice.rectangle = true;

	//894 364		1124 427
	set_mr.upLeftx = 894;
	set_mr.upLefty = 364;
	set_mr.downRightx = 1124;
	set_mr.downRighty = 427;
	set_mr.rectangle = true;

	//893 442		1124 506
	set_sr.upLeftx = 893;
	set_sr.upLefty = 442;
	set_sr.downRightx = 1124;
	set_sr.downRighty = 506;
	set_sr.rectangle = true;

	//1053 748 r = 30
	win_music_btn.centrex = 1053;
	win_music_btn.centrey = 748;
	win_music_btn.radius = 30;
	win_music_btn.circle = true;
	
	//1134 749 r = 30
	win_exit_btn.centrex = 1134;
	win_exit_btn.centrey = 748;
	win_exit_btn.radius = 30;
	win_exit_btn.circle = true;

	return;
}

void variableInit() {
	for (int i = 0; i < 8; i++) {
		character_selected[i] = false;
		player_id[i] = 0;
	}
	for (int i = 0; i < 4; i++) {
		character_id[i] = 0;
		robot_control[i] = false;
		player_control[i] = false;
	}
	player_robot_ok = false;
	return;
}

int welcomePage() {

	if (!canvas_open) {
		initgraph(GRAPH_WIDTH, GRAPH_HEIGHT, developer_mode);
		setbkmode(0);
		setbkcolor(WHITE);
		cleardevice();
		canvas_open = true;
	}
	
	//MoveWindow(, int X, int Y, int nWidth, int nHeight, BOOL bRepaint);
	variableInit();


	BeginBatchDraw();
	putimage(0, 0, &background_welcomepage);
	EndBatchDraw();
	
	if(developer_mode) coor();


	mciSendString(L"open welcomePage.mp3", NULL, 0, NULL);
	mciSendString(L"play welcomePage.mp3 repeat", NULL, 0, NULL);
	bool pause_cd = false;

	MOUSEMSG m;

	while (1) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (start_btn.inButton(m.x, m.y)) {
				mciSendString(L"stop welcomePage.mp3", NULL, 0, NULL);
				return 1;
			}
			if (setting_btn.inButton(m.x, m.y)) {
				mciSendString(L"stop welcomePage.mp3", NULL, 0, NULL);
				return 2;
			}
			if (exit_btn.inButton(m.x, m.y)) {
				mciSendString(L"stop welcomePage.mp3", NULL, 0, NULL);
				return -1;
			}
			if (about_btn.inButton(m.x, m.y)) {
				mciSendString(L"stop welcomePage.mp3", NULL, 0, NULL);
				return 3;
			}
			if (music_btn.inButton(m.x, m.y)) {
				if(pause_cd) mciSendString(L"play welcomePage.mp3 repeat", NULL, 0, NULL);
				else { 
					mciSendString(L"stop welcomePage.mp3", NULL, 0, NULL); 
					cout << "stop" << endl;
				}
				pause_cd = !pause_cd;
			}
		}
	}
}

int playerRobot() {
	
	/*initgraph(GRAPH_WIDTH, GRAPH_HEIGHT, developer_mode);
	setbkmode(0);
	setbkcolor(WHITE);
	cleardevice();*/

	BeginBatchDraw();
	putimage(0, 0, &player_robot);
	EndBatchDraw();

	if (developer_mode) coor();

	mciSendString(L"play welcomePage.mp3 repeat", NULL, 0, NULL);
	bool pause_cd = false;

	MOUSEMSG m;
	bool need_refresh = true;
	while (1) {
		m = GetMouseMsg();
		
		player_num = robot_num = 0;
		for (int i = 0; i < 4; i++) if (player_control[i]) player_num++;
		for (int i = 0; i < 4; i++) if (robot_control[i]) robot_num++;
		if (player_num + robot_num > 1 && need_refresh) {
			BeginBatchDraw();
			putimage(0, 0, &player_robot_ok);
			EndBatchDraw();
		}
		else if(need_refresh) {
			BeginBatchDraw();
			putimage(0, 0, &player_robot);
			EndBatchDraw();
		}
		if (need_refresh) {
			BeginBatchDraw();
			for (int i = 0; i < 4; i++) if (player_control[i]) {
				putimage(player_btn[i].upLeftx, 
					player_btn[i].upLefty, 
					&tick, SRCPAINT);
				putimage(player_btn[i].upLeftx, 
					player_btn[i].upLefty, 
					&wtick, SRCAND);
			}
			for (int i = 0; i < 4; i++) if (robot_control[i]) {
				putimage(robot_btn[i].upLeftx,
					robot_btn[i].upLefty,
					&tick, SRCPAINT);
				putimage(robot_btn[i].upLeftx,
					robot_btn[i].upLefty,
					&wtick, SRCAND);
			}
			EndBatchDraw();
			need_refresh = false;
		}
		


		if (m.uMsg == WM_LBUTTONDOWN) {
			cout << "click" << endl;
			need_refresh = true;
			for (int i = 0; i < 4; i++) {
				if (player_btn[i].inButton(m.x, m.y) && !player_control[i]) {
					cout << "player btn " << i << endl;
					player_control[i] = true;
					robot_control[i] = false;
					continue;
				}
				if(player_btn[i].inButton(m.x, m.y) && player_control[i]) {
					cout << "player btn cancel" << i << endl;
					player_control[i] = false;
					continue;
				}
			}

			for (int i = 0; i < 4; i++) {
				if (robot_btn[i].inButton(m.x, m.y) && !robot_control[i]) {
					cout << "robot btn " << i << endl;
					robot_control[i] = true;
					player_control[i] = false;
					continue;
				}
				if (robot_btn[i].inButton(m.x, m.y) && robot_control[i]) {
					cout << "robot btn cancel" << i << endl;
					robot_control[i] = false;
					continue;
				}
			}

			if (prok_btn.inButton(m.x, m.y) && player_num + robot_num > 1) {
				mciSendString(L"stop welcomePage.mp3", NULL, 0, NULL);
				return 1;
			}

			if (character_exit_btn.inButton(m.x, m.y)) {
				mciSendString(L"stop welcomePage.mp3", NULL, 0, NULL);
				return -1;
			}

			if (character_music_btn.inButton(m.x, m.y)) {
				if (pause_cd) mciSendString(L"play welcomePage.mp3.mp3 repeat", NULL, 0, NULL);
				else {
					mciSendString(L"stop welcomePage.mp3", NULL, 0, NULL);
					std::cout << "stop" << endl;
				}
				pause_cd = !pause_cd;
			}
		}
	}

	return -1;
}

int setting() {
	BeginBatchDraw();
	putimage(0, 0, &background_setting);
	EndBatchDraw();

	if (developer_mode) coor();

	bool pause_cd = false;
	mciSendString(L"play welcomePage.mp3 repeat", NULL, 0, NULL);
	MOUSEMSG m;
	while (1)
	{
		
		BeginBatchDraw();
		putimage(0, 0, &background_setting);
		if (master_robot) {
			putimage(set_mr.upLeftx+20,set_mr.upLefty-20, &tick, SRCPAINT);
			putimage(set_mr.upLeftx+20, set_mr.upLefty-20,&wtick, SRCAND);
		}
		else {
			putimage(set_sr.upLeftx+20, set_sr.upLefty-20, &tick, SRCPAINT);
			putimage(set_sr.upLeftx+20, set_sr.upLefty-20, &wtick, SRCAND);
		}
		EndBatchDraw();
		settextcolor(BLACK);
		settextstyle(80, 0, L"Î¢ÈíÑÅºÚ");
		if (least_go_out_number == 6) outtextxy(set_dice.upLeftx, set_dice.upLefty, L" 6 ");
		else outtextxy(set_dice.upLeftx, set_dice.upLefty, L" 5 ");
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (set_dice.inButton(m.x, m.y)) {
				if (least_go_out_number == 6) least_go_out_number = 5;
				else least_go_out_number = 6;
			}

			if (set_mr.inButton(m.x, m.y) && !master_robot) {
				master_robot = true;
			}
			if (set_sr.inButton(m.x, m.y) && master_robot) {
				master_robot = false;
			}
			if (as_exit_btn.inButton(m.x, m.y)) {
				mciSendString(L"stop welcomePage.mp3", NULL, 0, NULL);
				return 0;
			}
			if (as_music_btn.inButton(m.x, m.y)) {
				if (pause_cd) mciSendString(L"play welcomePage.mp3 repeat", NULL, 0, NULL);
				else mciSendString(L"stop welcomePage.mp3", NULL, 0, NULL);
				pause_cd = !pause_cd;
			}
		}
	}

	//putimage(,	&tick, SRCPAINT);
	//putimage(,	&wtick, SRCAND);
	return 0;
}

void about() {

	BeginBatchDraw();
	putimage(0, 0, &background_about);
	EndBatchDraw();

	if (developer_mode) coor();

	bool pause_cd = false;
	mciSendString(L"open about.mp3", NULL, 0, NULL);
	mciSendString(L"play about.mp3 repeat", NULL, 0, NULL);
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (as_exit_btn.inButton(m.x, m.y)) {
				mciSendString(L"stop about.mp3", NULL, 0, NULL);
				return;
			}
			if (as_music_btn.inButton(m.x, m.y)) {
				if (pause_cd) mciSendString(L"play about.mp3 repeat", NULL, 0, NULL);
				else mciSendString(L"stop about.mp3", NULL, 0, NULL);
				pause_cd = !pause_cd;
			}
		}
	}
	return;
}

void imageLoad() {
	cout << "Loading image...";

	// player and robot
	loadimage(&player_robot, L"playerRobot.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&player_robot_ok, L"playerRobotOK.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&tick, L"tick.png", 120, 120);
	loadimage(&wtick, L"tick_w.png", 120, 120);

	//choose your legend
	loadimage(&choose_your_legend, L"chooseYourLegend.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&selected_img, L"selected.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);

	//character choose
	loadimage(&character_choose[0], L"character1.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&character_choose[1], L"character2.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&character_choose[2], L"character3.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&character_choose[3], L"character4.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&character_choose[4], L"character5.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&character_choose[5], L"character6.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&character_choose[6], L"character7.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&character_choose[7], L"character8.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);

	// character normal
	loadimage(&blank, L"blank.png", 120, 120);
	loadimage(&character_normal[0], L"normal1.jpg", 120, 120);
	loadimage(&character_normal[1], L"normal2.jpg", 120, 120);
	loadimage(&character_normal[2], L"normal3.jpg", 120, 120);
	loadimage(&character_normal[3], L"normal4.jpg", 120, 120);
	loadimage(&character_normal[4], L"normal5.jpg", 120, 120);
	loadimage(&character_normal[5], L"normal6.jpg", 120, 120);
	loadimage(&character_normal[6], L"normal7.jpg", 120, 120);
	loadimage(&character_normal[7], L"normal8.jpg", 120, 120);

	// character win
	loadimage(&character_win[0], L"cwin1.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&character_win[1], L"cwin2.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&character_win[2], L"cwin3.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&character_win[3], L"cwin4.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&character_win[4], L"cwin5.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&character_win[5], L"cwin6.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&character_win[6], L"cwin7.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&character_win[7], L"cwin8.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);

	// character lose

	//dice
	loadimage(&dice[0], L"dice1.jpg", 230, 230);
	loadimage(&dice[1], L"dice2.jpg", 230, 230);
	loadimage(&dice[2], L"dice3.jpg", 230, 230);
	loadimage(&dice[3], L"dice4.jpg", 230, 230);
	loadimage(&dice[4], L"dice5.jpg", 230, 230);
	loadimage(&dice[5], L"dice6.jpg", 230, 230);
	loadimage(&dice[6], L"diceinfty.jpg", 230, 230);
	loadimage(&nodice, L"nodice.jpg", 230, 230);

	//back ground
	loadimage(&background_welcomepage, L"welcomePage.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&background_about, L"about.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&background_setting, L"setting.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	loadimage(&chessboard, L"chessboard.jpg", GRAPH_WIDTH, GRAPH_HEIGHT);
	
	// airplane
	for (int i = 0; i < 5; i++) loadimage(&plane[0][i], L"redplane.png", 30, 30);
	for (int i = 0; i < 5; i++) loadimage(&plane[1][i], L"yellowplane.png", 30, 30);
	for (int i = 0; i < 5; i++) loadimage(&plane[2][i], L"blueplane.png", 30, 30);
	for (int i = 0; i < 5; i++) loadimage(&plane[3][i], L"greenplane.png", 30, 30);
	for (int i = 0; i < 5; i++) loadimage(&wplane[0][i], L"redplane_w.png", 30, 30);
	for (int i = 0; i < 5; i++) loadimage(&wplane[1][i], L"yellowplane_w.png", 30, 30);
	for (int i = 0; i < 5; i++) loadimage(&wplane[2][i], L"blueplane_w.png", 30, 30);
	for (int i = 0; i < 5; i++) loadimage(&wplane[3][i], L"greenplane_w.png", 30, 30);

	loadimage(&airplanewin, L"airplanewin.png", 30, 30);
	loadimage(&wairplanewin, L"wairplanewin.png", 30, 30);

	cout << "\rComplete!         ";
	Sleep(500);
	cout << "\r                    \r";
	return;
}

void airplaneInit() {

	for (int i = 0; i < 4; i++) {
		if (!player_control[i] && !robot_control[i]) continue;
		for (int j = 0; j < 4; j++) {
			air[i][j].in_hangar = true;
			air[i][j].in_ready = false;
			air[i][j].in_track = false;
			air[i][j].is_win = false;
			air[i][j].in_wintrack = false;
			air[i][j].winstep = 6;
			air[i][j].step = -1;
			air[i][j].p = &plane[i][j];
			air[i][j].wp = &wplane[i][j];
		}
	}

	return;
}

inline void showTextG() {

	return;
}

inline void gamePageDraw() {

	BeginBatchDraw();
	putimage(0, 0, &chessboard);

	// draw sculptrue
	for (int i = 0; i < 8; i++) {
		if (character_selected[i]) {
			int j = player_id[i];
			putimage(sculptrue[j].x, sculptrue[j].y, &character_normal[i]);
		}
	}
	for (int i = 0; i < 4; i++) {
		if (!player_control[i] && !robot_control[i]) {
			putimage(sculptrue[i].x, sculptrue[i].y, &blank);
		}
	}


	// draw airplane
	for (int i = 0; i < 4; i++) {
		if (!player_control[i] && !robot_control[i]) continue;
		for (int j = 0; j < 4; j++) {
			if (air[i][j].in_hangar) {
				putimage(hangar[i][j].x, hangar[i][j].y, air[i][j].p, SRCAND);
				putimage(hangar[i][j].x, hangar[i][j].y, air[i][j].wp, SRCPAINT);
			}

			if (air[i][j].in_ready) {
				putimage(ready[i].x, ready[i].y, air[i][j].p, SRCAND);
				putimage(ready[i].x, ready[i].y, air[i][j].wp, SRCPAINT);
			}

			if (air[i][j].in_track) {
				int now = (ord[i] * 13 + air[i][j].step)%52;
				putimage(map[now].x, map[now].y, air[i][j].p, SRCAND);
				putimage(map[now].x, map[now].y, air[i][j].wp, SRCPAINT);
			}

			if (air[i][j].in_wintrack) {
				int now = air[i][j].winstep;
				putimage(wintrack[i][now].x, wintrack[i][now].y, air[i][j].p, SRCAND);
				putimage(wintrack[i][now].x, wintrack[i][now].y, air[i][j].wp, SRCPAINT);
			}

			if (air[i][j].is_win) {
				putimage(hangar[i][j].x, hangar[i][j].y, &airplanewin, SRCAND);
				putimage(hangar[i][j].x, hangar[i][j].y, &wairplanewin, SRCPAINT);
			}
		}
	}

	EndBatchDraw();
	return;
}

void showImgC(int p) {

	BeginBatchDraw();
	putimage(myturn.x, myturn.y, &character_normal[p]);
	EndBatchDraw();

	return;
}

int godNeverThrowDice() {
	int d = 0;
	while (d < 1 || d>61) {
		cout << "please type the dice number: ";
		cin >> d;
	}
	cout << "dice number is " << d-- << endl;
	BeginBatchDraw();
	if (d < 6) putimage(dice_p.x, dice_p.y, &dice[d]);
	else putimage(dice_p.x, dice_p.y, &dice[6]);
	EndBatchDraw();
	return d+1;
}

int getDice() {
	cout << "throw the dice ..." << endl;
	settextcolor(BLACK);
	settextstyle(90, 0, L"Î¢ÈíÑÅºÚ");
	outtextxy(220, 0, L"THROW THE DICE");

	BeginBatchDraw();
	putimage(dice_p.x, dice_p.y, &nodice);
	EndBatchDraw();
	
	if (god_mode) return godNeverThrowDice();

	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (throw_dice.inButton(m.x, m.y)) {
				srand(time(0));
				int n = rand() % 20 + 20;
				for (int i = 0; i < n; i++) {
					int r = rand() % 6;
					BeginBatchDraw();
					putimage(dice_p.x, dice_p.y, &dice[r]);
					EndBatchDraw();
					Sleep(15);
				}
				int rn = rand() % 6;
				BeginBatchDraw();
				putimage(dice_p.x, dice_p.y, &dice[rn]);
				EndBatchDraw();
				cout << "\r                             \r";
				cout << "dice number is " << rn+1 << endl;
				return rn+1;
			}
			if (game_exit_btn.inButton(m.x, m.y)) return -1;
			if (game_music_btn.inButton(m.x, m.y)) return -2;
		}
	}
	
	return 0;
}

int getDiceR() {
	cout << "throw the dice ..." << endl;
	settextcolor(BLACK);
	settextstyle(90, 0, L"Î¢ÈíÑÅºÚ");
	outtextxy(220, 0, L"THROW THE DICE");
	BeginBatchDraw();
	putimage(dice_p.x, dice_p.y, &nodice);
	EndBatchDraw();
	// Maybe god can't influence the robot
	if (god_mode) return godNeverThrowDice();
	Sleep(800);
	srand(time(0));
	int n = rand() % 20 + 20;
	for (int i = 0; i < n; i++) {
		int r = rand() % 6;
		BeginBatchDraw();
		putimage(dice_p.x, dice_p.y, &dice[r]);
		EndBatchDraw();
		Sleep(15);
	}
	int rn = rand() % 6;
	BeginBatchDraw();
	putimage(dice_p.x, dice_p.y, &dice[rn]);
	EndBatchDraw();
	cout << "\r                             \r";
	cout << "dice number is " << rn + 1 << endl;
	return rn + 1;
}

inline void planeCircleInit(int i, int j, int cx, int cy, int r) {
	plane_circle[i][j].centrex = cx;
	plane_circle[i][j].centrey = cy;
	plane_circle[i][j].radius = r;
	plane_circle[i][j].circle = true;
	return;
}

void deleteCircle(int player) {
	for (int i = 0; i < 4; i++) {
		plane_circle[player][i].centrex = 0;
		plane_circle[player][i].centrey = 0;
		plane_circle[player][i].radius = 0;
		plane_circle[player][i].circle = false;
	}
}

bool circleAirplane(int d, int player) {

	bool flag = false;
	// centre = map+15 r = 30
	for (int i = 0; i < 4; i++) {
		if (air[player][i].in_track) {
			if (!flag) flag = true;
			int pos = (air[player][i].step + ord[player] * 13) % 52;
			int nx = map[pos].x+15;
			int ny = map[pos].y+15;
			setlinecolor(BLACK);
			setlinestyle(PS_SOLID, 4);
			circle(nx, ny, 18);
			planeCircleInit(player, i, nx, ny, 18);
		}
		if (air[player][i].in_wintrack) {
			if (!flag) flag = true;
			int pos = air[player][i].winstep;
			int nx = wintrack[player][pos].x+15;
			int ny = wintrack[player][pos].y+15;
			setlinecolor(BLACK);
			setlinestyle(PS_SOLID, 4);
			circle(nx, ny, 18);
			planeCircleInit(player, i, nx, ny, 18);
		}
		if (air[player][i].in_ready) {
			if (!flag) flag = true;
			int nx = ready[player].x+15;
			int ny = ready[player].y+15;
			setlinecolor(BLACK);
			setlinestyle(PS_SOLID, 4);
			circle(nx, ny, 18);
			planeCircleInit(player, i, nx, ny, 18);
		}
	}
	if (d >= least_go_out_number) {
		for (int i = 0; i < 4; i++) {
			if (air[player][i].in_hangar) {
				if (!flag) flag = true;
				setlinecolor(BLACK);
				setlinestyle(PS_SOLID, 4);
				circle(hangar[player][i].x+15, hangar[player][i].y+15, 18);
				planeCircleInit(player, i, 
					hangar[player][i].x + 15, hangar[player][i].y + 15, 18
				);
			}
		}
	}
	return !flag;
}

int getAirplane(int i) {
	cout << "choose the airplane ";
	setfillcolor(WHITE);
	setlinecolor(WHITE);
	fillrectangle(182, 0, 838, 77);
	settextcolor(BLACK);
	settextstyle(70, 0, L"Î¢ÈíÑÅºÚ");
	outtextxy(220, 0, L"CHOOSE THE AIRPLANE");

	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {

			for (int j = 0; j < 4; j++) {
				if (plane_circle[i][j].circle) {
					if (plane_circle[i][j].inButton(m.x, m.y)) {
						cout << "\rchoose the airplane No." << j+1 << "                                    " << endl;
						return j;
					}
				}
			}

			if (game_exit_btn.inButton(m.x, m.y)) return -1;
			if (game_music_btn.inButton(m.x, m.y)) return -2;
		}
	}

	return 0;
}

int getAirplaneR(int i, int d) {
	cout << "Robot is choosing the airplane " << endl;
	setfillcolor(WHITE);
	setlinecolor(WHITE);
	fillrectangle(182, 0, 838, 77);
	settextcolor(BLACK);
	settextstyle(70, 0, L"Î¢ÈíÑÅºÚ");
	outtextxy(220, 0, L"CHOOSE THE AIRPLANE");
	
	Sleep(1500); // pretend thinking

	int robot_choice[4] = {}, siz = 0;
	for (int j = 0; j < 4; j++) {
		if (plane_circle[i][j].circle) {
			robot_choice[siz++] = j;
		}
	}

	if (!master_robot || siz == 1) // what a stupid robot!
		return robot_choice[rand() % siz]; 

	int max_score = -10, my_choice = 0;
	
	// rules to give a score:
	// go out the hangar +11
	// small jump +5
	// big jump +21
	// detour -5
	// eat an airplane +20
	// go to the wintrack +9
	// arrive +15

	for (int k = 0; k < siz; k++) {
		int j = robot_choice[k];
		int now_score = 0;
		if (air[i][j].in_hangar) {
			now_score += 11;
		}
		else if (air[i][j].in_track) {
			switch (air[i][j].step + d) {
			case 1:
			case 5:
			case 9:
			case 21:
			case 25:
			case 29:
			case 33:
			case 37:
			case 41:
			case 45:
				now_score += 5;
				break;
			case 13:
			case 17:
				now_score += 21;
				break;
			}
			if (air[i][j].step < 17 && air[i][j].step + d > 17) {
				now_score -= 5;
			}
			int mn = (air[i][j].step + ord[i] * 13) % 52;
			for (int ei = 0; ei < 4; ei++) {
				if (ei == i) continue;
				if (!robot_control[i] && !player_control[i]) continue;
				for (int ej = 0; ej < 4; ej++) {
					int en = (air[ei][ej].step + ord[ei] * 13) % 52;
					if (en == mn) now_score += 20;
				}
			}
			if (air[i][j].step + d > 49) now_score += 9;
		}
		else if (air[i][j].in_wintrack) {
			if (air[i][j].winstep == d) now_score += 15;
			else now_score -= 10;
		}
		if (now_score > max_score) {
			max_score = now_score;
			my_choice = j;
		}
	}
	
	cout << "master robot choose " << my_choice << " which has score " << max_score << endl;
	
	return my_choice; 
}

// mn -> map number, an-> airplane number, pn-> player number
void eatAirplane(int mn, int an, int pn) {

	for (int i = 0; i < 4; i++) {
		if (!player_control[i] && !robot_control[i]) continue;
		if (i == pn) continue;
		for (int j = 0; j < 4; j++) {
			if (!air[i][j].in_track) continue;
			int ms = (air[i][j].step + ord[i] * 13) % 52;
			if (ms == mn) { // eat
				cout << "eat the airplane " << endl;
				setfillcolor(WHITE);
				setlinecolor(WHITE);
				fillrectangle(182, 0, 838, 77);
				settextcolor(BLACK);
				settextstyle(60, 0, L"Î¢ÈíÑÅºÚ");
				outtextxy(220, 0, L"DESTORY THE AIRPLANE!!!");
				
				air[i][j].in_track = false;
				air[i][j].in_hangar = true;
				air[i][j].step = -1;
				Sleep(666);
			}
		}
	}

	return;
}

// ns -> now step  an-> airplane number, pn-> player number
int extraJump(int ns, int an, int pn) {
	int cnt = 0;
	
	// big jump

	if (ns == 13) { // eat 17 29
		cout << "big jump " << endl;
		setfillcolor(WHITE);
		setlinecolor(WHITE);
		fillrectangle(182, 0, 838, 77);
		settextcolor(BLACK);
		settextstyle(80, 0, L"Î¢ÈíÑÅºÚ");
		outtextxy(220, 0, L"BIG JUMP!!!");
		Sleep(400);

		int map_number = (17 + ord[pn] * 13) % 52;
		eatAirplane(map_number, an, pn);
		map_number = (29 + ord[pn] * 13) % 52;
		eatAirplane(map_number, an, pn);
		return 16;
	}

	if (ns == 17) { // eat 29 33
		cout << "big jump " << endl;
		setfillcolor(WHITE);
		setlinecolor(WHITE);
		fillrectangle(182, 0, 838, 77);
		settextcolor(BLACK);
		settextstyle(80, 0, L"Î¢ÈíÑÅºÚ");
		outtextxy(220, 0, L"BIG JUMP!!!");
		Sleep(400);

		int map_number = (29 + ord[pn] * 13) % 52;
		eatAirplane(map_number, an, pn);
		map_number = (33 + ord[pn] * 13) % 52;
		eatAirplane(map_number, an, pn);
		return 16;
	}

	// small jump
	for (int i = 1; i < 49; i += 4) {
		if (i == ns) {
			cout << "jump " << endl;
			setfillcolor(WHITE);
			setlinecolor(WHITE);
			fillrectangle(182, 0, 838, 77);
			settextcolor(BLACK);
			settextstyle(80, 0, L"Î¢ÈíÑÅºÚ");
			outtextxy(220, 0, L"JUMP!");
			Sleep(200);

			int map_number = (ns+4 + ord[pn] * 13) % 52;
			eatAirplane(map_number, an, pn);
			return 4;
		}
	}

	return 0;
}

bool checkWin(int p) {
	for (int i = 0; i < 4; i++) {
		if (!air[p][i].is_win) return false;
	}
	return true;
}

int mainGame() {

	airplaneInit();
	gamePageDraw();

	if (developer_mode) coor();

	mciSendString(L"open Game.mp3", NULL, 0, NULL);
	mciSendString(L"play Game.mp3 repeat", NULL, 0, NULL);
	bool pause_cd = false;
	//Sleep(100000);
	int round=-1;
	while (1)
	{
		round++;
		int player = round % 4;
		if (!player_control[player] && !robot_control[player]) continue;
		cout << "round " << round/4+1 ;
		cout << " player " << player << endl;
		if (player_control[player]) 
		{
			_DICE:
			gamePageDraw();
			showImgC(character_id[player]);
			int d = getDice();
			if (d == -1){
				mciSendString(L"stop Game.mp3", NULL, 0, NULL);
				return 0; // exit
			}
			if (d == -2) 
			{ // music control
				if(pause_cd) mciSendString(L"play Game.mp3 repeat", NULL, 0, NULL);
				else mciSendString(L"stop Game.mp3", NULL, 0, NULL);
				pause_cd = !pause_cd;
				goto _DICE;
			}
			//if(rand()%5 > 2) d = 6;
			bool flag = circleAirplane(d, player);
			if (flag) {
				deleteCircle(player);
				cout << "No choice, skip this turn" << endl;
				continue;
			}
			_AIRPLANE:
			int a = getAirplane(player);
			if (a == -1) {
				deleteCircle(player);
				mciSendString(L"stop Game.mp3", NULL, 0, NULL);
				return 0; // exit
			}
			if (a == -2)
			{ // music control
				if (pause_cd) mciSendString(L"play Game.mp3 repeat", NULL, 0, NULL);
				else mciSendString(L"stop Game.mp3", NULL, 0, NULL);
				pause_cd = !pause_cd;
				goto _AIRPLANE;
			}
			deleteCircle(player);
			// fly
			if (air[player][a].in_hangar) {
				air[player][a].in_hangar = false;
				air[player][a].in_ready = true;
			}
			else if (air[player][a].in_ready) {
				air[player][a].in_ready = false;
				air[player][a].in_track = true;
				air[player][a].step = d - 1;
				eatAirplane((air[player][a].step + ord[player] * 13) % 52, a, player);
				int bonus = extraJump(air[player][a].step, a, player);
				air[player][a].step += bonus;
				if (air[player][a].step > 49) { // this won't happen unless you open god mode
					air[player][a].in_wintrack = true;
					air[player][a].in_track = false;
					air[player][a].winstep = 6 - (air[player][a].step - 49);
					if (air[player][a].winstep < 0)
						air[player][a].winstep = 0 - air[player][a].winstep;
					air[player][a].step = -1;
					if (air[player][a].winstep == 0) {
						cout << "player " << player << " airplane " << a << " achieve the centre!" << endl;
						air[player][a].in_wintrack = false;
						air[player][a].is_win = true;
					}
				}
			}
			else if (air[player][a].in_track) {
				if (air[player][a].step + d > 49) {
					air[player][a].in_wintrack = true;
					air[player][a].in_track = false;
					air[player][a].winstep = 6 - (air[player][a].step + d - 49);
					if (air[player][a].winstep < 0) 
						air[player][a].winstep = 0-air[player][a].winstep;
					air[player][a].step = -1;
				}
				else { // normal move
					air[player][a].step += d;
					eatAirplane((air[player][a].step + ord[player] * 13) % 52, a, player);
					int bonus = extraJump(air[player][a].step ,a, player);
					air[player][a].step += bonus;
					if (air[player][a].step > 49) { // this won't happen unless you open god mode
						air[player][a].in_wintrack = true;
						air[player][a].in_track = false;
						air[player][a].winstep = 6 - (air[player][a].step - 49);
						if (air[player][a].winstep < 0)
							air[player][a].winstep = 0 - air[player][a].winstep;
						air[player][a].step = -1;
					}
				}
				if (air[player][a].winstep == 0 && air[player][a].in_wintrack) {
					cout << "player " << player << " airplane " << a << " achieve the centre!" << endl;
					air[player][a].in_wintrack = false;
					air[player][a].is_win = true;
				}
			}
			else if(air[player][a].in_wintrack) {
				cout << "player " << player << " airplane " << a << " in the last track" << endl;
				air[player][a].winstep = air[player][a].winstep - d;
				if (air[player][a].winstep < 0)
					air[player][a].winstep = 0 - air[player][a].winstep;
				if (air[player][a].winstep == 0) {
					cout << "player " << player << " airplane " << a << " achieve the centre!" << endl;
					air[player][a].in_wintrack = false;
					air[player][a].is_win = true;
				}
			}

			if (d == 6) 
			{ 
				cout << " extra throw! " << endl;
				goto _DICE;
			}
		}
		else if (robot_control[player]) { // »úÆ÷ÈËÈÓ÷»×Ó 1.6s »úÆ÷ÈËÑ¡·É»ú 1.5s
			_DICEROBOT:
			gamePageDraw();
			showImgC(character_id[player]);
			int d = getDiceR();
			Sleep(800);
			bool flag = circleAirplane(d, player);
			if (flag) {
				deleteCircle(player);
				cout << "No choice, skip this turn" << endl;
				continue;
			}
			int a = getAirplaneR(player, d);
			deleteCircle(player);
			// fly
			if (air[player][a].in_hangar) {
				air[player][a].in_hangar = false;
				air[player][a].in_ready = true;
			}
			else if (air[player][a].in_ready) {
				air[player][a].in_ready = false;
				air[player][a].in_track = true;
				air[player][a].step = d - 1;
				eatAirplane((air[player][a].step + ord[player] * 13) % 52, a, player);
				int bonus = extraJump(air[player][a].step, a, player);
				air[player][a].step += bonus;
				if (air[player][a].step > 49) { // this won't happen unless you open god mode
					air[player][a].in_wintrack = true;
					air[player][a].in_track = false;
					air[player][a].winstep = 6 - (air[player][a].step - 49);
					if (air[player][a].winstep < 0)
						air[player][a].winstep = 0 - air[player][a].winstep;
					air[player][a].step = -1;
					if (air[player][a].winstep == 0) {
						cout << "player " << player << " airplane " << a << " achieve the centre!" << endl;
						air[player][a].in_wintrack = false;
						air[player][a].is_win = true;
					}
				}
			}
			else if (air[player][a].in_track) {
				if (air[player][a].step + d > 49) {
					air[player][a].in_wintrack = true;
					air[player][a].in_track = false;
					air[player][a].winstep = 6 - (air[player][a].step + d - 49);
					if (air[player][a].winstep < 0)
						air[player][a].winstep = 0 - air[player][a].winstep;
					air[player][a].step = -1;
				}
				else { // normal move
					air[player][a].step += d;
					eatAirplane((air[player][a].step + ord[player] * 13) % 52, a, player);
					int bonus = extraJump(air[player][a].step, a, player);
					air[player][a].step += bonus;
					if (air[player][a].step > 49) { // this won't happen unless you open god mode
						air[player][a].in_wintrack = true;
						air[player][a].in_track = false;
						air[player][a].winstep = 6 - (air[player][a].step - 49);
						if (air[player][a].winstep < 0)
							air[player][a].winstep = 0 - air[player][a].winstep;
						air[player][a].step = -1;
					}
				}
				if (air[player][a].winstep == 0 && air[player][a].in_wintrack) {
					cout << "player " << player << " airplane " << a << " achieve the centre!" << endl;
					air[player][a].in_wintrack = false;
					air[player][a].is_win = true;
				}
			}
			else if (air[player][a].in_wintrack) {
				cout << "player " << player << " airplane " << a << " in the last track" << endl;
				air[player][a].winstep = air[player][a].winstep - d;
				if (air[player][a].winstep < 0)
					air[player][a].winstep = 0 - air[player][a].winstep;
				if (air[player][a].winstep == 0) {
					cout << "player " << player << " airplane " << a << " achieve the centre!" << endl;
					air[player][a].in_wintrack = false;
					air[player][a].is_win = true;
				}
			}

			if (d == 6)
			{
				cout << " extra throw! " << endl;
				goto _DICEROBOT;
			}
		}

		if (checkWin(player)) { 
			cout << "player " << player << " win the game!!!" << endl;
			winner_id = character_id[player];
			mciSendString(L"stop Game.mp3", NULL, 0, NULL);
			return 4; 
		}
	}

	Sleep(100000);

	return 0;
}

void corInit() {
	//player red 629 639
	sculptrue[0].x = 629;
	sculptrue[0].y = 639;

	//player yellow 98 111
	sculptrue[1].x = 98;
	sculptrue[1].y = 111;
	
	//player blue 629 109
	sculptrue[2].x = 629;
	sculptrue[2].y = 109;
	
	//player green 101 638
	sculptrue[3].x = 101;
	sculptrue[3].y = 638;

	//	805 573 /+58
	//	805 633
	//	803 689
	//	804 747
	for (int i = 0; i < 4; i++) {
		hangar[0][i].x = 805;
		hangar[0][i].y = 573 + (i * 58);
	}

	//	12 95
	//	9 154
	//	9 216
	//	8 271
	for (int i = 0; i < 4; i++) {
		hangar[1][i].x = 12;
		hangar[1][i].y = 95 + (i * 58);
	}
	
	//	796 95
	//	795 155
	//	793 214
	//	795 272
	for (int i = 0; i < 4; i++) {
		hangar[2][i].x = 795;
		hangar[2][i].y = 95 + (i * 58);
	}

	//	26 568
	//	23 629
	//	23 685
	//	23 743
	for (int i = 0; i < 4; i++) {
		hangar[3][i].x = 25;
		hangar[3][i].y = 568 + (i * 58);
	}

	//747 566
	ready[0].x = 747;
	ready[0].y = 566;

	//70 269
	ready[1].x = 70;
	ready[1].y = 269;

	//559 76
	ready[2].x = 559;
	ready[2].y = 76;

	//256 753
	ready[3].x = 256;
	ready[3].y = 753;

	// program generate
	/*ifstream inFile("map.in");
	ofstream outFile("map.out");
	int cnt = 0;
	while(cnt<52){
		int x,y;
		inFile >> x >> y;
		outFile << "map[" << cnt << "].x = " << x << ";" << endl;
		outFile << "map[" << cnt << "].y = " << y << ";" << endl;
		cnt++;
	}*/
	// paste

	map[0].x = 693;
	map[0].y = 540;
	map[1].x = 650;
	map[1].y = 557;
	map[2].x = 610;
	map[2].y = 557;
	map[3].x = 570;
	map[3].y = 539;
	map[4].x = 531;
	map[4].y = 574;
	map[5].x = 550;
	map[5].y = 617;
	map[6].x = 550;
	map[6].y = 658;
	map[7].x = 532;
	map[7].y = 703;
	map[8].x = 490;
	map[8].y = 714;
	map[9].x = 450;
	map[9].y = 714;
	map[10].x = 410;
	map[10].y = 714;
	map[11].x = 370;
	map[11].y = 714;
	map[12].x = 330;
	map[12].y = 714;
	map[13].x = 287;
	map[13].y = 701;
	map[14].x = 268;
	map[14].y = 659;
	map[15].x = 268;
	map[15].y = 618;
	map[16].x = 286;
	map[16].y = 576;
	map[17].x = 250;
	map[17].y = 539;
	map[18].x = 207;
	map[18].y = 558;
	map[19].x = 170;
	map[19].y = 558;
	map[20].x = 126;
	map[20].y = 539;
	map[21].x = 112;
	map[21].y = 498;
	map[22].x = 112;
	map[22].y = 459;
	map[23].x = 112;
	map[23].y = 419;
	map[24].x = 112;
	map[24].y = 380;
	map[25].x = 112;
	map[25].y = 343;
	map[26].x = 126;
	map[26].y = 298;
	map[27].x = 168;
	map[27].y = 282;
	map[28].x = 209;
	map[28].y = 282;
	map[29].x = 250;
	map[29].y = 300;
	map[30].x = 287;
	map[30].y = 263;
	map[31].x = 268;
	map[31].y = 220;
	map[32].x = 268;
	map[32].y = 180;
	map[33].x = 286;
	map[33].y = 137;
	map[34].x = 329;
	map[34].y = 124;
	map[35].x = 370;
	map[35].y = 124;
	map[36].x = 408;
	map[36].y = 124;
	map[37].x = 449;
	map[37].y = 124;
	map[38].x = 490;
	map[38].y = 124;
	map[39].x = 533;
	map[39].y = 137;
	map[40].x = 550;
	map[40].y = 180;
	map[41].x = 550;
	map[41].y = 220;
	map[42].x = 532;
	map[42].y = 264;
	map[43].x = 568;
	map[43].y = 299;
	map[44].x = 610;
	map[44].y = 280;
	map[45].x = 650;
	map[45].y = 280;
	map[46].x = 692;
	map[46].y = 300;
	map[47].x = 707;
	map[47].y = 341;
	map[48].x = 707;
	map[48].y = 380;
	map[49].x = 707;
	map[49].y = 419;
	map[50].x = 707;
	map[50].y = 457;
	map[51].x = 707;
	map[51].y = 497;

	// 900 136
	myturn.x = 900;
	myturn.y = 136;

	dice_p.x = 887;
	dice_p.y = 303;

	//  649 419
	//	610 420
	//	570 420
	//	530 419
	//	491 422
	//	445 421
	for (int i = 5; i > 0; i--) {
		wintrack[0][i].x = 650 - 40 * (5-i);
		wintrack[0][i].y = 420;
	}
	wintrack[0][0].x = 445;
	wintrack[0][0].y = 420;

	//  170 420
	//	209 418
	//	249 420
	//	291 420
	//	287 420
	//	329 420
	//	373 421
	for (int i = 5; i > 0; i--) {
		wintrack[1][i].x = 170 + 40 * (5-i);
		wintrack[1][i].y = 420;
	}
	wintrack[1][0].x = 373;
	wintrack[1][0].y = 420;

	////410 180
	//  411 219
	//	410 260
	//	409 301
	//	409 340
	//	410 385
	for (int i = 5; i > 0; i--) {
		wintrack[2][i].x = 409;
		wintrack[2][i].y = 180 + 40*(5-i);
	}
	wintrack[2][0].x = 409;
	wintrack[2][0].y = 385;

	////408 659
	//  408 620
	//	410 581
	//	409 541
	//	409 501
	//	410 457
	//	409 456
	for (int i = 5; i > 0; i--) {
		wintrack[3][i].x = 409;
		wintrack[3][i].y = 660-40*(5-i);
	}
	wintrack[3][0].x = 409;
	wintrack[3][0].y = 456;



}

int getNextState(int state) {
	int nextstate = 0;
	switch (state) {
	case 0: // Welcome Page
		nextstate = welcomePage();
		return getNextState(nextstate);
	case 1:// character select
		nextstate = playerRobot();
		if (nextstate == -1) return getNextState(0);
		nextstate = characterChoose();
		if(nextstate == -1) return getNextState(0);
		nextstate = mainGame();
		return getNextState(nextstate);
	case 2:// setting
		nextstate = setting();
		return getNextState(nextstate);
	case 3:// about
		about();
		return getNextState(0);
	case 4:// winner winner chicken dinner
		winnerPageDraw();
		return getNextState(0);
	case -1:
		return -1;
	}
}

inline void showTextCC(int player_num_now) {
	settextcolor(WHITE);
	settextstyle(60, 0, _T("Î¢ÈíÑÅºÚ"));
	
	if (player_num_now == 0 && player_control[player_num_now]) outtextxy(526, 581, _T("PLAYER 1 is choosing"));
	if (player_num_now == 1 && player_control[player_num_now]) outtextxy(526, 581, _T("PLAYER 2 is choosing"));
	if (player_num_now == 2 && player_control[player_num_now]) outtextxy(526, 581, _T("PLAYER 3 is choosing"));
	if (player_num_now == 3 && player_control[player_num_now]) outtextxy(526, 581, _T("PLAYER 4 is choosing"));
	if (player_num_now == 0 && robot_control[player_num_now]) outtextxy(526, 581, _T("ROBOT 1 is choosing"));
	if (player_num_now == 1 && robot_control[player_num_now]) outtextxy(526, 581, _T("ROBOT 2 is choosing"));
	if (player_num_now == 2 && robot_control[player_num_now]) outtextxy(526, 581, _T("ROBOT 3 is choosing"));
	if (player_num_now == 3 && robot_control[player_num_now]) outtextxy(526, 581, _T("ROBOT 4 is choosing"));

	for (int i = 0; i < 8; i++) {
		if (character_selected[i]) {
			settextcolor(YELLOW);
			settextstyle(80, 20, _T("Î¢ÈíÑÅºÚ"));
			switch (player_id[i]) {
			case 0:
				outtextxy(character_choose_btn[i].upLeftx, character_choose_btn[i].upLefty, _T("P1"));
				break;
			case 1:
				outtextxy(character_choose_btn[i].upLeftx, character_choose_btn[i].upLefty, _T("P2"));
				break;
			case 2:
				outtextxy(character_choose_btn[i].upLeftx, character_choose_btn[i].upLefty, _T("P3"));
				break;
			case 3:
				outtextxy(character_choose_btn[i].upLeftx, character_choose_btn[i].upLefty, _T("P4"));
				break;
			}
		}
	}
	return;
}

int characterChoose() {

	/*initgraph(GRAPH_WIDTH, GRAPH_HEIGHT, developer_mode);
	setbkmode(0);
	setbkcolor(WHITE);
	cleardevice();
	*/
	BeginBatchDraw();
	putimage(0, 0, &choose_your_legend);
	EndBatchDraw();
	cout << "choose your legend" << endl;
	if (developer_mode) coor();

	mciSendString(L"open \chooseYourLegend.mp3", NULL, 0, NULL);
	mciSendString(L"play \chooseYourLegend.mp3 repeat", NULL, 0, NULL);
	bool pause_cd = false;


	MOUSEMSG m;

	player_num = robot_num = 0;
	for (int i = 0; i < 4; i++) if (player_control[i]) player_num++;
	for (int i = 0; i < 4; i++) if (robot_control[i]) robot_num++;

	int player_num_now = 0;
	while (player_num_now<4) {
		if (!player_control[player_num_now] && !robot_control[player_num_now]) {
			player_num_now++;
			continue;
		}
		showTextCC(player_num_now);
		
		if (robot_control[player_num_now]) {
			srand(time(0));
			int n = rand() % 7 + 3;
			for (int i = 0; i < n; i++) {
				int now = rand() % 8;
				while (character_selected[now])
					now = (now + 1) % 8;
				BeginBatchDraw();
				putimage(0, 0, &character_choose[now]);
				showTextCC(player_num_now);
				EndBatchDraw();
				Sleep(100);
			}
			int now = rand() % 8;
			while (character_selected[now])
				now = (now + 1) % 8;
			BeginBatchDraw();
			putimage(0, 0, &character_choose[now]);
			showTextCC(player_num_now);
			EndBatchDraw();
			Sleep(2000);
			BeginBatchDraw();
			putimage(0, 0, &selected_img);
			EndBatchDraw();
			Sleep(100);
			character_selected[now] = true;
			player_id[now] = player_num_now;
			character_id[player_num_now] = now;
			cout << player_num_now << " choose " << now << endl;
			player_num_now++;
			continue;
		}

		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			for (int i = 0; i < 8; i++) {
				if (character_choose_btn[i].inButton(m.x, m.y) && !character_selected[i]) {
					BeginBatchDraw();
					putimage(0, 0, &selected_img);
					EndBatchDraw();
					character_selected[i] = true;

					player_id[i] = player_num_now;
					character_id[player_num_now] = i;
					cout << player_num_now << " choose " << i << endl;
					player_num_now++;
					Sleep(100);
				}
			}

			if (character_exit_btn.inButton(m.x, m.y)) {
				mciSendString(L"stop chooseYourLegend.mp3", NULL, 0, NULL);
				return 0;
			}

			if (character_music_btn.inButton(m.x, m.y)) {
				if (pause_cd) mciSendString(L"play chooseYourLegend.mp3 repeat", NULL, 0, NULL);
				else {
					mciSendString(L"stop chooseYourLegend.mp3", NULL, 0, NULL);
					cout << "stop" << endl;
				}
				pause_cd = !pause_cd;
			}
		}
		if (m.uMsg == WM_MOUSEMOVE) {
			bool flag = true;
			for (int i = 0; i < 8; i++) {
				if (character_choose_btn[i].inButton(m.x, m.y) && !character_selected[i]) {
					flag = false;
					BeginBatchDraw();
					putimage(0, 0, &character_choose[i]);
					EndBatchDraw();
				}
			}
			if (flag) {
				BeginBatchDraw();
				putimage(0, 0, &choose_your_legend);
				EndBatchDraw();
			}
		}
	}
	showTextCC(player_num_now);
	if (developer_mode) {
		mciSendString(L"stop chooseYourLegend.mp3", NULL, 0, NULL); 
		return 2;
	}
	int x = 5;
	while (x--) {
		settextcolor(BLACK);
		settextstyle(80, 0, _T("Î¢ÈíÑÅºÚ"));
		outtextxy(0, 400, L"THE GAME STARTS ");
		outtextxy(0, 500, L"IN 5 SECOND");
		Sleep(1000);
	}
	mciSendString(L"stop chooseYourLegend.mp3", NULL, 0, NULL);
	
	return 2;
}

void resourceLoad() {
	least_go_out_number = 6;
	ord[0] = 0, ord[1] = 2, ord[2] = 3, ord[3] = 1;
	master_robot = true;
	imageLoad();
	btnInit();
	corInit();
	return;
}
