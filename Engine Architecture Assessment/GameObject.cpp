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
	SetObjectPosition(100, 100);
	
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(Maintexture);
	SDL_DestroyTexture(SecondaryTexture);
}

void GameObject::Draw(SDL_Renderer* renderer)
{
	///rendercopy here 
	SDL_Rect dstRect{ pos.x,pos.y,width,height };
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	//SDL_SetRenderTarget(renderer, Maintexture);
	SDL_RenderCopyEx(renderer, Maintexture, NULL, &dstRect, rotation, NULL, flip);
	std::cout << "Drawing object" << std::endl; 
	
}

void GameObject::Update(SDL_Renderer* renderer)
{
	//std::cout << Object << "is updating" << std::endl; 
	Draw(renderer);
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

//void GameObject::Spawn(ObjectType type)
//{
//	if (type == Circle)
//	{
//		std::cout << "Spawned Circle" << std::endl; 
//	}
//	else if (type == Square)
//	{
//		std::cout << "Spawned Square" << std::endl;
//	}
//}

void GameObject::ChangeTexture()
{
	
}

void GameObject::SetObjectPosition(int x, int y)
{
	pos.x = x;
	pos.y = y;
}
