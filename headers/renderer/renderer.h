#pragma once
#include "renderApi.h"
#include "vertexArray.h"
#include "shader.h"
#include "coreCamera.h"
#include "mesh.h"


namespace LaughTaleEngine
{

    struct SceneData
    {
        coreCamera *camera;
    };

    class renderer
    {
        private:
            SceneData data;
            renderApi *api;
        public:
            renderer(renderApi *api):
                api(api){}
                
            void beginScene(coreCamera *camera);
            void endScene();

            void Submit(shader *s, uint32_t count, glm::mat4 transform = glm::mat4(1.0f));
            void Submit(mesh *toRender);
    };
    
    
}
