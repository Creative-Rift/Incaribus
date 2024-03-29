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
#include "window/Window.hpp"
#include "components/AudioSource.hpp"

Player::Player(sw::GameObject &gameObject) :
sw::Component(gameObject)
{
    m_gameObject.scene().eventManager["Start"].subscribe(this, &Player::start);
    m_gameObject.scene().eventManager["Update"].subscribe(this, &Player::update);
}

void Player::start()
{
    sw::ConcreteComponent auto& sprite = m_gameObject.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = m_gameObject.createComponent<sw::Animator>("AnimatorManager");
    sw::ConcreteComponent auto& collision = m_gameObject.createComponent<sw::BoxCollider>("BoxColliderManager");
    sw::ConcreteComponent auto& rigidbody = m_gameObject.createComponent<sw::RigidBody2D>("RigidBody2DManager");
    std::string ye("Idle");

    m_gameObject.transform().setPosition(210, 225);
    m_gameObject.transform().scale(3.0f, 3.0f);
    sprite.setTexture(ye).flipOnX(true);
    m_gameObject.setLayer("SpriteManager", 3);
    animator.setRect({33, 32}).setFPS(8).setLoop(true).setAnimType(sw::Animator::ANIM_LINE).setLine(2, 3);
    animator.play();
    collision.setSize(33 * 3, 32 * 3);
    rigidbody.setMass(0.75);
    if (sw::OpenGLModule::sceneManager().getActiveScene().name != "Game")
        rigidbody.setActive(false);
}

void Player::update()
{
    if (sw::isKeyDown(sw::Keyboard::G))
        gameObject().scene().getGameObject("MainCamera").getComponent<sw::AudioSource>("AudioManager").play();
    if (sw::OpenGLModule::sceneManager().getActiveScene().name != "Game")
        return;
    sw::ConcreteComponent auto& velocity = m_gameObject.getComponent<sw::RigidBody2D>("RigidBody2DManager");
    sw::ConcreteComponent auto& anim = m_gameObject.getComponent<sw::Animator>("AnimatorManager");
    sw::Vector2f move{0, velocity.getVelocity().y};
    if (sw::isKeyDown(sw::Keyboard::R)) {
        m_gameObject.transform().setPosition(210, 225);
        velocity.setVelocity({0, 0});
        move.x = 0;
        move.y = 0;
    }

    m_gameObject.getComponent<sw::Animator>("AnimatorManager").setLine(2, 3);
    if (sw::isKeyDown(sw::Keyboard::A)) {
        m_gameObject.getComponent<sw::Sprite>("SpriteManager").flipOnX(true);

        move.x = -4;
        m_gameObject.getComponent<sw::Animator>("AnimatorManager").setLine(3);
    }
    if (sw::isKeyDown(sw::Keyboard::D)) {
        m_gameObject.getComponent<sw::Sprite>("SpriteManager").flipOnX(false);
        move.x = 4;
        m_gameObject.getComponent<sw::Animator>("AnimatorManager").setLine(3);
    }
    if (sw::isKeyDown(sw::Keyboard::SPACE) && velocity.getVelocity().y == 0)
        move.y = -700;
    velocity.setVelocity(move);

    auto& camera = m_gameObject.scene().getGameObject("MainCamera");
    auto& transformCam = camera.transform();

    if (transformCam.getPosition().x < 1100 && m_gameObject.transform().getPosition().x > transformCam.getPosition().x + 1000)
        transformCam.move(7, 0);
    if (transformCam.getPosition().x > 0 && m_gameObject.transform().getPosition().x < transformCam.getPosition().x + 900)
        transformCam.move(-7, 0);

    if (velocity.getVelocity().y > 0)
        anim.setLine(1, 0);
    if (velocity.getVelocity().y < 0)
        anim.setLine(0, 0);
}