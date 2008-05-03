
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <assert.h>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

#include "./BWAPI/Globals.h"
#include "./BWAPI/Game.h"


DWORD WINAPI CTRT_Thread( LPVOID lpThreadParameter )
{
  // IT never gets here
  FILE *f = fopen("testx.log","wt"); 
  fprintf(f, "asdf");
  fclose(f);
  while(true)
  {
    BWAPI::Broodwar.update();
    Sleep(500);
  }
  return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                      DWORD  ul_reason_for_call,
                      LPVOID lpReserved
                      )
{

   switch (ul_reason_for_call)
   {
     case DLL_PROCESS_ATTACH: 
     {
       CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CTRT_Thread, NULL, 0, NULL);
        return true;
     }
     case DLL_THREAD_ATTACH:
     case DLL_THREAD_DETACH:
     case DLL_PROCESS_DETACH:
      break;
   }

   return true;
}