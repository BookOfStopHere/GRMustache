// The MIT License
// 
// Copyright (c) 2012 Gwendal Roué
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "GRMustacheAvailabilityMacros_private.h"

@protocol GRMustacheRendering;
@class GRMustacheTag;
@class GRMustacheContext;
@class GRMustacheTemplateRepository;

// Documented in GRMustache.h
typedef struct {
    int major;
    int minor;
    int patch;
} GRMustacheVersion;

@interface GRMustache: NSObject

// Documented in GRMustache.h
+ (GRMustacheVersion)version GRMUSTACHE_API_PUBLIC;

// Documented in GRMustache.h
+ (void)preventNSUndefinedKeyExceptionAttack GRMUSTACHE_API_PUBLIC;

// Documented in GRMustache.h
+ (id<GRMustacheRendering>)renderingObjectForObject:(id)object GRMUSTACHE_API_PUBLIC;

// Documented in GRMustache.h
+ (id<GRMustacheRendering>)renderingObjectWithBlock:(NSString *(^)(GRMustacheTag *tag, GRMustacheContext *context, BOOL *HTMLSafe, NSError **error))block GRMUSTACHE_API_PUBLIC;

/**
 * Returns the HTML-escaped version of the string parameter.
 *
 * Characters & < > " ' are escaped to &amp; &lt; &gt; &quot; &apos;
 * respectively.
 *
 * Be cautious with mutable string input: this method may return its input.
 *
 * @param string  The string to be HTML-escaped
 * @return An HTML-escaped string
 */
+ (NSString *)escapeHTML:(NSString *)string;

@end
