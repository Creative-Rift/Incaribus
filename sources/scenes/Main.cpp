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
    sw::ConcreteComponent auto& camera = mainCamera.createComponent<sw::Camera>("CameraManager");
    sw::ConcreteComponent auto& camTrans = mainCamera.createComponent<sw::Transform>("TransformManager");
    //auto& explode = createEntity("Explode");
    //sw::ConcreteComponent auto& ex_sprite = explode.createComponent<sw::Sprite>("SpriteManager");
    //sw::ConcreteComponent auto& ex_animator = explode.createComponent<sw::Animator>("AnimatorManager");
    //sw::ConcreteComponent auto& ex_transform = explode.createComponent<sw::Transform>("TransformManager");
    std::string foo("Explode");

    camera.setClippingNear(-1);
    entity.createComponent<inc::BackgroundManager>("ScriptManager");
    //transform.setPosition(3, 3, 0); // Coord 2D - orthographic
    //transform.setPosition(3, 0, 3); // Coord 3D - perspective
    //sprite.setColor(sw::CyanColor);


    //ex_transform.move(1, 0, -2);
    //ex_sprite.setTexture(ye);
    //ex_animator.setRect({33, 32}).setFPS(100).setLoop(true);
    //ex_animator.play();
    eventManager().drop("Start");
}

void Main::onUpdate()
{
    eventManager().drop("Update");
}

void Main::onUnload()
{

}