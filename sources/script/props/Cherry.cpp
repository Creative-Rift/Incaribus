/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Opossum.cpp
** Description: [CHANGE]
*/

#include "script/props/Cherry.hpp"
#include "components/Transform.hpp"
#include "components/Sprite.hpp"
#include "components/Animator.hpp"

inc::Cherry::Cherry(sw::GameObject &gameObject) :
sw::Component(gameObject)
{
    gameObject.scene().eventManager["Start"].subscribe(this, &inc::Cherry::start);
}

void inc::Cherry::start()
{
    sw::ConcreteComponent auto& sprite = m_gameObject.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = m_gameObject.createComponent<sw::Animator>("AnimatorManager");
    std::string ye("Cherry");

    m_gameObject.transform().setPosition(1400, 250);
    m_gameObject.transform().setScale(3.0f, 3.0f);
    sprite.setTexture(ye);
    m_gameObject.setLayer("SpriteManager", 2);
    animator.setRect({21, 21}).setLoop(true).setFPS(8).play();
}