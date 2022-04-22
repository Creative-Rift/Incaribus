/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Opossum.cpp
** Description: [CHANGE]
*/

#include "script/props/Gem.hpp"
#include "components/Transform.hpp"
#include "components/Sprite.hpp"
#include "components/Animator.hpp"
#include "components/BoxCollider.hpp"
#include "event/EventCollision.hpp"

inc::Gem::Gem(sw::GameObject &gameObject) :
sw::Component(gameObject)
{
    gameObject.scene().eventManager["Start"].subscribe(this, &inc::Gem::start);
    gameObject.scene().eventManager["Collision"].subscribe(this, &inc::Gem::onCollide);
}

void inc::Gem::start()
{
    sw::ConcreteComponent auto& transform = m_gameObject.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = m_gameObject.createComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& animator = m_gameObject.createComponent<sw::Animator>("AnimatorManager");
    sw::ConcreteComponent auto& collider = m_gameObject.createComponent<sw::BoxCollider>("BoxColliderManager");
    std::string ye("Gem");

    transform.setPosition(1300, 760);
    transform.setScale(2.5f, 2.5);
    sprite.setTexture(ye);
    m_gameObject.setLayer("SpriteManager", 2);
    animator.setRect({15, 13}).setLoop(true).setFPS(8).play();
    collider.setSize(15 * 2.5, 13 * 2.5);
    collider.setStatic(true);
    collider.setTrigger(true);
}

void inc::Gem::onCollide(sw::EventInfo &info)
{
    auto& einfo = info.getInfo<sw::CollisionEvent>();

    if (einfo.m_obj == "Player" && einfo.m_target == m_gameObject.name())
        m_gameObject.setActive(false);
}