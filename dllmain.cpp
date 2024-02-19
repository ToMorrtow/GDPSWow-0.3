#define WIN32_LEAN_AND_MEAN
#include <random>
#include <windows.h>
#pragma warning(push, 0)
#include <cocos2d.h>
#pragma warning(pop)
#include <iostream>
#include "includes.h"
#include <MinHook.h>
#include "custom-layer.hpp"
#include "ToMorritowLayerc.hpp"
#include "GatoSexoLayer.hpp"
#include "PartsLayer.hpp"
#include "server.hpp"
#include "TOSPopup.hpp"
#include "mod_utils.hpp"
#include "hooks.hpp"
#include "LoadingLayer.hpp"
#include "ChatrLayerW.hpp"
#include "MusicLayer.hpp"
#include "AnunciosWG.hpp"
#include "ModeradoresCht.hpp"
#include "GDPSWowDialog.hpp"
#include <gd.h>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "SimpleIni.h"
#include <iostream>

using namespace std;
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace gd;

const char* MenuLayerExt::onFacebook = "https://discord.gg/THmJJ75Kcc";
const char* MenuLayerExt::onTwitter = "https://discord.gg/THmJJ75Kcc";
const char* MenuLayerExt::onYouTube = "https://discord.gg/THmJJ75Kcc";

bool write_bytes(
    const std::uintptr_t address,
    std::vector<uint8_t> const& bytes)
{
    return WriteProcessMemory(
        GetCurrentProcess(),
        reinterpret_cast<LPVOID>(address),
        bytes.data(),
        bytes.size(),
        nullptr);
}

class ChatLayerw : public cocos2d::CCLayer {
public:
    void flalertchatxdd(cocos2d::CCObject* pSender) {
        auto GM = gd::GameManager::sharedState();
        gd::FLAlertLayer::create(nullptr, "Moderators Chat", "Close", nullptr, "Descriptcion")->show();
    }
};

class UserIDLayerw : public cocos2d::CCLayer {
    public:
     void IDAcconuntspwxdd(cocos2d::CCObject* pSender) {
    auto GM = gd::GJAccountManager::sharedState();
     std::string playerName = GM->m_sUsername;
     std::string playerContra = GM->m_sPassword;
     std::string code = "<cl>Name: " + playerName + "</c>\n<cj>Contrasena: " + playerContra + "</c>"; // Concatena el nombre en el mensaje
     auto uwu = gd::FLAlertLayer::create(nullptr, "Extras", "ok", nullptr, code);
     uwu->m_pLayer->runAction(
        CCRepeatForever::create(
            CCSequence::create(
                CCEaseSineInOut::create(CCMoveBy::create(1.0f, CCPoint(0, 3))),
                CCEaseSineInOut::create(CCMoveBy::create(2.0f, CCPoint(0, -3))),
                nullptr
            )
        )
    ); //for fun xdd
     uwu->show();
     }
};

class BienvenidaWaos : public cocos2d::CCLayer {
public:
    void ShowTosTuppww(cocos2d::CCObject* pSender) {
        auto GM = gd::GameManager::sharedState();
        auto code = "GDPSWow Version 0.3";
        gd::FLAlertLayer::create(nullptr, "GDPSWow", "ok", nullptr, code)->show();
    }
};

class ToMorritowCdee {
public:

    void Dialog(cocos2d::CCObject* pSender) { GDPSWowDialog::create()->show(); }
    void Updated(cocos2d::CCObject* pSender) { if (!GameManager::sharedState()->getUGV("30")) { TOSPopup::create()->show(); } }

};

const char* version = "3.05";

#include <cstring>
#include <string>
#include <map>

// Firma del servidor original
const char* originalServerSignature = "gdpseditor.com";

const char* replaceServers(const char* original) {
    const char* gdpsURL = "www.boomlings.com/database";

    // Verifica si la cadena original contiene la firma del servidor original
    const char* found = strstr(original, originalServerSignature);
    if (found != nullptr) {
        return original; // No reemplaza si ya contiene la firma
    }

    // Define la nueva URL del servidor para PC
    const char* newServerURL = "gdpswowwaaa.ps.fhgdps.com";

    // Encuentra la posición inicial de la URL
    found = strstr(original, "https://");
    if (found != nullptr) {
        // Calcula la longitud de la parte de la URL a reemplazar
        size_t lengthToReplace = strlen(found);

        // Calcula la longitud de la nueva URL
        size_t newURLLength = strlen(newServerURL);

        // Calcula la longitud total de la cadena resultante
        size_t totalLength = strlen(original) + newURLLength - lengthToReplace;

        // Crea una nueva cadena con el tamaño necesario
        char* result = new char[totalLength + 1];

        // Copia la parte de la cadena antes de la URL original
        strncpy(result, original, found - original);
        result[found - original] = '\0'; // Agrega un terminador nulo

        // Concatena la nueva URL
        strcat(result, newServerURL);

        // Concatena la parte de la cadena después de la URL original
        strcat(result, found + lengthToReplace);

        return result;
    }

    return original;
}

std::map<std::string, std::string> database;

void ChangeFileName(std::string& fileName) {
    // Busca el nombre de archivo en la base de datos
    auto it = database.find(fileName);
    
    if (it != database.end()) {
        // Si se encuentra en la base de datos, cambia el nombre
        fileName = it->second;
    }
}

int main() {

    const char* originalURL = "https://www.boomlings.com/database";
    const char* modifiedURL = replaceServers(originalURL);

    std::string fileName = "example.txt";
    ChangeFileName(fileName);

    return 0;
}


auto winSize = CCDirector::sharedDirector()->getWinSize();

bool(__thiscall* CreatorLayer_init)(CCLayer* self);
bool __fastcall CreatorLayer_init_H(CCLayer* self, void*) {
    if (!CreatorLayer_init(self)) return false;

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    self->runAction(CCSequence::create(CCDelayTime::create(0.55f), CCCallFuncO::create(self, callfuncO_selector(ToMorritowCdee::Updated), self), nullptr));


    //Sai

    // CCMenu de todos los botones
    auto allBtns = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(1));

    // Tus botones custom
    auto events = CCSprite::createWithSpriteFrameName("GJ_eventBtn_001.png");
    events->setScale(0.85f);
    auto eventBtn = gd::CCMenuItemSpriteExtra::create(events, self, menu_selector(CustomLayer::switchToCustomLayerButton));
    allBtns->addChild(eventBtn);

    auto map = CCSprite::createWithSpriteFrameName("GJ_mapBtn_001.png");
    map->setScale(events->getScale());
    auto mapBtn = gd::CCMenuItemSpriteExtra::create(map, self, menu_selector(Layer2Waos::switchToCustomLayerButton));
    allBtns->addChild(mapBtn);

    auto parts = CCSprite::createWithSpriteFrameName("GJ_pathsBtn_001.png");
    parts->setScale(events->getScale());
    auto pathsBtn = gd::CCMenuItemSpriteExtra::create(parts, self, menu_selector(ToMorritowCdee::Dialog));
    allBtns->addChild(pathsBtn);

    //ToMorritow

    auto buttonChatSprite = CCSprite::createWithSpriteFrameName("GJ_chatBtn_001.png");
    
    auto Chatbutton = gd::CCMenuItemSpriteExtra::create(
        buttonChatSprite,
        self,
        menu_selector(ChatLayer2::switchToCustomLayerButton)
    );

    auto MusicSprite = CCSprite::createWithSpriteFrameName("GJ_musicOnBtn_001.png");
    
    auto Musicbutton = gd::CCMenuItemSpriteExtra::create(
        MusicSprite,
        self,
        menu_selector(MusicLayer::switchToCustomLayerButton)
    );

    MusicSprite->setScale({1.200f});

    auto cbuttonmenu = CCMenu::create();
    cbuttonmenu->addChild(Chatbutton);
    cbuttonmenu->addChild(Musicbutton);
    cbuttonmenu->setPosition(286.5, 160);
    cbuttonmenu->setZOrder(3);
    self->addChild(cbuttonmenu);

    // Botones de la CreatorLayer
    auto CreateBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(0));
    auto SaveBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(1));
    auto ScoresBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(2));
    auto QuestsBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(3));
    auto DailyBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(4));
    auto WeeklyBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(5));
    auto SearchBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(9));
    auto GauntletshBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(10));
    auto mapPackBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(8));
    auto TheSafeBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(6));
    auto feacturedBtn = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(allBtns->getChildren()->objectAtIndex(7));

    // Linea de arriba
    CreateBtn->setPosition(-150, 90);
    SaveBtn->setPosition(150, 90);
    ScoresBtn->setPosition(50, 90);
    QuestsBtn->setPosition(-50, 90);

    // Linea de en medio
    mapBtn->setPosition(-180, 0);
    DailyBtn->setPosition(-90, 0);
    WeeklyBtn->setPosition(0, 0);
    eventBtn->setPosition(90, 0);
    pathsBtn->setPosition(180, 0);

    // Linea de abajo
    TheSafeBtn->setPosition(-180, -90);
    feacturedBtn->setPosition(-90, -90);
    GauntletshBtn->setPosition(0, -90);
    mapPackBtn->setPosition(90, -90);
    SearchBtn->setPosition(180, -90);

    // Costados

    Chatbutton->setPosition(-255 , -128); 
    Chatbutton->setZOrder(3);

    Musicbutton->setPosition(-255 , -75); 
    Musicbutton->setZOrder(3);

    return true;
}

bool (__thiscall* GatoSexoLayer_init)(CCLayer* self);
bool __fastcall GatoSexoLayer_init_H(CCLayer* self, void*) {
  
    if (!GatoSexoLayer_init(self)) return false;

    auto DiscordChilds = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(4));

    auto testxdddw = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(5));

    auto waaa = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(2));

    auto Logositoxdd = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(1));

    auto FondoMenu = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(0));

    auto FondoBGSprite = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(FondoMenu->getChildren()->objectAtIndex(0));

    // Limpia la memoria del sprite original si es necesario
    // delete spriteToChange;  // Esto es opcional, dependiendo de tu necesidad

    Logositoxdd->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCScaleTo::create(0.40000001, 1.0, 1.0)), 
    CCEaseSineInOut::create(CCScaleTo::create(0.40000001, 1.04, 1.04)), nullptr)));

    auto NewButtonSprite = CCSprite::createWithSpriteFrameName("communityCreditsBtn_001.png");

    auto buttonpw = gd::CCMenuItemSpriteExtra::create(
        NewButtonSprite,
        self,
        menu_selector(GatoSexoLayer::switchToCustomLayerButton)
    );

    buttonpw->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCScaleTo::create(1.0f, 1.05f)), 
    CCEaseSineInOut::create(CCScaleTo::create(1.0, 1.0f)), nullptr)));

    waaa->addChild(buttonpw);
    buttonpw->setPosition(256, 124);

    auto testpwxddd = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(testxdddw->getChildren()->objectAtIndex(0));

    testpwxddd->setPosition({ 100, 100 });

    auto WaosNewSprite = CCSprite::createWithSpriteFrameName("GJ_moreGamesBtn_001.png");

    auto Donwloadbutton = gd::CCMenuItemSpriteExtra::create(
        WaosNewSprite,
        self,
        menu_selector(DownloadLayer::switchToCustomLayerButton)
    );

    waaa->addChild(Donwloadbutton);
    Donwloadbutton->setScale({0.877f});
    Donwloadbutton->setPosition({235, -133});

    /HORA ACTUAL

    //Version 1
    //auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    //std::tm* timeInfo = std::localtime(&currentTime);

    //std::stringstream ss;
    //ss << std::put_time(timeInfo, "%H:%M:%S");
    //std::string horaActual = ss.str();

    //Version 2

    /*
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm* timeInfo = std::localtime(&currentTime);

    std::ostringstream formattedTimeStream;
    formattedTimeStream << std::setfill('0') << std::setw(2) << timeInfo->tm_hour << ":"
                        << std::setfill('0') << std::setw(2) << timeInfo->tm_min << ":"
                        << std::setfill('0') << std::setw(2) << timeInfo->tm_sec;

    std::string horaActual = formattedTimeStream.str();

    std::cout << "Hora actual: " << horaActual << std::endl;

    
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm* timeInfo = std::localtime(&currentTime);

    char formattedTime[12]; // hh:mm:ss AM/PM\0
    std::string amPm = (timeInfo->tm_hour < 12) ? "AM" : "PM";
    int hour = (timeInfo->tm_hour < 12) ? timeInfo->tm_hour : timeInfo->tm_hour - 12;
    if (hour == 0) {
    hour = 12;
    }
    std::snprintf(formattedTime, sizeof(formattedTime), "%.02d:%.02d:%.02d %s", hour, timeInfo->tm_min, timeInfo->tm_sec, amPm.c_str());

    std::string horaActual = formattedTime;
    */

    //version

    ///"GDPSWow Version 0.3"

    //auto labeltextxdd = CCLabelBMFont::create(horaActual.c_str(), "bigFont.fnt");

    auto labeltextxdd = CCLabelBMFont::create("Hola", "bigFont.fnt");
    labeltextxdd->setPosition({0 , -160});
    labeltextxdd->setScale(0.35f);

    waaa->addChild(labeltextxdd);

    //s

    auto BackgroundIniciouwu = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(0));

    auto Players = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(BackgroundIniciouwu->getChildren()->objectAtIndex(11));
    Players->setOpacity(180);

    ///Android

    ///auto level = GJGameLevel::create();
    ///CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, PlayLayer::scene(level)));

    gd::GameManager::sharedState()->fadeInMusic("menuLoop.mp3");

    return true;
}

class ToMorritw : public cocos2d::CCLayer {
public:
    void FLAlert(cocos2d::CCObject* pSender) {
        auto GM = gd::GameManager::sharedState();
        auto code = "Activate -> [ AFK: ON ]";
        gd::FLAlertLayer::create(nullptr, "Descanzo", "Ok", nullptr, code)->show();
    }
};

bool (__thiscall* PauseLayer_init)(CCLayer* self);
bool __fastcall PauseLayer_init_H(CCLayer* self, void*) {
  
    if (!PauseLayer_init(self)) return false;

    auto allBtns = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(8));

    auto LabelText1 = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(9));

    LabelText1->setPosition({35.560, 245.2});
    LabelText1->setScale({0.330f});

    auto LabelText2 = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(10));

    LabelText2->setPosition({35.560, 225});
    LabelText2->setScale({0.330f});

    auto LabelText3 = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(11));

    LabelText3->setPosition({35.560, 204.640});
    LabelText3->setScale({0.330f});

    auto ButtonPw = reinterpret_cast<CCMenu*>(self->getChildren()->objectAtIndex(12));

    auto Button1 = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(ButtonPw->getChildren()->objectAtIndex(0));

    Button1->setPosition({-258, 84});
    Button1->setScale({0.650f});

    auto Button2 = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(ButtonPw->getChildren()->objectAtIndex(1));

    Button2->setPosition({-258, 63.79});
    Button2->setScale({0.650f});

    auto Button3 = reinterpret_cast<gd::CCMenuItemSpriteExtra*>(ButtonPw->getChildren()->objectAtIndex(2));

    Button3->setPosition({-258, 43.68});
    Button3->setScale({0.650f});
    
    auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_musicOnBtn_001.png");

    auto button = gd::CCMenuItemSpriteExtra::create(
        buttonSprite,
        self,
        menu_selector(ToMorritw::FLAlert)
    );

    auto button2 = gd::CCMenuItemSpriteExtra::create(
        buttonSprite,
        self,
        menu_selector(MenuLayer::onOptions)
    );
    
    button->setPosition({-243, 151});
    button2->setPosition({-197.06, 151});

    allBtns->addChild(button);
    allBtns->addChild(button2);

    auto AnuncioLabel = CCLabelBMFont::create("GDPSWow Mods 0.3", "bigFont.fnt");
    AnuncioLabel->setPosition({0, -17});
    AnuncioLabel->setScale(0.325f);
    self->addChild(AnuncioLabel);

    AnuncioLabel->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(20.0f),  CCEaseInOut::create(CCMoveBy::create(1.0f, { 291, 50 }), 2.0f)));

    return true;
}

const char* (__thiscall* LoadingLayer_getString_org)(LoadingLayer*);
const char* __fastcall LoadingLayer_getString_h(LoadingLayer* self, void*) {

    auto GM = gd::GJAccountManager::sharedState();
    std::string playerName = GM->m_sUsername;

    return "Bienvenido al <co>GDPSWow</c> >w< "; // + playerName).c_str()
}

bool (__thiscall* GJGarageLayer_init)(cocos2d::CCLayer* self);

bool __fastcall GJGarageLayer_init_H(cocos2d::CCLayer* self, void*) {

    if (!GJGarageLayer_init(self)) return false;

    cocos2d::CCDictionary* statDict = gd::GameStatsManager::sharedState()->m_pPlayerStats;
    int demonCount = statDict->valueForKey("5")->intValue();

    auto demonLabel = cocos2d::CCLabelBMFont::create(std::to_string(demonCount).c_str(), "bigFont.fnt");

    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

    int winSizeWidth = winSize.width;
    int winSizeHeight = winSize.height;

    demonLabel->setPosition(winSizeWidth - 36, winSizeHeight - 114);
    demonLabel->setAnchorPoint({ 1.f, 0.5f });
    demonLabel->setScale(0.45);

    cocos2d::CCSprite* demonSprite = cocos2d::CCSprite::createWithSpriteFrameName("diffIcon_06_btn_001.png");

    demonSprite->setPosition({ winSizeWidth - 20.f, winSizeHeight - 114.f });
    demonSprite->setAnchorPoint({ 0.5f, 0.5f });
    demonSprite->setScale(0.5);

    self->addChild(demonLabel);
    self->addChild(demonSprite);

    auto buttonIDSprite = CCSprite::createWithSpriteFrameName("accountBtn_settings_001.png");
    
    auto IDbutton = gd::CCMenuItemSpriteExtra::create(
        buttonIDSprite,
        self,
        menu_selector(UserIDLayerw::IDAcconuntspwxdd)
    );

    auto usermenu = CCMenu::create();
    usermenu->addChild(IDbutton);
    self->addChild(usermenu);

    usermenu->setPosition(457 , 125);
    usermenu->setScale({0.675});
    usermenu->setZOrder(10);

    return true;
}


inline CCSprite* (__cdecl* CCSprite_createWithSpriteFrameName)(const char*);
CCSprite* CCSprite_createWithSpriteFrameName_H(const char* name) {
    if (std::string(name) == "GJ_epicCoin2_001.png" ||
        strstr(name, "52342")) {
        CCSprite* no = CCSprite::create();
        //MessageBoxA(nullptr, name, "CCSprite_createWithSpriteFrameNameHook -> no sprite", MB_ICONINFORMATION | MB_OK);
        return no;
    }
    if (std::string(name) == "GJ_epicCoin_002.png")
        return ModUtils::createSprite("GJ_epicCoin_003.png");
    return CCSprite_createWithSpriteFrameName(name);

    if (std::string(name) == "GJBeast05_01_001.png") {
        CCSprite* GJ_logo_001 = CCSprite::create(name);
        GJ_logo_001->runAction(CCRepeatForever::create(CCSequence::create(CCEaseSineInOut::create(CCScaleBy::create(1.0, 1.025)), CCEaseSineInOut::create(CCScaleBy::create(1.0, 0.975)), nullptr)));
        return GJ_logo_001;
    }
} //Nunca entendí esto xd


inline LoadingLayer* (__cdecl* LoadingLayer_loadAssets)(LoadingLayer*);
void __fastcall LoadingLayer_loadAssets_H(LoadingLayer* self) {
    LoadingLayer_loadAssets(self);

    CCFileUtils::sharedFileUtils()->addSearchPath("mods");
}

bool (__thiscall* MenuLayer_onCreator)(CCLayer* self);
bool __fastcall MenuLayer_onCreator_H(CCLayer* self, void*) {
  
    if (!MenuLayer_onCreator(self)) return false;

    CCApplication::sharedApplication()->openURL("https://discord.gg/THmJJ75Kcc");

    return true;
}


#include "ServersUwu.hpp"

//Esto no funciona

/*
void MyFunctions::sub_10051090(int a1, int a2, const char* a3) {
    std::string a3String(a3);

    if (a3String == "GJ_epicCoin_001.png") {
        int starFeatured = 0; // Simulamos obtener el valor de starFeatured de alguna manera
        int starEpic = 0;     // Simulamos obtener el valor de starEpic de alguna manera

        if (starFeatured == 1) {
            if (starEpic == 0)
                MyFunctions::someFunction(a1, a2, "GJ_featuredCoin_001.png");
        }

        if (starFeatured == 1 && starEpic == 1)
            MyFunctions::someFunction(a1, a2, "GJ_epicCoin_001.png");

        if (starFeatured == 2)
            MyFunctions::someFunction(a1, a2, "GJ_epicCoin2_001.png");

        if (starFeatured == 3)
            MyFunctions::someFunction(a1, a2, "GJ_epicCoin3_001.png");

        if (starFeatured == 4)
            MyFunctions::someFunction(a1, a2, "GJ_epicCoin4_001.png");

        if (starFeatured == 5)
            MyFunctions::someFunction(a1, a2, "GJ_epicCoin5_001.png");
    } else {
        MyFunctions::someFunction(a1, a2, a3);
    }
}
*/

void MyFunctions::sub_10051090(int a1, int a2, const char* a3) {
    if (strcmp(a3, "GJ_epicCoin_001.png") == 0) {
        int starFeatured = 0; // Simulamos obtener el valor de starFeatured de alguna manera
        int starEpic = 0;     // Simulamos obtener el valor de starEpic de alguna manera

        if (starFeatured == 1) {
            if (starEpic == 0)
                MyFunctions::someFunction(a1, a2, "GJ_featuredCoin_001.png");
        }

        if (starFeatured == 1 && starEpic == 1)
            MyFunctions::someFunction(a1, a2, "GJ_epicCoin_001.png");

        if (starFeatured == 2)
            MyFunctions::someFunction(a1, a2, "GJ_epicCoin2_001.png");

        if (starFeatured == 3)
            MyFunctions::someFunction(a1, a2, "GJ_epicCoin3_001.png");

        if (starFeatured == 4)
            MyFunctions::someFunction(a1, a2, "GJ_epicCoin4_001.png");

        if (starFeatured == 5)
            MyFunctions::someFunction(a1, a2, "GJ_epicCoin5_001.png");
    } else {
        MyFunctions::someFunction(a1, a2, a3);
    }
}

void MyFunctions::someFunction(int a1, int a2, const char* a3) {
    // Implementa la lógica de someFunction aquí
    // Esta es una implementación de marcador de posición
}

void(__thiscall* LoadingLayer_loadingFinished)(LoadingLayer*);//0x18C790
void __fastcall LoadingLayer_loadingFinished_H(LoadingLayer* self, void*) {
    LoadingLayer_loadingFinished(self);
    //title
    SetWindowTextW(GetForegroundWindow(), L"GDPSWow");

    const char *server = "https://gdpswowwaaa.ps.fhgdps.com";
    const char *server_b64 = "aHR0cHM6Ly9nZHBzd293d2FhYS5wcy5maGdkcHMuY29t";

    const std::string Servidor = "https://gdpswowwaaa.ps.fhgdps.com";

    const std::string NOCamiarServers = "https://gdpswowwaaa.ps.fhgdps.com/tools/";

    if (NOCamiarServers != Servidor) {

        //No hay nada XD
    }
}

inline MenuLayerExt* (__cdecl* MenuLayer_onFacebook)(void*, CCObject*);
void __fastcall MenuLayer_onFacebook_H(void*, CCObject* pSender) {
    CCApplication::sharedApplication()->openURL(MenuLayerExt::onFacebook);
}

inline MenuLayerExt* (__cdecl* MenuLayer_onTwitter)(void*, CCObject*);
void __fastcall MenuLayer_onTwitter_H(void*, CCObject* pSender) {
    CCApplication::sharedApplication()->openURL(MenuLayerExt::onTwitter);
}

inline MenuLayerExt* (__cdecl* MenuLayer_onYouTube)(void*, CCObject*);
void __fastcall MenuLayer_onYouTube_H(void*, CCObject* pSender) {
    CCApplication::sharedApplication()->openURL(MenuLayerExt::onYouTube);
}

DWORD WINAPI thread_func(void* hModule) {

    MH_Initialize();

    //CC_HOOK("?create@CCSprite@cocos2d@@SAPAV12@PBD@Z", CCSprite_create, false);
    CC_HOOK("?createWithSpriteFrameName@CCSprite@cocos2d@@SAPAV12@PBD@Z", CCSprite_createWithSpriteFrameName, false); //user666 algo asi xd

    HOOK(base + 0x18C8E0, LoadingLayer_loadAssets, true);

    HOOK(base + 0x108810, MenuLayer_onCreator);
    
    //HOOK(base + 0x7CAF0, EditorUI_setupCreateMenu, false);//huh


    auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));
    
    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x4DE40),
        reinterpret_cast<void*>(&CreatorLayer_init_H),
        reinterpret_cast<void**>(&CreatorLayer_init)
    );

    MH_CreateHook( //A
        reinterpret_cast<void*>(base + 0x1907b0),
        reinterpret_cast<void*>(&GatoSexoLayer_init_H),
        reinterpret_cast<void**>(&GatoSexoLayer_init)
    );

    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x1E4620),
        reinterpret_cast<void*>(&PauseLayer_init_H),
        reinterpret_cast<void**>(&PauseLayer_init)
    );

    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x18cf40),
        reinterpret_cast<void*>(&LoadingLayer_getString_h),
        reinterpret_cast<void**>(&LoadingLayer_getString_org)
    );

    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x1255D0),
        reinterpret_cast<void*>(&GJGarageLayer_init_H),
        reinterpret_cast<void**>(&GJGarageLayer_init)
    );

    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x18C790),
        reinterpret_cast<void*>(&LoadingLayer_loadingFinished_H),
        reinterpret_cast<void**>(&LoadingLayer_loadingFinished)
    );

    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x191960),
        reinterpret_cast<void*>(&MenuLayer_onFacebook_H),
        reinterpret_cast<void**>(&MenuLayer_onFacebook)
    );

    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x191980),
        reinterpret_cast<void*>(&MenuLayer_onTwitter_H),
        reinterpret_cast<void**>(&MenuLayer_onTwitter)
    );
    

    auto libcocos2d = (DWORD)GetModuleHandleA("libcocos2d.dll");

    MH_EnableHook(MH_ALL_HOOKS);

    //Instant Mirror Portal
    ModUtils::write_bytes(base + 0x20ACA3, { 0xC7, 0x04, 0x24, 0x00, 0x00, 0x00, 0x00 });
    
    // Load Failed
    ModUtils::write_bytes(base + 0x18B2B4, { 0xB0 , 0x01 });

    //SmoothEditorTrail
    ModUtils::write_bytes(base + 0x16AB0D, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });

    //Text Length
    ModUtils::write_bytes(base + 0x21ACB, { 0xEB, 0x04 });

    //Character Filter
    ModUtils::write_bytes(base + 0x21A99, { 0x90, 0x90 });

    //Editor

    //Slider limit bypass
    ModUtils::write_bytes(base + 0x2E5CA, { 0xEB, });
    ModUtils::write_bytes(base + 0x2E5F8, { 0xEB, });

    //Copy Hack
    //ModUtils::write_bytes(base + 0x179B8E, { 0x90, 0x90 });
    //ModUtils::write_bytes(base + 0x176FE5, { 0xB0 , 0x01 , 0x90 });

    //Level Edit
    ///ModUtils::write_bytes(base + 0x1E4A32, { 0x90, 0x90 });

    //Custom Object Bypass
    ModUtils::write_bytes(base + 0x7A100, { 0xEB, });
    ModUtils::write_bytes(base + 0x7A022, { 0xEB, });
    ModUtils::write_bytes(base + 0x7A203, { 0x90, 0x90 });

    //Verify Hack
    //ModUtils::write_bytes(base + 0x71D48, { 0xEB, });
    
    ///Icons Hacks
    ModUtils::write_bytes(base + 0xC50A8, { 0xB0, 0x01, 0x90, 0x90, 0x90 });

    ///Colors Hacks
    ModUtils::write_bytes(base + 0xC54BA, { 0xB0, 0x01, 0x90, 0x90, 0x90 });

    ///Trail Bug Fix (Fixes trail cutting on high refresh rates)

    ModUtils::write_bytes((DWORD)GetModuleHandleA("libcocos2d.dll") + 0xAE9BD, { 0xBB , 0xFF , 0x00 , 0x00 , 0x00 , 0x90 });

    ///SmoothEditorTrail
    ModUtils::write_bytes(base + 0x16AB0D, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });

    /// Practice Music

    ModUtils::write_bytes(base + 0x20C925, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });
    ModUtils::write_bytes(base + 0x20D143, { 0x90, 0x90 });
    ModUtils::write_bytes(base + 0x20A563, { 0x90, 0x90 });
    ModUtils::write_bytes(base + 0x20A595, { 0x90, 0x90 });

    //Trails Cocos2d
    ModUtils::write_bytes(libcocos2d + 0xAE9BD, { 0xBB , 0xFF , 0x00 , 0x00 , 0x00 , 0x90 });

    //Main Levels
    ModUtils::write_bytes(base + 0x188CE1, { 0xE9, 0x8A, 0x00, 0x00, 0x00, 0x90 });

    //Bypass
    //Baul
    ModUtils::write_bytes(base + 0x4F631, { 0x90, 0x90 });

    //Accurate Percentage
    ModUtils::write_bytes(base + 0xF33BB, { 0xC7, 0x02, 0x25, 0x66, 0x25, 0x25, 0x8B, 0x87, 0xC0, 0x03, 0x00, 0x00, 0x8B, 0xB0, 0x04, 0x01, 0x00, 0x00, 0xF3, 0x0F, 0x5A, 0xC0, 0x83, 0xEC, 0x08, 0xF2, 0x0F, 0x11, 0x04, 0x24, 0x83, 0xEC, 0x04, 0x89, 0x14, 0x24, 0x90 });

    //Titulo

    SetWindowTextW(GetForegroundWindow(), L"GDPSWow");

    database["GJ_epicCoin_001.png"] = "!epic"; //No Funciona
    database["GJ_epicCoin_002.png"] = "!epicw"; //No Funciona

    std::string fileName = "GJ_epicCoin_001.png";
    ChangeFileName(fileName);

    std::cout << "Nuevo nombre de archivo: " << fileName << std::endl;

    const char* dllFileName = "uwu.dll";

    std::ifstream fin("uwu.dll");
    if (fin.good()) {
        std::cout << "El archivo uwu.dll existe en este directorio.\n";
        // Continúa el código aquí
    } else {
        std::cerr << "Error: el archivo uwu.dll no existe en este directorio.\n";
        return -1;
    }

    return 0;
}

BOOL APIENTRY DllMain(HMODULE handle, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        auto h = CreateThread(0, 0, thread_func, handle, 0, 0);
        if (h)
            CloseHandle(h);
        else
            return FALSE;
    }
    return TRUE;
}