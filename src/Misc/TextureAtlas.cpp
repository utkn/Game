#include <iostream>
#include <fstream>
#include <sstream>
#include <pugixml.hpp>
#include "Misc/TextureAtlas.h"

TextureAtlas::TextureAtlas(std::string const& path, RenderWindow& window) {
    std::ifstream fs(path);
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load(fs);
    fs.close();
    if(!result) {
        std::cerr << "Error loading atlas: " << result.description();
        exit(1);
    }
    pugi::xml_node txAtlasNode = doc.child("TextureAtlas");
    std::string dirPath = path.substr(0, path.find_last_of("/\\") + 1);
    std::string imgPath = dirPath + std::string(txAtlasNode.attribute("imagePath").as_string());
    texture_.reset(new Texture(window, imgPath)); // Load the atlas image.
    for(auto& spriteNode :  doc.child("TextureAtlas").children()) {
        std::string name = spriteNode.attribute("n").as_string();
        if(regions_.size() == 0) defaultRegion_ = name; // First region is the default one.
        TextureRegion region(*texture_.get(), spriteNode.attribute("x").as_int(), spriteNode.attribute("y").as_int(),
                             spriteNode.attribute("w").as_int(), spriteNode.attribute("h").as_int());
        regions_.insert({name, region});
    }
}

TextureRegion& TextureAtlas::getRegion(std::string const& name) {
    return regions_.at(name);
}

TextureRegion& TextureAtlas::getDefault() {
    return regions_.at(defaultRegion_);
}
