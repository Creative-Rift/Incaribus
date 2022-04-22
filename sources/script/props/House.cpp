/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Opossum.cpp
** Description: [CHANGE]
*/

#include "script/props/House.hpp"
#include "components/Transform.hpp"
#include "components/Sprite.hpp"
#include "gameObject/GameObject.hpp"

inc::House::House(sw::GameObject &gameObject) :
sw::Component(gameObject)
{
    gameObject.scene().eventManager["Start"].subscribe(this, &inc::House::start);
}

void inc::House::start()
{
    sw::ConcreteComponent auto& sprite = m_gameObject.createComponent<sw::Sprite>("SpriteManager");
    std::string ye("House");

    m_gameObject.transform().setPosition(500, 532);
    m_gameObject.transform().setScale(2.5, 2.5);
    sprite.setTexture(ye);
    m_gameObject.setLayer("SpriteManager", 1);
}