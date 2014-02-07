// vs08pe.cpp : Implementation of WinMain


#include "stdafx.h"
#include "resource.h"
#include "vs08pe_i.h"


class Cvs08peModule : public CAtlExeModuleT< Cvs08peModule >
{
public :
	DECLARE_LIBID(LIBID_vs08peLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_VS08PE, "{44D62BDF-A3C5-46E3-A0FC-31C5CB4411B8}")
};

Cvs08peModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
                                LPTSTR /*lpCmdLine*/, int nShowCmd)
{
    return _AtlModule.WinMain(nShowCmd);
}

