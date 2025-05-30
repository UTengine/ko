// Ini.cpp: implementation of the CIni class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "Ini.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIni::CIni() {}

CIni::~CIni() {}

int CIni::GetProfileInt(const char * lpAppName, const char * lpKeyName, int nDefault) {
    if (m_szFileName[0] == '\0') {
        m_nError = 0X01;
        strcpy(m_strError, "File이 Set되지 않았습니다.");
        return -1;
    }

    GetPrivateProfileInt(lpAppName, lpKeyName, nDefault, m_szFileName);
    char tmpDefault[500];
    if (!GetPrivateProfileString(lpAppName, lpKeyName, "", tmpDefault, 500, m_szFileName)) {
        sprintf(tmpDefault, "%d", nDefault);
        WritePrivateProfileString(lpAppName, lpKeyName, tmpDefault, m_szFileName);
        return nDefault;
    }

    return GetPrivateProfileInt(lpAppName, lpKeyName, nDefault, m_szFileName);
}

const char * CIni::GetProfileString(const char * lpAppName, const char * lpKeyName, const char * lpDefault) {
    static char retString[200] = "";
    if (m_szFileName[0] == '\0') {
        m_nError = 0X01;
        strcpy(m_strError, "File이 Set되지 않았습니다.");
        strcpy(retString, "");
        return retString;
    }

    return GetProfileString(lpAppName, lpKeyName, lpDefault, retString, sizeof(retString));
}

const char * CIni::GetProfileString(const char * lpAppName, const char * lpKeyName, const char * lpDefault,
                                    char * szBuffer, uint32_t nBufferSize) const {
    DWORD ret = GetPrivateProfileString(lpAppName, lpKeyName, "", szBuffer, nBufferSize, m_szFileName);
    if (ret == 0) {
        WritePrivateProfileString(lpAppName, lpKeyName, lpDefault, m_szFileName);
        snprintf(szBuffer, nBufferSize, "%s", lpDefault);
    }
    return szBuffer;
}

bool CIni::SetPath(const char * filename) {
    fs::path fsIniPath = n3std::get_app_dir() / filename;
    std::snprintf(m_szFileName, sizeof(m_szFileName), fsIniPath.string().c_str());
    return true;
}

int CIni::SetProfileInt(const char * lpAppName, const char * lpKeyName, int nDefault) {
    int nRet = -1;
    if (m_szFileName[0] == '\0') {
        m_nError = 0X01;
        strcpy(m_strError, "File이 Set되지 않았습니다.");
        return nRet;
    }

    char tmpDefault[500];
    memset(tmpDefault, 0x00, 500);
    sprintf(tmpDefault, "%d", nDefault);
    nRet = WritePrivateProfileString(lpAppName, lpKeyName, tmpDefault, m_szFileName);

    return nRet;
}

int CIni::SetProfileString(const char * lpAppName, const char * lpKeyName, const char * lpDefault) {
    int nRet = -1;
    if (m_szFileName[0] == '\0') {
        m_nError = 0X01;
        strcpy(m_strError, "File이 Set되지 않았습니다.");
        return nRet;
    }

    nRet = WritePrivateProfileString(lpAppName, lpKeyName, lpDefault, m_szFileName);

    return nRet;
}
