// UILoading.cpp: implementation of the UILoading class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "UILoading.h"
#include "GameDef.h"
#include "GameEng.h"
#include "GameProcedure.h"
#include "UIManager.h"

#include "N3Base/N3UIProgress.h"
#include "N3Base/N3UIString.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUILoading::CUILoading() {
    m_pText_Info = NULL;
    m_pText_Version = NULL;
    m_pProgress_Loading = NULL;
}

CUILoading::~CUILoading() {
    CUILoading::Release();
}

void CUILoading::Release() {
    CN3UIBase::Release();

    m_pText_Info = NULL;
    m_pText_Version = NULL;
    m_pProgress_Loading = NULL;
}

bool CUILoading::Load(HANDLE hFile) {
    if (CN3UIBase::Load(hFile) == false) {
        return false;
    }

    m_pText_Version = (CN3UIString *)(CN3UIBase::GetChildByID("Text_Version"));
    __ASSERT(m_pText_Version, "NULL UI Component!!");
    if (m_pText_Version) {
        m_pText_Version->SetString(std::format("Ver. {:.3f}", CURRENT_VERSION / 1000.0f));
    }
    m_pText_Info = (CN3UIString *)(CN3UIBase::GetChildByID("Text_Info"));
    __ASSERT(m_pText_Info, "NULL UI Component!!");
    m_pProgress_Loading = (CN3UIProgress *)(CN3UIBase::GetChildByID("Progress_Loading"));
    __ASSERT(m_pProgress_Loading, "NULL UI Component!!");

    this->SetPosCenter();            // 가운데로 맞추기..
    m_pText_Version->SetPos(10, 10); // Version 은 맨위에 표시..

    if (m_pProgress_Loading) {
        m_pProgress_Loading->SetRange(0, 100);
    }

    return true;
}

void CUILoading::Render(const std::string & szInfo, int iPercentage) {
    if (m_pText_Info) {
        m_pText_Info->SetString(szInfo);
    }
    if (m_pProgress_Loading) {
        m_pProgress_Loading->SetCurValue(iPercentage);
    }

    CGameProcedure::s_pEng->Clear(0);     // 배경은 검은색
    CGameProcedure::s_pEng->BeginScene(); // 씬 렌더 ㅅ작...

    CN3UIBase::Tick();
    CUIManager::RenderStateSet();
    CN3UIBase::Render();
    CUIManager::RenderStateRestore();

    CGameProcedure::s_pEng->EndScene(); // 씬 렌더 시작...
    CGameProcedure::s_pEng->Present(CN3Base::s_hWndBase);
}
