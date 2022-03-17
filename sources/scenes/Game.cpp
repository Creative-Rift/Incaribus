/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Game.cpp
** Description: [CHANGE]
*/

#include "scenes/Game.hpp"
#include "module/managers/SpriteManager.hpp"
#include "module/managers/AnimatorManager.hpp"
#include "module/managers/TransformManager.hpp"
#include "module/managers/CameraManager.hpp"
#include "script/BackgroundManager.hpp"
#include "script/Player.hpp"
#include "script/Opossum.hpp"
#include "script/MapLoader.hpp"

void Game::onLoad()
{
    eventManager().create("Start");
    eventManager().create("Update");
    createManager<sw::SpriteManager>("SpriteManager");
    createManager<sw::AnimatorManager>("AnimatorManager");
    createManager<sw::TransformManager>("TransformManager");
    createManager<sw::CameraManager>("CameraManager");
    createManager<sw::ScriptManager>("ScriptManager");
    auto& entity = createEntity("Background");
    auto& mainCamera = createEntity("MainCamera");
    auto& player = createEntity("Player");
    auto& map = createEntity("Map");
    sw::ConcreteComponent auto& camera = mainCamera.createComponent<sw::Camera>("CameraManager");
    sw::ConcreteComponent auto& camTrans = mainCamera.createComponent<sw::Transform>("TransformManager");
    std::string foo("MapMenu");
    player.createComponent<Player>("ScriptManager");
    map.createComponent<inc::MapLoader>("ScriptManager");

    entity.createComponent<inc::BackgroundManager>("ScriptManager");
    camera.setClippingNear(-1);
    eventManager().drop("Start");
}

void Game::onUpdate()
{
    eventManager().drop("Update");
}

void Game::onUnload()
{

}