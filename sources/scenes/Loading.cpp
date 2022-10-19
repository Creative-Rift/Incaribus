/*
** ShipWreck Engine , 2022
** Loading.cpp
*/

#include "Loading.hpp"

#include "module/managers/CameraManager.hpp"
#include "script/character/PlayerLoading.hpp"
#include "script/SceneLoader.hpp"
#include "script/BackgroundManager.hpp"
#include "OpenGLModule.hpp"
#include "scenes_manager/SceneLoadEvent.hpp"

void Loading::onLoad(sw::EventInfo& info)
{
    auto& scene = info.getInfo<sw::SceneLoadEvent>().scene;

    if (scene.name != "Loading")
        return;

    scene.eventManager.create("Collision");
    auto& mainCamera = scene.createGameObject("MainCamera");
    auto& player = scene.createGameObject("Player");
    auto& background = scene.createGameObject("BackGround");
    auto& foreground = scene.createGameObject("ForeGround");
    auto& loader = scene.createGameObject("Loader");

    sw::ConcreteComponent auto& camera = mainCamera.createComponent<sw::Camera>("CameraManager");
    player.createComponent<PlayerLoading>("ScriptManager");
    loader.createComponent<inc::SceneLoader>("ScriptManager");
    auto& back = background.createComponent<inc::BackgroundManager>("ScriptManager", "Background1", 5.5f);
    back.m_layer = 2;
    back.m_speed = 2;
    auto& fore = foreground.createComponent<inc::BackgroundManager>("ScriptManager", "MapLoading", 3.0f);
    fore.m_layer = 1;
    fore.m_speed = 5;
    fore.m_multipleTexture = true;
    fore.m_rect = {0, 17 * 16, 1792, 17 * 16};
    fore.gameObject().transform().move(0, 285);

    camera.setClippingNear(-1);
}