#include "includes.h"
#include "MusicLayer.hpp"

MusicLayer* MusicLayer::create() {
    auto ret = new MusicLayer();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool MusicLayer::init() {

    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    m_pLrSize = cocos2d::CCSize();
	
    auto textlabelpw = CCLabelBMFont::create("MenuLoops", "bigFont.fnt");
    textlabelpw->setPosition(winSize.width / 2, 290);
    textlabelpw->setScale(0.75f);
    addChild(textlabelpw);

    auto bg = cocos2d::extension::CCScale9Sprite::create("GJ_square01.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	bg->setContentSize({ 300.0f, 175.0f });
	bg->setPosition(167, 210);
    bg->setScale({0.500f});
    addChild(bg);

    auto Background1 = cocos2d::extension::CCScale9Sprite::create("square02b_001.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	Background1->setContentSize({ 200.0f, 200.0f });
	Background1->setPosition(133, 210);
    Background1->setScale({0.350f});
    Background1->setColor({138, 71, 32});
    addChild(Background1);

    auto Imagen1 = CCSprite::create("GJ_musicOnBtn_001.png");
    Imagen1->setPosition({131, 210});
    Imagen1->setRotation(12);
    Imagen1->setScale({1.20f});
    addChild(Imagen1);

    auto Imagen2 = CCSprite::create("GJ_fxOnBtn_001.png");
    Imagen2->setPosition({200, 192});
    Imagen2->setScale({0.825f});
    addChild(Imagen2);

    auto texto1 = CCLabelBMFont::create("GDPSWow 0.1", "bigFont.fnt");
    texto1->setPosition({205, 234});
    texto1->setScale(0.275f);
    addChild(texto1);

    auto texto2 = CCLabelBMFont::create("MenuLoop 1", "bigFont.fnt");
    texto2->setPosition({204.5, 223});
    texto2->setScale(0.266f);
    addChild(texto2);

    ///MenuLoop 2

    auto bg2 = cocos2d::extension::CCScale9Sprite::create("GJ_square01.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	bg2->setContentSize({ 300.0f, 175.0f });
	bg2->setPosition(390, 210);
    bg2->setScale({0.500f});
    addChild(bg2);

    auto Background2 = cocos2d::extension::CCScale9Sprite::create("square02b_001.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	Background2->setContentSize({ 200.0f, 200.0f });
	Background2->setPosition(357, 210);
    Background2->setScale({0.350f});
    Background2->setColor({138, 71, 32});
    addChild(Background2);

    auto Imagen3 = CCSprite::create("GJ_musicOnBtn_001.png");
    Imagen3->setPosition({356.550, 210});
    Imagen3->setRotation(12);
    Imagen3->setScale({1.20f});
    addChild(Imagen3);

    auto Imagen4 = CCSprite::create("GJ_fxOnBtn_001.png");
    Imagen4->setPosition({426.500, 192});
    Imagen4->setScale({0.825f});
    addChild(Imagen4);

    auto texto3 = CCLabelBMFont::create("GDPSWow 0.2", "bigFont.fnt");
    texto3->setPosition({427.300, 234});
    texto3->setScale(0.275f);
    addChild(texto3);

    auto texto4 = CCLabelBMFont::create("MenuLoop 2", "bigFont.fnt");
    texto4->setPosition({426, 223});
    texto4->setScale(0.266f);
    addChild(texto4);

    ///MenuLoop 3

    auto bg3 = cocos2d::extension::CCScale9Sprite::create("GJ_square01.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	bg3->setContentSize({ 300.0f, 175.0f });
	bg3->setPosition(167, 85);
    bg3->setScale({0.500f});
    addChild(bg3);

    auto Background3 = cocos2d::extension::CCScale9Sprite::create("square02b_001.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	Background3->setContentSize({ 200.0f, 200.0f });
	Background3->setPosition(134, 83);
    Background3->setScale({0.350f});
    Background3->setColor({138, 71, 32});
    addChild(Background3);

    auto Imagen5 = CCSprite::create("GJ_musicOnBtn_001.png");
    Imagen5->setPosition({133.5, 82});
    Imagen5->setRotation(12);
    Imagen5->setScale({1.20f});
    addChild(Imagen5);

    auto Imagen6 = CCSprite::create("GJ_fxOnBtn_001.png");
    Imagen6->setPosition({201.5, 69});
    Imagen6->setScale({0.825f});
    addChild(Imagen6);

    auto texto5 = CCLabelBMFont::create("Others Song", "bigFont.fnt");
    texto5->setPosition({204.3, 110});
    texto5->setScale(0.325f);
    addChild(texto5);

    auto texto6 = CCLabelBMFont::create("MenuLoop 3", "bigFont.fnt");
    texto6->setPosition({205, 100});
    texto6->setScale(0.266f);
    addChild(texto6);

    auto bg4 = cocos2d::extension::CCScale9Sprite::create("GJ_square01.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	bg4->setContentSize({ 300.0f, 175.0f });
	bg4->setPosition(390, 85);
    bg4->setScale({0.500f});
    addChild(bg4);

    auto Background4 = cocos2d::extension::CCScale9Sprite::create("square02b_001.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	Background4->setContentSize({ 200.0f, 200.0f });
	Background4->setPosition(356, 85);
    Background4->setScale({0.350f});
    Background4->setColor({138, 71, 32});
    addChild(Background4);

    auto Imagen7 = CCSprite::create("GJ_musicOnBtn_001.png");
    Imagen7->setPosition({355.5, 84});
    Imagen7->setRotation(12);
    Imagen7->setScale({1.20f});
    addChild(Imagen7);

    auto Imagen8 = CCSprite::create("GJ_fxOnBtn_001.png");
    Imagen8->setPosition({425.5, 69});
    Imagen8->setScale({0.825f});
    addChild(Imagen8);

    auto texto7 = CCLabelBMFont::create("Test", "bigFont.fnt");
    texto7->setPosition({228.3, 234});
    texto7->setScale(0.225f);
    addChild(texto7);

    auto texto8 = CCLabelBMFont::create("MenuLoop 4", "bigFont.fnt");
    texto8->setPosition({229, 223});
    texto8->setScale(0.266f);
    addChild(texto8);

    auto backgroundSprite = CCSprite::create("MenuLoopsBackgrounds.png");
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({61, 65, 139});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(MusicLayer::backButtonCallback)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    
    menu->setPosition({25, winSize.height - 25});

    addChild(menu);

    setKeypadEnabled(true);

    return true;
}

void MusicLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void MusicLayer::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void MusicLayer::switchToCustomLayerButton(CCObject* object) {
    auto layer = MusicLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.5f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}