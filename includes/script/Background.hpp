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
            std::string m_texture;
        public:
            explicit Background(sw::GameObject& gameObject, std::string textureName);
            void start();
            void update();
    }; // class BackGround
} // namespace inc

#endif //INCARIBUS_BACKGROUND_HPP
