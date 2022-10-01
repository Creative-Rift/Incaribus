/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Entity.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_ENTITY_HPP
#define INCARIBUS_ENTITY_HPP

#include "components/Components.hpp"
#include "interface/IDoSetUp.hpp"
#include "entity/EntityHealth.hpp"
#include "utils/Reference.hpp"

namespace swc
{
    class Entity : public sw::Component, public IDoSetup
    {
        protected:
            sw::Reference<EntityHealth> m_entityHealth;

        public:
            explicit Entity(sw::GameObject& gameObject);
            ~Entity() override;
            void DoSetup() override;

    }; // class Entity
} // namespace swc

#endif //INCARIBUS_ENTITY_HPP
