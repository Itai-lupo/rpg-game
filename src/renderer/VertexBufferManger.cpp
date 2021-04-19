#include "VertexBufferManger.h"
#include "algorithm"
#include "logger.h"
namespace LaughTaleEngine
{
    std::vector<VertexBuffer *>  *VertexBufferManger::VertexBuffers = new std::vector<VertexBuffer *>();

    void VertexBufferManger::init()
    {
        VertexBuffers = new std::vector<VertexBuffer *>();
    }

    void VertexBufferManger::close()
    {
        std::for_each(
            VertexBuffers->begin(), 
            VertexBuffers->end(),
            [](VertexBuffer *vb){ free(vb); }
        );
        VertexBuffers->clear();
    }

    void VertexBufferManger::bind(vertexBufferId vbId)
    {
        (*std::find_if(
            VertexBuffers->begin(), 
            VertexBuffers->end(),
            [=](VertexBuffer * vb)-> bool { return vb->RendererID == vbId; }
            ))->bind();
    }

    void VertexBufferManger::unBind(vertexBufferId vbId)
    {
        (*std::find_if(
            VertexBuffers->begin(), 
            VertexBuffers->end(),
            [=](VertexBuffer * vb)-> bool { return vb->RendererID == vbId; }
            ))->unbind();
    }

    vertexBufferId VertexBufferManger::add(VertexBuffer *vbToAdd)
    {
        vbToAdd->RendererID = vbToAdd->init();

        VertexBuffers->push_back(vbToAdd);
        return vbToAdd->RendererID;
    }

    void VertexBufferManger::remove(vertexBufferId vbToRemove)
    {
        std::remove_if(
            VertexBuffers->begin(), 
            VertexBuffers->end(),
            [=](VertexBuffer * vb)-> bool { return vb->RendererID == vbToRemove; }
        );
    }

    void VertexBufferManger::changeData(vertexBufferId vbId, const void *data, uint32_t size)
    {
        (*std::find_if(
            VertexBuffers->begin(), 
            VertexBuffers->end(),
            [=](VertexBuffer * vb)-> bool { return vb->RendererID == vbId; }
            ))->setData(data, size);
    }

    VertexBuffer *VertexBufferManger::getVB(vertexBufferId vbId)
    {
        return (*std::find_if(
            VertexBuffers->begin(), 
            VertexBuffers->end(),
            [=](VertexBuffer * vb)-> bool { return vb->RendererID == vbId; }
            ));
    }


    std::vector<VertexBufferElement> VertexBufferManger::getElements(vertexBufferId vbId)
    {
        return (*std::find_if(
            VertexBuffers->begin(), 
            VertexBuffers->end(),
            [=](VertexBuffer * vb)-> bool { return vb->RendererID == vbId; }
            ))->getElements();
    }

    unsigned int VertexBufferManger::GetStride(vertexBufferId vbId)
    {
        return (*std::find_if(
            VertexBuffers->begin(), 
            VertexBuffers->end(),
            [=](VertexBuffer * vb)-> bool { return vb->RendererID == vbId; }
            ))->GetStride();
    }

    void VertexBufferManger::pushVertexBufferElement(vertexBufferId vbId, VertexBufferElement ElementToPush)
    {
        (*std::find_if(
            VertexBuffers->begin(), 
            VertexBuffers->end(),
            [=](VertexBuffer * vb)-> bool { return vb->RendererID == vbId; }
        ))->pushVertexBufferElement(ElementToPush);
    }
}