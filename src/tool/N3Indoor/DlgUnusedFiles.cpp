// DlgUnusedFiles.cpp : implementation file
//

#include "stdafx.h"
#include "N3Indoor.h"
#include "DlgUnusedFiles.h"
#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgUnusedFiles dialog

CDlgUnusedFiles::CDlgUnusedFiles(CWnd * pParent /*=NULL*/)
    : CDialog(CDlgUnusedFiles::IDD, pParent) {
    //{{AFX_DATA_INIT(CDlgUnusedFiles)
    // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
}

void CDlgUnusedFiles::DoDataExchange(CDataExchange * pDX) {
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgUnusedFiles)
    DDX_Control(pDX, IDC_LIST_INVALID_OBJECTS, m_ListInvalidObjects);
    DDX_Control(pDX, IDC_LIST_FILES, m_ListFiles);
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgUnusedFiles, CDialog)
//{{AFX_MSG_MAP(CDlgUnusedFiles)
ON_BN_CLICKED(IDC_DELETE, OnDelete)
ON_BN_CLICKED(ID_CANCEL, OnCancel)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgUnusedFiles message handlers

void CDlgUnusedFiles::OnDelete() {
    // TODO: Add your control notification handler code here
    int iSelFNC = m_ListFiles.GetSelCount();
    if (iSelFNC <= 0) {
        return;
    }

    int iYesNo = MessageBox("지우시겠습니까?", "확인", MB_YESNO);

    if (IDYES != iYesNo) {
        return;
    }

    std::vector<int> sel;
    sel.reserve(iSelFNC);
    m_ListFiles.GetSelItems(iSelFNC, &(sel[0]));

    CString szFN;
    for (int i = 0; i < iSelFNC; i++) {
        m_ListFiles.GetText(sel[i], szFN);
        ::DeleteFile(szFN);
    }

    CDialog::OnOK();
}

BOOL CDlgUnusedFiles::OnInitDialog() {
    CDialog::OnInitDialog();

    // TODO: Add extra initialization here
    this->UpdateAll();

    return TRUE; // return TRUE unless you set the focus to a control
                 // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgUnusedFiles::OnCancel() {
    // TODO: Add your control notification handler code here
    CDialog::OnCancel();
}

void CDlgUnusedFiles::UpdateAll() {
    int iFNC = m_FileNames.GetSize();
    for (int i = 0; i < iFNC; i++) {
        m_ListFiles.AddString(m_FileNames[i]);
    }

    iFNC = m_InvalidFileNames.GetSize();
    for (int i = 0; i < iFNC; i++) {
        m_ListInvalidObjects.AddString(m_InvalidFileNames[i]);
    }
}
