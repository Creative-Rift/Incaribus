/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: BackGround.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_BACKGROUNDMANAGER_HPP
#define INCARIBUS_BACKGROUNDMANAGER_HPP

#include "components/Components.hpp"

namespace inc
{
    class BackgroundManager : public sw::Component
    {
        private:

        public:
            explicit BackgroundManager(sw::GameObject& gameObject);
            void start();
            void update();
            void createLayer(std::string layer);
    }; // class BackGround
} // namespace inc

#endif //INCARIBUS_BACKGROUNDMANAGER_HPP
