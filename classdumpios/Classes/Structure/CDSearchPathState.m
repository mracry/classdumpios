// -*- mode: ObjC -*-

//  This file is part of class-dump, a utility for examining the Objective-C segment of Mach-O files.
//  Copyright (C) 1997-2019 Steve Nygard.

#import "CDSearchPathState.h"

@interface CDSearchPathState ()
@property (readonly) NSMutableArray *searchPathStack;
@end

#pragma mark -

@implementation CDSearchPathState
{
    NSString *_executablePath;
    NSMutableArray *_searchPathStack;
}

- (id)init;
{
    if ((self = [super init])) {
        _executablePath = nil;
        _searchPathStack = [[NSMutableArray alloc] init];
    }

    return self;
}

#pragma mark -

- (void)pushSearchPaths:(NSArray *)searchPaths;
{
    [self.searchPathStack addObject:searchPaths];
}

- (void)popSearchPaths;
{
    if ([self.searchPathStack count] > 0) {
        [self.searchPathStack removeLastObject];
    } else {
        DLog(@"Warning: Unbalanced popSearchPaths");
    }
}

- (NSArray *)searchPaths;
{
    NSMutableArray *result = [NSMutableArray array];
    for (NSArray *group in self.searchPathStack) {
        [result addObjectsFromArray:group];
    }

    return [result copy];
}

@end
