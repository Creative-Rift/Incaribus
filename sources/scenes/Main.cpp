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

void Main::onLoad()
{
    createManager<sw::SpriteManager>("SpriteManager");
    createManager<sw::AnimatorManager>("AnimatorManager");
    auto& entity = createEntity("Sprite");
    auto& explode = createEntity("Explode");
    sw::ConcreteComponent auto& sprite = entity.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = entity.createComponent<sw::Animator>("AnimatorManager");
    sw::ConcreteComponent auto& ex_sprite = explode.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& ex_animator = explode.createComponent<sw::Animator>("AnimatorManager");
    std::string ye("Idle");
    std::string foo("Explode");

    //sprite.setTexture(ye);
    animator.setRect({33, 32}).setFPS(12).setLoop(true);
    animator.play();

    //ex_sprite.setTexture(foo);
    //ex_animator.setRect({100, 100}).setFPS(30).setLoop(true);
    //ex_animator.play();
}

void Main::onUpdate()
{

}

void Main::onUnload()
{

}