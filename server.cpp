#include "server.hpp"
#include <string>
#include <cstring> // para la función strlen
#include "includes.h"
#include "gd.h"

void ServerLayer::serverw(CCObject* object) {
    LPCWSTR a = L"https://gdpswowwaaa.ps.fhgdps.com/tools/";
    ShellExecuteW(NULL, L"open", a, NULL, NULL, SW_SHOWNORMAL);
}