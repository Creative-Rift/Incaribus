/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: PlayerLoading.hpp
*/

#ifndef INCARIBUS_PLAYERLOADING_HPP
#define INCARIBUS_PLAYERLOADING_HPP

#include "components/base/Component.hpp"
#include "event/EventCollision.hpp"

class PlayerLoading : public sw::Component
{
    public:
        explicit PlayerLoading(sw::GameObject& gameObject);
        void start();
        void update();

}; // class Player

#endif //INCARIBUS_PLAYERLOADING_HPP
