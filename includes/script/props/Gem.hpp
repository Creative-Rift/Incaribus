/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Opossum.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_GEM_HPP
#define INCARIBUS_GEM_HPP

#include "SW/Component.hpp"
#include "SW/Utils.hpp"

namespace inc
{
    class Gem : public sw::Component
    {
        public:
            explicit Gem(sw::Entity& entity);
            void start();
    }; // class Cherry
} //namespace inc

#endif //INCARIBUS_GEM_HPP
