/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: EntityHealth.cpp
** Description: [CHANGE]
*/


#ifndef INCARIBUS_ENTITYHEALTH_HPP
#define INCARIBUS_ENTITYHEALTH_HPP

#include "components/Components.hpp"
#include "interface/IDoSetUp.hpp"

namespace swc
{
    class EntityHealth : public sw::Component, public IDoSetup
    {
        protected:
            int m_maxHealth{};
            int m_currentHealth{};

        public:
            explicit EntityHealth(sw::GameObject& gameObject);
            ~EntityHealth() override;
            void DoSetup() override;
    };
}

#endif //INCARIBUS_ENTITYHEALTH_HPP
