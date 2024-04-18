#include "Square.h"
#include "EventManager.h"

/// <summary>
/// Instantiation of Square triggers creation of a new collider, which is then added to collision manager. 
/// </summary>
/// <param name="params"></param>
Square::Square(Parameters params) :GameObject(params)
{
	MainTexture = params.texture;
	SecondaryTexture = params.SecondTexture;
	Renderer = params.renderer;
	Object = params.type;
	collider = new BoxCollider(pos.x, pos.y, width, height,std::bind(&GameObject::OnCollisionNotify,this,std::placeholders::_1));
	CollisionManager::AddCollider(collider); 
	EventManager::RegisterListener(collider, std::bind(&GameObject::OnOtherObjectCollisionNotify, this, std::placeholders::_1, std::placeholders::_2), EventType::Collision);
}

Square::~Square()
{
	delete collider;
}

void Square::OnCollisionNotify(Collider* col)
{
	if (col->GetColliderType() == collider->GetColliderType())
	{
		std::cout << "FRIENDLY FIRE" << std::endl;
		if (CollisionCount >= 10)
		{
			std::cout << "Square has reached 10 collision. Collider has been de activated" << std::endl;
		}
	}
	GameObject::OnCollisionNotify(col);
}

void Square::OnOtherObjectCollisionNotify(Collider* col, Collider* col1)
{
	if(col != collider && col1 != collider)
	{
		std::cout << "Square has Detected Collision between two other game objects" << std::endl;
		if (col->GetColliderType() == CircCollider && col1->GetColliderType() == SquareCollider || col->GetColliderType() == SquareCollider && col1->GetColliderType() == CircCollider)
		{
			std::cout << "A circle has attacked my square mate! " << std::endl;
			///attack circle 
		}
	}
	
	GameObject::OnOtherObjectCollisionNotify(col, col1);
}

