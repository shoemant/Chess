
#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <memory>
#include <stdexcept>

class ResourceManager
{
public:
    static ResourceManager &getInstance();

    sf::Texture &getTexture(const std::string &filename);

    sf::Font &getFont(const std::string &filename);

private:
    ResourceManager() = default;
    ResourceManager(const ResourceManager &) = delete;
    ResourceManager &operator=(const ResourceManager &) = delete;

    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> textures;
    std::unordered_map<std::string, std::unique_ptr<sf::Font>> fonts;
};
