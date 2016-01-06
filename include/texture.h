#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GL/glew.h>
#include "stb_image.h"
#include <cassert>
#include <iostream>

class Texture
{
    public:
        Texture(const std::string& fileName);

        void Bind(unsigned int unit);

        virtual ~Texture();
    protected:
    private:

        GLuint m_texture;
};

#endif // TEXTURE_H
