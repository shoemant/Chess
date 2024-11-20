
#include "ResourceManager.h"
#include <iostream>

ResourceManager &ResourceManager::getInstance()
{
    static ResourceManager instance;
    return instance;
}

// texture by filename
sf::Texture &ResourceManager::getTexture(const std::string &filename)
{
    auto it = textures.find(filename);
    if (it != textures.end())
    {
        return *(it->second);
    }
    else
    {
        std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
        if (!texture->loadFromFile(filename))
        {
            throw std::runtime_error("Failed to load texture: " + filename);
        }
        sf::Texture &ref = *texture;
        textures.emplace(filename, std::move(texture));
        return ref;
    }
}

// font by filename
sf::Font &ResourceManager::getFont(const std::string &filename)
{
    auto it = fonts.find(filename);
    if (it != fonts.end())
    {
        return *(it->second);
    }
    else
    {
        std::unique_ptr<sf::Font> font = std::make_unique<sf::Font>();
        if (!font->loadFromFile(filename))
        {
            throw std::runtime_error("Failed to load font: " + filename);
        }
        sf::Font &ref = *font;
        fonts.emplace(filename, std::move(font));
        return ref;
    }
}
