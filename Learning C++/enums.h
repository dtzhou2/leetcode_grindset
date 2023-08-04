#pragma once
#ifndef ENUMS_H
#define ENUMS_H

namespace Monster{
    enum MonsterType{
        orc, // This will be assigned integral value 0
        goblin, // Integral Value: 1
        troll, // Integral Value: 2
        ogre, // Integral Value: 3
        skeleton, // Integral Value: 4
    };
}

// This is a scoped enumeration instead of an unscoped enumeration
// This means it is strongly typed and strongly scoped
// Enumerators are in the enumerations scope and cannot be implicitly converted to integral types
enum class Fruits{
    banana,
    apple,
    peach,
    pear,
};

enum class Animal {
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

#endif