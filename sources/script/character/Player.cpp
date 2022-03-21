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
#include "components/BoxCollider.hpp"
#include "components/RigidBody2D.hpp"
#include "event/EventCollision.hpp"

#include "script/character/Player.hpp"
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
    sw::ConcreteComponent auto& collision = m_entity.createComponent<sw::BoxCollider>("BoxColliderManager");
    sw::ConcreteComponent auto& rigidbody = m_entity.createComponent<sw::RigidBody2D>("RigidBody2DManager");
    std::string ye("Idle");

    transform.setPosition(210, 225);
    transform.scale(3.0f, 3.0f);
    sprite.setTexture(ye);
    m_entity.setLayer("SpriteManager", 3);
    animator.setRect({33, 32}).setFPS(8).setLoop(true).setAnimType(sw::Animator::ANIM_LINE).setLine(2, 3);
    animator.play();
    collision.setSize(33 * 3, 32 * 3);
    rigidbody.setMass(0.7);
    if (sw::Engine::activeSceneName() != "Game")
        rigidbody.setActive(false);
}

void Player::update()
{
    if (sw::Engine::activeSceneName() != "Game")
        return;
    sw::ConcreteComponent auto& transform = m_entity.getComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& velocity = m_entity.getComponent<sw::RigidBody2D>("RigidBody2DManager");
    sw::Vector2f move{0, velocity.getVelocity().y};
    if (sw::isKeyDown(sw::Keyboard::R))
        transform.setPosition(210, 225);

    m_entity.getComponent<sw::Animator>("AnimatorManager").setLine(2, 3);
    if (sw::isKeyDown(sw::Keyboard::A)) {
        m_entity.getComponent<sw::Sprite>("SpriteManager").invertX(true);

        move.x = -4;
        m_entity.getComponent<sw::Animator>("AnimatorManager").setLine(3);
    }
    if (sw::isKeyDown(sw::Keyboard::D)) {
        m_entity.getComponent<sw::Sprite>("SpriteManager").invertX(false);
        move.x = 4;
        m_entity.getComponent<sw::Animator>("AnimatorManager").setLine(3);
    }
    if (sw::isKeyDown(sw::Keyboard::SPACE))
        move.y = -700;
    velocity.setVelocity(move);

    auto& camera = m_entity.scene().getEntity("MainCamera");
    auto& transformCam = camera.getComponent<sw::Transform>("TransformManager");

    if (transformCam.getPosition().x < 1100 && transform.getPosition().x > transformCam.getPosition().x + 1200)
        transformCam.move(7, 0);
    if (transformCam.getPosition().x > 0 && transform.getPosition().x < transformCam.getPosition().x + 800)
        transformCam.move(-7, 0);

}