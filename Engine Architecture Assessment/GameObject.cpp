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
}

void GameObject::Draw(SDL_Renderer* renderer)
{

}

void GameObject::Update()
{
	std::cout << Object << "is updating" << std::endl; 
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
