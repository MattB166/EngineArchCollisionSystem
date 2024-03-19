#include "GameObject.h"

GameObject::GameObject(ObjectType type)
{
	Object = type;
	std::cout << "\nSpawned a " << GameObject::ObjectTypeToString(type)<< "\n";
	

}

GameObject::GameObject(SDL_Texture* FirstTexture, SDL_Texture* SecondTexture, SDL_Renderer* renderer, ObjectType type)
{
	Maintexture = FirstTexture; 
	SecondaryTexture = SecondTexture;
	Renderer = renderer; 
	Object = type;
	SetObjectPosition();
	
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(Maintexture);
	SDL_DestroyTexture(SecondaryTexture);
}

void GameObject::Draw()
{
	if (Object == Circle)
	{
		std::cout << "Cannot currently draw a circle. " << std::endl;
	}
	else if (Object == Square)
	{
		Vector2 ObjectCentre = pos + Vector2(width / 2, height / 2);

		SDL_Rect dstRect{ ObjectCentre.x,ObjectCentre.y,width,height };
		SDL_RendererFlip flip = SDL_FLIP_NONE;

		SDL_RenderCopyEx(Game::instance()->GetRenderer(), Maintexture, NULL, &dstRect, rotation, NULL, flip);
	}
	
	 
	
}

void GameObject::Update()
{
	Draw();
}

std::string GameObject::ObjectTypeToString(ObjectType type)
{
	switch (type)
	{
	case Square:
		return "Square";
		break;
	case Circle:
		return "Circle";
		break;
	default:
		break;
	}
}

void GameObject::ChangeTexture()
{
	
}

void GameObject::SetObjectPosition()
{
	srand(time(NULL));

	int randX = rand() % 800 + 1;
	int randY = rand() % 600 + 1;

	pos.x = randX;
	pos.y = randY; 

	std::cout << "X Position is: " << randX << "And Y Position is: " << randY << std::endl; 
}

void GameObject::RandomMovement()
{
	/// random vector within screen and set it as a destination vector. 
	
}
