#ifndef VULN_H
#define VULN_H

#ifdef __cplusplus
extern "C" {
#endif

int add_nums(int a, int b);
int sum_bytes(const char* input, int len);
int copy_into_fixed_buf(const char* input, int len);

#ifdef __cplusplus
}
#endif

#endif