#include "includes.h"
#include <string>
#include <iostream>
#include <gd.h>
#include <cocos2d.h>
#include <gd.h>
#include <fstream>
#include "mod_utils.hpp"
#include "GDPSWowDialog.hpp"

class HolaXD {
public:

    void Dialog(cocos2d::CCObject* pSender) { GDPSWowDialog::create()->show(); }

};

bool GDPSWowDialog::init() {
	auto winSize = CCDirector::sharedDirector()->getWinSize();

	if (!this->initWithColor({ 0, 0, 0, 75 })) return false;
	m_pLayer = CCLayer::create();
	this->addChild(m_pLayer);

	auto Flash = CCSprite::create("GJ_bigStar_glow_001.png");
    Flash->setPosition({284, 100});
	Flash->setColor({0, 0, 0});
    Flash->setZOrder(-5);
    Flash->setScale(31.475f);
	Flash->setOpacity(001);
    m_pLayer->addChild(Flash);

	auto bg = CCScale9Sprite::create("GJ_square02.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	bg->setContentSize({ 380.0f, 103.0f });
	bg->setPosition(winSize.width / 2, winSize.height / 2);
	m_pLayer->addChild(bg);

	m_pButtonMenu = CCMenu::create();
	m_pLayer->addChild(m_pButtonMenu,5);

	auto textBg = CCScale9Sprite::create("square02_001.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	textBg->setPosition({330.1, 160});
	textBg->setContentSize({ 320.0f, 100.f });
	textBg->setOpacity(60);
	textBg->setScaleX({0.840});
	textBg->setScaleY({0.808});
	m_pLayer->addChild(textBg);

	auto Titulo = CCLabelBMFont::create("The Keymaster", "bigFont.fnt", 320, kCCTextAlignmentCenter);
	Titulo->setScale(0.5f);
	Titulo->setPosition({265.24, 189.3});
	m_pLayer->addChild(Titulo);

	auto SpriteLogo = CCSprite::create("dialogIcon_002.png");
    SpriteLogo->setPosition({146.49, 160.0});
    SpriteLogo->setScale({1.1f});
	m_pLayer->addChild(SpriteLogo);

	auto SpriteTerminar = CCSprite::create("GJ_chatBtn_02_001.png");
    SpriteTerminar->setPosition({285, 110});
    SpriteTerminar->setScale({1.0f});
	SpriteTerminar->setOpacity(001);
	m_pLayer->addChild(SpriteTerminar);

	auto Texto1 = CCLabelBMFont::create("Q", "chatFont.fnt");
	Texto1->setPosition({-73.010, -9.3});
	Texto1->setOpacity(001);
	
	auto Texto2 = CCLabelBMFont::create("u", "chatFont.fnt");
	Texto2->setPosition({-63.3, -9.3});
	Texto2->setOpacity(001);

	auto Texto3 = CCLabelBMFont::create("i", "chatFont.fnt");
	Texto3->setPosition({-57, -9.3});
	Texto3->setOpacity(001);

	auto Texto4 = CCLabelBMFont::create("e", "chatFont.fnt");
	Texto4->setPosition({-51.5, -9.3});
	Texto4->setOpacity(001);

	auto Texto5 = CCLabelBMFont::create("r", "chatFont.fnt");
	Texto5->setPosition({-45, -9.3});
	Texto5->setOpacity(001);

	auto Texto6 = CCLabelBMFont::create("e", "chatFont.fnt");
	Texto6->setPosition({-38.9, -9.3});
	Texto6->setOpacity(001);

	auto Texto7 = CCLabelBMFont::create("s", "chatFont.fnt");
	Texto7->setPosition({-31.5, -9.3});
	Texto7->setOpacity(001);

	auto Texto8 = CCLabelBMFont::create("e", "chatFont.fnt");
	Texto8->setPosition({-19.36, -9.3});
	Texto8->setOpacity(001);

	auto Texto9 = CCLabelBMFont::create("n", "chatFont.fnt");
	Texto9->setPosition({-11.06, -9.3});
	Texto9->setOpacity(001);

	auto Texto10 = CCLabelBMFont::create("t", "chatFont.fnt");
	Texto10->setPosition({-4.5, -9.3});
	Texto10->setOpacity(001);

	auto Texto11 = CCLabelBMFont::create("r", "chatFont.fnt");
	Texto11->setPosition({0.39, -9.3});
	Texto11->setOpacity(001);

	auto Texto12 = CCLabelBMFont::create("a", "chatFont.fnt");
	Texto12->setPosition({6.52, -9.3});
	Texto12->setOpacity(001);
	
	auto Texto13 = CCLabelBMFont::create("r", "chatFont.fnt");
	Texto13->setPosition({12.87, -9.3});
	Texto13->setOpacity(001);

	auto Texto14 = CCLabelBMFont::create("?", "chatFont.fnt");
	Texto14->setPosition({19.78, -9.3});
	Texto14->setOpacity(001);

	//Animaciones
	Texto1->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.15, 250), CCFadeTo::create(0.2, 250), nullptr)));
	Texto2->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.25, 250), CCFadeTo::create(0.4, 250), nullptr)));
	Texto3->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.35, 250), CCFadeTo::create(0.6, 250), nullptr)));
	Texto4->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.45, 250), CCFadeTo::create(0.8, 250), nullptr)));
	Texto5->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.55, 250), CCFadeTo::create(1.0, 250), nullptr)));
	Texto6->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.65, 250), CCFadeTo::create(1.1, 250), nullptr)));
	Texto7->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.75, 250), CCFadeTo::create(1.2, 250), nullptr)));
	Texto8->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.75, 250), CCFadeTo::create(1.3, 250), nullptr)));
	Texto9->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.75, 250), CCFadeTo::create(1.4, 250), nullptr)));
	Texto10->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.75, 250), CCFadeTo::create(1.5, 250), nullptr)));
	Texto11->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.75, 250), CCFadeTo::create(1.6, 250), nullptr)));
	Texto12->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.75, 250), CCFadeTo::create(1.7, 250), nullptr)));
	Texto13->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.75, 250), CCFadeTo::create(1.8, 250), nullptr)));
	Texto14->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.75, 250), CCFadeTo::create(1.9, 250), nullptr)));
	SpriteTerminar->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(1.0f),  CCEaseInOut::create(CCFadeTo::create(1, 250), 2.1f)));
	Flash->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2.0f, 250), CCFadeTo::create(1, 250), nullptr)));

	m_pButtonMenu->addChild(Texto1);
	m_pButtonMenu->addChild(Texto2);
	m_pButtonMenu->addChild(Texto3);
	m_pButtonMenu->addChild(Texto4);
	m_pButtonMenu->addChild(Texto5);
	m_pButtonMenu->addChild(Texto6);
	m_pButtonMenu->addChild(Texto7);
	m_pButtonMenu->addChild(Texto8);
	m_pButtonMenu->addChild(Texto9);
	m_pButtonMenu->addChild(Texto10);
	m_pButtonMenu->addChild(Texto11);
	m_pButtonMenu->addChild(Texto12);
	m_pButtonMenu->addChild(Texto13);
	m_pButtonMenu->addChild(Texto14);

	/*
	auto CerraDialogo = CCSprite::create("GJ_chatBtn_001.png");

	auto CerraDialogoXdddxdd = gd::CCMenuItemSpriteExtra::create(
		CerraDialogo,
		this,
		menu_selector(NuevoLayer::switchToCustomLayerButton)
	);

	auto menuuwu = CCMenu::create();

	menuuwu->addChild(CerraDialogoXdddxdd);

	addChild(menuuwu);
	*/

	//menuuwu->setScale({3.5f});
	//CerraDialogo->setOpacity(001);

	//Aciiones XD

	this->runAction(CCSequence::create(CCDelayTime::create(2.70f), CCCallFuncO::create(this, callfuncO_selector(NuevoLayer::switchToCustomLayerButton), this), nullptr));

	this->setKeypadEnabled(false);
	this->setTouchEnabled(true);

	return true;
}

void GDPSWowDialog::onOk(cocos2d::CCObject*) {
	this->removeFromParentAndCleanup(true);
	//menu_selector(NuevoLayer::switchToCustomLayerButton);
}

void GDPSWowDialog::onTermsOfUse(cocos2d::CCObject*) {CCApplication::sharedApplication()->openURL("https://discord.gg/THmJJ75Kcc");}
void GDPSWowDialog::onPrivacyPolicy(cocos2d::CCObject*) { CCApplication::sharedApplication()->openURL("https://www.youtube.com/channel/UCJ73MdeBMcrLuSRE-A5TQqg"); }

GDPSWowDialog* GDPSWowDialog::create() {
	GDPSWowDialog* pRet = new GDPSWowDialog();
	if (pRet && pRet->init()) {
		pRet->autorelease();
		return pRet;
	}
	else {
		CC_SAFE_DELETE(pRet);
		return nullptr;
	}
}

//Otra Layer xdd

NuevoLayer* NuevoLayer::create() {
    auto ret = new NuevoLayer();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool NuevoLayer::init() {

	auto winSize = CCDirector::sharedDirector()->getWinSize();

	auto m_pLayer = CCLayer::create();

	this->addChild(m_pLayer);

	auto bg = CCScale9Sprite::create("GJ_square02.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	bg->setContentSize({ 380.0f, 103.0f });
	bg->setPosition(winSize.width / 2, winSize.height / 2);
	m_pLayer->addChild(bg);

	auto m_pButtonMenu = CCMenu::create();
	m_pLayer->addChild(m_pButtonMenu,5);

	auto textBg = CCScale9Sprite::create("square02_001.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	textBg->setPosition({330.1, 160});
	textBg->setContentSize({ 320.0f, 100.f });
	textBg->setOpacity(60);
	textBg->setScaleX({0.840});
	textBg->setScaleY({0.808});
	m_pLayer->addChild(textBg);

	auto Titulo = CCLabelBMFont::create("The Keymaster", "bigFont.fnt", 320, kCCTextAlignmentCenter);
	Titulo->setScale(0.5f);
	Titulo->setPosition({265.24, 189.3});
	m_pLayer->addChild(Titulo);

	auto SpriteLogo = CCSprite::create("dialogIcon_002.png");
    SpriteLogo->setPosition({146.49, 160.0});
    SpriteLogo->setScale({1.1f});
	m_pLayer->addChild(SpriteLogo);

	auto SpriteTerminar = CCSprite::create("GJ_chatBtn_02_001.png");
    SpriteTerminar->setPosition({285, 110});
    SpriteTerminar->setScale({1.0f});
	SpriteTerminar->setOpacity(001);
	m_pLayer->addChild(SpriteTerminar);

	auto Texto1 = CCLabelBMFont::create("O", "chatFont.fnt");
	Texto1->setPosition({-73.010, -9.3});
	Texto1->setOpacity(001);
	
	auto Texto2 = CCLabelBMFont::create("k", "chatFont.fnt");
	Texto2->setPosition({-63.3, -9.3});
	Texto2->setOpacity(001);

	auto Texto3 = CCLabelBMFont::create(".", "chatFont.fnt");
	Texto3->setPosition({-57, -9.3});
	Texto3->setOpacity(001);

	auto Texto4 = CCLabelBMFont::create(".", "chatFont.fnt");
	Texto4->setPosition({-51.5, -9.3});
	Texto4->setOpacity(001);

	auto Texto5 = CCLabelBMFont::create(".", "chatFont.fnt");
	Texto5->setPosition({-45, -9.3});
	Texto5->setOpacity(001);

	//Animaciones
	Texto1->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.15, 250), CCFadeTo::create(1.0, 250), nullptr)));
	Texto2->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.25, 250), CCFadeTo::create(2.5, 250), nullptr)));
	Texto3->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.35, 250), CCFadeTo::create(3.0, 250), nullptr)));
	Texto4->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.45, 250), CCFadeTo::create(4.0, 250), nullptr)));
	Texto5->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.55, 250), CCFadeTo::create(5.0, 250), nullptr)));
	SpriteTerminar->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(1.0f),  CCEaseInOut::create(CCFadeTo::create(6, 250), 5.0f)));

	m_pButtonMenu->addChild(Texto1);
	m_pButtonMenu->addChild(Texto2);
	m_pButtonMenu->addChild(Texto3);
	m_pButtonMenu->addChild(Texto4);
	m_pButtonMenu->addChild(Texto5);

	this->runAction(CCSequence::create(CCDelayTime::create(7.5f), CCCallFuncO::create(this, callfuncO_selector(LoadingLayerXD::switchToCustomLayerButton), this), nullptr));

	this->setKeypadEnabled(false);
	this->setTouchEnabled(true);

	GameSoundManager::sharedState()->stopBackgroundMusic();
	GameSoundManager::playEffect("chest08.ogg");
    return true;
}

void NuevoLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.0f, PopTransition::kPopTransitionFade);
}

void NuevoLayer::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void NuevoLayer::switchToCustomLayerButton(CCObject* object) {
    auto layer = NuevoLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

LoadingLayerXD* LoadingLayerXD::create() {
    auto ret = new LoadingLayerXD();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool LoadingLayerXD::init() {

	//Aqui el codigo xdd
	this->runAction(CCSequence::create(CCDelayTime::create(3.0f), CCCallFuncO::create(this, callfuncO_selector(DialogLayerXdw::switchToCustomLayerButton), this), nullptr));

    return true;
}

void LoadingLayerXD::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.0f, PopTransition::kPopTransitionFade);
}

void LoadingLayerXD::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void LoadingLayerXD::switchToCustomLayerButton(CCObject* object) {
    auto layer = LoadingLayerXD::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(2.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

//Nombre

DialogLayerXdw* DialogLayerXdw::create() {
    auto ret = new DialogLayerXdw();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool DialogLayerXdw::init() {

	auto winSize = CCDirector::sharedDirector()->getWinSize();

	auto m_pLayer = CCLayer::create();

	this->addChild(m_pLayer);

	auto bg = CCScale9Sprite::create("GJ_square05.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	bg->setContentSize({ 380.0f, 103.0f });
	bg->setPosition(winSize.width / 2, winSize.height / 2);
	m_pLayer->addChild(bg);

	auto m_pButtonMenu = CCMenu::create();
	m_pLayer->addChild(m_pButtonMenu,5);

	auto textBg = CCScale9Sprite::create("square02_001.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	textBg->setPosition({330.1, 160});
	textBg->setContentSize({ 320.0f, 100.f });
	textBg->setOpacity(60);
	textBg->setScaleX({0.840});
	textBg->setScaleY({0.808});
	m_pLayer->addChild(textBg);

	auto GM = gd::GJAccountManager::sharedState();
    std::string playerName = GM->m_sUsername;

	std::string CodigoTitulo = playerName;

	auto Titulo = CCLabelBMFont::create(CodigoTitulo.c_str(), "bigFont.fnt", 320, kCCTextAlignmentCenter);
	Titulo->setScale(0.5f);
	Titulo->setPosition({265.24, 189.3});
	m_pLayer->addChild(Titulo);

	auto SpriteLogo = CCSprite::create("dialogIcon_015.png");
    SpriteLogo->setPosition({146.49, 160.0});
    SpriteLogo->setScale({1.1f});
	m_pLayer->addChild(SpriteLogo);

	auto SpriteTerminar = CCSprite::create("GJ_chatBtn_02_001.png");
    SpriteTerminar->setPosition({285, 110});
    SpriteTerminar->setScale({1.0f});
	SpriteTerminar->setOpacity(001);
	m_pLayer->addChild(SpriteTerminar);

	auto Texto1 = CCLabelBMFont::create(".", "chatFont.fnt");
	Texto1->setPosition({-73.000, -9.3});
	Texto1->setOpacity(001);
	
	auto Texto2 = CCLabelBMFont::create(".", "chatFont.fnt");
	Texto2->setPosition({-63.000, -9.3});
	Texto2->setOpacity(001);

	auto Texto3 = CCLabelBMFont::create(".", "chatFont.fnt");
	Texto3->setPosition({-53.000, -9.3});
	Texto3->setOpacity(001);

	//Animaciones
	Texto1->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(1.5, 250), CCFadeTo::create(1.0, 250), nullptr)));
	Texto2->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2.7, 250), CCFadeTo::create(2.5, 250), nullptr)));
	Texto3->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(3.9, 250), CCFadeTo::create(3.0, 250), nullptr)));
	SpriteTerminar->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(1.0f),  CCEaseInOut::create(CCFadeTo::create(6, 250), 4.5f)));

	m_pButtonMenu->addChild(Texto1);
	m_pButtonMenu->addChild(Texto2);
	m_pButtonMenu->addChild(Texto3);

	this->runAction(CCSequence::create(CCDelayTime::create(5.0f), CCCallFuncO::create(this, callfuncO_selector(PartsLayerUWU::switchToCustomLayerButton), this), nullptr));

	this->setKeypadEnabled(false);
	this->setTouchEnabled(true);

	GameSoundManager::sharedState()->stopBackgroundMusic();
    return true;
}

void DialogLayerXdw::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.7f, PopTransition::kPopTransitionFade);
}

void DialogLayerXdw::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void DialogLayerXdw::switchToCustomLayerButton(CCObject* object) {
    auto layer = DialogLayerXdw::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionMoveInB::create(0.7f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

//Codigo Principal xdd
PartsLayerUWU* PartsLayerUWU::create() {
    auto ret = new PartsLayerUWU();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool PartsLayerUWU::init() {

	gd::GameManager::sharedState()->fadeInMusic("menuLoop3.mp3");

	auto backgroundSprite = CCSprite::create("GJ_gradientBG.png"); // bg ( background )
	auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();
    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    backgroundSprite->setAnchorPoint({0, 0});
    backgroundSprite->setColor({186, 186, 186});
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);
	
    return true;
}

void PartsLayerUWU::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.0f, PopTransition::kPopTransitionFade);
}

void PartsLayerUWU::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void PartsLayerUWU::switchToCustomLayerButton(CCObject* object) {
    auto layer = PartsLayerUWU::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(2.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}