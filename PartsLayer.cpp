#include "includes.h"
#include "PartsLayer.hpp"

PartsLayer* PartsLayer::create() {
    auto ret = new PartsLayer();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool PartsLayer::init() {

    auto textlabelpw = CCLabelBMFont::create("EGGS Parts 0/3", "bigFont.fnt");
    textlabelpw->setPosition({279 , 288});
    textlabelpw->setScale(0.75f);
    addChild(textlabelpw);

    auto backgroundSprite = CCSprite::create("GJ_gradientBG.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({18,21,113});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(PartsLayer::backButtonCallback)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    
    menu->setPosition({25, winSize.height - 25});

    addChild(menu);

    setKeypadEnabled(true);

    return true;
}

void PartsLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void PartsLayer::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void PartsLayer::switchToCustomLayerButton(CCObject* object) {
    auto layer = PartsLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.5f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}