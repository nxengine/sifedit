#ifndef _GENCODE_H
#define _GENCODE_H

#include <string>
#include <vector>

bool generate_sprites_h(const char *fname);
bool generate_assignsprites_cpp(const char *fname);
bool read_list_of_objtypes(const char *hfile, std::vector<std::string> *names);
bool write_file_if_needed(std::string& str, const char *fname);
void init_hash();
void accum_hash(const char *str);
void accum_hash(char ch);
uint32_t read_hash(const char *fname);
const char *get_timestamp();

#endif // _GENCODE_H