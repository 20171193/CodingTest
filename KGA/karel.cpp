// Stanford Karel Unit 12 <Midpoint> 

#include <iostream>
#include <windows.h>
using namespace std;

#define DEFAULT_WIDTH 5
#define DEFAULT_HEIGHT 5

struct Karel {
	int x;
	int y;
	int d;
};

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
char beeper = '#', road = '\"', agentDir[4] = { '>', '^', '<', 'v' };
char myMap[101][101];

class KarelGame {
public:
	KarelGame() {
		width = DEFAULT_WIDTH;
		height = DEFAULT_HEIGHT;
		Setting();
	}
	KarelGame(int _w, int _h) {
		width = _w; 
		height = _h;
		Setting();
	}
	~KarelGame() {
	}
private:
	// map, Karel setting
	void Setting() {
		karel.x = 0;
		karel.y = height - 1;
		karel.d = 0;

		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				myMap[y][x] = '\"';
			}
		}
		myMap[karel.y][karel.x] = agentDir[karel.d];
	}

	// rendering 
	void Render() {
		Clear();
		cout << "\n";
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				cout << myMap[y][x];
			}
			cout << "\n";
		}
	}
	
	// clear
	void Clear() {
		Sleep(500);
		system("cls");
	}

public:
	// action
	void TurnLeft() {
		karel.d = (karel.d + 1) % 4;
		if(!BeepersPresent()) myMap[karel.y][karel.x] = agentDir[karel.d];
		Render();
	}
	void Move() {
		int _x = karel.x + dx[karel.d];
		int _y = karel.y + dy[karel.d];
		if (!checkClear(_x, _y)) {
			for (int i = 0; i < 4; i++){
				Sleep(200);
				system("cls");
				cout << "Front Is Block!";
				for (int j = 0; j < i; j++) {
					cout << " !";
				}
				cout << "\n";
			}
			Sleep(1000);
			system("cls");
			Sleep(50);
			cout << "--------------------------\n";
			cout << "--------------------------\n";
			cout << "--------------------------\n";
			cout << "          실패!!          \n";
			cout << "--------------------------\n";
			cout << "--------------------------\n";
			cout << "--------------------------\n";
			system("pause");
			return;
		}
		if (myMap[karel.y][karel.x] != beeper) myMap[karel.y][karel.x] = road;
		if(myMap[_y][_x] != beeper) myMap[_y][_x] = agentDir[karel.d];
		karel.x = _x;  karel.y = _y;

		Render();
	}

public:
	// facing
	bool FacingNorth() {
		if (karel.d == 1) return true;
		return false;
	}
	bool FacingEast() {
		if (karel.d == 0) return true;
		return false;
	}
	bool FacingSouth() {
		if (karel.d == 2) return true;
		return false;
	}
	bool FacingWest() {
		if (karel.d == 3) return true;
		return false;
	}

private:
	// check next position
	bool checkClear(int nx, int ny) {
		if (nx >= width || nx < 0 || ny >= height || ny < 0) return false;
		return true;
	}
public:
	bool FrontIsClear() {
		int _x = dx[karel.d] + karel.x;
		int _y = dy[karel.d] + karel.y;
		return checkClear(_x, _y);
	}
	bool LeftIsClear() {
		int _x = dx[(karel.d + 1) % 4] + karel.x;
		int _y = dy[(karel.d + 1) % 4] + karel.y;
		return checkClear(_x, _y);
	}
	bool RightIsClear() {
		int _x = dx[(karel.d + 3) % 4] + karel.x;
		int _y = dy[(karel.d + 3) % 4] + karel.y;
		return checkClear(_x, _y);
	}

	bool BeepersPresent() {
		if (myMap[karel.y][karel.x] == beeper) return true;
		return false;
	}

public:
	// Beeper 
	void PutBeeper() {
		myMap[karel.y][karel.x] = beeper;
		Render();
	}
	void PickBeeper() {
		myMap[karel.y][karel.x] = agentDir[karel.d];
		Render();
	}

	// check game clear
	bool checkGameClear() {
		pair<int, int> midPoint = { height - 1, width / 2 };
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				if (myMap[y][x] == beeper) {
					if (y == midPoint.first && x != midPoint.second) return false;
				}
			}
		}
		if (karel.x != width - 1 || karel.y != height - 1 || karel.d != 0) return false;
		
		return true;
	}
private:
	int width, height;
	Karel karel;
};

KarelGame *game;

// Karel commands
void move() { game->Move(); }
void turnLeft() { game->TurnLeft(); }
void putBeeper() { game->PutBeeper(); }
void pickBeeper() { game->PickBeeper(); }

// Karel conditions
bool frontIsClear() { return game->FrontIsClear(); }
bool leftIsClear() {  return game->LeftIsClear(); }
bool rightIsClear() { return game->RightIsClear(); }
bool facingNorth() { return game->FacingNorth(); }
bool facingEast() {  return game->FacingEast(); }
bool facingSouth() { return game->FacingSouth(); }
bool facingWest() {  return game->FacingWest(); }
bool beepersPresent() { return game->BeepersPresent(); }


// CustomFunction
void goStraight() {
	while (frontIsClear()) {
		move();
	}
}
void goStraightForBeeper() {
	while (!beepersPresent()) {
		move();
	}
}
void turnRight() {
	turnLeft();
	turnLeft();
	turnLeft();
}
void turnAround() {
	turnLeft(); 
	turnLeft();
}
void moveBack() {
	turnAround();
	move();
	turnAround();
}

int main() {
	int w = 0, h = 0;
	cout << "너비와 높이를 입력하시오. (1 <= 너비(*홀수),높이 <= 100)\n";
	cin >> w >> h;
	while ((1>w || 100<w) || (1>h || 100<h) || (w%2 == 0)) {
		cout << "다시 입력하세요. (1 <= 너비(*홀수),높이 <= 100)\n";
		cin >> w >> h;
	}
	game = new KarelGame(w,h);

	putBeeper();
	goStraight();
	putBeeper();
	turnAround();

	move();

	while (!beepersPresent()) {
		goStraightForBeeper();
		pickBeeper();
		moveBack();
		putBeeper();
		turnAround();

		move();
	}

	pickBeeper();
	goStraight();

	// check game result
	Sleep(200);
	system("cls");
	Sleep(50);
	if (game->checkGameClear()) {
		cout << "--------------------------\n";
		cout << "--------------------------\n";
		cout << "--------------------------\n";
		cout << "       게임 클리어!!       \n";
		cout << "--------------------------\n";
		cout << "--------------------------\n";
		cout << "--------------------------\n";
	}
	else {
		cout << "--------------------------\n";
		cout << "--------------------------\n";
		cout << "--------------------------\n";
		cout << "          실패!!          \n";
		cout << "--------------------------\n";
		cout << "--------------------------\n";
		cout << "--------------------------\n";
	}
	delete game;
	return 0;
}
