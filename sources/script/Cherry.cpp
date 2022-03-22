/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Opossum.cpp
** Description: [CHANGE]
*/

#include "script/Cherry.hpp"
#include "components/Transform.hpp"
#include "components/Sprite.hpp"
#include "components/Animator.hpp"

inc::Cherry::Cherry(sw::Entity &entity) :
sw::Component(entity)
{
    entity.scene().eventManager()["Start"].subscribe(this, &inc::Cherry::start);
}

void inc::Cherry::start()
{
    sw::ConcreteComponent auto& transform = m_entity.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = m_entity.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = m_entity.createComponent<sw::Animator>("AnimatorManager");
    std::string ye("Cherry");

    transform.setPosition(1400, 250);
    transform.setScale(3.0f, 3.0f);
    sprite.setTexture(ye);
    m_entity.setLayer("SpriteManager", 2);
    animator.setRect({21, 21}).setLoop(true).setFPS(8).play();
}