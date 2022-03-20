#include <stdio.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <Windows.h>
#include <direct.h>
#else
#include <unistd.h>
#define MAX_PATH PATH_MAX
#endif

#ifndef S_ISDIR
#define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
#endif

#ifndef S_ISREG
#define S_ISREG(mode)  (((mode) & S_IFMT) == S_IFREG)
#endif


int main(int argc, char* argv[])
{
    const char* folder;
    folder = "./tmp";
    struct stat sb;
    char buf[300];

#ifdef _CRT_NONSTDC_NO_WARNINGS
    printf("_CRT_NONSTDC_NO_WARNINGS is %i\n", _CRT_NONSTDC_NO_WARNINGS);
#endif

#ifdef _CRT_DECLARE_NONSTDC_NAMES
    printf("_CRT_DECLARE_NONSTD_NAMES is %i\n", _CRT_DECLARE_NONSTD_NAMES);
#endif

    printf("Current directory is %s\n", getcwd(buf, sizeof buf-1));
    printf("Did we find %s there?\n", folder);

    if (stat(folder, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}
