
#include "SpriteRecord.h"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

SpriteRecord::SpriteRecord()
{
  SIFSprite::Init(); // initialize the fully-POD base class
}

SpriteRecord::SpriteRecord(SIFSprite *insprite)
{
  SIFSprite::CopyFrom(insprite);
}

SpriteRecord::~SpriteRecord()
{
  SIFSprite::FreeData();
}

SpriteRecord *SpriteRecord::Duplicate()
{
  SpriteRecord *rec = new SpriteRecord;

  rec->CopyFrom(this);
  return rec;
}

void SpriteRecord::CopyFrom(SpriteRecord *other)
{
  SIFSprite::CopyFrom(other);
  name = other->name;
  comment = other->comment;
  group = other->group;
}

/*
void c------------------------------() {}
*/

SpriteList::SpriteList() {}

SpriteList::~SpriteList()
{
  MakeEmpty();
}

/*
void c------------------------------() {}
*/

SpriteRecord *SpriteList::SpriteAt(int index)
{
  if (index >= fList.size())
  {
    return NULL;
  }
  return (SpriteRecord *)fList.at(index);
}

int SpriteList::CountItems()
{
  return fList.size();
}

void SpriteList::MakeEmpty()
{
  for (int i = 0; i<fList.size(); i++)
  {
    SpriteRecord *rec = SpriteAt(i);
    if (!rec)
      break;

    delete rec;
  }

  fList.clear();
}

/*
void c------------------------------() {}
*/

SpriteRecord *SpriteList::AddSprite(SpriteRecord *record)
{
  if (record)
    fList.push_back(record);

  return record;
}

SpriteRecord *SpriteList::AddSprite(SpriteRecord *record, int index)
{
  if (record)
    fList.insert(fList.begin()+index, record);

  return record;
}

void SpriteList::DeleteSprite(int index)
{
  SpriteRecord *rec = SpriteAt(index);
  delete rec;
  fList.erase(fList.begin()+index);
}

SpriteRecord *SpriteList::RemoveSprite(int index)
{
  SpriteRecord *rec = SpriteAt(index);
  fList.erase(fList.begin()+index);
  return rec;
}

void SpriteList::SwapSprites(int index1, int index2)
{
  std::swap(fList[index1],fList[index2]);
}

/*
void c------------------------------() {}
*/

int SpriteList::IndexOf(SpriteRecord *sprite)
{
  int idx = 0;
  for (auto it: fList)
  {
    if (it == sprite) return idx;
    idx++;
  }

  return -1;
}

SpriteRecord *SpriteList::RemoveSprite(SpriteRecord *sprite)
{
  return RemoveSprite(IndexOf(sprite));
}

void SpriteList::DeleteSprite(SpriteRecord *sprite)
{
  DeleteSprite(IndexOf(sprite));
}

/*
void c------------------------------() {}
*/
