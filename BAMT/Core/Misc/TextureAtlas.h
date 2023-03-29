#ifndef BAMT_TEXTURE_ATLAS
#define BAMT_TEXTURE_ATLAS
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <experimental/filesystem>
#include <iostream>
#include "Debug.h"
#include <SDL_render.h>
#include <vector>


struct Image
{
	Image(const std::experimental::filesystem::path& png, SDL_Renderer* renderer);
	~Image();
	std::string name;
	SDL_Texture* texture;
};

class TextureAtlas
{
	std::vector<Image*> _textures;
	public:
		TextureAtlas();
		~TextureAtlas();
		std::vector<std::experimental::filesystem::path> png_files;
		void FindSprites(const std::experimental::filesystem::path& directory, std::vector<std::experimental::filesystem::path>& png_files);
		void LoadTextures(SDL_Renderer* renderer);
		SDL_Texture* FindTexture(const char* filename) const;
};

#endif
