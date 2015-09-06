#include <CoreFoundation/CoreFoundation.h>
#include <CoreServices/CoreServices.h>
#include <QuickLook/QuickLook.h>

OSStatus GeneratePreviewForURL(void *thisInterface, QLPreviewRequestRef preview, CFURLRef url, CFStringRef contentTypeUTI, CFDictionaryRef options);
void CancelPreviewGeneration(void *thisInterface, QLPreviewRequestRef preview);

/* -----------------------------------------------------------------------------
   Generate a preview for file

   This function's job is to create preview for designated file
   ----------------------------------------------------------------------------- */

OSStatus GeneratePreviewForURL(void *thisInterface, QLPreviewRequestRef preview, CFURLRef url, CFStringRef contentTypeUTI, CFDictionaryRef options)
{
    CFStringRef filename = CFStringCreateWithCString(kCFAllocatorDefault, "Contents.swift", kCFStringEncodingUTF8);
    url = CFURLCreateCopyAppendingPathComponent(kCFAllocatorDefault, url, filename, false);
    
    CFStringRef contentType = CFStringCreateWithCString(kCFAllocatorDefault, "public.swift-source", kCFStringEncodingUTF8);
    QLPreviewRequestSetURLRepresentation(preview, url, contentType, NULL);
    
    CFRelease(filename);
    CFRelease(contentType);
    CFRelease(url);
    
    return noErr;
}

void CancelPreviewGeneration(void *thisInterface, QLPreviewRequestRef preview)
{
    // Implement only if supported
}
