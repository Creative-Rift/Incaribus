/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Main.cpp
** Description: [CHANGE]
*/

#include "scenes/MainFile.hpp"
#include "module/managers/CameraManager.hpp"
#include "script/BackgroundManager.hpp"
#include "script/character/Player.hpp"
#include "script/character/Opossum.hpp"
#include "OpenGLModule.hpp"
#include "scenes_manager/SceneLoadEvent.hpp"

void MainFile::onLoad(sw::EventInfo& info)
{
    auto& scene = info.getInfo<sw::SceneLoadEvent>().scene;

    if (scene.name != "MainFile")
        return;
    scene.eventManager.create("Collision");

    auto& entity = scene.getGameObject("Background");
    auto& player = scene.getGameObject("Player");
    auto& opossum = scene.getGameObject("Opossum");

    player.createComponent<Player>("ScriptManager");
    opossum.createComponent<inc::Opossum>("ScriptManager");

    //auto& cam = scene.getGameObject("MainCamera");
    //scene.getGameObject("Rect").getComponent<sw::Camera>("CameraManager").createRenderTexture("HelloWorldus");
    //cam.transform().move(-3000, 0);

    //auto& go = scene.createGameObject("HelloWorldusRect");
    //auto& sprite = go.createComponent<sw::Sprite>("SpriteManager");
    //std::string sp = "HelloWorldus";
    //sw::FloatRect rect = {0, 0, 100, 100};
    //sprite.setTexture(sp).setTextureRect(rect);
    //go.transform().move(-3000, 0);

    entity.createComponent<inc::BackgroundManager>("ScriptManager");
}