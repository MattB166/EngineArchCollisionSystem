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
	
	
	
	
	
}

GameObject::GameObject()
{

}

GameObject::~GameObject()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(MainTexture);
	SDL_DestroyTexture(SecondaryTexture);
	
}

void GameObject::Draw()   
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
	Movement(Time::instance()->GetDeltaTime()); 

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

void GameObject::OnCollisionNotify(Collider* col)
{
	
	
	arrived = true;     
	movementStopped = true;
}

void GameObject::OnOtherObjectCollisionNotify(Collider* col, Collider* col1)
{
	///check how far away they are 
	ChangeTexture();
	//std::cout << "Collision between other objects noted" << std::endl;	
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
	static const float reverseDuration = 3.0f;
	static float reverseTime = 0.0f;
	if (!movementStopped)
	{
		static const float arrivalThreshold = 0.5f;
	    
		if (arrived)
		{
			int randX = rand() % 800 + 1;
			int randY = rand() % 600 + 1;
			movePos = Vector2(randX, randY);
			
			arrived = false;
		}

		
		pos = Vector2::MoveTowards(pos, movePos, speed * deltaTime);
		
		if(pos.x + (width / 2) > 800 || pos.x - (width / 2) < 0 || pos.y + (height / 2) > 600 || pos.y - (height / 2) < 0)
		{
			
			arrived = true;
		}
		
		if (Vector2::Distance(pos, movePos) < arrivalThreshold)
		{
			arrived = true;
			
		}
	}
	else
	{
		pos = Vector2::MoveTowards(pos, movePos, -speed * deltaTime);

		reverseTime += deltaTime;
		if (reverseTime >= reverseDuration)
		{
			movementStopped = false;
			reverseTime = 0.0f;
		}


	}

	

}

Parameters::Parameters(SDL_Texture* texture, SDL_Texture* SecondTexture, SDL_Renderer* renderer, ObjectType type)
{
	this->texture = texture;
	this->SecondTexture = SecondTexture;
	this->renderer = renderer;
	this->type = type;
}
