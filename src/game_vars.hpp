#ifndef GAME_VARS_HPP
#define GAME_VARS_HPP

#include <vector>
#include <memory>
#include <map>
#include "entity.hpp"

//Oh no! Global variables :)

typedef uint8_t byte;

inline std::vector<std::unique_ptr<Entity>> entities;
inline std::vector<int> entityRemoveQueue;
inline int fps;

/*
 Gets the index of the requested destroy from the entity and
 adds the index to the list. 
*/
inline void removeEntity(Entity *comp){
    auto itr = std::find_if(std::begin(entities), 
                        std::end(entities), 
                        [comp](auto &element) { return element.get() == comp;});  
    if(itr != entities.end()){
        entityRemoveQueue.push_back((itr - entities.begin()));
    }
}

inline int worldXOffset = 0;
inline int worldYOffset = 0;

inline std::map<Entity*, int> inventory;



//Entities - ID's
inline const byte KEY = 1;

#endif