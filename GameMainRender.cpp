//ある程度OK、数字の根拠、変数名、クラス名、その他見やすく

#define _CRT_SECURE_NO_WARNINGS
#include "System.h"
#include "GameMainRender.h"

int testmapdate[FIELD_WIDTH][FIELD_HEIGHT] =
{ { 26, 25, 24, 23, 35, 23, 24, 25, 26 },
  {  0, 28,  0,  0,  0,  0,  0, 27,  0 },
  { 21, 21, 21, 21, 21, 21, 21, 21, 21 },
  {  0,  0,  0,  0,  0,  0,  0,  0,  0 },
  {  0,  0,  0,  13,  14,  0,  0,  0,  0 },
  {  0,  0,  0,  0,  0,  9,  10, 11,  12 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1 },
  {  0,  7,  0,  0,  0,  0,  0,  8,  0 },
  {  6,  5,  4,  3,  2,  3,  4,  5,  6 }, };

int mapdate[FIELD_WIDTH][FIELD_HEIGHT] =
{ { 26, 25, 24, 23, 35, 23, 24, 25, 26 },
  {  0, 28,  0,  0,  0,  0,  0, 27,  0 },
  { 21, 21, 21, 21, 21, 21, 21, 21, 21 },
  {  0,  0,  0,  0,  0,  0,  0,  0,  0 },
  {  0,  0,  0,  0,  30,  0,  0,  0,  0 },
  {  0,  0,  0,  0,  0,  0,  0,  0,  0 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1 },
  {  0,  7,  0,  0,  0,  0,  0,  8,  0 },
  {  6,  5,  4,  3,  2,  3,  4,  5,  6 }, };


//通常駒の画像用
char cast[][40][64] = {
	"no","hu","ou","kin","gin","kei","kyou","kaku","hi","to","narigin","narikei",
	"narikyou","ryuu","uma","gyoku"
};
//持ち駒の画像用
char cast2[][40][64] = {
	"no","no","hu","kin","gin","kei","kyou","kaku","hi"
};

//処理の名前
class ShogiBoardRender{
public:
	//int test;
	void BoardRenders();
	void PieceRenders();
	void PawnRenders();
};

//背景、盤の描画
void ShogiBoardRender::BoardRenders()
{
	ClearDrawScreen();//画面消去
	//引いている400と600は背景の画像サイズの半分
	LoadGraphScreen(GRAPH_SIZE_X / 2 - 600,
		GRAPH_SIZE_Y / 2 -400,
		"texture/tatami.png",
		TRUE);

	//持ち駒の盤描画
	LoadGraphScreen(GRAPH_SIZE_X / 2 - 304 + 64 * 6 + 24,
		GRAPH_SIZE_Y / 2 - 304 + 64 * 2 - 16,
		"texture/syougi3.png",
		TRUE);
	LoadGraphScreen(GRAPH_SIZE_X / 2 - 304 + 64 * -7 + 56,
		GRAPH_SIZE_Y / 2 - 304 + 64  - 82,
		"texture/syougi3.png",
		TRUE);

	//引いている304は将棋盤の画像サイズの半分
	LoadGraphScreen(GRAPH_SIZE_X / 2 - 304,
		GRAPH_SIZE_Y / 2 - 304,
		"texture/syougi2.png",
		TRUE);
	
	//test = 500;
}
//駒の描画
void ShogiBoardRender::PieceRenders()
{
	for (int i = 0; i <= 8; i++) {
		for (int j = 0; j <= 8; j++) {
			int komas = testmapdate[j][i];
			std::string str2 = "texture/";
			str2 = str2 + cast[0][testmapdate[j][i] % 20] + ".png";
			const char* str = str2.c_str();
			int GHandle1 = LoadGraph(str);
			if (komas != 0 && komas < 21) 
			{//自分
				LoadGraphScreen(
					//足している64は駒の画像サイズ、16は駒のサイズの1/4
					GRAPH_SIZE_X / 2 - 304 + 64 * i + 16,
					GRAPH_SIZE_Y / 2 - 304 + 64 * j + 16,
					str,
					TRUE
				);
			}
			else if (komas != 0) 
			{
				DrawRotaGraph
				(
					GRAPH_SIZE_X / 2 - 304 + 64 * i + 48,
					GRAPH_SIZE_Y / 2 - 304 + 64 * j + 48,
					1.0f,
					PI,
					GHandle1,
					TRUE
				);
			}
			//ガイド
			if (i == _PosX && j == _PosY && testmapdate[j][i] > 0 && testmapdate[j][i] < 20 && guideflg == 1)
			{
				LoadGraphScreen
				(
					GRAPH_SIZE_X / 2 - 304 + 64 * i + 16,
					GRAPH_SIZE_Y / 2 - 304 + 64 * j + 16,
					"texture/hai.png",
					TRUE
				);
			}
		}
	}

	//DrawFormatString(0, 0, GetColor(0, 0, 0), "1回目の座標x:%d y:%d", _PosX, _PosY);
	//DrawFormatString(300, 0, GetColor(0, 0, 0), "2回目の座標x:%d y:%d", _PosX2, _PosY2);
	//DrawFormatString(0, 50, GetColor(0, 0, 0), "swap:%d 1つ目の駒:%d 2つ目の駒:%d 押された状態:%d", swap,

	/// <summary>
	/// 
	///DrawFormatString(100, 0, GetColor(0, 0, 0), "1回目の座標x:%d y:%d", PosX, PosY);
	///DrawFormatString(300, 0, GetColor(0, 0, 0), "1回目の座標x:%d y:%d", _PosX, _PosY);
	///DrawFormatString(500, 0, GetColor(100, 0, 0), "2回目の座標x:%d y:%d", _PosX2, _PosY2);
	/// </summary>

	//mapdate[_PosY][_PosX] / 20, mapdate[_PosX2][_PosY2] / 20, inputs);
	ScreenFlip();//裏画面のデータを表画面へ
}
//持ち駒描画
void ShogiBoardRender::PawnRenders()
{
	//7個 * 数値
	for (int i = 2; i <= 8; i++) {
		std::string str2 = "texture/";
		str2 = str2 + cast2[0][i] + ".png";
		const char* str = str2.c_str();
		int GHandle1 = LoadGraph(str);
		LoadGraphScreen(
			//足している64は駒の画像サイズ、16は駒のサイズの1/4
			GRAPH_SIZE_X / 2 - 304 + 64 * 10 + 32,
			GRAPH_SIZE_Y / 2 - 304 + 64 * i + 16,
			str,
			TRUE
		);
		DrawRotaGraph
		(
			GRAPH_SIZE_X / 2 - 304 + 64 * -2 + 32,
			GRAPH_SIZE_Y / 2 - 304 + 64 * (8-i) +48,
			1.0f,
			PI,
			GHandle1,
			TRUE
		);
	}
}

//メインルーチン
int GameMainRender() {

	ShogiBoardRender render;
	render.BoardRenders();
	render.PieceRenders();
	//render.PawnRenders();
	//DrawPixel(render.test, 240, GetColor(0, 0, 0));	// 点を打つ
	//WaitKey();				// キー入力待ち
	
	return 0;
}