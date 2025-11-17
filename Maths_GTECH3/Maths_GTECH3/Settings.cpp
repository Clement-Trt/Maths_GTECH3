#include "Settings.h"

Params Settings::ParseArguments(int argc, char** argv)
{
    if (argc > 1)
    {
        for (int i = 0; i < argc; i++)
        {
            if (std::string(argv[i]) == "-h")
            {
                m_height = std::stoi(argv[i + 1]);
            }
            if (std::string(argv[i]) == "-w")
            {
                m_width = std::stoi(argv[i + 1]);
            }
            if (std::string(argv[i]) == "-r")
            {
                m_resolution = std::stoi(argv[i + 1]);
            }
        }
    }
    Params p{ m_width, m_height,m_resolution };
    return p;
}
