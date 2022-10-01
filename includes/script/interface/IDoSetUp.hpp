/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: IDoSetup.hpp
** Description: [CHANGE]
*/

#ifndef INCARIBUS_IDOSETUP_HPP
#define INCARIBUS_IDOSETUP_HPP

namespace swc
{
    class IDoSetup
    {
        public:
            ~IDoSetup() = default;
            virtual void DoSetup() = 0;
    }; // class IDoSetup
} // namespace swc

#endif //INCARIBUS_IDOSETUP_HPP
