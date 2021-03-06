#include "util.h"

#include <cstdlib>

int parseNumber(const char *s, size_t *pos, timestamp *n)
{
    int i = (pos == NULL ? 0 : *pos);
    timestamp ans = 0;
    if (!('0' <= s[i] && s[i] <= '9')) return 1;
    while ('0' <= s[i] && s[i] <= '9') {
        int d = s[i++] - '0';
        if (ans > MAX_TIMESTAMP / 10) return 1;
        ans *= 10;
        if (ans >= MAX_TIMESTAMP - d) return 1;
        ans += d;
    }
    if (pos != NULL) *pos = i;
    *n = ans;
    return 0;
}

FILE *open_file_type(const char *prefix, const char *ftype, const char *mode) {
    char *file_name = new char[strlen(prefix) + strlen(ftype) + 1];
    strcpy(file_name, prefix);
    strcat(file_name, ftype);

    FILE *f = fopen(file_name, mode);
    delete [] file_name;

    return f;
}
