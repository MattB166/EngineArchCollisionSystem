#include "Square.h"

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
	collider = new BoxCollider(pos.x, pos.y, width, height,std::bind(&GameObject::OnCollisionNotify,this));
	CollisionManager::instance()->AddCollider(collider); 

}

