//
//  YWModular.h
//  YWModular
//
//  Created by huanglei on 17/2/15.
//  Copyright © 2017年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <mach-o/loader.h>

/**
 *  The load priority of ServiceImpls.
 *  ServiceImpls will be loaded immediately when YWModular setup except for ServiceImpls with YWServiceImplPriorityLevelLazy.
 */
typedef NS_ENUM(NSUInteger, YWServiceImplPriorityLevel) {
    /// The most fundamental services
    YWServiceImplPriorityLevelFundamental = 4000000,
    /// Context built-in services or logics
    YWServiceImplPriorityLevelBuiltIn = 3000000,
    /// Extension services, normally implemented outside the context itself.
    YWServiceImplPriorityLevelExtension = 2000000,
    /// Lazy loaded services, will not be load immediately when context modular is loading
    YWServiceImplPriorityLevelLazy = 1000000,
};

/// Error Domain
#define kYWModularErrorDomain   @"kYWModularErrorDomain"

typedef NS_ENUM(NSUInteger, kYWModularErrorCode) {
    /// for setup
    
    /// has already setup
    kYWModularErrorCodeHasAlreadySetup = 10000,
    /// invalid section name
    kYWModularErrorCodeInvalidSectionName,
    
};

typedef NS_ENUM(NSUInteger, kYWModularWarningCode) {
    /// for setup
    
    /// implict dependency exsits
    kYWModularWarningCodeImplictDependency = 1000000,
    /// invalid ServiceImpl description
    kYWModularWarningCodeInvalidServiceImplDescription,
    /// failed to fulfill ServiceImpl instance
    kYWModularWarningCodeFailedToInstantiation,
};

/**
 *  One ServiceImpl instance must confirm to this protocol.
 *  It will be retained by the modular object of some context.
 */
@protocol YWServiceImplProtocol <NSObject>

@required

/**
 *  The stantard initialize function of ServiceImpls
 *  @param aContextRef Context Object, must be WEAK referrenced by ServiceImpl, otherwise it will lead to circular referrence.
 *  @param aExtraInfo The extra infomation, it can be strong referrenced, because there is requirement to this dictionary.
 */
- (instancetype)initWithContextRef:(id)aContextRef extraInfo:(NSDictionary *)aExtraInfo;

@optional
/**
 *  The priority of this ServiceImpl.
 *  This function is optional, the default value is YWServiceImplPriorityLevelLazy
 *  @note The return value is NSUInteger, but not YWServiceImplPriorityLevel.
 *  This means you can specify a value below or uppon some level to control the precise priority.
 *  We recommend to accurately set the priority of the ServiceImpls, in particularly with fundamental modules.
 */
+ (NSUInteger)implPriority;

@optional


@end


/**
 *  The modular object, in general, belongs to some context. 
 *  For example, 'YWAPI', which is the unique entrance of YWIMSDK functions.
 *  Or, 'YWIMCore', which is the context of one IM Account to communicate with 
 *  IM server.
 *
 *  When the modular(context) is been loaded, the modular will search the 
 *  ServiceImpl classes, which are registered to this context by themself.
 *
 *  The YWModular object uses the standard initialize function to construct the 
 *  instances of ServiceImpls, and will retain those instances for callers outside.
*/
@interface YWModular : NSObject

/**
 *  @param aSectionName Always use @YW_MODULAR_SECTIONNAME(aContextName) macro definition to make the section name of a context.
 *  @param aContextRef The context object. It will be weak referrenced by modular.
 *  @param aExtraInfo Extra information, this dictionary will be retained, please be careful.
 */
- (instancetype)initWithSectionName:(NSString *)aSectionName
                         contextRef:(id)aContextRef
                          extraInfo:(NSDictionary *)aExtraInfo;

/**
 *  Setup the modular, during the setup, all ServiceImpls registered to this modular will be loaded.
 *  @param aGetError Get the error of the setup. ErrorCode = 0 is success.
 *  @param aGetWarnings Not serious error, but should take attention to those warnings, for example, implict dependencies.
 */
- (void)setupWithError:(NSError *__autoreleasing *)aGetError warnings:(NSArray<NSError *> *__autoreleasing *)aGetWarnings;

/**
 *  forbid the original initialize function
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 *  Get the ServiceImpl instance with protocol symbol from a modular.
 *  Usage: YW_MODULAR_GET_SERVICE_INSTANCE(self.modular, IYWTestService)
 */
#define YW_MODULAR_GET_SERVICE_INSTANCE(aModular, aProtocol) \
(id<aProtocol>)[aModular getServiceInstanceWithName:@#aProtocol];

/**
 *  Get the ServiceImpl instance with protocol name.
 *  @note This is thread-safety.
 */
- (id)getServiceInstanceWithName:(NSString *)aServiceName;

/**
 *  Set a ServiceImpl instance with the protocol name manually.
 *  This isn't a recommended method. Just use for some special scene.
 *  @note Thread-safety.
 */
- (void)setServiceInstance:(id)aInstance withName:(NSString *)aServiceName;

@end

#pragma mark - Internal Definitions, Just Ignore, See Public Definitions below

/// for address_sanitizer mode
#if __has_feature(address_sanitizer)
#define __YW_MODULAR_SEGNAME   SEG_OBJC
#else
#define __YW_MODULAR_SEGNAME   SEG_DATA
#endif

/// section name prefix, to avoid conflict
#define __YW_MODULAR_SECTIONNAME_PREFIX   "YW_"

/// Section name, such as "YW_YWAPI"
#define __YW_MODULAR_SECTIONNAME(aContextName) \
__YW_MODULAR_SECTIONNAME_PREFIX #aContextName

/// ServiceImpl description separator
#define __YW_MODULAR_SERVICEIMPL_DESC_SEPARATOR "//"

/// ServiceImpl description item index
typedef NS_ENUM(NSUInteger, __YW_MODULAR_SERVICEIMPL_DESC_ITEM) {
    __YW_MODULAR_SERVICEIMPL_DESC_ITEM_CLASSNAME,
    __YW_MODULAR_SERVICEIMPL_DESC_ITEM_PROTOCOLS,
    __YW_MODULAR_SERVICEIMPL_DESC_ITEM_COUNT
};


#pragma mark - Public Definitions

/**
 *  Make the section name from aContextName. It can be used to create a modular object.
 *  Example: YW_MODULAR_SECTIONNAME(YWAPI)  ===>>>   @"YW_YWAPI"
 *
 *  @param aContextName The name of a context, the length limit is 6. And because of the length limitation, abbreviation should be used. For example, "YWAPI", "IMCORE" etc.
 */
#define YW_MODULAR_SECTIONNAME(aContextName) \
@__YW_MODULAR_SECTIONNAME(aContextName)

/**
 *  This definition is used to register to some context,
 *  normally inside the implementation file of one ServiceImpl class.
 *
 *  For example: YWRegisterServiceImpl("YWAPI", YWTestServiceImpl, IYWTestService1, IYWTestService2)
 *  =====>   char *kSectStrYWTestServiceImplYWAPI __attribute((used, section("__DATA,YW_YWAPI"))) = "YWTestServiceImpl//IYWTestService1, IYWTestService2";
 *  =====>   @interface YWTestServiceImpl () <IYWTestService1, IYWTestService2> @end
 *  PS: Use NSObject to fix macro definition conflict of angle brackets.
 *
 *  @param aContextName The name of a context.
 *  @param aImplClassName The name of ServiceImpl class.
 *  @param ... The service protocols which are implemented by this ServiceImpl class.
 */
#define YWRegisterServiceImpl(aContextName, aImplClassName, ...) \
char *kSectStr##aImplClassName##aContextName \
__attribute((used, section(__YW_MODULAR_SEGNAME "," __YW_MODULAR_SECTIONNAME(aContextName)))) \
= #aImplClassName __YW_MODULAR_SERVICEIMPL_DESC_SEPARATOR #__VA_ARGS__; \
\
@interface aImplClassName () < YWServiceImplProtocol, ##__VA_ARGS__, NSObject > @end





