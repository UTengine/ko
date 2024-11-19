#pragma once

// VersionSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVersionSet recordset

class CVersionSet : public CRecordset {
  public:
    CVersionSet(CDatabase * pDatabase = NULL);
    DECLARE_DYNAMIC(CVersionSet)

    // Field/Param Data
    //{{AFX_FIELD(CVersionSet, CRecordset)
    int     m_sVersion;
    CString m_strFile;
    CString m_strPatchFileName;
    int     m_sHistoryVersion;
    //}}AFX_FIELD

    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CVersionSet)
  public:
    virtual CString GetDefaultConnect();                   // Default connection string
    virtual CString GetDefaultSQL();                       // Default SQL for Recordset
    virtual void    DoFieldExchange(CFieldExchange * pFX); // RFX support
                                                           //}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext & dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
