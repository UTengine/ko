#pragma once

// KnightsRankSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKnightsRankSet recordset

class CKnightsRankSet : public CRecordset {
  public:
    CKnightsRankSet(CDatabase * pDatabase = NULL);
    DECLARE_DYNAMIC(CKnightsRankSet)

    // Field/Param Data
    //{{AFX_FIELD(CKnightsRankSet, CRecordset)
    long    m_nRank;
    int     m_shIndex;
    CString m_strName;
    long    m_nPoints;
    //}}AFX_FIELD

    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CKnightsRankSet)
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
