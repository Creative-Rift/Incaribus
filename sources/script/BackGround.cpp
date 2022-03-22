/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: BackGround.cpp
** Description: [CHANGE]
*/

#include "components/Transform.hpp"
#include "components/Sprite.hpp"
#include "script/Background.hpp"
#include "SW/Engine.hpp"

inc::Background::Background(sw::Entity &entity, std::string textureName) :
sw::Component(entity),
m_texture(textureName)
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &inc::Background::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &inc::Background::update);
}

void inc::Background::start()
{
    sw::ConcreteComponent auto& transform = m_entity.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = m_entity.createComponent<sw::Sprite>("SpriteManager");

    sprite.setTexture(m_texture);
    transform.setScale(5.5f, 5.5f);
    if (m_entity.name().find('2') != std::string::npos)
        transform.setPosition(sprite.texture()->getWidth() * transform.getScale().x, 0);
}

void inc::Background::update()
{
    sw::ConcreteComponent auto& transform = m_entity.getComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = m_entity.getComponent<sw::Sprite>("SpriteManager");

    transform.move(-3, 0);
    if (-transform.getPosition().x > sprite.texture()->getWidth() * transform.getScale().x)
        transform.setPosition(sprite.texture()->getWidth() * transform.getScale().x - 10, 0);
}