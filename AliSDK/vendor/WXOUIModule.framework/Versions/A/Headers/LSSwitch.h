//
//  LSSwitch.h
//  Messenger
//
//  Created by Jai Chen on 15/6/1.
//
//

#import "DVSwitch.h"

@interface LSSwitch : DVSwitch

- (void)moveSlider:(CGFloat)indexOffset;
- (void)moveSliderFinished;

@property (strong, nonatomic) UIView *sliderView;
@property (strong, nonatomic) NSArray *strings;

@end
