//
// Created by Manoloon on 13/12/2021.
//

#include "EntityManager.h"

EntityManager::EntityManager(){}

void EntityManager::Update()
{
    for(auto e:m_toAdd)
    {
        m_entities.push_back(e);
        // store it in the map of tag->entityVector
        m_entitiesMap[e->GetTag()].push_back(e);
    }
    // remove those who are marked for dead
    removeEntities(m_entities);

    for(auto&[tag,entityVec] : m_entitiesMap)
    {
        removeEntities(EntityVec);
    }
    // end of frame -> clear the vector.
    m_toAdd.clear();
}

ptr<Entity> EntityManager::addEntity(const std::string &tag)
{
    // We declare it this way because Entity have a private constructor.
    auto newEntity = ptr<Entity>(new Entity(m_totalEntities++,tag));
    // store it in the queue for beeing store on the next frame.
    m_toAdd.push_back(newEntity);
    // return the entity obj
    return newEntity;
}

void EntityManager::removeEntities(EntityVec &vec)
{
//TODO : implementar esta funcion donde las entities son anadidas al m_entitiesToAdd vector,
// y luego a la locacion correspondiente in update()
}

const EntityVec &EntityManager::GetEntities()
{
    return m_entities;
}

const EntityVec &EntityManager::GetEntities(const std::string &tag)
{
    // TODO : deberia devolver el vector correspondiente del Map.
    return m_entitiesMap[tag];
}

