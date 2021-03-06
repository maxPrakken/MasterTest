#include "..\include\texture.h"

Texture::Texture()
{
}

Texture::Texture(SDL_Renderer* renderer, std::string path)
{
	tex = loadTexture(renderer, path);
	Uint32 i = 0;
	int a = 0;
	int w, h;
	SDL_QueryTexture(tex, &i, &a, &w, &h);
	_resolution = Vector2(w, h);	
}

Texture::~Texture()
{
	if (tex != NULL) {
		SDL_DestroyTexture(tex);
	}
}

SDL_Texture * Texture::loadTexture(SDL_Renderer* renderer, std::string path)
{
	SDL_Surface* surf = IMG_Load(path.c_str());
	if (surf == NULL)
	{
		std::cout << "Could not load image: " << IMG_GetError() << std::endl;
		return NULL;
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
	
		SDL_FreeSurface(surf);
	std::cout << "Image loaded: " << path << std::endl;
	return tex;
}
