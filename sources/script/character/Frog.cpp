/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Opossum.cpp
** Description: [CHANGE]
*/

#include "script/character/Frog.hpp"
#include "components/Transform.hpp"
#include "components/Sprite.hpp"
#include "components/Animator.hpp"

inc::Frog::Frog(sw::GameObject &gameObject) :
sw::Component(gameObject)
{
    gameObject.scene().eventManager["Start"].subscribe(this, &inc::Frog::start);
}

void inc::Frog::start()
{
    sw::ConcreteComponent auto& sprite = m_gameObject.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = m_gameObject.createComponent<sw::Animator>("AnimatorManager");
    std::string ye("Frog");

    m_gameObject.transform().setPosition(1000, 735);
    m_gameObject.transform().setScale(2.5f, 2.5f);
    sprite.setTexture(ye);
    m_gameObject.setLayer("SpriteManager", 2);
    animator.setRect({35, 32}).setLoop(true, 5).setFPS(6).play();
}