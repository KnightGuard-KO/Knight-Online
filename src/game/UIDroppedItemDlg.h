// UIDroppedItemDlg.h: interface for the UIDroppedItemDlg class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "GameDef.h"
#include "N3UIWndBase.h"

//////////////////////////////////////////////////////////////////////

class CUIDroppedItemDlg : public CN3UIWndBase {
  public:
    __IconItemSkill * m_pMyDroppedItem[MAX_ITEM_BUNDLE_DROP_PIECE];
    bool              m_bSendedIconArray[MAX_ITEM_BUNDLE_DROP_PIECE];

    int                  m_iItemBundleID;
    CUIImageTooltipDlg * m_pUITooltipDlg;

    int m_iBackupiOrder;

  protected:
    int GetInventoryEmptyInviOrder(__IconItemSkill * spItem = NULL);
    int GetItemiOrder(__IconItemSkill * spItem);

  public:
    CUIDroppedItemDlg();
    virtual ~CUIDroppedItemDlg();
    void Release();

    void          SetVisibleWithNoSound(bool bVisible, bool bWork = false, bool bReFocus = false);
    virtual DWORD MouseProc(DWORD dwFlags, const POINT & ptCur, const POINT & ptOld);
    virtual bool  ReceiveMessage(CN3UIBase * pSender, DWORD dwMsg);
    void          Init(CN3UIBase * pParent);
    void          Render();
    void          EnterDroppedState(int xpos, int ypos);
    void          LeaveDroppedState();
    void          GetItemByIDToInventory(BYTE bResult, int iItemId, int iGold, int iPos, int iItemCount, int iStrLen,
                                         std::string strString);
    void          AddToItemTable(int iItemId, int iItemCount, int iOrder);
    void          AddToItemTableToInventory(int iItemId, int iItemCount, int iOrder);

    bool ReceiveIconDrop(__IconItemSkill * spItem, POINT ptCur);

    void InitIconWnd(e_UIWND eWnd);
    void InitIconUpdate();

    __IconItemSkill * GetHighlightIconItem(CN3UIIcon * pUIIcon);
};
