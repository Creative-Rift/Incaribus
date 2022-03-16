/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Opossum.cpp
** Description: [CHANGE]
*/

#include "script/Gem.hpp"
#include "components/Transform.hpp"
#include "components/Sprite.hpp"
#include "components/Animator.hpp"

inc::Gem::Gem(sw::Entity &entity) :
sw::Component(entity)
{
    entity.scene().eventManager()["Start"].subscribe(this, &inc::Gem::start);
}

void inc::Gem::start()
{
    sw::ConcreteComponent auto& transform = m_entity.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = m_entity.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = m_entity.createComponent<sw::Animator>("AnimatorManager");
    std::string ye("Gem");

    transform.setPosition(1300, 760);
    transform.setScale(2.5f, 2.5);
    sprite.setTexture(ye);
    m_entity.setLayer("SpriteManager", 1);
    animator.setRect({15, 13}).setLoop(true).setFPS(8).play();
}