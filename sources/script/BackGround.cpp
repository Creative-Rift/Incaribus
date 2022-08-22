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
#include "OpenGLModule.hpp"

inc::Background::Background(sw::GameObject &gameObject, std::string textureName) :
sw::Component(gameObject),
m_texture(textureName)
{
    m_gameObject.scene().eventManager["Update"].subscribe(this, &inc::Background::update);
}

void inc::Background::start()
{
    sw::ConcreteComponent auto& sprite = m_gameObject.getComponent<sw::Sprite>("SpriteManager");

    sprite.setTexture(m_texture);
    m_gameObject.transform().setScale(5.5f, 5.5f);
    if (m_gameObject.name().find('2') != std::string::npos)
        m_gameObject.transform().setPosition(sprite.texture()->getWidth() * m_gameObject.transform().getScale().x, 0);
}

void inc::Background::update()
{
    sw::ConcreteComponent auto& sprite = m_gameObject.getComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& camTransform = m_gameObject.scene().getGameObject("MainCamera").transform();

    m_gameObject.transform().move(-3, 0);
    if (camTransform.getPosition().x - m_gameObject.transform().getPosition().x > sprite.texture()->getWidth() * m_gameObject.transform().getScale().x)
        m_gameObject.transform().setPosition(camTransform.getPosition().x + sprite.texture()->getWidth() * m_gameObject.transform().getScale().x - 10, 0);
    if (sw::isKeyReleased(sw::Keyboard::SPACE) && sw::OpenGLModule::sceneManager().getActiveScene().name == "Main")
        sw::OpenGLModule::sceneManager().loadScene("Game");
}