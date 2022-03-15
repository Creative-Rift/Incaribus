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

inc::BackgroundManager::BackgroundManager(sw::Entity &entity) :
sw::Component(entity)
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &inc::BackgroundManager::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &inc::BackgroundManager::update);
}

void inc::BackgroundManager::start()
{
    m_entity.createComponent<sw::Transform>("TransformManager");
    createLayer("LastBG");
}

void inc::BackgroundManager::update()
{

}

void inc::BackgroundManager::createLayer(std::string layer)
{
    auto& layer1 = m_entity.scene().createEntity(layer + "1");
    auto& layer2 = m_entity.scene().createEntity(layer + "2");

    layer1.createComponent<inc::Background>("ScriptManager", "Background1").start();
    layer2.createComponent<inc::Background>("ScriptManager", "Background1").start();

}