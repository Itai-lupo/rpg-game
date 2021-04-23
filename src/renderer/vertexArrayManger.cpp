#include "vertexArrayManger.h"
#include "VertexBufferManger.h"
#include "algorithm"

namespace LaughTaleEngine
{
    void vertexArrayManger::init()
    {
        vertexArrays = new std::vector<vertexArray*>();
    }

    void vertexArrayManger::close()
    {
        vertexArrays->clear();
    }    
    
    vertexArrayId vertexArrayManger::add(vertexArray *va)
    {
        va->rendererId = va->init();
        vertexArrays->push_back(va);
        return va->rendererId;
    }    
    
    void vertexArrayManger::addBuffer(vertexArrayId id,  VertexBuffer *vb)
    {
        (*std::find_if(
            vertexArrays->begin(),
            vertexArrays->end(),
            [=](vertexArray *va) -> bool { return va->rendererId == id; }
        ))->AddBuffer(vb);
    }    
    
    void vertexArrayManger::bind(vertexArrayId id)
    {
        (*std::find_if(
            vertexArrays->begin(),
            vertexArrays->end(),
            [=](vertexArray *va) -> bool { return va->rendererId == id; }
        ))->bind();
    }    
    
    void vertexArrayManger::unbind(vertexArrayId id)
    {
        (*std::find_if(
            vertexArrays->begin(),
            vertexArrays->end(),
            [=](vertexArray *va) -> bool { return va->rendererId == id; }
        ))->unbind();
    }
}