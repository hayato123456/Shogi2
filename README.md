# Shogi<br>
　DxLibで動かせる将棋を作成している途中です。<br>
<br>
①タイトル<br>
　将棋

②概要<br>
　9x9の盤上に40枚の駒があり、対局者が交互に駒を動かしていき、<br>
  相手の王を動かせなくしたほうの勝ち<br>

③使用言語<br>
　C言語、C++<br>

④開発環境<br>
　VisualStudio2022,DxLib<br>

⑤処理<br>
★現在実装されている処理<br>
・駒と将棋盤の描画処理<br>
・マウスでクリックしたところの座標の取得<br>
・駒の入れ替え処理<br>
・プレイヤー側が駒が動かせるかどうかを判定(歩、王、銀、金、桂、と、成銀、成桂、成香)まで<br>
<br>

====================================================
<br>
★これから実装したい処理<br>
・プレイヤー側が駒を動かせるかどうかを判定(香、角、飛、龍、馬、玉)<br>
・相手側が駒を動かせるかどうかの判定<br>
・プレイヤー側が動かせる箇所のガイドを表示<br>
・UIの実装(一手戻る、降参)<br>
・詰みの処理<br>
・一手戻るの処理<br>
・降参の処理<br>
・千日手の処理<br>
・2歩の処理<br>
・リザルト画面やスタート画面、設定画面などの追加<br>
・思考ルーチン(人工知能)<br>
<br>
⑥工夫したところ<br>
・管理がしやすいように極力、ヘッダーファイルを作って関数の宣言などは<br>
ヘッダーファイルに書き込んでいます。<br>
・管理がしやすいようにオブジェクト指向を意識して作りました。<br>
・駒に割り当てられた番号から該当の配列(動けるマス)をコピーし、マウスで<br>
2回目にクリックした場所と一致するかで動かせるかの判定をしています。<br>

⑦その他<br>
　制作において過程が大事だと考えていますので、<br>
　概要だけをみて1から自分で考えてソースコードを書きました。<br>
