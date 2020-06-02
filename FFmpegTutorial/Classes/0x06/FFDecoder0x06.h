//
//  FFDecoder0x06.h
//  FFmpegTutorial
//
//  Created by Matt Reach on 2020/6/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef struct AVStream AVStream;
typedef struct AVFormatContext AVFormatContext;
typedef struct AVPacket AVPacket;
typedef struct AVFrame AVFrame;

@class FFDecoder0x06;
@protocol FFDecoderDelegate0x06 <NSObject>

@required
///解码器向 delegater 要一个 AVPacket
- (int)decoder:(FFDecoder0x06 *)decoder wantAPacket:(AVPacket *)packet;
///将解码后的 AVFrame 给 delegater
- (void)decoder:(FFDecoder0x06 *)decoder reveivedAFrame:(AVFrame *)frame;

@end

@interface FFDecoder0x06 : NSObject

@property (nonatomic, assign) AVFormatContext *ic;
@property (nonatomic, assign) int streamIdx;
@property (nonatomic, copy) NSString * name;
@property (nonatomic, weak) id <FFDecoderDelegate0x06> delegate;
@property (nonatomic, assign, readonly) AVStream * stream;
/**
 打开解码器，创建解码线程;
 return 0;（没有错误）
 */
- (int)open;
//开始解码
- (void)start;
//取消解码
- (void)cancel;
//内部线程join
- (void)join;

@end


NS_ASSUME_NONNULL_END
