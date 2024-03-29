/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Opossum.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_OPOSSUM_HPP
#define INCARIBUS_OPOSSUM_HPP

#include "components/base/Component.hpp"
#include "utils/Vector2.hpp"

namespace inc
{
    class Opossum : public sw::Component
    {
        private:
            enum Direction {
                LEFT,
                RIGHT
            } m_direction;

        public:
            sw::Vector2f m_pos1;
            sw::Vector2f m_pos2;

            explicit Opossum(sw::GameObject& entity);
            void start();
            void update();
    }; // class Opossum
} //namespace inc

#endif //INCARIBUS_OPOSSUM_HPP
