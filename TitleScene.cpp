#include "TitleScene.h"
#include "Engine\Image.h"
#include "Engine\Input.h"
#include "Engine\SceneManager.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent, "TitleScene"),hTitlePic_(-1)
{
}

void TitleScene::Initialize()
{
	hTitlePic_ = Image::Load("ojisan.png");
	assert(hTitlePic_ >= 0);
}

void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_TEST);
	}
}

void TitleScene::Draw()
{
	transform_.scale_ = { 1.0f,1.0f,1.0f, }; //画像の大きさを変更
	Image::SetTransform(hTitlePic_, transform_); //画像の位置や向きなどを設定
	Image::Draw(hTitlePic_); //画像を表示
}

void TitleScene::Release()
{
}
