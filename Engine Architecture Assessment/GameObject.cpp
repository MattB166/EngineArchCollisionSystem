#include "GameObject.h"

GameObject::GameObject(ObjectType type)
{
	Object = type;
	
	std::cout << "\nSpawned a " << GameObject::ObjectTypeToString(type)<< "\n";
	

}

GameObject::GameObject(Parameters params)
{
	Maintexture = params.texture; 
	SecondaryTexture = params.SecondTexture;
	Renderer = params.renderer; 
	Object = params.type;
	SetObjectPosition();
	//RegisterToEvents();
	Observe();
	///add collider to collision class 
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
	RandomMovement(); ///works but its absolutely mental atm. need speed and delta time 
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

std::string GameObject::getName()
{
	return name;
}

void GameObject::Observe()
{
	EventManager::instance()->RegisterListener(this);
}

void GameObject::ChangeTexture()
{
	
}

void GameObject::SetObjectPosition()
{
	
	///check to world bounds 
	int randX = rand() % 800 + 1;
	int randY = rand() % 600 + 1;

	pos.x = randX;
	pos.y = randY; 

	std::cout << "X Position is: " << randX << "And Y Position is: " << randY << std::endl; 
}

void GameObject::RandomMovement()//take delta time as a float 
{
    //destinationReached = false;
	//static const float arrivalThreshold = 5.0f;
	

	
	int randX = rand() % 800 + 1;
	int randY = rand() % 600 + 1;
	Vector2	movePos = Vector2(randX, randY);
	//destinationReached = false;
	 
		
	//destinationReached = false;
	std::cout << "New Dest is: " << movePos.x << " : " << movePos.y << std::endl;
	pos = Vector2::MoveTowards(pos, movePos,0.1);///need proper arrival check, speed and delta time for this to work better, as well as only setting
	                                             // new position when reached the old one 
	

  /*if (Vector2::Distance(pos, movePos) < arrivalThreshold)
	{
		destinationReached = true;
	}
	*/
}
