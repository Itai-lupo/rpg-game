#include "entity.h"
#include <stdlib.h>

#include "logger.h"
namespace LTE
{
    gameObject::gameObjectBuilder *entityManger::builder = nullptr;
    std::vector<gameObject*> entityManger::entitys = std::vector<gameObject*>();
    u_int32_t entityManger::nextEventId = 0;


    void entityManger::init()
    {
        entityManger::entitys = std::vector<gameObject*>();
        builder = new gameObject::gameObjectBuilder();
    }

    void entityManger::close()
    {
        entityManger::entitys.clear();
        entityManger::nextEventId = 0;
    }

    entityTaleId entityManger::addEntity(std::function<void(gameObject::gameObjectBuilder *Builder)> buildGameObject)
    {
        builder->reset();
        buildGameObject(builder);
        gameObject *res = builder->build(entityManger::nextEventId);
        entityManger::entitys.push_back(res);
        entityManger::nextEventId++;
        return res->getId();
    }

    gameObject *entityManger::getEntityByName(const std::string& name)
    {
        gameObject *e = nullptr;
        for (uint64_t i = 0; i < entityManger::entitys.size(); i++)
        {
            if(entityManger::entitys[i]->getName()  == name)
                return entityManger::entitys[i];
        }
        
        LAUGHTALE_ENGINR_LOG_WARNING("game object with id:" << name << "wasn't found");
        return  NULL;
        
    }

    gameObject *entityManger::getEntityById(entityTaleId id)
    {
        gameObject *e = nullptr;
        for (uint64_t i = 0; i < entityManger::entitys.size(); i++)
        {
            if(entityManger::entitys[i]->getId()  == id)
                return entityManger::entitys[i];
        }
        
        LAUGHTALE_ENGINR_LOG_WARNING("game object with id: " << id << "    wasn't found");
        return  NULL;
    }

    void entityManger::removeEntityById(entityTaleId id)
    {
        for (uint64_t i = 0; i < entityManger::entitys.size(); i++)
        {
            if(entityManger::entitys[i]->getId()  == id)
            {
                entityManger::entitys[i]->end();
                delete entityManger::entitys[i];
                entityManger::entitys.erase(entityManger::entitys.begin() + i);
            }
        }
        
    }
}