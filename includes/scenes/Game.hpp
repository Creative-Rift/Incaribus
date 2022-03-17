/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Game.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_GAME_HPP
#define INCARIBUS_GAME_HPP

#include "SW/Scene.hpp"

class Game : public sw::AScene
{
    private:
        using sw::AScene::AScene;

        void onLoad() override;
        void onUpdate() override;
        void onUnload() override;
        std::string type() const override { return (""); }
};

#endif //INCARIBUS_GAME_HPP
