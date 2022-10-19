/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2021
** Author: Guillaume S.
** File name: Cyber.cpp
** Description: [CHANGE]
*/

#include "scenes/Cyber.hpp"
#include "CameraFPS.hpp"
#include "module/managers/Managers.hpp"
#include "OpenGLModule.hpp"
#include "resources/OpenResources.hpp"
#include "scenes_manager/SceneLoadEvent.hpp"

void Cyber::onLoad(sw::EventInfo& info)
{
    auto& scene = info.getInfo<sw::SceneLoadEvent>().scene;

    if (scene.name != "Cyber")
        return;
    scene.eventManager.create("Collision");

    auto& mainCamera = scene.createGameObject("MainCamera");
    auto& model = scene.createGameObject("Model");
    auto& cube = scene.createGameObject("Cube");

    mainCamera.createComponent<inc::CameraFPS>("ScriptManager");
    model.createComponent<sw::MeshRenderer>("MeshRendererManager", "Backpack");
    cube.createComponent<sw::MeshRenderer>("MeshRendererManager", "Cube");
    cube.transform().move(0, 0, 10);
}