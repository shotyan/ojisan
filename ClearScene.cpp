#include "ClearScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

ClearScene::ClearScene(GameObject* parent)
	: GameObject(parent, "ClearScene"), hClearPic_(-1)
{
}

void ClearScene::Initialize()
{
	hClearPic_ = Image::Load("ojisanclrear.png");
	assert(hClearPic_ >= 0);
}

void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

void ClearScene::Draw()
{
	transform_.scale_ = { 0.8f, 0.7f, 0.8f }; //画像の大きさを変更
	Image::SetTransform(hClearPic_, transform_); //画像の位置や向きなどを設定
	Image::Draw(hClearPic_); //画像を表示
}

void ClearScene::Release()
{
}
