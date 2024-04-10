#include "Circle.h"

Circle::Circle(Parameters params, CircleParameters param)
{
	MainTexture = params.texture;
	SecondaryTexture = params.SecondTexture;
	Renderer = params.renderer;
	Object = params.type;
	radius = param.radius;
	SetObjectPosition();
	collider = new CircleCollider(pos.x, pos.y, radius, std::bind(&GameObject::OnCollisionNotify, this,std::placeholders::_1));
	CollisionManager::instance()->AddCollider(collider);

}

Circle::~Circle()
{
	delete collider;
}

void Circle::Draw()
{
	//Vector2 ObjectCentre = pos + Vector2(width / 2, height / 2);
	SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255);
	for (int w = 0; w < radius * 2; ++w)
	{
		
		for (int h = 0; h < radius * 2; ++h)
		{
			int dx = radius - w;
			int dy = radius - h;
			if ((dx * dx + dy * dy) <= (radius * radius))
			{
				
				SDL_RenderDrawPoint(Renderer, pos.x + dx, pos.y + dy);
				
			}
		}
	}

	
	//std::cout << "Circle X Position is: " << pos.x  << "Circle Y Position is:" << pos.y << std::endl;
	
}


CircleParameters::CircleParameters(float radius)
{
	this->radius = radius;
}
