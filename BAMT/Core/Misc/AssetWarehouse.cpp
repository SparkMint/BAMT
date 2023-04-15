#include "AssetWarehouse.h"

#include <SDL_image.h>

Image::Image(const std::experimental::filesystem::path& png, SDL_Renderer* renderer)
{
    const std::string filePath = png.string();
    name = png.filename().string();
    texture = IMG_LoadTexture(renderer, filePath.c_str());
}

Image::~Image()
{
    // Free Image memory
    SDL_DestroyTexture(texture);
    Debug::Log("Image: " + name + " successfully destroyed.", this);
}

Font::Font(const std::experimental::filesystem::path& path, SDL_Renderer* renderer)
{
    ttf = TTF_OpenFont(path.string().c_str(), 100);
    name = path.filename().string();

    SDL_Surface* text;
    SDL_Rect dest;
    char character[2];
    SDL_Rect* glyph;

    SDL_Surface* surface = SDL_CreateRGBSurface(0, TEXTURE_MAX_SIZE, TEXTURE_MAX_SIZE, 32, 0, 0, 0, 255);
    dest.x = dest.y = 0;

    for (int i = ' '; i <= 'z'; i++)
    {
        character[0] = i;
        character[1] = 0;

        text = TTF_RenderUTF8_Blended(ttf, character, {255,255,255, 255 });
        TTF_SizeText(ttf, character, &dest.w, &dest.h);

        if (dest.x + dest.w >= TEXTURE_MAX_SIZE)
        {
            dest.x = 0;
            dest.y += dest.h + 1;

            if (dest.y + dest.h >= TEXTURE_MAX_SIZE)
            {
                Debug::LogError("FATAL! Ran out of glyph space while trying to create glyph atlas!", this);
                exit(1);
            }
        }
        Uint32 colorkey = SDL_MapRGB(text->format, 0, 0, 0);
        SDL_SetColorKey(surface, SDL_TRUE, colorkey);
        SDL_BlitSurface(text, NULL, surface, &dest);

        glyph = &glyphs[i];

        glyph->x = dest.x;
        glyph->y = dest.y;
        glyph->w = dest.w;
        glyph->h = dest.h;

        SDL_FreeSurface(text);

        dest.x += dest.w;
    }

    glyphAtlas = SDL_CreateTextureFromSurface(renderer, surface);
}
Font::~Font()
{
    // Free glyphAtlas memory
    SDL_DestroyTexture(glyphAtlas);
    Debug::Log("Font: " + name + " successfully destroyed.", this);
}

AssetWarehouse::~AssetWarehouse()
{
	for (auto tex : _textures)
	{
        delete(tex);
	}
    for(auto ttf : _fonts)
    {
        delete(ttf);
    }
}

void AssetWarehouse::FindAssets(const std::experimental::filesystem::path& directory, std::vector<std::experimental::filesystem::path>& png_files)
{
    for (const auto& file : std::experimental::filesystem::directory_iterator(directory))
    {
        if (is_directory(file))
        {
            // Recursively search the sub-directory for PNG files
            FindAssets(file.path(), png_files);
        }
        else if (file.path().extension() == ".png")
        {
            // Add the PNG file to the vector
            png_files.push_back(file.path());
        }
        else if (file.path().extension() == ".ttf")
        {
            // Add the TTF file to the vector
            ttf_files.push_back(file.path());
        }
    }
}

void AssetWarehouse::LoadTextures(SDL_Renderer* renderer)
{
	for (auto png : png_files)
	{
        Debug::Log("Loading Texture... Name: " + png.filename().string());
		auto* newTexture = new Image(png, renderer);
        _textures.push_back(newTexture);
	}
}

void AssetWarehouse::LoadFonts(SDL_Renderer* renderer)
{
    for (auto ttf : ttf_files)
    {
        Debug::Log("Loading Font... Name: " + ttf.filename().string());
        auto* newFont = new Font(ttf, renderer);
        _fonts.push_back(newFont);
    }
}

SDL_Texture* AssetWarehouse::GetTexture(const char* filename) const
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

Font* AssetWarehouse::GetFont(const char* filename) const
{
    for (const auto font : _fonts)
    {
        if (font->name == filename)
        {
            return font;
        }
    }
    return nullptr;
}