CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(PolycodeStandalone)

SET(POLYCODE_RELEASE_DIR ${PolycodeStandalone_SOURCE_DIR}/../Release/${CMAKE_SYSTEM_NAME})
SET(CMAKE_INSTALL_PREFIX ${POLYCODE_RELEASE_DIR}/Standalone/)

INSTALL(FILES ../LICENSE.txt
        DESTINATION ./)

INSTALL(DIRECTORY ${PolycodeStandalone_SOURCE_DIR}/../Modules/Bindings/2DPhysics/API DESTINATION Modules/Physics2D)
INSTALL(DIRECTORY ${PolycodeStandalone_SOURCE_DIR}/../Modules/Bindings/3DPhysics/API DESTINATION Modules/Physics3D)

INSTALL(DIRECTORY ${PolycodeStandalone_SOURCE_DIR}/../Examples/Lua DESTINATION Examples)

IF(MSVC OR MINGW)

  INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Core/Dependencies/bin/OpenAL32.dll DESTINATION Player)
  INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Core/Dependencies/bin/OpenAL32.dll DESTINATION Publish/Win)

	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/PolycodePlayer.exe DESTINATION Player)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/default.pak DESTINATION Player)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/hdr.pak DESTINATION Player)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/api.pak DESTINATION Player)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/StandalonePlayer.exe DESTINATION Publish/Win)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/default.pak DESTINATION Publish/Win)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/hdr.pak DESTINATION Publish/Win)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/api.pak DESTINATION Publish/Win)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/main.polyapp DESTINATION Publish/Win)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Bindings/Lua/Modules/2DPhysics/lib/Physics2D.dll DESTINATION Modules/Physics2D/Lib/win)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Bindings/Lua/Modules/3DPhysics/lib/Physics3D.dll DESTINATION Modules/Physics3D/Lib/win)

INSTALL(PROGRAMS ${POLYCODE_RELEASE_DIR}/Framework/Tools/polybuild.exe DESTINATION Bin)
INSTALL(PROGRAMS ${POLYCODE_RELEASE_DIR}/Framework/Tools/polyimport.exe DESTINATION Bin)
INSTALL(DIRECTORY ${PolycodeStandalone_SOURCE_DIR}/../Assets/Templates/Lua DESTINATION Template)


ELSEIF(APPLE)

	INSTALL(DIRECTORY ${POLYCODE_RELEASE_DIR}/Framework/Player/PolycodePlayer.app DESTINATION Player USE_SOURCE_PERMISSIONS)
	INSTALL(DIRECTORY ${POLYCODE_RELEASE_DIR}/Framework/Player/StandalonePlayer.app DESTINATION Publish/Mac USE_SOURCE_PERMISSIONS)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Bindings/Lua/Modules/2DPhysics/lib/Physics2D.dylib DESTINATION Modules/Physics2D/Lib/osx)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Bindings/Lua/Modules/3DPhysics/lib/Physics3D.dylib DESTINATION Modules/Physics3D/Lib/osx)

INSTALL(PROGRAMS ${POLYCODE_RELEASE_DIR}/Framework/Tools/polybuild DESTINATION Bin)
INSTALL(PROGRAMS ${POLYCODE_RELEASE_DIR}/Framework/Tools/polyimport DESTINATION Bin)
INSTALL(DIRECTORY ${PolycodeStandalone_SOURCE_DIR}/../Assets/Templates/Lua DESTINATION Template)

ELSE(MSVC OR MINGW)

	INSTALL(PROGRAMS ${POLYCODE_RELEASE_DIR}/Framework/Player/PolycodePlayer DESTINATION Player)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/default.pak DESTINATION Player)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/hdr.pak DESTINATION Player)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/api.pak DESTINATION Player)
	INSTALL(PROGRAMS ${POLYCODE_RELEASE_DIR}/Framework/Player/StandalonePlayer DESTINATION Publish/Linux)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/default.pak DESTINATION Publish/Linux)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/hdr.pak DESTINATION Publish/Linux)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/api.pak DESTINATION Publish/Linux)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Player/main.polyapp DESTINATION Publish/Linux)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Bindings/Lua/Modules/2DPhysics/lib/Physics2D.so DESTINATION Modules/Physics2D/Lib/linux)
	INSTALL(FILES ${POLYCODE_RELEASE_DIR}/Framework/Bindings/Lua/Modules/3DPhysics/lib/Physics3D.so DESTINATION Modules/Physics3D/Lib/linux)

INSTALL(PROGRAMS ${POLYCODE_RELEASE_DIR}/Framework/Tools/polybuild DESTINATION Bin)
INSTALL(PROGRAMS ${POLYCODE_RELEASE_DIR}/Framework/Tools/polyimport DESTINATION Bin)
INSTALL(DIRECTORY ${PolycodeStandalone_SOURCE_DIR}/../Assets/Templates/Lua DESTINATION Template)


ENDIF(MSVC OR MINGW)


