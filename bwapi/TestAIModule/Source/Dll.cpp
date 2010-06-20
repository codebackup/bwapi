#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#include <BWAPI.h>

#include "TestMap1.h"
#include "TerranTest.h"
#include "ProtossTest.h"
#include "ZergTest.h"
namespace BWAPI { Game* Broodwar; }
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
    BWAPI::BWAPI_init();
		break;
	case DLL_PROCESS_DETACH:
		break;
	}


	return TRUE;
}

 extern "C" __declspec(dllexport) BWAPI::AIModule* newAIModule(BWAPI::Game* game)
{
  BWAPI::Broodwar=game;
  if (game->mapFilename()=="testmap1.scm")
    return new TestMap1();
  if (game->mapFilename()=="TerranTest.scm")
    return new TerranTest();
  if (game->mapFilename()=="ProtossTest.scm")
    return new ProtossTest();
  if (game->mapFilename()=="ZergTest.scm")
    return new ZergTest();
  return new BWAPI::AIModule();
}