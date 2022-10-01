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

inc::Opossum::Opossum(sw::GameObject &gameObject) :
sw::Component(gameObject),
m_direction(LEFT),
m_pos1{1550, 225},
m_pos2{2000, 225}
{
    gameObject.scene().eventManager["Start"].subscribe(this, &inc::Opossum::start);
    gameObject.scene().eventManager["Update"].subscribe(this, &inc::Opossum::update);
}

void inc::Opossum::start()
{
    sw::ConcreteComponent auto& sprite = m_gameObject.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = m_gameObject.createComponent<sw::Animator>("AnimatorManager");
    std::string ye("Opossum");

    m_gameObject.transform().setPosition(1800, 250);
    m_gameObject.transform().setScale(2.5f, 2.5f);
    sprite.setTexture(ye);
    animator.setRect({36, 28}).setLoop(true).setFPS(7).play();
}

void inc::Opossum::update()
{
    sw::ConcreteComponent auto& sprite = m_gameObject.getComponent<sw::Sprite>("SpriteManager");

    if (m_direction == LEFT) {
        m_gameObject.transform().move(-4, 0);
        if (m_gameObject.transform().getPosition().x <= m_pos1.x) {
            m_direction = RIGHT;
            sprite.flipOnX(true);
        }
    } else {
        m_gameObject.transform().move(4, 0);
        if (m_gameObject.transform().getPosition().x >= m_pos2.x) {
            m_direction = LEFT;
            sprite.flipOnX(false);
        }
    }
}