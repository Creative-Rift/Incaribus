/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: BackGround.cpp
** Description: [CHANGE]
*/

#include "components/Transform.hpp"
#include "script/BackgroundManager.hpp"
#include "script/Background.hpp"

inc::BackgroundManager::BackgroundManager(sw::GameObject &gameObject) :
sw::Component(gameObject)
{
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
    auto& layer1 = m_gameObject.scene().getGameObject(layer + "1");
    auto& layer2 = m_gameObject.scene().getGameObject(layer + "2");

    layer1.createComponent<inc::Background>("ScriptManager", "Background1").start();
    layer2.createComponent<inc::Background>("ScriptManager", "Background1").start();
    m_gameObject.addChild(layer1.name());
    m_gameObject.addChild(layer2.name());
}