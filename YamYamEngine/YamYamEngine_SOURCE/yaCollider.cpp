#include "yaCollider.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaScene.h"
#include "yaSceneManager.h"

//�浹�� �ϱ� ���� �ϳ��� ����
namespace ya
{
	UINT Collider::mCollisionCount = 0;

	Collider::Collider()
		:Component(COMPONENTTYPE::COLLIDER)
		, mSize(Vector2::Zero)
		, mOffset(Vector2::Zero)
		, mCollisionNumber(-1)
		, mbIsCollision(false)
	{
		mCollisionNumber = mCollisionCount;
		mCollisionCount++;
	}

	Collider::~Collider()
	{
	}

	void Collider::Initialize()
	{
	}

	void Collider::Update()
	{
	}

	void Collider::Render()
	{
		////tr �� pos�� ���°� �ȸ���(tr�� Vector3, pos�� Vector2)
		//Transform* tr = GetOwner()->GetComponent<Transform>();
		//Vector3 pos = tr->GetPosition();
		//mPosition = pos + mOffset;

		//pos.x -= mSize.x / 2.0f;
		//pos.y -= mSize.y / 2.0f;
		//pos.x += mOffset.x;
		//
		//// ī�޶�
		////pos = Camera::CalculatePosition(pos);

		//// ����Ʈ �귯�� - ���� ������Ʈ
		//HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		//// ���� �ٲٴ� �� �� �귯��
		///*HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(50, 255, 50));
		//HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);*/

		//HPEN pen = NULL;
		//if (mbIsCollision)			// �浹�Ǿ��ִ� ���¶��(�浹�� �� �������� üũ)
		//{
		//	pen = CreatePen(PS_SOLID, 2, RGB(255, 50, 50));
		//}
		//else
		//{
		//	pen = CreatePen(PS_SOLID, 2, RGB(50, 255, 50));
		//}

		//HPEN oldPen = (HPEN)SelectObject(hdc, pen);

		//// Rectangle �� Long���� ���ǰ� �Ǿ� ����
		//// Rectangle(hdc, pos.x, pos.y, pos.x + mSize.x, pos.y + mSize.y);

		//SelectObject(hdc, oldBrush);
		//DeleteObject(transparentBrush);

		//SelectObject(hdc, oldPen);
		//DeleteObject(pen);//pos.y += mOffset.y;


	}

	void Collider::OnCollisionEnter(Collider* other)
	{
		mbIsCollision = true;
		GetOwner()->OnCollisionEnter(other);
	}
	void Collider::OnCollisionStay(Collider* other)
	{
		GetOwner()->OnCollisionStay(other);
	}
	void Collider::OnCollisionExit(Collider* other)		// �� ���������� ��(�浹 X)
	{
		mbIsCollision = false;
		GetOwner()->OnCollisionExit(other);
	}

	void Collider::ColliderOff()
	{

	}
}
