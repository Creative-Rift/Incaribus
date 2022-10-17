/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Player.cpp
** Description: [CHANGE]
*/

#include "components/Components.hpp"
#include "event/EventCollision.hpp"

#include "script/character/PlayerLoading.hpp"
#include "OpenGLModule.hpp"

PlayerLoading::PlayerLoading(sw::GameObject &gameObject) :
sw::Component(gameObject)
{
    m_gameObject.scene().eventManager["Start"].subscribe(this, &PlayerLoading::start);
    m_gameObject.scene().eventManager["Update"].subscribe(this, &PlayerLoading::update);
}

void PlayerLoading::start()
{
    sw::ConcreteComponent auto& sprite = m_gameObject.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = m_gameObject.createComponent<sw::Animator>("AnimatorManager");
    std::string ye("Idle");

    m_gameObject.transform().setPosition(210, 480);
    m_gameObject.transform().scale(3.0f, 3.0f);
    sprite.setTexture(ye);
    m_gameObject.setLayer("SpriteManager", 3);
    animator.setRect({33, 32}).setFPS(8).setLoop(true).setAnimType(sw::Animator::ANIM_LINE).setLine(3, 5);
    animator.play();
}

void PlayerLoading::update()
{
}