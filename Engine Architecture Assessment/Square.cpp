#include "Square.h"

Square::Square(Parameters params) :GameObject(params)
{
	MainTexture = params.texture;
	SecondaryTexture = params.SecondTexture;
	Renderer = params.renderer;
	Object = params.type;
	collider = new BoxCollider(pos.x, pos.y, width, height);
	CollisionManager::instance()->AddCollider(collider);
}

