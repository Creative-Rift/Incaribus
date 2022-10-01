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
#include "components/BoxCollider.hpp"
#include "script/MapLoader.hpp"

inc::MapLoader::MapLoader(sw::GameObject &gameObject, std::string mapPath) :
sw::Component(gameObject),
m_mapPath(mapPath)
{
    gameObject.scene().eventManager["Start"].subscribe(this, &inc::MapLoader::start);
}

void inc::MapLoader::start()
{
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
            sw::FloatRect rect{16 * (float)(std::atoi(s.c_str()) % 25), 368 - 16 * (float)(std::atoi(s.c_str()) / 25 + 1), 16, 16};
            auto& newEntity = m_gameObject.scene().createGameObject("Tile-" + std::to_string(x) + "-" + std::to_string(y));
            sw::ConcreteComponent auto& newSprite = newEntity.createComponent<sw::Sprite>("SpriteManager");
            newEntity.transform().setScale(3, 3);
            newEntity.transform().setPosition(x * 16 * 3 - 16 * 3, y * 16 * 3 + 250);
            newSprite.setTexture(tileSet);
            newSprite.setTextureRect(rect);
            newEntity.setLayer("SpriteManager", 1);
            if (s == "28" || s == "469" || s == "26" || s == "30" || s == "365" || s == "367" || s == "369" || s == "332" || s == "334" || s == "336" || s == "338" || s == "126") {
                sw::ConcreteComponent auto& newCollider = newEntity.createComponent<sw::BoxCollider>("BoxColliderManager");
                newCollider.setSize(16 * 3, 16 * 3);
                newCollider.setStatic(true);
                newCollider.setTrigger(false);
            }
            x++;
        }
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