//ガイド、途中

#include "Mouse_Pos_Geter.h"
#include "System.h"
#include "GameMainRender.h"


//処理の名前

int MouseX, MouseY, Mouse;
int PosX, PosY, inputs = 0, _PosX = 0, _PosY = 0;
int _PosX2, _PosY2;
int guideflg = 0;

class Mouse_Geter {
public:
	void PosGeter();
};


//マウスの座標取得
void Mouse_Geter::PosGeter()
{
	GetMousePoint(&MouseX, &MouseY);
	//Mouse = GetMouseInput();
	if (MouseX > GRAPH_SIZE_X / 2 - 304 + 16 &&
		MouseX < GRAPH_SIZE_X / 2 + 304 - 16 &&
		MouseY > GRAPH_SIZE_Y / 2 - 304 + 16 &&
		MouseY < GRAPH_SIZE_Y / 2 + 304 - 16
		) {
		PosX = (MouseX - (GRAPH_SIZE_X / 2 - 304 + 16)) / 64;
		PosY = (MouseY - (GRAPH_SIZE_Y / 2 - 304 + 16)) / 64;

		//クリック1回目
		if (inputs == 0 && testmapdate[PosY][PosX] > 0) {
			_PosX = PosX, _PosY = PosY;
			inputs = 1;
			guideflg = 1;
		}
		//クリック2回目
		else if (inputs == 1) {
			_PosX2 = PosX, _PosY2 = PosY;
			//if (mapdate[_PosX2][_PosY2] == mapdate[_PosX][_PosY]) {
				//inputs = 1;
			//}
			//else
			inputs = 2;
			//inputs = 0;
			guideflg = 0;
		}

	}
	//ここ調査中
	//DrawFormatString(0, 0, GetColor(100, 0, 0), "1回目の座標x:%d y:%d", MouseX, MouseY);
	
	//WaitKey();
	
}

int Mouse_Pos_Geter()
{
	Mouse_Geter geter;
	geter.PosGeter();
	return 0;
}