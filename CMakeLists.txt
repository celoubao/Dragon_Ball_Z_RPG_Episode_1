cmake_minimum_required(VERSION 2.8)
project(Dragon_Ball_Z_RPG_Edition)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        characters/saiyans/Broly.h
        characters/saiyans/Goku.h
        characters/saiyans/Vegeta.h
        characters/Saiyan.h
        components/moves/ErasorCannon.h
        components/moves/Kamehameha.h
        components/moves/GalicGun.h
        components/Character.h
        components/Move.h
        components/GameData.h
        components/loops/BattleLoop.h
        components/loops/GameSequence.h
        components/loops/VersusScreen.h
        linkedlist/Node.h
        linkedlist/Iterator.h
        linkedlist/LinkedList.h
        main.cpp components/loops/SimpleBattleLoop.h
        include/Terminal.h
        include/String.h components/loops/MainScreen.h components/moves/RandomMove.h components/moves/KiBlast.h components/loops/CharacterSelectionScreen.h components/CharacterSelectionCallback.h components/moves/KiCharge.h components/loops/AttackSequence.h)

add_executable(Dragon_Ball_Z_RPG_Edition ${SOURCE_FILES})
