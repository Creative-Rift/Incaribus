/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: IDoTearDown.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_IDOTEARDOWN_HPP
#define INCARIBUS_IDOTEARDOWN_HPP

namespace swc
{
    class IDoTearDown
    {
        public:
            ~IDoTearDown() = default;
            virtual void DoTearDown() = 0;
    }; // class IDoTearDown
} // namespace swc

#endif //INCARIBUS_IDOTEARDOWN_HPP
