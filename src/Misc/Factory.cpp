#include <Components/Position.h>
#include <Components/Center.h>
#include <Components/Renderable.h>
#include <Components/Scale.h>
#include <Components/Rotation.h>
#include <Components/Flip.h>
#include <Components/Velocity.h>
#include <Components/VelApproach.h>
#include <Components/Bounds.h>
#include <Components/Collideable.h>
#include <Components/Animation.h>
#include <Graphics/RenderWindow.h>
#include "Misc/Factory.h"

void Factory::createPlayer(ecs::EntityHandle& handle, int spawnX, int spawnY) {
    TextureAtlas& playerAtlas = atlasMap_.at("player");
    createSprite(handle, playerAtlas.getDefault());
    handle.get<Position>().x = spawnX;
    handle.get<Position>().y = spawnY;
    handle.add<Velocity>();
    handle.add<VelApproach>(100, 200);
    //handle.add<Bounds>();
    handle.add<Collideable>(true, false);
    handle.add<Animation>(playerAtlas);
}

void Factory::createSprite(ecs::EntityHandle &handle, TextureRegion &region) {
    handle.add<Center>(region.width/2, region.height/2);
    handle.add<Renderable>(region);
    handle.add<Position>();
    handle.add<Scale>();
    handle.add<Rotation>();
    handle.add<Flip>();
}

Factory::Factory(RenderWindow& window) {
    atlasMap_.emplace(std::piecewise_construct, std::forward_as_tuple("player"),
                      std::forward_as_tuple("assets/chars/player/atlas.xml", window));
}
