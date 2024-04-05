#include "GameObject.h"

GameObject::GameObject(ObjectType type)
{
	Object = type;
	
	std::cout << "\nSpawned a " << GameObject::ObjectTypeToString(type)<< "\n";
	
	
}

GameObject::GameObject(Parameters params)
{
	MainTexture = params.texture; 
	SecondaryTexture = params.SecondTexture;
	Renderer = params.renderer; 
	Object = params.type;
	texture = MainTexture;
	
	SetObjectPosition();
	
	
	
	//Observe();
	
}

GameObject::GameObject()
{

}

GameObject::~GameObject()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(MainTexture);
	SDL_DestroyTexture(SecondaryTexture);
	//delete(information);
}

void GameObject::Draw()    ///make virtual void 
{
	
	if (Object == ShapeSquare)
	{
		Vector2 ObjectCentre = pos + Vector2(width / 2, height / 2);

		SDL_Rect dstRect{ ObjectCentre.x,ObjectCentre.y,width,height };
		SDL_RendererFlip flip = SDL_FLIP_NONE;
		SDL_RenderCopyEx(Game::instance()->GetRenderer(), texture, NULL, &dstRect, rotation, NULL, flip);

	 }
	else
	{

	}
	
		

	
}


void GameObject::Update()
{
	
	Draw();
	Movement(Time::instance()->GetDeltaTime()); ///works but its absolutely mental atm. need speed and delta time 

}
ObjectType GameObject::GetType()
{
	return Object;
}

std::string GameObject::ObjectTypeToString(ObjectType type)
{
	switch (type)
	{
	case ShapeSquare:
		return "Square";
		break;
	case ShapeCircle:
		return "Circle";
		break;
	default:
		break;
	}
}

Vector2 GameObject::GetPosition()
{
	return pos;
}

std::string GameObject::getName()
{
	return name;
}

//void GameObject::Observe()
//{
//	EventManager::instance()->RegisterListener(this);
//	
//}

void GameObject::OnCollisionNotify(Collider* col)
{
	//std::cout << "Calling collision" << std::endl; 
	ChangeTexture();
	arrived = true;      //////this method does work but can cause some issues with the movement method. when 2 objects collide they both stop moving if chosen opposite direction from opposite side. 
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

	
}

void GameObject::Movement(float deltaTime)
{
	if (!movementStopped)
	{
		static const float arrivalThreshold = 0.5f;
	    
		if (arrived)
		{
			int randX = rand() % 800 + 1;
			int randY = rand() % 600 + 1;
			movePos = Vector2(randX, randY);
			std::cout << "New Dest is: " << movePos.x << " : " << movePos.y << std::endl;
			arrived = false;
		}

		//pos.x += 5;
		pos = Vector2::MoveTowards(pos, movePos, speed * deltaTime);///need proper arrival check, speed and delta time for this to work better, as well as only setting
		
		
		// new position when reached the old one 
		if (Vector2::Distance(pos, movePos) < arrivalThreshold)
		{
			arrived = true;
			
		}
	}
	/*else
	{
		pos = Vector2::MoveTowards(pos, movePos, speed * deltaTime);
		if (Vector2::Distance(pos, movePos) < 0.05f)
		{
			movementStopped = false;
		}
	}*/

	

}

Parameters::Parameters(SDL_Texture* texture, SDL_Texture* SecondTexture, SDL_Renderer* renderer, ObjectType type)
{
	this->texture = texture;
	this->SecondTexture = SecondTexture;
	this->renderer = renderer;
	this->type = type;
}
