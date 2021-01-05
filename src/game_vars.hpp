#ifndef GAME_VARS_HPP
#define GAME_VARS_HPP

#include <vector>
#include <memory>
#include "entity.hpp"

inline std::vector<std::unique_ptr<Entity>> entities;
inline int worldXOffset = 0;
inline int worldYOffset = 0;

#endif