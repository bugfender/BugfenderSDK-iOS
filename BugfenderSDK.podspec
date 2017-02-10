Pod::Spec.new do |s|
  s.name     = 'BugfenderSDK'
  s.version  = '1.4.1'
  s.ios.deployment_target     = '8.0'
  s.license  = { :type => 'Commercial', :text => 'See http://bugfender.com/terms-of-service/' }
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
                        cp BugfenderSDK.framework/BugfenderSDK libBugfenderSDK.a
                   CMD
  s.subspec 'ObjC' do |x|
    x.source_files = 'BugfenderSDK.h'
    x.preserve_paths = 'libBugfenderSDK.a'
    x.vendored_libraries = 'libBugfenderSDK.a'
    x.libraries = 'BugfenderSDK'
    x.xcconfig = { 'HEADER_SEARCH_PATHS' => "${PODS_ROOT}/#{s.name}" }
  end
  s.subspec 'Swift' do |x|
    x.dependency 'BugfenderSDK/ObjC'
    x.source_files = 'Swift/*.swift'
  end
end

