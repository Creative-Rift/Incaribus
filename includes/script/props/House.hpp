/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Opossum.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_HOUSE_HPP
#define INCARIBUS_HOUSE_HPP

#include "components/base/Component.hpp"

namespace inc
{
    class House : public sw::Component
    {
        public:
            explicit House(sw::GameObject& gameObject);
            void start();
    }; // class House
} //namespace inc

#endif //INCARIBUS_HOUSE_HPP
