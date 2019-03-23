
#include "TreeItemList.h"

#include <wx/treectrl.h>

TreeItemList::~TreeItemList()
{
  MakeEmpty();
}

void TreeItemList::AddItem(wxTreeItemId id)
{
  Entry *entry = new Entry;
  entry->id    = id;

  fList.push_back(entry);
}

wxTreeItemId TreeItemList::RemoveItem(int index)
{
  Entry *entry     = (Entry *)fList.at(index);
  fList.erase(fList.begin()+index);
  wxTreeItemId old = entry->id;
  delete entry;

  return old;
}

bool TreeItemList::RemoveItem(wxTreeItemId id)
{
  for (size_t i = 0; i< fList.size(); i++)
  {
    Entry *entry = (Entry *)fList.at(i);
    if (!entry)
      break;

    if (entry->id == id)
    {
      fList.erase(fList.begin()+i);
      delete entry;
      return 0;
    }
  }

  return 1;
}

void TreeItemList::MakeEmpty()
{
  for (size_t i = 0; i< fList.size(); i++)
  {
    Entry *entry = (Entry *)fList.at(i);
    if (!entry)
      break;

    delete entry;
  }

  fList.clear();
}

int TreeItemList::CountItems()
{
  return fList.size();
}

wxTreeItemId TreeItemList::ItemAt(int index)
{
  Entry *entry = (Entry *)fList.at(index);
  if (entry)
    return entry->id;

  wxTreeItemId NotIsOk;
  return NotIsOk;
}
