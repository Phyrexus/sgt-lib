include(LibFindMacros)

libfind_pkg_check_modules(catch_PKGCONF Catch)

find_path(catch_INCLUDE_DIR
    NAMES catch.hpp
    PATHS ${catch_PKGCONF_INCLUDE_DIRS}
)

libfind_process(catch)
