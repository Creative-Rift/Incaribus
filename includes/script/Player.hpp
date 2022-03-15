/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Player.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_PLAYER_HPP
#define INCARIBUS_PLAYER_HPP

#include "SW/Component.hpp"

class Player : public sw::Component
{
    public:
        Player(sw::Entity& entity);
        void start();
        void update();

}; // class Player

#endif //INCARIBUS_PLAYER_HPP