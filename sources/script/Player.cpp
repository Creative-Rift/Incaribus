/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Player.cpp
** Description: [CHANGE]
*/

#include "components/Transform.hpp"
#include "components/Sprite.hpp"
#include "components/Animator.hpp"

#include "script/Player.hpp"
#include "OpenGLModule.hpp"

Player::Player(sw::Entity &entity) :
sw::Component(entity)
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Player::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Player::update);
}

void Player::start()
{
    sw::ConcreteComponent auto& sprite = m_entity.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = m_entity.createComponent<sw::Animator>("AnimatorManager");
    sw::ConcreteComponent auto& transform = m_entity.createComponent<sw::Transform>("TransformManager");
    std::string ye("Idle");

    transform.setPosition(1800, 0);
    transform.scale(3.0f, 3.0f);
    sprite.setTexture(ye);
    animator.setRect({33, 32}).setFPS(10).setLoop(true).setAnimType(sw::Animator::ANIM_LINE).setLine(2, 3);
    animator.play();
}

void Player::update()
{
    sw::ConcreteComponent auto& transform = m_entity.getComponent<sw::Transform>("TransformManager");

    m_entity.getComponent<sw::Animator>("AnimatorManager").setLine(2, 3);
    if (sw::isKeyDown(sw::Keyboard::A)) {
        m_entity.getComponent<sw::Sprite>("SpriteManager").invertX(true);
        transform.move(-4, 0);
        m_entity.getComponent<sw::Animator>("AnimatorManager").setLine(3);
    }
    if (sw::isKeyDown(sw::Keyboard::D)) {
        m_entity.getComponent<sw::Sprite>("SpriteManager").invertX(false);
        transform.move(4, 0);
        m_entity.getComponent<sw::Animator>("AnimatorManager").setLine(3);
    }
}