#
# Be sure to run `pod lib lint AliSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'AliSDK'
  s.version          = '0.1.0'
  s.summary          = '使用到的阿里SDK集合'
  s.description      = <<-DESC
使用到的阿里SDK集合，主要是为了防止产生冲突，所以将framework封装到pod库中进行管理
                       DESC

  s.homepage         = 'https://github.com/TimeKillerA/AliSDK'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'yuchenzheng' => '378306664@qq.com' }
  s.source           = { :git => 'https://github.com/TimeKillerA/AliSDK.git', :tag => s.version.to_s }
  s.ios.deployment_target = '8.0'
  s.compiler_flags = '-ObjC'
  s.source_files = 'AliSDK/Classes/**/*'
  
  s.resource = 'AliSDK/vendor/*.jpg', 'AliSDK/vendor/*.bundle'
  
  # s.resource_bundles = {
  #   'AliSDK' => ['AliSDK/Assets/*.png']
  # }

  s.frameworks = 'UIKit', 'AddressBook', 'SystemConfiguration', 'CoreLocation', 'CoreTelephony', 'CoreData', 'MobileCoreServices', 'ImageIO', 'AudioToolbox', 'AVFoundation', 'AssetsLibrary', 'CoreMotion'
  
  s.libraries = 'z', 'sqlite3', 'resolv', 'stdc++.6.0.9', 'sqlite3.0'
  
  s.ios.vendored_frameworks = '**/AliSDK/vendor/*.framework'
 
end
