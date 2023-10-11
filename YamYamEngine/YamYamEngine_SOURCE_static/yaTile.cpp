#include "yaTile.h"
#include "yaTile.h"
#include "yaMeshRenderer.h"
#include "yaCollider.h"
//#include "yaTexture.h"
#include "yaResources.h"
#include "yaCollisionManager.h"
#include "yaObject.h"
#include "yaToolScene.h"



namespace ya
{
	UINT Tile::mSelectedX = 0;
	UINT Tile::mSelectedY = 0;


	Tile::Tile()
		: mMeshRenderer(nullptr)
		, mSourceIndexX(0)
		, mSourceIndexY(0)
		, mIndexX(0)
		, mIndexY(0)
		, mType(eType::None)

	{

	}

	Tile::~Tile()
	{
	}

	void Tile::Initialize()
	{
		mMeshRenderer = AddComponent<MeshRenderer>();
		//AddComponent<Collider>();

		// Ÿ�� �ּ�
		ya::Texture* Tile_
			= ya::Resources::Find<ya::Texture>(L"Tile");

		mMeshRenderer->SetImage(Tile_);
		mMeshRenderer->SetScale(Vector2(1.0f, 1.0f));
	}

	void Tile::Update()
	{
		GameObject::Update();
	}

	void Tile::Render()
	{
		GameObject::Render();
	}

	void Tile::SetTile(int x, int y, int z)
	{
		mMeshRenderer->SetTile(x, y, z);
	}

	void Tile::OnCollisionEnter(Collider* other)
	{
		if (other->GetOwner()->GetLayer() == LAYER::ATTACK)
		{
			// �μ����� Ÿ���� ��� �ݶ��̴� ������Ʈ�� Delete ���ִ� �Լ��� �ʿ�
			// �浹�ϰ� �Ǹ� � Ÿ�Ϸ� �ٲ�� �Ǵ��� SetSourceTileIdx�� ����
			// �μ����� �Ǹ� Ÿ���� Ÿ���� None���� �ٲ���
			if (this->GetType() == eType::Crack)
			{
				Transform* tiletr = this->GetComponent<Transform>();
				Vector3  Steampos = tiletr->GetPosition();
				if (this->GetSourceTileIdx() == Vector3(0, 0, 1) ||
					this->GetSourceTileIdx() == Vector3(1, 0, 1) ||
					this->GetSourceTileIdx() == Vector3(2, 0, 1))
				{
					this->SetSourceTileIdx(0, 1, 1);
					this->DeleteComponent<Collider>();
					mMeshRenderer->SetTile(0, 1, 0);
					this->SetType(eType::None);
				}

				else if (this->GetSourceTileIdx() == Vector3(3, 2, 1) ||
					this->GetSourceTileIdx() == Vector3(4, 2, 1))
				{
					this->SetSourceTileIdx(1, 1, 1);
					this->DeleteComponent<Collider>();
					mMeshRenderer->SetTile(1, 1, 1);
					this->SetType(eType::None);
				}

				else if (this->GetSourceTileIdx() == Vector3(3, 0, 1) ||
					this->GetSourceTileIdx() == Vector3(4, 0, 1))
				{
					this->SetSourceTileIdx(3, 4, 1);
					this->DeleteComponent<Collider>();
					mMeshRenderer->SetTile(3, 4, 1);
					this->SetType(eType::None);
				}

			}
			else if (this->GetType() == eType::Uncrushable)
			{

			}
		}
	}
	void Tile::OnCollisionStay(Collider* other)
	{

	}
	void Tile::OnCollisionExit(Collider* other)
	{

	}


}