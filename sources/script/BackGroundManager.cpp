/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: BackGround.cpp
** Description: [CHANGE]
*/

#include <utility>

#include "components/Transform.hpp"
#include "script/BackgroundManager.hpp"
#include "script/Background.hpp"

inc::BackgroundManager::BackgroundManager(sw::GameObject &gameObject, std::string textureName, float scale) :
sw::Component(gameObject),
m_textureName(std::move(textureName)),
m_scale(scale),
m_multipleTexture(false)
{
    m_gameObject.scene().eventManager["Start"].subscribe(this, &inc::BackgroundManager::start);
    m_gameObject.scene().eventManager["Update"].subscribe(this, &inc::BackgroundManager::update);
}

void inc::BackgroundManager::start()
{
    createLayer("LastBG");
}

void inc::BackgroundManager::update()
{

}

void inc::BackgroundManager::createLayer(std::string layer)
{
    auto& layer1 = m_gameObject.scene().createGameObject(layer + "1" + m_textureName);
    auto& layer2 = m_gameObject.scene().createGameObject(layer + "2" + m_textureName);

    m_gameObject.addChild(layer1.name());
    m_gameObject.addChild(layer2.name());
    auto& back1 = layer1.createComponent<inc::Background>("ScriptManager", m_textureName, m_scale);
    auto& back2 = layer2.createComponent<inc::Background>("ScriptManager", m_textureName, m_scale);
    back1.m_speed = m_speed;
    back2.m_speed = m_speed;
    back1.m_multipleTexture = m_multipleTexture;
    back2.m_multipleTexture = m_multipleTexture;
    if (m_multipleTexture) {
        back1.m_rect = m_rect;
        back2.m_rect = m_rect;
    }
    back1.start();
    back2.start();
    layer1.setLayer("SpriteManager", m_layer);
    layer2.setLayer("SpriteManager", m_layer);
}