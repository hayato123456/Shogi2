//途中
#include"System.h"
int swap = 0;
int Move_X = 0,Move_Y = 0;
int flg_X = 0, flg_Y = 0;
int Piece_Move[10][2];
int PB = 0;//駒に割り当てられ数値の変数
/*
char cast[][40][64] = {
	"no","hu","ou","kin","gin","kei","kyou","kaku","hi","to","narigin","narikei",
	"narikyou","ryuu","uma","gyoku"
};
*/
int hu[10][2] =
{  
	{ 0, 1},
};

int ou[10][2] =
{  
	{ 0, 1},//上
	{ 1, 0},//右
	{ 0, -1},//下
	{ -1, 0},//左
	{ 1, 1},//右下
	{ -1, 1},//左下
	{ 1, -1},//右上
	{ -1, -1}, //左上
};
int kin[10][2] =
{   
	{ 0, 1},
	{ 1, 0},
	{ 0, -1},
	{ -1, 0},
	{ -1, 1},
	{ 1, 1}, 
};
int gin[10][2] =
{   
	{ 0, 1},
	{ 1, 1},
	{ -1, 1},
	{ 1, -1},
	{ -1, -1}, 
};
int kei[10][2] =
{  
	{ -1, 2},
	{ 1, 2},
};

//動作、挙動、判断全般
class CantPutjudg
{
public:
	void Put();
	void Swaping();
	void PutJudg();
	void jam();
};

//
void CantPutjudg::Put()
{

}

//詰みの処理
//相手の駒すべてが進める先に自分の王が進めない場合、降参を押した場合
void CantPutjudg::jam()
{

};

//駒が置けるか判断
//1回目に押した駒が4
// xが横、yが縦
//1回目の座標から2回目に押した座標までで左右上下、ななめを見ていって「自分の駒以下かつ相手の手前の駒まで」進める、飛車角以外は1つ進んで終わり、啓馬は別の処理
void CantPutjudg::PutJudg()
{
	//1回目に押したのが持ち駒なのか通常の駒なのか？

	//通常の駒の場合どの方向に押されたか

	
	//_PosY(1回目の縦) _PosX(1回目の横)　_PosY2(2回目の縦) _PosX2(2回目の横)
	//0123 横は2回目より1回目のほうが低ければ左、高ければ右
	//1 縦は2回目より1回目のほうが低ければ上、高ければ下
	//2 
	Move_X = _PosX - _PosX2;//横
	Move_Y = _PosY - _PosY2;//縦
	DrawFormatString(100, 0, GetColor(0, 0, 0), "最終的差分の座標x:%d y:%d　", Move_X, Move_Y);
	DrawFormatString(300, 0, GetColor(0, 0, 0), "　1回目の座標x:%d y:%d", _PosX, _PosY);
	DrawFormatString(500, 0, GetColor(100, 0, 0), "2回目の座標x:%d y:%d", _PosX2, _PosY2);

	

	//1だと歩
	//配列のコピー//コピーを可変にする
	PB = testmapdate[_PosY][_PosX];
	for (int i = 0; i <= 8; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			//OK 歩、王、銀、金、桂、と、"narigin","narikei","narikyou"
			//NG 香、角、飛, "ryuu", "uma", "gyoku"
			if (PB == 1) 
			{
				Piece_Move[i][j] = hu[i][j];
			}
			else if (PB == 2 || PB == 13 || PB == 14 || PB == 35)
			{
				Piece_Move[i][j] = ou[i][j];
			}
			else if (PB == 3 || PB == 9 || PB == 10 || PB == 11) 
			{
				Piece_Move[i][j] = kin[i][j];
			}
			else if (PB == 4) 
			{
				Piece_Move[i][j] = gin[i][j];
			}
			else if (PB == 5) 
			{
				Piece_Move[i][j] = kei[i][j];
			}
		}
	}
	
	//駒ごと(0～28)に動いた分(縦、横)が動ける表と一致するか調べる
	for (int i = 0; i <= 8; i++) 
	{
		for (int j = 0; j <= 1; j++) 
		{
			if (j == 0) 
			{
				if (Move_X == Piece_Move[i][j])
				{
					flg_X = 1;
				}
				else
				{
					flg_X = 0;
				}

			}
			if (j == 1) 
			{
				if (Move_Y == Piece_Move[i][j])
				{
					flg_Y = 1;
				}
				else
				{
					flg_Y = 0;
				}
			}
			
		}
		if (flg_X == 1 && flg_Y == 1)
		{
			break;
		}
	}
	//香車
	if (PB == 6)
	{
		if (Move_X == 0 && Move_Y < 0)
		{
			//for (int i = -1; i >= 1; i++)
			//{

			//}
		}
	}
};

//駒の入れ替え
void CantPutjudg::Swaping()
{
	if (inputs == 2) {
		swap = testmapdate[_PosY][_PosX];
		testmapdate[_PosY][_PosX] = testmapdate[_PosY2][_PosX2];
		testmapdate[_PosY2][_PosX2] = swap;
		inputs = 0;
	}
};

int CantPut()//メインルーチン
{
	CantPutjudg judg;
	//judg.Put();
	judg.PutJudg();
	if (flg_X == 1 && flg_Y == 1)
	{
		judg.Swaping();
	}
	//
	else if(inputs == 2)
	{
		inputs = 0;
	}
	
	return 0;
}