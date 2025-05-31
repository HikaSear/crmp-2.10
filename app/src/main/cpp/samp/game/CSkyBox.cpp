#include "CSkyBox.h"
#include "../main.h"
#include "../game/game.h"
#include "patch.h"

extern CGame* pGame;

CObject* CSkyBox::m_pSkyBox = nullptr;
RwTexture* pSkyTexture = nullptr;
float rx = 0.0f;
bool CSkyBox::is = true;

void CSkyBox::Process() {
    if (!m_pSkyBox) {
        CVector vec = {
                pGame->FindPlayerPed()->m_pPed->m_matrix->m_pos.x,
                pGame->FindPlayerPed()->m_pPed->m_matrix->m_pos.y,
                pGame->FindPlayerPed()->m_pPed->m_matrix->m_pos.z - 100.0f
        };
        CVector vec2 = {0.0f, 0.0f, 0.0f};
        m_pSkyBox = pGame->NewObject(18659, vec, vec2, 1.0f);
    } else {
        m_pSkyBox->MoveTo(
                pGame->FindPlayerPed()->m_pPed->m_matrix->m_pos.x,
                pGame->FindPlayerPed()->m_pPed->m_matrix->m_pos.y,
                pGame->FindPlayerPed()->m_pPed->m_matrix->m_pos.z,
                1.0f, 0.0f, 0.0f, rx
        );
        rx += 0.01f;
    }
}

void CSkyBox::RwPon() {
    is = false;
    for (int i = 0; i < 1000; i++) {
        m_pSkyBox->MoveTo(
                pGame->FindPlayerPed()->m_pPed->m_matrix->m_pos.x,
                pGame->FindPlayerPed()->m_pPed->m_matrix->m_pos.y,
                pGame->FindPlayerPed()->m_pPed->m_matrix->m_pos.z,
                1.0f, 0.0f, 0.0f, 0.0f
        );
    }
}

RpAtomic* CSkyBox::ObjectMaterialCallBackEdgar(RpAtomic* rpAtomic, CObject* pObject) {
    return rpAtomic;
}