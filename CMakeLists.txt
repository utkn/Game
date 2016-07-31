cmake_minimum_required(VERSION 3.5)
project(Game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Graphics/RenderWindow.cpp include/Graphics/RenderWindow.h src/Graphics/Texture.cpp include/Graphics/Texture.h src/Graphics/TextureRegion.cpp include/Graphics/TextureRegion.h include/Graphics/Graphics.h src/ECS/Manager.cpp include/ECS/Manager.h src/ECS/Misc.cpp include/ECS/Misc.h include/ECS/Component.h src/ECS/EntityHandle.cpp include/ECS/EntityHandle.h src/ECS/BaseSystem.cpp include/ECS/BaseSystem.h include/ECS/System.h include/Components/Position.h include/ECS/ECS.h include/Components/Velocity.h include/Components/Renderable.h src/Systems/RenderSystem.cpp include/Systems/RenderSystem.h include/Components/Scale.h include/Components/Rotation.h include/Components/Control.h src/Systems/InputSystem.cpp include/Systems/InputSystem.h include/Components/Flip.h src/Systems/ControlSystem.cpp include/Systems/ControlSystem.h include/Components/Center.h src/Systems/MoveSystem.cpp include/Systems/MoveSystem.h include/Components/VelApproach.h src/Systems/ApproachSystem.cpp include/Systems/ApproachSystem.h include/Scenes/Scene.h src/Scenes/SceneManager.cpp include/Scenes/SceneManager.h src/Scenes/MapScene.cpp include/Scenes/MapScene.h include/Components/Bounds.h src/Misc/Tileset.cpp include/Misc/Tileset.h include/Math/Point.h src/Math/Polygon.cpp include/Math/Polygon.h src/Math/Point.cpp include/Components/Collideable.h src/Math/Vector.cpp include/Math/Vector.h src/Misc/Factory.cpp include/Misc/Factory.h src/Misc/TextureAtlas.cpp include/Misc/TextureAtlas.h include/Components/Animation.h)
add_executable(Game ${SOURCE_FILES})

include_directories(/usr/local/include/)
include_directories(include/)
set(BUILD_SHARED_LIBRARIES false)
find_library(sdl2 SDL2)
find_library(sdl2_image SDL2_image)
find_library(tmxparser tmxparser)
find_library(tinyxml tinyxml2)
find_library(zlib z)
find_library(pugixml pugixml)

target_link_libraries(Game ${sdl2} ${sdl2_image} ${tmxparser} ${tinyxml} ${zlib} ${pugixml})
