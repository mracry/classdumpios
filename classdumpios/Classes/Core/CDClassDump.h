// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-2019 Steve Nygard.

#import "CDFile.h" // For CDArch

#define CLASS_DUMP_BASE_VERSION "1.0.1 (64 bit)"

#ifdef DEBUG
#define CLASS_DUMP_VERSION CLASS_DUMP_BASE_VERSION " (iOS port by DreamDevLost)(Debug version compiled " __DATE__ " " __TIME__ ")"
#else
#define CLASS_DUMP_VERSION CLASS_DUMP_BASE_VERSION
#endif

@class CDFile;
@class CDTypeController;
@class CDVisitor;
@class CDSearchPathState;

@interface CDClassDump : NSObject

@property (readonly) CDSearchPathState *searchPathState;

@property (assign) BOOL shouldProcessRecursively;
@property (assign) BOOL shouldSortClasses;
@property (assign) BOOL shouldSortClassesByInheritance;
@property (assign) BOOL shouldSortMethods;
@property (assign) BOOL shouldShowIvarOffsets;
@property (assign) BOOL shouldShowMethodAddresses;
@property (assign) BOOL shouldShowHeader;
@property (assign) BOOL verbose;

@property (strong) NSRegularExpression *regularExpression;
- (BOOL)shouldShowName:(NSString *)name;

@property (strong) NSString *sdkRoot;

@property (readonly) NSArray *machOFiles;
@property (readonly) NSArray *objcProcessors;

@property (assign) CDArch targetArch;

@property (nonatomic, readonly) BOOL containsObjectiveCData;
@property (nonatomic, readonly) BOOL hasEncryptedFiles;
@property (nonatomic, readonly) BOOL hasObjectiveCRuntimeInfo;

@property (readonly) CDTypeController *typeController;

- (BOOL)loadFile:(CDFile *)file error:(NSError **)error;
- (void)processObjectiveCData;

- (void)recursivelyVisit:(CDVisitor *)visitor;

- (void)appendHeaderToString:(NSMutableString *)resultString;

- (void)registerTypes;

- (void)showHeader;
- (void)showLoadCommands;
+ (void)logLevel:(NSInteger)level stringWithFormat:(NSString *)fmt, ...;
+ (void)logLevel:(NSInteger)level string:(NSString *)string;
+ (BOOL)isVerbose;
+ (BOOL)isDebug;
+ (BOOL)printFixupData;
@end

extern NSString *CDErrorDomain_ClassDump;
extern NSString *CDErrorKey_Exception;
