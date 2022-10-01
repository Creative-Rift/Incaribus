/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Game.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_GAME_HPP
#define INCARIBUS_GAME_HPP

#include "event/EventInfo.hpp"

class Game
{
    public:
        std::string name() {return ("ye");}
        void onLoad(sw::EventInfo& info);
};

#endif //INCARIBUS_GAME_HPP
