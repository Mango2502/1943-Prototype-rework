#include "Module.h"

Module::Module(bool startEnabled) : isEnabled(startEnabled)
{

}

bool Module::Init()
{
	return true;
}

bool Module::Start()
{
	return true;
}

Update_Status Module::PreUpdate(float deltaTime)
{
	return Update_Status::UPDATE_CONTINUE;
}

Update_Status Module::Update(float deltaTime)
{
	return Update_Status::UPDATE_CONTINUE;
}

Update_Status Module::PostUpdate(float deltaTime)
{
	return Update_Status::UPDATE_CONTINUE;
}

bool Module::CleanUp()
{
	return true;
}

void Module::OnCollision(Collider* c1, Collider* c2)
{

}

void Module::Enable()
{
	if (!isEnabled)
	{
		isEnabled = true;
		Start();
	}
}

void Module::Disable()
{
	if (isEnabled)
	{
		isEnabled = false;
		CleanUp();
	}
}
