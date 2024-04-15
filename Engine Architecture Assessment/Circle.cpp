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
	CollisionManager::AddCollider(collider);

}

Circle::~Circle()
{
	delete collider;
}

void Circle::Draw()
{
	
	SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 255); ///random ints every time it collides 
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

	
	
	
}


CircleParameters::CircleParameters(float radius)
{
	this->radius = radius;
}
