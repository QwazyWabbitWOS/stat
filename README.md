# stat
This is a quick hack to test the pending changes to MSVC's deprecation of the POSIX function names in their headers. The use of the stat function is incidental. The real interest is in `_getcwd` and the `_CRT_DECLARE_NONSTDC_NAMES`, `_CRT_NONSTDC_NO_WARNINGS` macros. I just happened to have the stat project handy when the discussion of the POSIX functions within MSVC context came up.