#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <vector>
#include <iostream>

class Vertex
{
public:
    Vertex(const glm::vec3& pos,const glm::vec2& texCoord)
    {
        this->texCoord = texCoord;
        this->pos = pos;
    }
    inline glm::vec3* GetPos() {return &pos;}
    inline glm::vec2* GetTexCoord() {return &texCoord;}
protected:
private:
    glm::vec3 pos;
    glm::vec2 texCoord;
};

class Mesh
{
    public:
        Mesh(Vertex* vertices, unsigned int numVertices);

        void Draw();

        virtual ~Mesh();
    protected:
    private:

        Mesh(const Mesh& other);
        void operator=(const Mesh& other);

        enum
        {
            POSITION_VB,

            TEXCOORD_VB,

            NUM_BUFFERS
        };

        GLuint m_vertexArrayObject;
        GLuint m_vertexArrayBuffers[NUM_BUFFERS];
        unsigned int m_drawCount;
};

#endif // MESH_H
