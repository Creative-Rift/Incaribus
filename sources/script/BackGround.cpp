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
    m_gameObject.scene().eventManager["Start"].subscribe(this, &inc::Background::start);
    m_gameObject.scene().eventManager["Update"].subscribe(this, &inc::Background::update);
}

void inc::Background::start()
{
    sw::ConcreteComponent auto& transform = m_gameObject.createComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = m_gameObject.createComponent<sw::Sprite>("SpriteManager");

    sprite.setTexture(m_texture);
    transform.setScale(5.5f, 5.5f);
    if (m_gameObject.name().find('2') != std::string::npos)
        transform.setPosition(sprite.texture()->getWidth() * transform.getScale().x, 0);
}

void inc::Background::update()
{
    sw::ConcreteComponent auto& transform = m_gameObject.getComponent<sw::Transform>("TransformManager");
    sw::ConcreteComponent auto& sprite = m_gameObject.getComponent<sw::Sprite>("SpriteManager");
    sw::ConcreteComponent auto& camTransform = m_gameObject.scene().getGameObject("MainCamera").getComponent<sw::Transform>("TransformManager");

    transform.move(-3, 0);
    if (camTransform.getPosition().x - transform.getPosition().x > sprite.texture()->getWidth() * transform.getScale().x)
        transform.setPosition(camTransform.getPosition().x + sprite.texture()->getWidth() * transform.getScale().x - 10, 0);
    if (sw::isKeyReleased(sw::Keyboard::SPACE) && sw::OpenGLModule::sceneManager().getActiveScene().name == "Main")
        sw::OpenGLModule::sceneManager().loadScene("Game");
}