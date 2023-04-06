Pod::Spec.new do |s|
  s.name     = 'BugfenderSDK'
  s.version  = '1.12.1'
  s.ios.deployment_target     = '11.0'
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
  s.swift_versions = ['5.1']
  s.frameworks = "Foundation", "SystemConfiguration", "Security", "MobileCoreServices"
  s.library = 'c++'
  s.vendored_frameworks = 'BugfenderSDK.xcframework'
  s.cocoapods_version = '>= 1.10.0'
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'arm64 arm64e armv7 armv7s x86_64' }
  s.preserve_paths = ['upload-symbols.sh']
  s.prepare_command = <<-PREPARE_COMMAND_END
    cp -f ./xcode-upload-symbols/upload-symbols.sh ./upload-symbols.sh
  PREPARE_COMMAND_END

end
