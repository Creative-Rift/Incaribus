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

inc::Frog::Frog(sw::Entity &entity) :
sw::Component(entity)
{
    entity.scene().eventManager()["Start"].subscribe(this, &inc::Frog::start);
}

void inc::Frog::start()
{
    sw::ConcreteComponent auto& transform = m_entity.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = m_entity.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = m_entity.createComponent<sw::Animator>("AnimatorManager");
    std::string ye("Frog");

    transform.setPosition(1000, 735);
    transform.setScale(2.5f, 2.5f);
    sprite.setTexture(ye);
    m_entity.setLayer("SpriteManager", 2);
    animator.setRect({35, 32}).setLoop(true, 5).setFPS(6).play();
}