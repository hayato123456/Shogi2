//OK

#include "System.h";
#include "GameMainRender.h";

//�����͂��̂܂�
int System_Main() {
	ChangeWindowMode(TRUE);//�E�C���h�E���[�h
	SetGraphMode(GRAPH_SIZE_X, GRAPH_SIZE_Y, 32);//��ʃT�C�Y�̐ݒ�
	SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�
	SetBackgroundColor(255, 255, 255);//�w�i�̐F
	if (DxLib_Init() == -1)return -1;// �c�w���C�u��������������
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		if (ProcessMessage() != 0)break; //�v���Z�X�̓����ɃG���[���N������I��
		GameMainRender();
		//CantPut();
		WaitKey();            // �L�[�̓��͑҂�(�wWaitKey�x���g�p)
		Mouse_Pos_Geter();

		CantPut();
	}


	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}