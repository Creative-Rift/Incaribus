/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: BackGround.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_BACKGROUND_HPP
#define INCARIBUS_BACKGROUND_HPP

#include "components/Components.hpp"
#include "resources/OpenResources.hpp"

namespace inc
{
    class Background : public sw::Component
    {
        private:

        public:
            std::string m_texture;
            float m_scale;
            float m_speed;
            bool m_multipleTexture;
            sw::FloatRect m_rect;

            explicit Background(sw::GameObject& gameObject, std::string textureName, float scale);
            void start();
            void update();
    }; // class BackGround
} // namespace inc

#endif //INCARIBUS_BACKGROUND_HPP
