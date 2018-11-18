#include "j1App.h"
#include "j1Collision.h"
#include "j1Player.h"
#include "j1Scene.h"
#include "j1Map.h"
#include "j1Bat.h"

j1Bat::j1Bat(int x, int y, EntityType type) : j1Entity(x, y, EntityType::BAT)
{
	current_animation = NULL;

	idle.LoadAnimations("bat", "flying");
	position.x = x;
	position.y = y;
}

void  j1Bat::LoadValues()
{

}

j1Bat::~j1Bat(){}

bool j1Bat::Start()
{
	graphics = App->tex->Load("textures/bat_sprite.png");
	if (graphics == NULL)
	{
		LOG("bat sprite not loaded");
		return false;
	}
	collider = App->collision->AddCollider({ (int)position.x, (int)position.y, 31, 28 }, COLLIDER_PLAYER, App->entityManager);
	current_animation = &idle;
	return true;
}

bool j1Bat::Update(float dt, bool do_logic)
{
	dt_bat = dt;
	collider->SetPos(position.x, position.y);
	
	return true;
}

bool j1Bat::PostUpdate()
{
	Draw();
	return true;
}

bool j1Bat::CleanUp()
{
	App->tex->UnLoad(graphics);
	if (collider != nullptr)
		collider->to_delete = true;
	return true;
}

void j1Bat::Draw()
{
	SDL_Rect rect = current_animation->GetCurrentFrame(dt_bat);
	App->render->Blit(graphics, (int)position.x, (int)position.y, &rect, SDL_FLIP_NONE);
}

void j1Bat::OnCollision(Collider* c1, Collider* c2)
{

}

void j1Bat::Move(p2DynArray<iPoint>& path, float dt)
{

}

bool j1Bat::Load(pugi::xml_node&)
{
	return true;
}
bool j1Bat::Save(pugi::xml_node&) const
{
	return true;
}




