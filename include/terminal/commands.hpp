#ifndef __UL_TERMINAL_COMMANDS_HPP
#define __UL_TERMINAL_COMMANDS_HPP

namespace ul{

namespace terminal{

namespace commands{

    static const char* home     = "\e[H";
    static const char* up       = "\e[A";
    static const char* down     = "\e[B";
    static const char* right    = "\e[C";
    static const char* left     = "\e[D";
    static const char* save     = "\e[s";
    static const char* unsave   = "\e[u";
    static const char* saveattr = "\e[7";
    static const char* restore  = "\e[8";

    static const char* eraseright   = "\e[K";
    static const char* eraseleft    = "\e[1K";
    static const char* eraseline    = "\e[2K";
    static const char* erasedown    = "\e[J";
    static const char* eraseup      = "\e[1J";
    static const char* eraseall     = "\e[2J";

};

};

};

#endif // __UL_TERMINAL_COMMANDS_HPP
