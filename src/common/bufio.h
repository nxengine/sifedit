
#ifndef _BUFIO_H
#define _BUFIO_H

#include "DBuffer.h"

uint8_t read_U8(const uint8_t **data, const uint8_t *data_end);
uint16_t read_U16(const uint8_t **data, const uint8_t *data_end);
uint32_t read_U32(const uint8_t **data, const uint8_t *data_end);
uint64_t read_U64(const uint8_t **data, const uint8_t *data_end);
float read_F32(const uint8_t **data, const uint8_t *data_end);
double read_F64(const uint8_t **data, const uint8_t *data_end);
void write_U8(DBuffer *buffer, uint8_t data);
void write_U16(DBuffer *buffer, uint16_t data);
void write_U32(DBuffer *buffer, uint32_t data);
void write_U64(DBuffer *buffer, uint64_t data);
void write_F32(DBuffer *buffer, float data);
void write_F64(DBuffer *buffer, double data);
uint32_t read_U24(const uint8_t **data, const uint8_t *data_end);
void write_U24(DBuffer *buffer, uint32_t data);
char read_char(const char **data, const char *data_end);
char read_nonblank_char(const char **data, const char *data_end);
char *read_string(const uint8_t **data, const uint8_t *data_end);
void read_Variable(DBuffer *out, const uint8_t **data, const uint8_t *data_end);
void write_Variable(DBuffer *out, DBuffer *in);
void write_Variable(DBuffer *out, const uint8_t *data, int len);
void read_Variable16(DBuffer *out, const uint8_t **data, const uint8_t *data_end);
void write_Variable16(DBuffer *out, DBuffer *in);

#endif
