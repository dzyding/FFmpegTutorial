//
//  MR0x15VideoRenderer.h
//  FFmpegTutorial-iOS
//
//  Created by Matt Reach on 2020/6/25.
//  Copyright © 2020 Matt Reach's Awesome FFmpeg Tutotial. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreMedia/CMSampleBuffer.h>

NS_ASSUME_NONNULL_BEGIN

@interface MR0x15VideoRenderer : UIView

- (void)enqueueSampleBuffer:(CMSampleBufferRef)buffer;
- (void)cleanScreen;

@end

NS_ASSUME_NONNULL_END
