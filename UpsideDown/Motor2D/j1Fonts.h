#ifndef __j1FONTS_H__
#define __j1FONTS_H__

#include "j1Module.h"
#include "p2List.h"
#include "SDL\include\SDL_pixels.h"

#define DEFAULT_FONT "fonts/heavy_data.ttf"
#define CREDITS_FONT "fonts/Munro.ttf"
#define BIGGER_FONT_SIZE 70
#define DEFAULT_FONT_SIZE 30
#define SMALLER_FONT_SIZE 15

struct SDL_Texture;
struct _TTF_Font;

class j1Fonts : public j1Module
{
public:

	j1Fonts();

	// Destructor
	virtual ~j1Fonts();

	// Called before render is available
	bool Awake(pugi::xml_node&);

	// Called before quitting
	bool CleanUp();

	// Load Font
	_TTF_Font* const Load(const char* path, int size = 12);

	// Create a surface from text
	SDL_Texture* Print(const char* text, SDL_Color color = { 255, 255, 255, 255 }, _TTF_Font* font = NULL);

	bool CalcSize(const char* text, int& width, int& height, _TTF_Font* font = NULL) const;


public:

	p2List<_TTF_Font*>	fonts;
	_TTF_Font*			default;
	_TTF_Font*			bigger; 
	_TTF_Font*			smaller;
	_TTF_Font*			Credits;
};


#endif // __j1FONTS_H__