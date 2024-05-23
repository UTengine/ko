#pragma once

// MakeLareItemTableSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMakeLareItemTableSet recordset

class CMakeLareItemTableSet : public CRecordset {
  public:
    CMakeLareItemTableSet(CDatabase * pDatabase = NULL);
    DECLARE_DYNAMIC(CMakeLareItemTableSet)

    // Field/Param Data
    //{{AFX_FIELD(CMakeLareItemTableSet, CRecordset)
    BYTE m_byLevelGrade;
    int  m_sLareItem;
    int  m_sMagicItem;
    int  m_sGereralItem;
    //}}AFX_FIELD

    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CMakeLareItemTableSet)
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
