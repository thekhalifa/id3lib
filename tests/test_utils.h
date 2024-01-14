// SPDX-License-Identifier: LGPL-3.0-only

#ifndef ID3LIB_TEST_UTILS_H
#define ID3LIB_TEST_UTILS_H

#define CMP_BUFF_SIZE 8192

inline int test_utils_files_match(const char *left, const char *right) {

    std::ifstream lfile(left, std::ifstream::binary);
    std::ifstream rfile(right, std::ifstream::binary);

    if (!(lfile.good() && rfile.good()) )
        return 0;

    char *lbuff = new char[CMP_BUFF_SIZE]();
    char *rbuff = new char[CMP_BUFF_SIZE]();
    while (lfile.good() || rfile.good()) {
        lfile.read(lbuff, CMP_BUFF_SIZE);
        rfile.read(rbuff, CMP_BUFF_SIZE);

        if (lfile.gcount() != rfile.gcount())
            return 0;
        if (std::memcmp(lbuff, rbuff, CMP_BUFF_SIZE)) {
            delete[] lbuff;
            delete[] rbuff;
            return 0;
        }
    }

    delete[] lbuff;
    delete[] rbuff;
    return 1;
}

#endif /* ID3LIB_TEST_UTILS_H */
