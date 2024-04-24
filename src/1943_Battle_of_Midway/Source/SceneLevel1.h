#ifndef __SCENE_LEVEL1_H__
#define __SCENE_LEVEL1_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

struct Background
{
	SDL_Texture* texture;
	int w, h;
};

class SceneLevel1 : public Module
{
public:
	//Constructor
	SceneLevel1(bool startEnabled);

	//Destructor
	~SceneLevel1();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	Update_Status Update(float deltaTime) override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	Update_Status PostUpdate(float deltaTime) override;

	// Disables the player and the enemies
	bool CleanUp();

public:
	
	// The scene sprite sheet loaded into an SDL_Texture
	Background* waterTex = nullptr;
	Background* waterTex2 = nullptr;
	int scrollBg;
	int texHeight;
};

#endif