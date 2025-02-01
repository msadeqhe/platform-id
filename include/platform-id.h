/* Platform ID
 * Copyright (C) 2017-2025  Mohamad Sadeq Hojat-ol Eslami
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PLATFORM_ID_H_INCLUDED
#define PLATFORM_ID_H_INCLUDED

#if defined(__FreeBSD__)
	#define PLATFORM_FREEBSD
#elif defined(__NetBSD__)
	#define PLATFORM_NETBSD
#elif defined(__OpenBSD__)
	#define PLATFORM_OPENBSD
#elif defined(__DragonFly__)
	#define PLATFORM_DRAGONFLY
#elif defined(__APPLE__) && defined(__MACH__)
	#define PLATFORM_DARWIN
	#include <TargetConditionals.h>
	#if TARGET_OS_IPHONE == 1
		#define PLATFORM_IPHONE
		#if TARGET_OS_IOS == 1
			#define PLATFORM_IOS
		#elif TARGET_OS_WATCH == 1
			#define PLATFORM_WATCHOS
		#elif TARGET_OS_TV == 1
			#define PLATFORM_TVOS
		#endif
	#elif TARGET_OS_MAC == 1
		#define PLATFORM_MACOS
	#endif
#else
	#define PLATFORM_UNKNOWN
#endif

#ifndef PLATFORM_UNKNOWN
	#define PLATFORM_BSD
#else
	#undef PLATFORM_UNKNOWN
#endif

#if defined(__linux__)
	#define PLATFORM_LINUX
	#if defined(__gnu_linux__)
		#define PLATFORM_GNULINUX
	#elif defined(__gnu__linux__) || defined(__gnu__linux) // Oracle Developer Studio's ugly macro names
		#define PLATFORM_GNULINUX
	#elif defined(__ANDROID__)
		#define PLATFORM_ANDROID
	#endif
#elif defined(PLATFORM_BSD)
	// pass
#elif defined(__sun) && defined(__SVR4)
	#define PLATFORM_SOLARIS
#elif defined(__minix)
	#define PLATFORM_MINIX
#elif defined(_AIX)
	#define PLATFORM_AIX
#elif defined(__hpux)
	#define PLATFORM_HPUX
#else
	#define PLATFORM_UNKNOWN
#endif

#ifndef PLATFORM_UNKNOWN
	#define PLATFORM_UNIX
	#define PLATFORM_POSIX
#else
	#undef PLATFORM_UNKNOWN
#endif

#if defined(_WIN32)
	#define PLATFORM_WINDOWS
	#if defined(_WIN64)
		#define PLATFORM_WINDOWS_X64
	#else
		#define PLATFORM_WINDOWS_X32
	#endif
#elif defined(PLATFORM_UNIX)
	// pass
#elif defined(__unix__) || defined(__unix) // Find other Unix-based platforms
	#define PLATFORM_UNIX
	#include <unistd.h>
	#if defined(_POSIX_VERSION)
		#define PLATFORM_POSIX
	#endif
	#include <sys/param.h>
	#if defined(BSD)
		#define PLATFORM_BSD
	#endif
#else
	#define PLATFORM_UNKNOWN
#endif

#endif
