#include <iostream>
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"

int main()
{
    Display display(800, 600,"OpenGL");

    Vertex vertices[] = {Vertex(glm::vec3(-0.5,-0.5,0),glm::vec2(0,0)),
                         Vertex(glm::vec3(0,0.5,0),glm::vec2(0.5,1.0)),
                         Vertex(glm::vec3(0.5,-0.5,0),glm::vec2(1.0,0)),};
    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

    Shader shader("./res/basicShader");
    Texture texture("./res/bricks.jpg");
    Transform transform(glm::vec3(0,0,0));



    float counter = 0.0f;

    while(!display.isClosed())
    {

        display.Clear(0.0f, 0.15f, 0.3f,1.0f);

        //transform.GetPos().x = sinf(counter);
        //transform.GetScale().z = counter;

        shader.Bind();
        texture.Bind(0);
        shader.Update(transform);
        mesh.Draw();

        display.Update();
        counter += 0.1f;

    }
    return 0;

}
