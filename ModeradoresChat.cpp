#include "includes.h"
#include "ModeradoresCht.hpp"

ModeradorChat* ModeradorChat::create() {
    auto ret = new ModeradorChat();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool ModeradorChat::init() {

    setKeypadEnabled(true);

    return true;
}

void ModeradorChat::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void ModeradorChat::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void ModeradorChat::switchToCustomLayerButton(CCObject* object) {
    auto layer = ModeradorChat::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.5f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}