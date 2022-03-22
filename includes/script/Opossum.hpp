/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Opossum.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_OPOSSUM_HPP
#define INCARIBUS_OPOSSUM_HPP

#include "SW/Component.hpp"
#include "SW/Utils.hpp"

namespace inc
{
    class Opossum : public sw::Component
    {
        private:
            sw::Vector2f m_pos1;
            sw::Vector2f m_pos2;
            enum Direction {
                LEFT,
                RIGHT
            } m_direction;

        public:
            explicit Opossum(sw::Entity& entity);
            void start();
            void update();
    }; // class Opossum
} //namespace inc

#endif //INCARIBUS_OPOSSUM_HPP
