#include "yaPlayer.h"
#include "yaInput.h"
#include "yaTransform.h"
#include "yaTime.h"
#include "yaMeshRenderer.h"
#include "yaPlayerScript.h"
#include "yaResources.h"
#include "yaRigidbody.h"
#include "yaCollider.h"
#include "yaRigidbody.h"

namespace ya
{
	Player::Player()
		: HP(100),
		mState(eState::Live)
	{
		AddComponent<Transform>();
		AddComponent<Rigidbody>();
		AddComponent<Collider>();
	}

	Player::~Player()
	{
	}

	void Player::Initialize()
	{
		GameObject::Initialize();
	}
	void Player::Update()
	{
		GameObject::Update();

		// ����
		if (Input::GetKeyDown(eKeyCode::LCTRL))
		{
			mState = eState::Jump;
		}

		switch (mState)
		{
		case ya::Player::eState::Live:
			Live();
			break;
		case ya::Player::eState::Hit:
			Hit();
			break;
		case ya::Player::eState::Dead:
			Dead();
			break;

		case ya::Player::eState::End:
			break;
		default:
			break;
		}
	}
	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Player::Render()
	{
		GameObject::Render();
	}
	void Player::OnCollisionEnter(Collider* other)
	{
		// �Ѿ˰� �浹�ϸ�
		if (other->GetOwner()->GetLayer() == LAYER::ATTACK)
		{
			mState = eState::Hit;
		}

		// ��Ż �浹 �� ó��
		if (other->GetOwner()->GetLayer() == LAYER::PORTAL)
		{
			
		}
	}
	void Player::OnCollisionStay(Collider* other)
	{
	
	}
	void Player::OnCollisionExit(Collider* other)
	{
	
	}
	void Player::Live()
	{
	}
	void Player::Jump()
	{
		Transform* tr = GetComponent<Transform>();
		Vector3 position = tr->GetPosition();
		this->GetComponent<Rigidbody>();
	}
	void Player::Hit()
	{
		if(HP != 0)
		{
			HP -= 10;
		}
		else
		{
			mState = eState::Dead;
		}
	}
	void Player::Dead()
	{
		Destroy(this);
	}
}
