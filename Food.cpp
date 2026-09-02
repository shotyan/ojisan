#include "Food.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "TestScene.h"
#include "Ground.h"


Food::Food(GameObject* parent)
	:GameObject(nullptr, "Food"), type_(FOODTYPE_NORMAL),hModel_(-1),score_(0)
{
}

Food::~Food()
{
}

void Food::Initialize()
{
	transform_.scale_ = { 0.3f,0.3f,0.3f };
}

void Food::Update()
{
	if (type_ == FoodType::FOODTYPE_POWER)
	{
		transform_.rotate_.y += 1.0f;
	}
}

void Food::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Food::Release()
{
}

void Food::SetFoodType(FoodType type)
{
	type_ = type;
	if (type_ == FoodType::FOODTYPE_NORMAL)
	{
		SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0.3, 0), 0.3f);
		AddCollider(collision);
		hModel_ = Model::Load("Pawer esa.fbx");
		score_ = 1;
	}
	else if (type_ == FoodType::FOODTYPE_POWER)
	{
		SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0.6, 0), 0.6f);
		AddCollider(collision);
		hModel_ = Model::Load("Oden.fbx");
		score_ = 5;
	}
}


void Food::OnCollision(GameObject* pTarget)
{
	TestScene* testScene = dynamic_cast<TestScene*>(GetParent()->GetParent());
	testScene->AddScore(score_);
	Ground* ground = dynamic_cast<Ground*>(FindObject("Ground"));
	ground->DecEsaCount(type_);
	if (pTarget->GetObjectName() == "Player")
	{
		KillMe();
	}
}

