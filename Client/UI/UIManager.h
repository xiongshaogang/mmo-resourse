#pragma once
#include "GamePage.h"
#include "../Engine/Render.h"
namespace CEGUI
{
    class String;
    class System;
    class Direct3D9Renderer;
    class LuaScriptModule;
    class GeometryBuffer;
    class ImageSet;
}
class MyRenderedStringParser;
class C3DIconEffect;
class AnimEffectIcon;
class Layer2D;
class UIManager
{
public:
    UIManager(void);
    virtual ~UIManager(void);
    void Init();
    void Fini();
    CEGUI::Window* LoadUI(const char* id);

    static void Create(LPDIRECT3DDEVICE9 pDeviece);

    static void Destroy();
	
	static void Render();

	static void CEGUI_ResetD3D();

    static void SetCameraPosAndView(float XPos,float YPos,float ZPos);

	static inline CEGUI::Direct3D9Renderer * GetCeguiRender() { return m_pCeguiD3D9Render;}

    static bool IOProc(UINT message, WPARAM wParam, LPARAM lParam);

    static void ReleaseAllPage();

    static void ReleasePage(CEGUI::Window *pWnd);

    static void ReleasePage(const char * name);

    static void CloseAllPage(const char *exceptName = NULL);

    static void AddGamePage(GamePage *page);

	//当前鼠标是否在ui 窗口内
	static bool isMouseRollOverWindow();

    //@brief编辑当前界面 nikai 2010/3/24
    void EditUI();
    //@brief改变当前的编辑控件 nikai 2010/3/24
    static void FreshCurEditComponent();

    //设置是否隐藏界面
    static void ShowUI(bool b);

    //管理3DIconEffect
    static void Add3DIconEffect(CEGUI::Window *pWnd,C3DIconEffect *Icon);
    static C3DIconEffect * Get3DIconEffect(CEGUI::Window *pWnd);
    static void ReleaseAll3DIcon();

    //管理序列帧动画效果mapAnimIconManager
    static void AddAnimIcon(CEGUI::Window *pWnd,AnimEffectIcon *Icon);
    static AnimEffectIcon * GetAnimIcon(CEGUI::Window *pWnd);
    static void ReleaseAllAnimIcon();

    //绘制文字
    void   OutPutText(int iX,int iY,const char *pszString, D3DCOLOR color, int iStyleIndex=0,
                      const float space_extra = 0.0f,const float x_scale = 1.0f, const float y_scale = 1.0f);

	static Layer2D* GetLayer2D(){return gameLayer2D;}
    //绘制图
    bool   isImageSetDefined(const char *ImageSetName);
    void   CreateImageSetFromFile(const char *ImageSetName,const char * filePath);

    long   GetImageWidth(const char *ImageSetName,const char * imageName = "full_image");
    long   GetImageHeight(const char *ImageSetName,const char * imageName = "full_image");
    void   DrawImage(int iX,int iY, const char *imageSetName,const char *image = "full_image");
    void   DrawImage(int iX,int iY, int iWidth, int iHeight, const char *imageSetName,const char *image = "full_image");
    void   DrawImage(CEGUI::Window *pDestWin, int iX, int iY, const char *imageSetName,const char *image = "full_image");
    void   Clear2DBuff();
    int    GetFontWidth(const char * text, int iStyle = 0, float x_fscale = 1.0f);
    int    GetFontHeight(int iStyle = 0, float y_scale = 1.0f);
    
    //2010.9.8 显示当前编辑组件的颜色区域
    void   ShowEditColorArea();

    //2010.9.27
    //获取当前有编辑焦点的窗口
    static CEGUI::Window *GetInputsCapturedWin();
    static void   Run();
	/***********************************************************************/
	/*  zhaohang 2010-11-5 add*/
	/***********************************************************************/
	static MyRenderedStringParser* GetMyRenderedStringParser();
private:
    static void initialiseResourceGroupDirectories();

    static void initialiseDefaultResourceGroups();

    static const char * getDataPathPrefix();

    //更新cegui 系统时钟
    static void UpDateCEGUISystemTime();

    static void ProcessCopy();
    static void ProcessPaste();
    static void ProcessClip();
    static void ProcessTab();
    static CEGUI::System			* m_pSystemCEGUI;
    static CEGUI::Direct3D9Renderer * m_pCeguiD3D9Render;
    static CEGUI::LuaScriptModule   * m_pScriptModule;
    CEGUI::GeometryBuffer           * d_fps_geometry;
    CEGUI::GeometryBuffer           * d_logo_geometry;
    
    static D3DXMATRIX                 s_matWorld;
    static D3DXMATRIX                 s_matView;
    static D3DXMATRIX                 s_matProj;
    static render::Camera             m_Camera;
    static DWORD	m_FVF;
    static IDirect3DVertexShader9		*m_VertexShader; ///< 顶点shader
    static IDirect3DPixelShader9		*m_PixelShader; ///< 像素shader
    static DWORD m_LIGHTING;
    static DWORD m_FOGENABLE;
    static DWORD m_ZENABLE;
    static DWORD m_ALPHATESTENABLE;
    static DWORD m_CULLMODE;
    static DWORD m_FILLMODE;
    static DWORD m_SCISSORTESTENABLE;
    static DWORD m_ZWRITENABLE;
    static DWORD m_SAMPADDRESSU;
    static DWORD m_SAMPADDRESSV;
    static DWORD m_COLORARG1;
    static DWORD m_COLORARG2;
    static DWORD m_COLOROP;
    static DWORD m_ALPHAARG1;
    static DWORD m_ALPHAARG2;
    static DWORD m_ALPHAOP;
    static DWORD m_MINFILTER;
    static DWORD m_MAGFILTER;
    static DWORD m_TSS1_COLOROP;
    static DWORD m_RS_ALPHABLENDENABLE;
    static DWORD m_RS_SRCBLEND;
    static DWORD m_RS_DESTBLEND;
    static DWORD m_RS_SRCBLENDALPHA;
    static DWORD m_RS_DESTBLENDALPHA;
    //window解析對象
    static MyRenderedStringParser   *myRenderParser; 

    static bool getFocusedInputBoxCoord(POINT& point, float& height);
    
    static bool IMEFollow();
    
    //处理中文输入
    static bool ChnInjectChar(WPARAM wParam); 
    //虚拟键转换扫描码
    static UINT VirtualKeyToScanCode(WPARAM wParam, LPARAM lParam);
    //保存渲染状态
    static void SaveRenderState();
    //还原渲染状态
    static void ResetRenderState();

    
    //GamePage容器
    static map<string , GamePage *>  mapPageManager;
    
    //3D特效管理器
    static map<CEGUI::Window *,C3DIconEffect*>   map3DIconManager;

    //序列帧管理器
    static map<CEGUI::Window *,AnimEffectIcon*>  mapAnimIconManager;

    //当前用户正在编辑的窗口
    static CEGUI::Window * m_UserEditWin;

    static Layer2D         * gameLayer2D;
};
