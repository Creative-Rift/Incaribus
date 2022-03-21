/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Game.cpp
** Description: [CHANGE]
*/

#include "includes/manager/ScriptManager.hpp"
#include "scenes/Game.hpp"
#include "module/managers/SpriteManager.hpp"
#include "module/managers/AnimatorManager.hpp"
#include "module/managers/TransformManager.hpp"
#include "module/managers/CameraManager.hpp"
#include "module/managers/RigidBody2DManager.hpp"
#include "module/managers/BoxColliderManager.hpp"
#include "script/BackgroundManager.hpp"
#include "script/character/Player.hpp"
#include "script/MapLoader.hpp"
#include "script/props/Gem.hpp"
#include "script/character/Frog.hpp"
#include "script/character/Opossum.hpp"

void Game::onLoad()
{
    eventManager().create("Start");
    eventManager().create("Update");
    eventManager().create("Collision");
    createManager<sw::SpriteManager>("SpriteManager");
    createManager<sw::AnimatorManager>("AnimatorManager");
    createManager<sw::TransformManager>("TransformManager");
    createManager<sw::CameraManager>("CameraManager");
    createManager<sw::ScriptManager>("ScriptManager");
    createManager<sw::BoxColliderManager>("BoxColliderManager");
    createManager<sw::RigidBody2DManager>("RigidBody2DManager");

    auto& entity = createEntity("Background");
    auto& mainCamera = createEntity("MainCamera");
    auto& player = createEntity("Player");
    auto& map = createEntity("Map");
    auto& gem1 = createEntity("Gem1");
    auto& gem2 = createEntity("Gem2");
    auto& gem3 = createEntity("Gem3");
    auto& frog1 = createEntity("Frog1");
    auto& frog2 = createEntity("Frog2");
    auto& opossum = createEntity("Opossum");
    sw::ConcreteComponent auto& camera = mainCamera.createComponent<sw::Camera>("CameraManager");
    sw::ConcreteComponent auto& camTrans = mainCamera.createComponent<sw::Transform>("TransformManager");
    std::string foo("MapMenu");
    player.createComponent<Player>("ScriptManager");
    map.createComponent<inc::MapLoader>("ScriptManager");

    gem1.createComponent<inc::Gem>("ScriptManager");
    gem2.createComponent<inc::Gem>("ScriptManager");
    gem3.createComponent<inc::Gem>("ScriptManager");
    frog1.createComponent<inc::Frog>("ScriptManager");
    frog2.createComponent<inc::Frog>("ScriptManager");
    opossum.createComponent<inc::Opossum>("ScriptManager");

    entity.createComponent<inc::BackgroundManager>("ScriptManager");
    mainCamera.addChild(entity.name());
    camera.setClippingNear(-1);
    eventManager().drop("Start");
    gem1.getComponent<sw::Transform>("TransformManager").setPosition(1000, 550);
    gem2.getComponent<sw::Transform>("TransformManager").setPosition(1450, 830);
    gem3.getComponent<sw::Transform>("TransformManager").setPosition(2600, 780);
    frog1.getComponent<sw::Transform>("TransformManager").setPosition(830, 518);
    frog2.getComponent<sw::Transform>("TransformManager").setPosition(2800, 858);
    opossum.getComponent<sw::Transform>("TransformManager").setPosition(2800, 180);
    opossum.getComponent<inc::Opossum>("ScriptManager").m_pos1 = {2000, 180};
    opossum.getComponent<inc::Opossum>("ScriptManager").m_pos2 = {3000, 180};
}

void Game::onUpdate()
{
    eventManager().drop("Update");
}

void Game::onUnload()
{

}