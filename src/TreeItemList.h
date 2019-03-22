#ifndef _TREEITEMLIST_H
#define _TREEITEMLIST_H

#include <vector>
#include <wx/treectrl.h>

struct Entry
{
  wxTreeItemId id;
};

class TreeItemList
{
public:
  virtual ~TreeItemList();

  void AddItem(wxTreeItemId id);
  bool RemoveItem(wxTreeItemId id);
  wxTreeItemId RemoveItem(int index);

  wxTreeItemId ItemAt(int index);
  int CountItems();
  void MakeEmpty();

private:
  std::vector<Entry*> fList;
};

#endif
