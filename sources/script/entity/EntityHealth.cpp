/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: EntityHealth.cpp
** Description: [CHANGE]
*/

#include "entity/EntityHealth.hpp"

swc::EntityHealth::EntityHealth(sw::GameObject &gameObject) :
sw::Component(gameObject),
m_maxHealth(100),
m_currentHealth(100)
{}

swc::EntityHealth::~EntityHealth() noexcept
= default;

void swc::EntityHealth::DoSetup()
{
    m_currentHealth = m_maxHealth;
}
