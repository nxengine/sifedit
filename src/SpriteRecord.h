
#ifndef _SPRITERECORD_H
#define _SPRITERECORD_H

#include "siflib/sif.h"
#include <string>
#include <vector>

// derived class of SIFSprite used by SIFEdit which stores
// meta information together with the sprite. This way we don't
// have to include fields the game doesn't care about in the
// SIFSprite structure itself.
struct SpriteRecord : public SIFSprite
{
public:
  SpriteRecord();
  SpriteRecord(SIFSprite *insprite);
  ~SpriteRecord();

  SpriteRecord *Duplicate();
  void CopyFrom(SpriteRecord *other);

  // this might save some typing
  const char *Name()
  {
    return name.c_str();
  }
  const char *Comment()
  {
    return comment.c_str();
  }

  std::string name;
  std::string comment;
  uint8_t group;
};

// rec = sprites.AddRecord(sprites.CurRecord().Duplicate());
// rec.sprite.SetFrames(1);
// rec.SetName(stprintf("%d"));

class SpriteList
{
public:
  SpriteList();
  ~SpriteList();

  SpriteRecord *SpriteAt(int index);
  int CountItems();
  void MakeEmpty();

  SpriteRecord *AddSprite(SpriteRecord *record);
  SpriteRecord *AddSprite(SpriteRecord *record, int index);

  void DeleteSprite(int index);
  void DeleteSprite(SpriteRecord *record);

  SpriteRecord *RemoveSprite(int index);
  SpriteRecord *RemoveSprite(SpriteRecord *record);

  void SwapSprites(int index1, int index2); // switch order of records in list
  int IndexOf(SpriteRecord *record);

private:
  std::vector<SpriteRecord*> fList;
};

#endif
