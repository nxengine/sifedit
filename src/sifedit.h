
#ifndef _SIFEDIT_H
#define _SIFEDIT_H

#include "EditArea.h"
#include "SheetManager.h"
#include "SpriteRecord.h"
#include "common/DBuffer.h"

#include "siflib/sectSprites.h"
#include "siflib/sectStringArray.h"
#include "siflib/sif.h"
#include "siflib/sifloader.h"

#include <sys/param.h>
#include <wx/wx.h>
#include <string>
#include <vector>

#define MAX_SPRITES 512

class MyApp : public wxApp
{
  virtual bool OnInit();
  int FilterEvent(wxEvent &event);
};

struct GlobalData
{
  int cursprite;
  int curframe;
  int curdir;
  int curmode;
  bool ctrl, shift;

  struct
  {
    int sprite, frame, dir;
  } clipboard;

  std::vector<std::string> sheetfiles; // spritesheet names
  std::vector<std::string> groupnames; // names of sprite groups

  char openfilename[MAXPATHLEN];
  bool nojerk; // hack to prevent jerking spritetree selection back to current sprite when not desirable
};

extern GlobalData gd;
extern SpriteList spritelist;
extern const char *pathPrefix;
extern SheetManager sheetmgr;

const char *GetSpriteHeaderName(const char *sprname);

SpriteRecord *CurSprite();
SIFFrame *CurFrame();
SIFDir *CurDir();
int CurFrameCount();
int CurDirCount();
int CountSpritesheetUsage(int sheetno, int *firstuse_out = NULL);
const char *PrefixPath(const char *path);
char* wxStringToChar(wxString input);
int FindFirstSpriteInGroup(int groupno);
void ReorderGroups(std::vector<int> *movelist, int insertafter);
bool IsValidFrame(int s, int f);
bool IsValidDir(int s, int d);
bool IsValidSprite(int s);
bool save_sif(const char *fname);

bool load_sif(const char *fname);
bool LoadStringSection(SIFLoader *sif, int type, std::vector<std::string> *strings);
bool LoadGroupsSection(SIFLoader *sif);
bool LoadSessionSection(SIFLoader *sif);
bool SaveStringSection(SIFLoader *sif, int type, std::vector<std::string> *strings);
bool SaveGroupsSection(SIFLoader *sif);
bool SaveSessionSection(SIFLoader *sif);
void DeleteGroup(int delgroup, int kickgroup);
void RemoveSpritesheet(int sheetno);
bool load_spritesheet(wxImage *image, const char *filename);

#endif
