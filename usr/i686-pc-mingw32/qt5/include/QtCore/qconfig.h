/* Everything */

/* Qt Edition */
#ifndef QT_EDITION
#  define QT_EDITION QT_EDITION_OPENSOURCE
#endif
/* Compile time features */
/* Qt was configured for a static build */
#if !defined(QT_SHARED) && !defined(QT_STATIC)
# define QT_STATIC
#endif

#define QT_POINTER_SIZE 4
#define QT_REDUCE_RELOCATIONS

// Compiler sub-arch support
#define QT_COMPILER_SUPPORTS_SSE2
#define QT_COMPILER_SUPPORTS_SSE3
#define QT_COMPILER_SUPPORTS_SSSE3
#define QT_COMPILER_SUPPORTS_SSE4_1
#define QT_COMPILER_SUPPORTS_SSE4_2
#define QT_COMPILER_SUPPORTS_AVX
#define QT_COMPILER_SUPPORTS_AVX2

#ifndef QT_BOOTSTRAPPED

#if defined(QT_BUILTIN_GIF_READER) && defined(QT_NO_BUILTIN_GIF_READER)
# undef QT_BUILTIN_GIF_READER
#elif !defined(QT_BUILTIN_GIF_READER) && !defined(QT_NO_BUILTIN_GIF_READER)
# define QT_BUILTIN_GIF_READER 1
#endif

#if defined(QT_LINKED_OPENSSL) && defined(QT_NO_LINKED_OPENSSL)
# undef QT_LINKED_OPENSSL
#elif !defined(QT_LINKED_OPENSSL) && !defined(QT_NO_LINKED_OPENSSL)
# define QT_LINKED_OPENSSL
#endif

#if defined(QT_NO_ALSA) && defined(QT_ALSA)
# undef QT_NO_ALSA
#elif !defined(QT_NO_ALSA) && !defined(QT_ALSA)
# define QT_NO_ALSA
#endif

#if defined(QT_NO_CLOCK_MONOTONIC) && defined(QT_CLOCK_MONOTONIC)
# undef QT_NO_CLOCK_MONOTONIC
#elif !defined(QT_NO_CLOCK_MONOTONIC) && !defined(QT_CLOCK_MONOTONIC)
# define QT_NO_CLOCK_MONOTONIC
#endif

#if defined(QT_NO_CUPS) && defined(QT_CUPS)
# undef QT_NO_CUPS
#elif !defined(QT_NO_CUPS) && !defined(QT_CUPS)
# define QT_NO_CUPS
#endif

#if defined(QT_NO_EGL) && defined(QT_EGL)
# undef QT_NO_EGL
#elif !defined(QT_NO_EGL) && !defined(QT_EGL)
# define QT_NO_EGL
#endif

#if defined(QT_NO_EGLFS) && defined(QT_EGLFS)
# undef QT_NO_EGLFS
#elif !defined(QT_NO_EGLFS) && !defined(QT_EGLFS)
# define QT_NO_EGLFS
#endif

#if defined(QT_NO_EVENTFD) && defined(QT_EVENTFD)
# undef QT_NO_EVENTFD
#elif !defined(QT_NO_EVENTFD) && !defined(QT_EVENTFD)
# define QT_NO_EVENTFD
#endif

#if defined(QT_NO_GETADDRINFO) && defined(QT_GETADDRINFO)
# undef QT_NO_GETADDRINFO
#elif !defined(QT_NO_GETADDRINFO) && !defined(QT_GETADDRINFO)
# define QT_NO_GETADDRINFO
#endif

#if defined(QT_NO_GETIFADDRS) && defined(QT_GETIFADDRS)
# undef QT_NO_GETIFADDRS
#elif !defined(QT_NO_GETIFADDRS) && !defined(QT_GETIFADDRS)
# define QT_NO_GETIFADDRS
#endif

#if defined(QT_NO_GLIB) && defined(QT_GLIB)
# undef QT_NO_GLIB
#elif !defined(QT_NO_GLIB) && !defined(QT_GLIB)
# define QT_NO_GLIB
#endif

#if defined(QT_NO_GSTREAMER) && defined(QT_GSTREAMER)
# undef QT_NO_GSTREAMER
#elif !defined(QT_NO_GSTREAMER) && !defined(QT_GSTREAMER)
# define QT_NO_GSTREAMER
#endif

#if defined(QT_NO_ICONV) && defined(QT_ICONV)
# undef QT_NO_ICONV
#elif !defined(QT_NO_ICONV) && !defined(QT_ICONV)
# define QT_NO_ICONV
#endif

#if defined(QT_NO_INOTIFY) && defined(QT_INOTIFY)
# undef QT_NO_INOTIFY
#elif !defined(QT_NO_INOTIFY) && !defined(QT_INOTIFY)
# define QT_NO_INOTIFY
#endif

#if defined(QT_NO_IPV6IFNAME) && defined(QT_IPV6IFNAME)
# undef QT_NO_IPV6IFNAME
#elif !defined(QT_NO_IPV6IFNAME) && !defined(QT_IPV6IFNAME)
# define QT_NO_IPV6IFNAME
#endif

#if defined(QT_NO_MREMAP) && defined(QT_MREMAP)
# undef QT_NO_MREMAP
#elif !defined(QT_NO_MREMAP) && !defined(QT_MREMAP)
# define QT_NO_MREMAP
#endif

#if defined(QT_NO_NIS) && defined(QT_NIS)
# undef QT_NO_NIS
#elif !defined(QT_NO_NIS) && !defined(QT_NIS)
# define QT_NO_NIS
#endif

#if defined(QT_NO_OPENVG) && defined(QT_OPENVG)
# undef QT_NO_OPENVG
#elif !defined(QT_NO_OPENVG) && !defined(QT_OPENVG)
# define QT_NO_OPENVG
#endif

#if defined(QT_NO_PULSEAUDIO) && defined(QT_PULSEAUDIO)
# undef QT_NO_PULSEAUDIO
#elif !defined(QT_NO_PULSEAUDIO) && !defined(QT_PULSEAUDIO)
# define QT_NO_PULSEAUDIO
#endif

#if defined(QT_NO_STYLE_GTK) && defined(QT_STYLE_GTK)
# undef QT_NO_STYLE_GTK
#elif !defined(QT_NO_STYLE_GTK) && !defined(QT_STYLE_GTK)
# define QT_NO_STYLE_GTK
#endif

#if defined(QT_NO_XRENDER) && defined(QT_XRENDER)
# undef QT_NO_XRENDER
#elif !defined(QT_NO_XRENDER) && !defined(QT_XRENDER)
# define QT_NO_XRENDER
#endif

#if defined(QT_NO_ZLIB) && defined(QT_ZLIB)
# undef QT_NO_ZLIB
#elif !defined(QT_NO_ZLIB) && !defined(QT_ZLIB)
# define QT_NO_ZLIB
#endif

#if defined(QT_RUNTIME_XCURSOR) && defined(QT_NO_RUNTIME_XCURSOR)
# undef QT_RUNTIME_XCURSOR
#elif !defined(QT_RUNTIME_XCURSOR) && !defined(QT_NO_RUNTIME_XCURSOR)
# define QT_RUNTIME_XCURSOR
#endif

#if defined(QT_RUNTIME_XFIXES) && defined(QT_NO_RUNTIME_XFIXES)
# undef QT_RUNTIME_XFIXES
#elif !defined(QT_RUNTIME_XFIXES) && !defined(QT_NO_RUNTIME_XFIXES)
# define QT_RUNTIME_XFIXES
#endif

#if defined(QT_RUNTIME_XINERAMA) && defined(QT_NO_RUNTIME_XINERAMA)
# undef QT_RUNTIME_XINERAMA
#elif !defined(QT_RUNTIME_XINERAMA) && !defined(QT_NO_RUNTIME_XINERAMA)
# define QT_RUNTIME_XINERAMA
#endif

#if defined(QT_RUNTIME_XINPUT) && defined(QT_NO_RUNTIME_XINPUT)
# undef QT_RUNTIME_XINPUT
#elif !defined(QT_RUNTIME_XINPUT) && !defined(QT_NO_RUNTIME_XINPUT)
# define QT_RUNTIME_XINPUT
#endif

#if defined(QT_RUNTIME_XRANDR) && defined(QT_NO_RUNTIME_XRANDR)
# undef QT_RUNTIME_XRANDR
#elif !defined(QT_RUNTIME_XRANDR) && !defined(QT_NO_RUNTIME_XRANDR)
# define QT_RUNTIME_XRANDR
#endif

#if defined(QT_SQL_ODBC) && defined(QT_NO_SQL_ODBC)
# undef QT_SQL_ODBC
#elif !defined(QT_SQL_ODBC) && !defined(QT_NO_SQL_ODBC)
# define QT_SQL_ODBC
#endif

#if defined(QT_SQL_PSQL) && defined(QT_NO_SQL_PSQL)
# undef QT_SQL_PSQL
#elif !defined(QT_SQL_PSQL) && !defined(QT_NO_SQL_PSQL)
# define QT_SQL_PSQL
#endif

#if defined(QT_SQL_SQLITE) && defined(QT_NO_SQL_SQLITE)
# undef QT_SQL_SQLITE
#elif !defined(QT_SQL_SQLITE) && !defined(QT_NO_SQL_SQLITE)
# define QT_SQL_SQLITE
#endif

#if defined(QT_SQL_TDS) && defined(QT_NO_SQL_TDS)
# undef QT_SQL_TDS
#elif !defined(QT_SQL_TDS) && !defined(QT_NO_SQL_TDS)
# define QT_SQL_TDS
#endif

#if defined(QT_USE_MATH_H_FLOATS) && defined(QT_NO_USE_MATH_H_FLOATS)
# undef QT_USE_MATH_H_FLOATS
#elif !defined(QT_USE_MATH_H_FLOATS) && !defined(QT_NO_USE_MATH_H_FLOATS)
# define QT_USE_MATH_H_FLOATS
#endif

#endif // QT_BOOTSTRAPPED

#define QT_QPA_DEFAULT_PLATFORM_NAME "windows"
