class-dump-c
==========

It is no longer necessary to build using Theos, there are native build targets in the Xcode project as well now.

This is a port for Theos build by me.

class-dump is a command-line utility for examining the Objective-C
segment of Mach-O files.  It generates declarations for the classes,
categories and protocols.  This is the same information provided by
using 'otool -ov', but presented as normal Objective-C declarations.

The latest version and information is available at:

    http://stevenygard.com/projects/class-dump

Usage
-----

    class-dump-c 4.2.0 (64 bit)
    Usage: classdumpc [options] <mach-o-file>

      where options are:
            -a             show instance variable offsets
            -A             show implementation addresses
            --arch <arch>  choose a specific architecture from a universal binary (ppc, ppc64, i386, x86_64)
            -C <regex>     only display classes matching regular expression
            -f <str>       find string in method name
            -H             generate header files in current directory, or directory specified with -o
            -I             sort classes, categories, and protocols by inheritance (overrides -s)
            -o <dir>       output directory used for -H
            -r             recursively expand frameworks and fixed VM shared libraries
            -s             sort classes and categories by name
            -S             sort methods by name
            -t             suppress header in output, for testing
            -e             dump the entitlements
            --list-arches  list the arches in the file, then exit
            --sdk-ios      specify iOS SDK version (will look in /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS<version>.sdk
            --sdk-mac      specify Mac OS X version (will look in /Developer/SDKs/MacOSX<version>.sdk
            --sdk-root     specify the full SDK root path (or use --sdk-ios/--sdk-mac for a shortcut)

- class-dump-ios AppKit:

    classdumpios /System/Library/Frameworks/AppKit.framework

- class-dump-ios UIKit:

    classdumpios /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.3.sdk/System/Library/Frameworks/UIKit.framework

- class-dump-ios UIKit and all the frameworks it uses:

    classdumpios /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS4.3.sdk/System/Library/Frameworks/UIKit.framework -r --sdk-ios 4.3

- class-dump-ios UIKit (and all the frameworks it uses) from developer tools that have been installed in /Dev42 instead of /Developer:

    classdumpios /Dev42/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS5.0.sdk/System/Library/Frameworks/UIKit.framework -r --sdk-root /Dev42/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS5.0.sdk


License
-------

This file is part of class-dump, a utility for examining the
Objective-C segment of Mach-O files.
Copyright (C) 1997-2019 Steve Nygard.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
