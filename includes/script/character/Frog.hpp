/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Opossum.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_FROG_HPP
#define INCARIBUS_FROG_HPP

#include "SW/Component.hpp"
#include "SW/Utils.hpp"

namespace inc
{
    class Frog : public sw::Component
    {
        public:
            explicit Frog(sw::Entity& entity);
            void start();
    }; // class Frog
} //namespace inc

#endif //INCARIBUS_FROG_HPP
