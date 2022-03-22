/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Main.cpp
** Description: [CHANGE]
*/

#include "scenes/Main.hpp"
#include "module/managers/SpriteManager.hpp"
#include "module/managers/AnimatorManager.hpp"
#include "module/managers/TransformManager.hpp"
#include "module/managers/CameraManager.hpp"
#include "script/BackgroundManager.hpp"
#include "script/Player.hpp"
#include "script/Opossum.hpp"
#include "script/Gem.hpp"
#include "script/Frog.hpp"
#include "script/House.hpp"

void Main::onLoad()
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
    auto& menuMap = createEntity("MenuMap");
    auto& player = createEntity("Player");
    auto& opossum = createEntity("Opossum");
    auto& gem = createEntity("Gem");
    auto& frog = createEntity("Frog");
    auto& house = createEntity("House");
    sw::ConcreteComponent auto& camera = mainCamera.createComponent<sw::Camera>("CameraManager");
    sw::ConcreteComponent auto& camTrans = mainCamera.createComponent<sw::Transform>("TransformManager");
    std::string foo("MapMenu");
    sw::ConcreteComponent auto& mapTrans = menuMap.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& mapSprite = menuMap.createComponent<sw::Sprite>("SpriteManager");
    mapSprite.setTexture(foo);
    mapTrans.setScale(2.5f, 2.5f);
    player.createComponent<Player>("ScriptManager");
    opossum.createComponent<inc::Opossum>("ScriptManager");
    gem.createComponent<inc::Gem>("ScriptManager");
    frog.createComponent<inc::Frog>("ScriptManager");
    house.createComponent<inc::House>("ScriptManager");

    entity.createComponent<inc::BackgroundManager>("ScriptManager");
    camera.setClippingNear(-1);
    eventManager().drop("Start");
}

void Main::onUpdate()
{
    eventManager().drop("Update");
}

void Main::onUnload()
{

}