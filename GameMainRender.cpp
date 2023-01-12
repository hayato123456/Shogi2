//������xOK�A�����̍����A�ϐ����A�N���X���A���̑����₷��

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


//�ʏ��̉摜�p
char cast[][40][64] = {
	"no","hu","ou","kin","gin","kei","kyou","kaku","hi","to","narigin","narikei",
	"narikyou","ryuu","uma","gyoku"
};
//������̉摜�p
char cast2[][40][64] = {
	"no","no","hu","kin","gin","kei","kyou","kaku","hi"
};

//�����̖��O
class ShogiBoardRender{
public:
	//int test;
	void BoardRenders();
	void PieceRenders();
	void PawnRenders();
};

//�w�i�A�Ղ̕`��
void ShogiBoardRender::BoardRenders()
{
	ClearDrawScreen();//��ʏ���
	//�����Ă���400��600�͔w�i�̉摜�T�C�Y�̔���
	LoadGraphScreen(GRAPH_SIZE_X / 2 - 600,
		GRAPH_SIZE_Y / 2 -400,
		"texture/tatami.png",
		TRUE);

	//������̔Օ`��
	LoadGraphScreen(GRAPH_SIZE_X / 2 - 304 + 64 * 6 + 24,
		GRAPH_SIZE_Y / 2 - 304 + 64 * 2 - 16,
		"texture/syougi3.png",
		TRUE);
	LoadGraphScreen(GRAPH_SIZE_X / 2 - 304 + 64 * -7 + 56,
		GRAPH_SIZE_Y / 2 - 304 + 64  - 82,
		"texture/syougi3.png",
		TRUE);

	//�����Ă���304�͏����Ղ̉摜�T�C�Y�̔���
	LoadGraphScreen(GRAPH_SIZE_X / 2 - 304,
		GRAPH_SIZE_Y / 2 - 304,
		"texture/syougi2.png",
		TRUE);
	
	//test = 500;
}
//��̕`��
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
			{//����
				LoadGraphScreen(
					//�����Ă���64�͋�̉摜�T�C�Y�A16�͋�̃T�C�Y��1/4
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
			//�K�C�h
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

	//DrawFormatString(0, 0, GetColor(0, 0, 0), "1��ڂ̍��Wx:%d y:%d", _PosX, _PosY);
	//DrawFormatString(300, 0, GetColor(0, 0, 0), "2��ڂ̍��Wx:%d y:%d", _PosX2, _PosY2);
	//DrawFormatString(0, 50, GetColor(0, 0, 0), "swap:%d 1�ڂ̋�:%d 2�ڂ̋�:%d �����ꂽ���:%d", swap,

	/// <summary>
	/// 
	///DrawFormatString(100, 0, GetColor(0, 0, 0), "1��ڂ̍��Wx:%d y:%d", PosX, PosY);
	///DrawFormatString(300, 0, GetColor(0, 0, 0), "1��ڂ̍��Wx:%d y:%d", _PosX, _PosY);
	///DrawFormatString(500, 0, GetColor(100, 0, 0), "2��ڂ̍��Wx:%d y:%d", _PosX2, _PosY2);
	/// </summary>

	//mapdate[_PosY][_PosX] / 20, mapdate[_PosX2][_PosY2] / 20, inputs);
	ScreenFlip();//����ʂ̃f�[�^��\��ʂ�
}
//������`��
void ShogiBoardRender::PawnRenders()
{
	//7�� * ���l
	for (int i = 2; i <= 8; i++) {
		std::string str2 = "texture/";
		str2 = str2 + cast2[0][i] + ".png";
		const char* str = str2.c_str();
		int GHandle1 = LoadGraph(str);
		LoadGraphScreen(
			//�����Ă���64�͋�̉摜�T�C�Y�A16�͋�̃T�C�Y��1/4
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

//���C�����[�`��
int GameMainRender() {

	ShogiBoardRender render;
	render.BoardRenders();
	render.PieceRenders();
	//render.PawnRenders();
	//DrawPixel(render.test, 240, GetColor(0, 0, 0));	// �_��ł�
	//WaitKey();				// �L�[���͑҂�
	
	return 0;
}