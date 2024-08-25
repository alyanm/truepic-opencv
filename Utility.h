#ifndef UTILITY_H
#define UTILITY_H

#include <string>

namespace Utility {
    void VerifyOpenCV();
    void CheckFileValidity(const string& imagePath);
    void Help(const char* argv[]);
}

#endif // UTILITY_H
