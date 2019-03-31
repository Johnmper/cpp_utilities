#ifndef __UL_TERMINAL_STYLE_HPP
#define __UL_TERMINAL_STYLE_HPP

namespace ul{

namespace terminal{

namespace style{

    static const char* black     = "\e[30m";
    static const char* red       = "\e[31m";
    static const char* green     = "\e[32m";
    static const char* yellow    = "\e[33m";
    static const char* blue      = "\e[34m";
    static const char* magenta   = "\e[35m";
    static const char* cyan      = "\e[36m";
    static const char* gray      = "\e[37m";

    static const char* normal    = "\e[0m";
    static const char* bold      = "\e[1m";
    static const char* dim       = "\e[2m";
    static const char* underline = "\e[4m";
    static const char* blink     = "\e[5m";
    static const char* invert    = "\e[7m";
    static const char* invisible = "\e[8m";

};  // STYLE NAMESPACE

};  // TERMINAL NAMESPACE

};  // UL NAMESPACE

#endif  // __UL_TERMINAL_STYLE_HPP
