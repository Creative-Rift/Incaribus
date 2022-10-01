/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Opossum.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_FROG_HPP
#define INCARIBUS_FROG_HPP

#include "components/base/Component.hpp"

namespace inc
{
    class Frog : public sw::Component
    {
        public:
            explicit Frog(sw::GameObject& gameObject);
            void start();
    }; // class Frog
} //namespace inc

#endif //INCARIBUS_FROG_HPP
