//�r��
#include"System.h"
int swap = 0;
int Move_X = 0,Move_Y = 0;
int flg_X = 0, flg_Y = 0;
int Piece_Move[10][2];
int PB = 0;//��Ɋ��蓖�Ă�ꐔ�l�̕ϐ�
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
	{ 0, 1},//��
	{ 1, 0},//�E
	{ 0, -1},//��
	{ -1, 0},//��
	{ 1, 1},//�E��
	{ -1, 1},//����
	{ 1, -1},//�E��
	{ -1, -1}, //����
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

//����A�����A���f�S��
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

//�l�݂̏���
//����̋�ׂĂ��i�߂��Ɏ����̉����i�߂Ȃ��ꍇ�A�~�Q���������ꍇ
void CantPutjudg::jam()
{

};

//��u���邩���f
//1��ڂɉ������4
// x�����Ay���c
//1��ڂ̍��W����2��ڂɉ��������W�܂łō��E�㉺�A�ȂȂ߂����Ă����āu�����̋�ȉ�������̎�O�̋�܂Łv�i�߂�A��Ԋp�ȊO��1�i��ŏI���A�[�n�͕ʂ̏���
void CantPutjudg::PutJudg()
{
	//1��ڂɉ������̂�������Ȃ̂��ʏ�̋�Ȃ̂��H

	//�ʏ�̋�̏ꍇ�ǂ̕����ɉ����ꂽ��

	
	//_PosY(1��ڂ̏c) _PosX(1��ڂ̉�)�@_PosY2(2��ڂ̏c) _PosX2(2��ڂ̉�)
	//0123 ����2��ڂ��1��ڂ̂ق����Ⴏ��΍��A������ΉE
	//1 �c��2��ڂ��1��ڂ̂ق����Ⴏ��Ώ�A������Ή�
	//2 
	Move_X = _PosX - _PosX2;//��
	Move_Y = _PosY - _PosY2;//�c
	DrawFormatString(100, 0, GetColor(0, 0, 0), "�ŏI�I�����̍��Wx:%d y:%d�@", Move_X, Move_Y);
	DrawFormatString(300, 0, GetColor(0, 0, 0), "�@1��ڂ̍��Wx:%d y:%d", _PosX, _PosY);
	DrawFormatString(500, 0, GetColor(100, 0, 0), "2��ڂ̍��Wx:%d y:%d", _PosX2, _PosY2);

	

	//1���ƕ�
	//�z��̃R�s�[//�R�s�[���ςɂ���
	PB = testmapdate[_PosY][_PosX];
	for (int i = 0; i <= 8; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			//OK ���A���A��A���A�j�A�ƁA"narigin","narikei","narikyou"
			//NG ���A�p�A��, "ryuu", "uma", "gyoku"
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
	
	//���(0�`28)�ɓ�������(�c�A��)��������\�ƈ�v���邩���ׂ�
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
	//����
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

//��̓���ւ�
void CantPutjudg::Swaping()
{
	if (inputs == 2) {
		swap = testmapdate[_PosY][_PosX];
		testmapdate[_PosY][_PosX] = testmapdate[_PosY2][_PosX2];
		testmapdate[_PosY2][_PosX2] = swap;
		inputs = 0;
	}
};

int CantPut()//���C�����[�`��
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