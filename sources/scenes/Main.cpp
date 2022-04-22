/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Main.cpp
** Description: [CHANGE]
*/

#include "module/managers/ScriptManager.hpp"
#include "scenes/Main.hpp"
#include "module/managers/SpriteManager.hpp"
#include "module/managers/AnimatorManager.hpp"
#include "module/managers/TransformManager.hpp"
#include "module/managers/CameraManager.hpp"
#include "module/managers/BoxColliderManager.hpp"
#include "module/managers/RigidBody2DManager.hpp"
#include "module/managers/TextManager.hpp"
#include "module/managers/AudioSourceManager.hpp"
#include "script/BackgroundManager.hpp"
#include "script/character/Player.hpp"
#include "script/character/Opossum.hpp"
#include "script/props/Gem.hpp"
#include "script/character/Frog.hpp"
#include "script/props/House.hpp"
#include "OpenGLModule.hpp"
#include "scenes_manager/SceneLoadEvent.hpp"

void Main::onLoad(sw::EventInfo& info)
{
    auto& scene = info.getInfo<sw::SceneLoadEvent>().scene;

    if (scene.name != "Main")
        return;
    scene.eventManager.create("Collision");
    scene.createManager<sw::SpriteManager>("SpriteManager");
    scene.createManager<sw::AnimatorManager>("AnimatorManager");
    scene.createManager<sw::TransformManager>("TransformManager");
    scene.createManager<sw::CameraManager>("CameraManager");
    scene.createManager<sw::ScriptManager>("ScriptManager");
    scene.createManager<sw::BoxColliderManager>("BoxColliderManager");
    scene.createManager<sw::RigidBody2DManager>("RigidBody2DManager");
    scene.createManager<sw::TextManager>("TextManager");
    scene.createManager<sw::AudioSourceManager>("AudioManager");

    auto& entity = scene.createGameObject("Background");
    auto& mainCamera = scene.createGameObject("MainCamera");
    auto& menuMap = scene.createGameObject("MenuMap");
    auto& player = scene.createGameObject("Player");
    auto& opossum = scene.createGameObject("Opossum");
    auto& gem = scene.createGameObject("Gem");
    auto& frog = scene.createGameObject("Frog");
    auto& house = scene.createGameObject("House");
    auto& title = scene.createGameObject("Title");
    auto& subtitle = scene.createGameObject("Subtitle");
    sw::ConcreteComponent auto& camera = mainCamera.createComponent<sw::Camera>("CameraManager");
    sw::ConcreteComponent auto& camTrans = mainCamera.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& camAudio = mainCamera.createComponent<sw::AudioSource>("AudioManager");
    camAudio.setAudio("Menu").setVolume(.5f).play();
    std::string foo("MapMenu");
    std::string ye("Incaribus");
    std::string subtitleT("Press SPACE to start the game");
    std::string font("Pixel");
    sw::ConcreteComponent auto& mapTrans = menuMap.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& mapSprite = menuMap.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& titleText = title.createComponent<sw::Text>("TextManager");
    sw::ConcreteComponent auto& subtitleText = subtitle.createComponent<sw::Text>("TextManager");
    mapSprite.setTexture(foo);
    mapTrans.setScale(2.5f, 2.5f);
    player.createComponent<Player>("ScriptManager");
    opossum.createComponent<inc::Opossum>("ScriptManager");
    gem.createComponent<inc::Gem>("ScriptManager");
    frog.createComponent<inc::Frog>("ScriptManager");
    house.createComponent<inc::House>("ScriptManager");
    titleText.setText(ye);
    titleText.setPosition(800.0f, 1000.0f);
    titleText.setColor(sw::Color(105.0f / 255.0f, 166.0f / 255.0f, 31.0f / 255.0f));
    titleText.setFont(font);
    subtitleText.setText(subtitleT);
    subtitleText.setPosition(300.0f, 150.0f);
    subtitleText.setColor(sw::Color(105.0f / 255.0f, 166.0f / 255.0f, 31.0f / 255.0f));
    subtitleText.setFont(font);

    entity.createComponent<inc::BackgroundManager>("ScriptManager");
    camera.setClippingNear(-1);
    scene.eventManager.drop("Start");
}