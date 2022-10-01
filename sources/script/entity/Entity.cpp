/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Entity.cpp
** Description: [CHANGE]
*/

#include "entity/Entity.hpp"

swc::Entity::Entity(sw::GameObject& gameObject) :
sw::Component(gameObject)
{

}

swc::Entity::~Entity() noexcept
= default;

void swc::Entity::DoSetup()
{
    m_entityHealth.value().DoSetup();
}