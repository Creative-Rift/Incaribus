/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Speech.hpp
*/

#ifndef __SHIPWRECK_Speech_HPP__
#define __SHIPWRECK_Speech_HPP__

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <vector>

#include "Chrono.hpp"
#include "../Log.hpp"
#include "../Config.hpp"

namespace sw
{

    class SW_CORE_API_EXPORT Speech
    {

        private:
            static std::vector<std::pair<std::string, std::string>> m_logList;
            static std::vector<std::pair<std::string, std::string>> m_lastLogList;

            static std::string time();

        public:
            static bool colorized;
            static bool displayed;
            static bool dispError;
            static bool dispWarning;
            static bool dispDebug;
            static bool dispInfo;
            static bool clearOnPlay;
            static bool dispTime;
            static bool stack;
            #if (__unix__)
                #define E_CHAR "\e"
            #elif (_WIN32)
                #define E_CHAR
            #endif
            class Color {
                public:
                    static constexpr char const *Reset        {"[0m"};
                    static constexpr char const *Bold         {"[1m"};
                    static constexpr char const *Dim          {"[2m"};
                    static constexpr char const *Underlined   {"[4m"};
                    static constexpr char const *Blink        {"[5m"};
                    static constexpr char const *Inverted     {"[7m"};
                    static constexpr char const *Hidden       {"[8m"};

                    static constexpr char const *White        {"[39m"};
                    static constexpr char const *Black        {"[30m"};
                    static constexpr char const *Grey         {"[90m"};
                    static constexpr char const *Red          {"[31m"};
                    static constexpr char const *Green        {"[32m"};
                    static constexpr char const *Yellow       {"[33m"};
                    static constexpr char const *Blue         {"[34m"};
                    static constexpr char const *Magenta      {"[35m"};
                    static constexpr char const *Cyan         {"[36m"};

                    static constexpr char const *LightWhite   {"[97m"};
                    static constexpr char const *LightGrey    {"[246m"};
                    static constexpr char const *LightRed     {"[91m"};
                    static constexpr char const *LightGreen   {"[92m"};
                    static constexpr char const *LightYellow  {"[93m"};
                    static constexpr char const *LightBlue    {"[94m"};
                    static constexpr char const *LightMagenta {"[95m"};
                    static constexpr char const *LightCyan    {"[96m"};

                    static constexpr char const *BackWhite    {"[49m"};
                    static constexpr char const *BackBlack    {"[40m"};
                    static constexpr char const *BackGrey     {"[100m"};
                    static constexpr char const *BackRed      {"[41m"};
                    static constexpr char const *BackGreen    {"[42m"};
                    static constexpr char const *BackYellow   {"[43m"};
                    static constexpr char const *BackBlue     {"[44m"};
                    static constexpr char const *BackMagenta  {"[45m"};
                    static constexpr char const *BackCyan     {"[46m"};

                    static constexpr char const *BackLightWhite  {"[107m"};
                    static constexpr char const *BackLightGrey   {"[47m"};
                    static constexpr char const *BackLightRed    {"[101m"};
                    static constexpr char const *BackLightGreen  {"[102m"};
                    static constexpr char const *BackLightYellow {"[103m"};
                    static constexpr char const *BackLightBlue   {"[104m"};
                    static constexpr char const *BackLightMagenta{"[105m"};
                    static constexpr char const *BackLightCyan   {"[106m"};
            };


            static void Info(const Log& log);
            static void Info(const std::string& message, const std::string& code = "0");
            static void Debug(const Log& log);
            static void Debug(const std::string& message, const std::string& code = "0");
            static void Warning(const Log& log);
            static void Warning(const std::string& message, const std::string& code = "0");
            static void Error(const Log& log);
            static void Error(const std::string& message, const std::string& code = "0");
            static void flush(std::ostream& os = std::cout);
            static void clearConsole(std::ostream& os = std::cout);
            static void clearLog();

            static void setDisplayed(bool value);

    }; // class Speech

} // namespace sw

#endif // __SHIPWRECK_Speech_HPP__