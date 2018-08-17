Pod::Spec.new do |s|
  s.name     = 'BugfenderSDK'
  s.version  = '1.5.5'
  s.ios.deployment_target     = '8.0'
  s.license  = { :type => 'Commercial', :text => 'See https://bugfender.com/terms-of-service/' }
  s.summary  = 'Bugfender: a mobile remote logger'
  s.description = 'A modern remote logger tailor-made for mobile development.'
  s.homepage = 'https://bugfender.com'
  s.author   = { 'Bugfender' => 'support@bugfender.com' }
  s.social_media_url = 'https://twitter.com/bugfenderapp'
  s.requires_arc = true
  s.source   = {
    :git => 'https://github.com/bugfender/BugfenderSDK-iOS.git',
    :tag => s.version.to_s
  }
  s.prepare_command = <<-CMD
                        cp BugfenderSDK.framework/Headers/BugfenderSDK.h BugfenderSDK.h
                        cp BugfenderSDK.framework/BugfenderSDK libBugfenderSDKstatic.a
                   CMD
  s.default_subspecs = "Swift"
  s.frameworks = "Foundation", "SystemConfiguration", "Security", "MobileCoreServices"
  s.library = 'c++'
  s.subspec 'ObjC' do |x|
    x.vendored_library = 'libBugfenderSDKstatic.a'
    x.source_files = 'BugfenderSDK.h'
  end
  s.subspec 'Swift' do |x|
    x.vendored_library = 'libBugfenderSDKstatic.a'
    x.source_files = 'swift/*.swift', 'BugfenderSDK.h'
  end
end
