#ifndef __SCENE_MENU_H__
#define __SCENE_MENU_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class SceneMenu : public Module
{
public:
	//Constructor
	SceneMenu(bool startEnabled);

	//Destructor
	~SceneMenu();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	Update_Status Update(float deltaTime) override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	Update_Status PostUpdate(float deltaTime) override;

public:
	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* bgTexture = nullptr; //Water texture
	SDL_Texture* titleTexture = nullptr; //1943Logo texture
	const char* fontTexturePath; //font texture
	int font;
};

#endif