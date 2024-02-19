#include "includes.h"
#include "AnunciosWG.hpp"

DownloadLayer* DownloadLayer::create() {
    auto ret = new DownloadLayer();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool DownloadLayer::init() {

    auto textlabelpw = CCLabelBMFont::create("Donwload GDPSWow", "bigFont.fnt");
    textlabelpw->setPosition({279 , 288});
    textlabelpw->setScale(0.75f);
    addChild(textlabelpw);

	auto button2 = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_starBtn_001.png"),
        this,
        menu_selector(HistoriaLayer::switchToCustomLayerButton)
    );

	button2->setPosition(100, 100);

	auto gdg = CCMenu::create();
	gdg->addChild(button2);
	gdg->setPosition(0, 0);
	addChild(gdg);

    auto backgroundSprite = CCSprite::create("game_bg_19_001.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({100, 100, 100});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(DownloadLayer::backButtonCallback)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    
    menu->setPosition({25, winSize.height - 25});

    addChild(menu);

    setKeypadEnabled(true);

    return true;
}

void DownloadLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void DownloadLayer::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void DownloadLayer::switchToCustomLayerButton(CCObject* object) {
    auto layer = DownloadLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.5f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

///GD Gravity #Layer 2

HistoriaLayer* HistoriaLayer::create() {
    auto ret = new HistoriaLayer();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool HistoriaLayer::init() {

    gd::GameManager::sharedState()->fadeInMusic("eggs\\menuHistoria.mp3");

    auto LogoTexto = CCSprite::create("eggs\\modo_historia.png");
    LogoTexto->setPosition({284.5, 290});
    LogoTexto->setScale({1.0f});
    addChild(LogoTexto);

    auto art1 = CCSprite::create("eggs\\GJ_sideArt_001.png");
    art1->setPosition({35, 34});
    art1->setScale({1.0f});
    art1->setColor({106, 106, 106});
    addChild(art1);

    auto art2 = CCSprite::create("eggs\\GJ_sideArt_001.png");
    art2->setPosition({534, 34});
    art2->setScaleX({-1.0f});
    art2->setColor({106, 106, 106});
    addChild(art2);

    auto art3 = CCSprite::create("eggs\\GJ_sideArt_001.png");
    art3->setPosition({534, 286});
    art3->setScaleX({-1.0f});
    art3->setScaleY({-1.0f});
    art3->setColor({106, 106, 106});
    addChild(art3);

    auto art4 = CCSprite::create("eggs\\GJ_sideArt_001.png");
    art4->setPosition({35, 286});
    art4->setScaleY({-1.0f});
    art4->setColor({106, 106, 106});
    addChild(art4);

    auto backgroundSprite = CCSprite::create("eggs\\bgHistoria.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({100, 100, 100});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(HistoriaLayer::backButtonCallback)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    
    menu->setPosition({24, 297});

    addChild(menu);

    setKeypadEnabled(true);

    return true;
}

void HistoriaLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void HistoriaLayer::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void HistoriaLayer::switchToCustomLayerButton(CCObject* object) {
    auto layer = HistoriaLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.5f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}