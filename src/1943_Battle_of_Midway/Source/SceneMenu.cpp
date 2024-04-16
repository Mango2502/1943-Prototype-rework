#include "SceneMenu.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFonts.h"
#include "ModuleFadeToBlack.h"

SceneMenu::SceneMenu(bool startEnabled) : Module(startEnabled)
{

}

SceneMenu::~SceneMenu()
{

}

// Load assets
bool SceneMenu::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Sprites/water.png");       // Background texture (water)
	titleTexture = App->textures->Load("Assets/Sprites/1943Logo.png"); // Title Texture
	fontTexturePath = "Assets/Fonts/rtype_font3.png";                  // Font texture path (const char*)

	const char* lookUpTable = "! ç,_./0123456789€;->?abcdefghijklmnopqrstuvwxyz";  // LookupTable from the rtype_font3.png

	font = App->fonts->Load(fontTexturePath, lookUpTable, 2);

	// AUDIO MUTED 
	// App->audio->PlayMusic("Assets/Music/Title.ogg", 1.0f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

Update_Status SceneMenu::Update()
{
	if (App->input->keys[SDL_SCANCODE_SPACE] == Key_State::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneLevel_1, 90);
	}

	// TODO: Add input like the original game and all interactive stuff.

	return Update_Status::UPDATE_CONTINUE;
}

Update_Status SceneMenu ::PostUpdate()
{
	// Draw everything --------------------------------------
	App->render->Blit(bgTexture, 0, 0, NULL);           // Water texture
	App->render->Blit(titleTexture, 128, 80, NULL);     // Title texture

	App->fonts->BlitText(10, 10, font, "hello world!"); // Font test

	// TODO: Make the scene as if it was the original, with all its textures,
	// it must have all sounds, fx and input.

	return Update_Status::UPDATE_CONTINUE;
}