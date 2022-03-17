/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: MapLoader.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_MAPLOADER_HPP
#define INCARIBUS_MAPLOADER_HPP

#include "SW/Component.hpp"

namespace inc
{
    class MapLoader : public sw::Component
    {
        private:
            std::string m_mapPath;
        public:
            explicit MapLoader(sw::Entity& entity, std::string mapPath = "resources/map/GameMap.csv");
            void start();
            void loadMap(std::string mapPath);
            void reloadMap();
            void clearMap();
    }; // class House
} //namespace inc

#endif //INCARIBUS_MAPLOADER_HPP
