#include "TextureAtlas.h"

#include <SDL_image.h>

Image::Image(const std::experimental::filesystem::path& png, SDL_Renderer* renderer)
{
    const std::string filePath = png.string();
    Debug::Log(filePath);
    name = png.filename().string();
    texture = IMG_LoadTexture(renderer, filePath.c_str());
}

Image::~Image()
{
    // Free texture memory
    SDL_DestroyTexture(texture);
}

TextureAtlas::TextureAtlas()
{
}

TextureAtlas::~TextureAtlas()
{
	for (auto tex : _textures)
	{
        delete(tex);
	}
}

void TextureAtlas::FindSprites(const std::experimental::filesystem::path& directory, std::vector<std::experimental::filesystem::path>& png_files)
{
    for (const auto& file : std::experimental::filesystem::directory_iterator(directory))
    {
        if (is_directory(file))
        {
            // Recursively search the sub-directory for PNG files
            FindSprites(file.path(), png_files);
        }
        else if (file.path().extension() == ".png")
        {
            // Add the PNG file to the vector
            png_files.push_back(file.path());
        }
    }
}

void TextureAtlas::LoadTextures(SDL_Renderer* renderer)
{
	for (auto png : png_files)
	{
        Debug::Log("Loading Sprite... Sprite Name: " + png.filename().string());
		auto* newTexture = new Image(png, renderer);
        _textures.push_back(newTexture);
	}
}

SDL_Texture* TextureAtlas::FindTexture(const char* filename) const
{
	for (const auto tex : _textures)
	{
		if(tex->name == filename)
		{
            return tex->texture;
		}
	}
    return nullptr;
}
