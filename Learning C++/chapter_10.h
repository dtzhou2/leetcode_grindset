#pragma once
#ifndef CHAPTER_10_H
#define CHAPTER_10_H
#include "enums.h"

void which_monster(Monster::MonsterType monster);
constexpr std::string_view getAnimalName(Animal animal);
void printNumberOfLegs(Animal animal);

#endif