/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Opossum.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_CHERRY_HPP
#define INCARIBUS_CHERRY_HPP

#include "components/base/Component.hpp"

namespace inc
{
    class Cherry : public sw::Component
    {
        public:
            explicit Cherry(sw::GameObject& gameObject);
            void start();
    }; // class Cherry
} //namespace inc

#endif //INCARIBUS_CHERRY_HPP
