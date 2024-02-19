#include "includes.h"
#include "ChatrLayerW.hpp"
#include "mod_utils.hpp"
#include <MinHook.h>
#include <gd.h>

ChatLayer2* ChatLayer2::create() {
    auto ret = new ChatLayer2();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool ChatLayer2::init() {

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    auto BackgroundChat1 = CCSprite::create("BackgroundChat.png");
    BackgroundChat1->setPosition({winSize.width / 2, winSize.height / 2});
    BackgroundChat1->setScale({1.700f});
    addChild(BackgroundChat1);

    auto IconToMorritw = CCSprite::create("ToMorritowIcon.png");
    IconToMorritw->setPosition({136, 256});
    IconToMorritw->setScale({0.650f});
    addChild(IconToMorritw);

    auto labeltextxdd = CCLabelBMFont::create("ToMorritow", "goldFont.fnt");
    labeltextxdd->setScale(0.7f);

    auto TextToMorritwButton = CCMenuItemSpriteExtra::create(labeltextxdd, this, menu_selector(ChatLayer2::onIconClicked));
	TextToMorritwButton->setTag(1);
	TextToMorritwButton->setPosition({203, 257});

    auto Texto1 = CCLabelBMFont::create("GDPSWow Actualizacion 0.3", "chatFont.fnt");
    Texto1->setPosition({218, 226});
    Texto1->setScale(1.0f);
    Texto1->setColor({250,255,6});
    addChild(Texto1);

    auto text2 = CCLabelBMFont::create("Announcements", "goldFont.fnt");
    text2->setPosition({290, 291});
    text2->setScale(0.884f);
    addChild(text2);

    auto Bagde1 = CCSprite::create("modBadge_06_001.png");
    Bagde1->setPosition({269, 255});
    Bagde1->setScale({1.0f});
    addChild(Bagde1);

    auto buttonESP = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("btn_chatHistory_001.png"),
        this,
        menu_selector(ChatLayer2::switchToCustomLayerButton)
    );

    auto buttonENG = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("btn_chatHistory_001.png"),
        this,
        menu_selector(ChatLayer3::switchToCustomLayerButton)
    );

    buttonESP->setPosition(89, 200);
    buttonENG->setPosition(89, 136);
    buttonESP->setColor({100, 100, 100});

    auto TextEsp = CCLabelBMFont::create("Esp", "bigFont.fnt");
    TextEsp->setPosition({90 , 233});
    TextEsp->setScale(0.425f);

    auto TextEng = CCLabelBMFont::create("Eng", "bigFont.fnt");
    TextEng->setPosition({90 , 158});
    TextEng->setScale(0.425f);

    auto menuidioma = CCMenu::create();
    menuidioma->addChild(buttonESP);
    menuidioma->addChild(buttonENG);
    menuidioma->addChild(TextEsp);
    menuidioma->addChild(TextEng);
    menuidioma->setPosition({0, 0});
    addChild(menuidioma);

    auto menufla = CCMenu::create();
    menufla->addChild(TextToMorritwButton);
    menufla->setPosition({0, 0});
    addChild(menufla);
    
    auto backgroundSprite = CCSprite::create("GJ_gradientBG.png");

    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({0, 102, 255});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(ChatLayer2::backButtonCallback)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    
    menu->setPosition({25, winSize.height - 25});

    addChild(menu);

    setKeypadEnabled(true);

    return true;
}

void ChatLayer2::onIconClicked(cocos2d::CCObject* pSender)
{

	switch(pSender->getTag())
	{
		// Info Badges
		case 1:
			ProfilePage::create(1, false)->show();
		break;
	}
}

void ChatLayer2::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.0f, PopTransition::kPopTransitionFade);
}

void ChatLayer2::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void ChatLayer2::switchToCustomLayerButton(CCObject* object) {
    auto layer = ChatLayer2::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

//Layer 2

ChatLayer3* ChatLayer3::create() {
    auto ret = new ChatLayer3();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool ChatLayer3::init() {

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    auto BackgroundChat1 = CCSprite::create("BackgroundChat.png");
    BackgroundChat1->setPosition({winSize.width / 2, winSize.height / 2});
    BackgroundChat1->setScale({1.700f});
    addChild(BackgroundChat1);

    auto labeltextxdd = CCLabelBMFont::create("ToMorritow", "goldFont.fnt");
    labeltextxdd->setScale(0.7f);

    auto TextToMorritwButton = CCMenuItemSpriteExtra::create(labeltextxdd, this, menu_selector(ChatLayer3::onIconClicked));
	TextToMorritwButton->setTag(1);
	TextToMorritwButton->setPosition({203, 257});

    auto IconToMorritw = CCSprite::create("ToMorritowIcon.png");
    IconToMorritw->setPosition({136, 256});
    IconToMorritw->setScale({0.650f});
    addChild(IconToMorritw);

    auto Texto1 = CCLabelBMFont::create("GDPSWow Update 0.3", "chatFont.fnt");
    Texto1->setPosition({199, 226});
    Texto1->setScale(1.0f);
    Texto1->setColor({250,255,6});
    addChild(Texto1);

    auto text2 = CCLabelBMFont::create("Announcements", "goldFont.fnt");
    text2->setPosition({290, 291});
    text2->setScale(0.884f);
    addChild(text2);

    auto Bagde1 = CCSprite::create("modBadge_06_001.png");
    Bagde1->setPosition({269, 255});
    Bagde1->setScale({1.0f});
    addChild(Bagde1);

    auto buttonESP = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("btn_chatHistory_001.png"),
        this,
        menu_selector(ChatLayer2::switchToCustomLayerButton)
    );

    auto buttonENG = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("btn_chatHistory_001.png"),
        this,
        menu_selector(ChatLayer3::switchToCustomLayerButton)
    );

    buttonESP->setPosition(89, 200);
    buttonENG->setPosition(89, 136);
    buttonENG->setColor({100, 100, 100});

    auto TextEsp = CCLabelBMFont::create("Esp", "bigFont.fnt");
    TextEsp->setPosition({90 , 233});
    TextEsp->setScale(0.425f);

    auto TextEng = CCLabelBMFont::create("Eng", "bigFont.fnt");
    TextEng->setPosition({90 , 158});
    TextEng->setScale(0.425f);

    auto menuidioma = CCMenu::create();
    menuidioma->addChild(buttonESP);
    menuidioma->addChild(buttonENG);
    menuidioma->addChild(TextEsp);
    menuidioma->addChild(TextEng);
    menuidioma->setPosition({0, 0});
    addChild(menuidioma);

    auto menufla = CCMenu::create();
    menufla->addChild(TextToMorritwButton);
    menufla->setPosition({0, 0});
    addChild(menufla);
    
    auto backgroundSprite = CCSprite::create("GJ_gradientBG.png");

    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({0, 102, 255});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(ChatLayer3::backButtonCallback)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    
    menu->setPosition({24, winSize.height - 30});

    addChild(menu);

    setKeypadEnabled(true);

    return true;
}

void ChatLayer3::onIconClicked(cocos2d::CCObject* pSender)
{

	switch(pSender->getTag())
	{
		// Info Badges
		case 1:
			ProfilePage::create(1, false)->show();
		break;
	}
}

void ChatLayer3::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.0f, PopTransition::kPopTransitionFade);
}

void ChatLayer3::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void ChatLayer3::switchToCustomLayerButton(CCObject* object) {
    auto layer = ChatLayer3::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}