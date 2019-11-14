Pod::Spec.new do |s|
  s.name     = 'BugfenderSDK'
  s.version  = '1.8.0'
  s.ios.deployment_target     = '8.0'
  s.license  = { :type => 'Commercial', :text => 'See https://bugfender.com/terms-of-service/' }
  s.summary  = 'Bugfender: a mobile remote logger'
  s.description = 'A modern remote logger tailor-made for mobile development.'
  s.homepage = 'https://bugfender.com'
  s.author   = { 'Bugfender' => 'support@bugfender.com' }
  s.requires_arc = true
  s.source   = {
    :git => 'https://github.com/bugfender/BugfenderSDK-iOS.git',
    :tag => s.version.to_s
  }
  s.swift_versions = ['3.0', '3.1', '4.0', '4.2', '5.0']
  s.frameworks = "Foundation", "SystemConfiguration", "Security", "MobileCoreServices"
  s.library = 'c++'
  s.vendored_framework = 'BugfenderSDK.framework'
end
