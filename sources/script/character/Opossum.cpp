/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Opossum.cpp
** Description: [CHANGE]
*/

#include "script/character/Opossum.hpp"
#include "components/Transform.hpp"
#include "components/Sprite.hpp"
#include "components/Animator.hpp"

inc::Opossum::Opossum(sw::Entity &entity) :
sw::Component(entity),
m_direction(LEFT),
m_pos1{1550, 225},
m_pos2{2000, 225}
{
    entity.scene().eventManager()["Start"].subscribe(this, &inc::Opossum::start);
    entity.scene().eventManager()["Update"].subscribe(this, &inc::Opossum::update);
}

void inc::Opossum::start()
{
    sw::ConcreteComponent auto& transform = m_entity.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = m_entity.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = m_entity.createComponent<sw::Animator>("AnimatorManager");
    std::string ye("Opossum");

    transform.setPosition(1800, 250);
    transform.setScale(2.5f, 2.5f);
    sprite.setTexture(ye);
    animator.setRect({36, 28}).setLoop(true).setFPS(7).play();
}

void inc::Opossum::update()
{
    sw::ConcreteComponent auto& transform = m_entity.getComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = m_entity.getComponent<sw::Sprite>("SpriteManager");

    if (m_direction == LEFT) {
        transform.move(-4, 0);
        if (transform.getPosition().x <= m_pos1.x) {
            m_direction = RIGHT;
            sprite.flipOnX(true);
        }
    } else {
        transform.move(4, 0);
        if (transform.getPosition().x >= m_pos2.x) {
            m_direction = LEFT;
            sprite.flipOnX(false);
        }
    }
}