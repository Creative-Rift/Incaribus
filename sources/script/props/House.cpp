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

inc::House::House(sw::Entity &entity) :
sw::Component(entity)
{
    entity.scene().eventManager()["Start"].subscribe(this, &inc::House::start);
}

void inc::House::start()
{
    sw::ConcreteComponent auto& transform = m_entity.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = m_entity.createComponent<sw::Sprite>("SpriteManager");
    std::string ye("House");

    transform.setPosition(500, 532);
    transform.setScale(2.5, 2.5);
    sprite.setTexture(ye);
    m_entity.setLayer("SpriteManager", 1);
}