#include "GameObject.h"

GameObject::GameObject(ObjectType type)
{
	Object = type;
	
	std::cout << "\nSpawned a " << GameObject::ObjectTypeToString(type)<< "\n";
	
	
}

GameObject::GameObject(SquareParameters params)
{
	MainTexture = params.texture; 
	SecondaryTexture = params.SecondTexture;
	Renderer = params.renderer; 
	Object = params.type;
	texture = MainTexture;
	SetObjectPosition();
	//RegisterToEvents();
	Observe();
	///add collider to collision class 
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(MainTexture);
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
		SDL_RenderCopyEx(Game::instance()->GetRenderer(), texture, NULL, &dstRect, rotation, NULL, flip);
	}
	
	 
	
}

void GameObject::Update()
{
	Draw();
	RandomMovement(Time::instance()->GetDeltaTime()); ///works but its absolutely mental atm. need speed and delta time 
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
	if (textureActive == true)
	{
		texture = SecondaryTexture;
		SecondaryTexture = MainTexture;
		textureActive = false;
	}
	else
	{
		SecondaryTexture = texture;
		texture = MainTexture;
		textureActive = true;
	}
}

void GameObject::SetObjectPosition()
{
	
	///check to world bounds 
	int randX = rand() % 800 + 1;
	int randY = rand() % 600 + 1;

	pos.x = randX;
	pos.y = randY; 

	//std::cout << "X Position is: " << randX << "And Y Position is: " << randY << std::endl; 
}

void GameObject::RandomMovement(float deltaTime)//take delta time as a float 
{
	if (!movementStopped)
	{
		static const float arrivalThreshold = 0.5f;
	    
		if (arrived)
		{
			int randX = rand() % 800 + 1;
			int randY = rand() % 600 + 1;
			movePos = Vector2(randX, randY);
			//std::cout << "New Dest is: " << movePos.x << " : " << movePos.y << std::endl;
			arrived = false;
		}


		pos = Vector2::MoveTowards(pos, movePos, speed * deltaTime);///need proper arrival check, speed and delta time for this to work better, as well as only setting
		
		
		// new position when reached the old one 
		if (Vector2::Distance(pos, movePos) < arrivalThreshold)
		{
			arrived = true;
			ChangeTexture();
		}
	}
	

}

void GameObject::OnCollisionEnter()
{
	movementStopped = true;

	ChangeTexture();

	//return to movement enabled once bounced away 
}
