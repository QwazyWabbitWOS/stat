#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

// If we're doing MSVC we rename the POSIX functions.
#if defined (_WIN32) && defined (_MSC_VER)
#include <Windows.h>
#include <direct.h>
//#define getcwd _getcwd
#else
#include <unistd.h>
#endif

// Because MSVC doesn't define these.
#ifndef S_ISDIR
#define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
#endif

#ifndef S_ISREG
#define S_ISREG(mode)  (((mode) & S_IFMT) == S_IFREG)
#endif

void ShowMacros(void)
{
#ifdef _CRT_NONSTDC_NO_WARNINGS
	printf("_CRT_NONSTDC_NO_WARNINGS is %i\n", _CRT_NONSTDC_NO_WARNINGS);
#endif

#ifdef _CRT_DECLARE_NONSTDC_NAMES
	printf("_CRT_DECLARE_NONSTD_NAMES is %i\n", _CRT_DECLARE_NONSTD_NAMES);
#endif
}

int main(int argc, char* argv[])
{
	const char* folder;
	folder = "./tmp";
	struct stat sb;
	char buf[1000];

	ShowMacros();
	printf("Current directory is %s\n", getcwd(buf, sizeof buf - 1));
	printf("Did we find %s there? %s\n", folder, (stat(folder, &sb) == 0 && S_ISDIR(sb.st_mode)) ? "YES" : "NO");
}
