/*
 
 Copyright (c) 2013, SMB Phone Inc.
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 The views and conclusions contained in the software and documentation are those
 of the authors and should not be interpreted as representing official policies,
 either expressed or implied, of the FreeBSD Project.
 
 */

#import <Foundation/Foundation.h>

@class HOPRolodexContact;
@class HOPContact;
@class HOPMessage;
@class HTTPDownloaderDelegate;

@interface APNSManager : NSObject<NSURLSessionDelegate, NSURLSessionTaskDelegate,HTTPDownloaderDelegate>

@property (nonatomic, strong) NSString* deviceToken;
@property  (nonatomic) int pushesToSend;
@property   (nonatomic) BOOL goingToBackground;

+ (id) sharedAPNSManager;
- (void) prepareUrbanAirShip;
//- (void) sendPushNotificationForDeviceToken:(NSString*) deviceToken message:(NSString*) message;
- (void) registerDeviceToken:(NSData*) devToken;

- (void) sendPushNotificationForContact:(HOPContact*) contact message:(NSString*) message missedCall:(BOOL) missedCall;
//- (void) sendRichPushNotificationForContact:(HOPContact*) contact message:(HOPMessage*) message missedCall:(BOOL) missedCall;
- (void) sendRichPushNotificationForMessage:(HOPMessage*) message missedCall:(BOOL) missedCall;
- (BOOL) areTherePushesForSending;

- (void) requestDeviceTokenForPeerURI:(NSString*) peerURI;
- (void) registerDeviceToken;
@end
