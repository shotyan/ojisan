#define _CRT_SECURE_NO_WARNINGS
#include "TestScene.h"
#include "Player.h"
#include "Ground.h"
#include "Engine\\Camera.h"
#include "Engine\Text.h"

//namespace {
//	int myScore = 10;
//}


//コンストラクタ
TestScene::TestScene(GameObject* parent)
	: GameObject(parent, "TestScene"), myScore(0)
{
}

//初期化
void TestScene::Initialize()
{	
	//pWp = Instantiate<Weapon>(this);
	Player* pPlayer = Instantiate <Player>(this);
	Ground* pGround = Instantiate <Ground>(this);
	pPlayer->SetGround(pGround);


	Camera::SetPosition({ 0,10,-20 });
	Camera::SetTarget({ 0,0,0 });

	pText_ = new Text;
	pText_->Initialize();//テキストの初期化
}

//更新
void TestScene::Update()
{
}

//やること！
//餌を数えて、残りの餌数を表示
//スコアを表示
//sprintfでcの文字列を直で作ってもよい

//描画
void TestScene::Draw()
{
	std::string scrText;
	char buffer[256];
	sprintf(buffer, "SCORE:%010d", myScore);
	scrText = "SCORE:" + myScore;
	pText_->Draw(500, 50, scrText.c_str());
}

//開放
void TestScene::Release()
{
	pText_->Release();//テキストの解放
}
