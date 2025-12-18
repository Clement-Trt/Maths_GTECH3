#include "Settings.h"

Params Settings::ParseArguments(int argc, char** argv)
{
    if (argc > 1)
    {
        for (int i = 0; i < argc; i++)
        {
            if (std::string(argv[i]) == "-h")
            {
                m_height = std::stof(argv[i + 1]);
            }
            if (std::string(argv[i]) == "-w")
            {
                m_width = std::stof(argv[i + 1]);
            }
            if (std::string(argv[i]) == "-r")
            {
                m_resolution = std::stof(argv[i + 1]);
            }

            if (std::string(argv[i]) == "-s")
            {
                m_screenPosition = std::stof(argv[i + 1]);
            }
            if (std::string(argv[i]) == "-v")
            {
                m_viewerPosition = std::stof(argv[i + 1]);
            }
            if (std::string(argv[i]) == "-b")
            {
                m_backGroundChar = argv[i + 1][0];
            }
            if (std::string(argv[i]) == "-p")
            {
                m_meshProjChar = argv[i + 1][0];
            }
            if (std::string(argv[i]) == "-lx")
            {
                m_lightDir.x = argv[i + 1][0];
            }
            if (std::string(argv[i]) == "-ly")
            {
                m_lightDir.y = argv[i + 1][0];
            }
            if (std::string(argv[i]) == "-lz")
            {
                m_lightDir.z = argv[i + 1][0];
            }
        }
    }
    Params p{ m_width, m_height, m_resolution, m_screenPosition, m_viewerPosition, m_backGroundChar, m_meshProjChar, m_lightDir };
    return p;
}
