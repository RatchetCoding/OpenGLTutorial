#include "mesh.h"
/*
* In this class we draw a triangle. We construct the class with an array of vertices and give it the length of the array.
*/
Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
    // We save the amount of vertices into our draw count. It saves how many vertices we have to draw
    m_drawCount = numVertices;

    // We create and bind an vertexArrayObject. It saves how the data in the VBO is formatted
    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> texCoords;

    positions.reserve(numVertices);
    texCoords.reserve(numVertices);

    for(unsigned int i = 0; i < numVertices; i++)
    {
        positions.push_back(*vertices[i].GetPos());
        texCoords.push_back(*vertices[i].GetTexCoord());
    }
    //Wir erstellen den VBO, er liegt im Speicher der Grafikkarte und enthält unser Vektorarray, so dass die Grafikkarte schnell darauf zugreifen kann
    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);

    // We copy our data into the buffer object
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);

    // we enable the first vectorarrayobject
    glEnableVertexAttribArray(0);
    // (Index of VAO, Number of Values in every element (X,Y,Z in this case), type of the values,  somehting strange, distance between the values , where to begin)
    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 0, 0);


    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,2,GL_FLOAT, GL_FALSE, 0, 0);

    // wir entbinden das VAO wieder, damit wir es nicht mehr verändern können
    glBindVertexArray(0);


}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::Draw()
{
// we only have to bind the VAO because the VBO is already bound to it
glBindVertexArray(m_vertexArrayObject);
// We draw the vertices in the array as triangles
glDrawArrays(GL_TRIANGLES,0, m_drawCount);

glBindVertexArray(0);

}
