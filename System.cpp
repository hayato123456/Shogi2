//OK

#include "System.h";
#include "GameMainRender.h";

//ここはそのまま
int System_Main() {
	ChangeWindowMode(TRUE);//ウインドウモード
	SetGraphMode(GRAPH_SIZE_X, GRAPH_SIZE_Y, 32);//画面サイズの設定
	SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に
	SetBackgroundColor(255, 255, 255);//背景の色
	if (DxLib_Init() == -1)return -1;// ＤＸライブラリ初期化処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		if (ProcessMessage() != 0)break; //プロセスの同期にエラーが起きたら終了
		GameMainRender();
		//CantPut();
		WaitKey();            // キーの入力待ち(『WaitKey』を使用)
		Mouse_Pos_Geter();

		CantPut();
	}


	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}