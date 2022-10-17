/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: BackGround.cpp
** Description: [CHANGE]
*/

#include <utility>

#include "components/Transform.hpp"
#include "components/Sprite.hpp"
#include "script/Background.hpp"
#include "managers/Managers.hpp"
#include "OpenGLModule.hpp"
#include "window/Window.hpp"

inc::Background::Background(sw::GameObject &gameObject, std::string textureName, float scale) :
sw::Component(gameObject),
m_texture(std::move(textureName)),
m_scale(scale),
m_speed(3)
{
    m_gameObject.scene().eventManager["Start"].subscribe(this, &inc::Background::start);
    m_gameObject.scene().eventManager["Update"].subscribe(this, &inc::Background::update);
}

void inc::Background::start()
{
    sw::ConcreteComponent auto& sprite = m_gameObject.createComponent<sw::Sprite>("SpriteManager");

    sprite.setTexture(m_texture);
    m_gameObject.setLayer("SpriteManager", 5);
    m_gameObject.transform().setScale(m_scale, m_scale);
    if (m_gameObject.name().find('2') != std::string::npos)
        m_gameObject.transform().move(sprite.texture()->getWidth() * m_gameObject.transform().getScale().x, 0);
    if (m_multipleTexture) {
        sw::FloatRect newrect = {m_rect.left, m_rect.top * (std::rand() % 2), m_rect.width, m_rect.height};
        sprite.setTextureRect(newrect);
    }
}

void inc::Background::update()
{
    sw::ConcreteComponent auto& sprite = m_gameObject.getComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& camTransform = m_gameObject.scene().getGameObject("MainCamera").transform();

    m_gameObject.transform().move(-m_speed, 0);
    if (camTransform.getPosition().x - m_gameObject.transform().getPosition().x > sprite.texture()->getWidth() * m_gameObject.transform().getScale().x) {
        m_gameObject.transform().setPosition(camTransform.getPosition().x + sprite.texture()->getWidth() * m_gameObject.transform().getScale().x - 10, m_gameObject.transform().getPosition().y);
        if (m_multipleTexture) {
            sw::FloatRect newrect = {m_rect.left, m_rect.top * (std::rand() % 2), m_rect.width, m_rect.height};
            sprite.setTextureRect(newrect);
        }
    }
    if (sw::isKeyReleased(sw::Keyboard::SPACE) && sw::OpenGLModule::sceneManager().getActiveScene()->name == "Main")
        sw::OpenGLModule::sceneManager().loadScene("Game");
}