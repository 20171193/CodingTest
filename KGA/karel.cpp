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
	void turnLeft() {
		karel.d = (karel.d + 1) % 4;
		myMap[karel.y][karel.x] = agentDir[karel.d];
		Render();
	}
	void Move() {
		int _x = karel.x + dx[karel.d];
		int _y = karel.y + dy[karel.d];
		if (checkClear(_x, _y)) {
			cout << "Front Is Block!!" << '\n';
			return;
		}
		if (myMap[karel.y][karel.x] != beeper) {
			myMap[karel.y][karel.x] = road;
			karel.x = _x;  karel.y = _y;
			myMap[karel.y][karel.x] = agentDir[karel.d];
		}


	}

public:
	// facing
	bool facingNorth() {
		if (karel.d == 1) return true;
		return false;
	}
	bool facingEast() {
		if (karel.d == 0) return true;
		return false;
	}
	bool facingSouth() {
		if (karel.d == 2) return true;
		return false;
	}
	bool facingWest() {
		if (karel.d == 3) return true;
		return false;
	}

private:
	// check next position
	bool checkClear(int nx, int ny) {
		if (nx > width || nx < 0 || ny > height || ny < 0) return true;
		return false;
	}
public:
	bool frontIsClear() {
		int _x = dx[karel.d] + karel.x;
		int _y = dy[karel.d] + karel.y;
		return checkClear(_x, _y);
	}
	bool leftIsClear() {
		int _x = dx[(karel.d + 1) % 4] + karel.x;
		int _y = dy[(karel.d + 1) % 4] + karel.y;
		return checkClear(_x, _y);
	}
	bool rightIsClear() {
		int _x = dx[(karel.d + 3) % 4] + karel.x;
		int _y = dy[(karel.d + 3) % 4] + karel.y;
		return checkClear(_x, _y);
	}

public:
	// Beeper 
	void putBeeper() {
		myMap[karel.y][karel.x] = beeper;
	}
	void pickBeeper() {
		myMap[karel.y][karel.x] = agentDir[karel.d];
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

// CustomFunction
void goStaright() {
}
void turnRight() {
	game->turnLeft();
	game->turnLeft();
	game->turnLeft();
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

	// input
	turnRight();

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
