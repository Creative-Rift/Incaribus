/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: MapLoader.cpp
** Description: [CHANGE]
*/

#include <fstream>
#include <string>

#include "components/Transform.hpp"
#include "components/Sprite.hpp"
#include "script/MapLoader.hpp"

inc::MapLoader::MapLoader(sw::Entity &entity, std::string mapPath) :
sw::Component(entity),
m_mapPath(mapPath)
{
    entity.scene().eventManager()["Start"].subscribe(this, &inc::MapLoader::start);
}

void inc::MapLoader::start()
{
    sw::ConcreteComponent auto& transform = m_entity.createComponent<sw::Transform>("TransformManager");
    loadMap(m_mapPath);
}

void inc::MapLoader::loadMap(std::string mapPath)
{
    m_mapPath = mapPath;
    std::ifstream mapFile;
    std::stringstream content;
    std::vector<std::string> line;
    std::string s;
    int x = 0;
    int y = 0;
    std::string tileSet("TileSet");

    mapFile.open(mapPath);
    while (std::getline(mapFile, s, '\n'))
        line.push_back(s);
    for (auto& lineData : line) {
        std::stringstream lineContent(lineData);
        while (std::getline(lineContent, s, ',')) {
            if (s == "-1") {
                x++;
                continue;
            }
            std::cout << s << " ";
            sw::FloatRect rect{16 * (float)(std::atoi(s.c_str()) % 25), 368 - 16 * (float)(std::atoi(s.c_str()) / 25 + 1), 16, 16};
            auto& newEntity = m_entity.scene().createEntity("Tile-" + std::to_string(x) + "-" + std::to_string(y));
            sw::ConcreteComponent auto& newTransform = newEntity.createComponent<sw::Transform>("TransformManager");
            sw::ConcreteComponent auto& newSprite = newEntity.createComponent<sw::Sprite>("SpriteManager");
            newTransform.setScale(3, 3);
            newTransform.setPosition(x * 16 * 3, y * 16 * 3 + 350);
            newSprite.setTexture(tileSet);
            newSprite.setTextureRect(rect);
            newEntity.setLayer("SpriteManager", 1);
            x++;
        }
        std::cout << std::endl;
        x = 0;
        y++;
    }
}

void inc::MapLoader::reloadMap()
{
    clearMap();
    loadMap(m_mapPath);
}

void inc::MapLoader::clearMap()
{

}