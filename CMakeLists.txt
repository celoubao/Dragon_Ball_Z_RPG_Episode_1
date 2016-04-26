cmake_minimum_required(VERSION 2.8)
project(Dragon_Ball_Z_RPG_Edition)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        characters/Frieza.h
        characters/saiyans/Goku.h
        characters/saiyans/SSJGoku.h
        characters/saiyans/Vegeta.h
        characters/Saiyan.h
        components/moves/DeathBeam.h
        components/moves/Kamehameha.h
        components/moves/SuperKamehameha.h
        components/moves/GalicGun.h
        components/Character.h
        components/Move.h
        components/GameData.h
        components/loops/BattleLoop.h
        components/loops/GameSequence.h
        components/loops/VersusScreen.h
        main.cpp components/loops/SimpleBattleLoop.h
        include/Terminal.h
        include/String.h components/loops/MainScreen.h
        components/moves/KiBlast.h components/loops/CharacterSelectionScreen.h components/CharacterSelectionCallback.h components/moves/KiCharge.h components/loops/AttackSequence.h components/moves/Block.h components/modes/FightMode.h components/modes/FreeForAll.h components/modes/ModeSelectionScreen.h components/moves/Kaioken.h components/moves/CharacterStates.h)

add_executable(Dragon_Ball_Z_RPG_Edition ${SOURCE_FILES})
