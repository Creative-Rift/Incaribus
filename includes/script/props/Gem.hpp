/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Opossum.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_GEM_HPP
#define INCARIBUS_GEM_HPP

#include "components/base/Component.hpp"
#include "event/EventInfo.hpp"

namespace inc
{
    class Gem : public sw::Component
    {
        public:
            explicit Gem(sw::GameObject& gameObject);
            void start();
            void onCollide(sw::EventInfo& info);
    }; // class Cherry
} //namespace inc

#endif //INCARIBUS_GEM_HPP
