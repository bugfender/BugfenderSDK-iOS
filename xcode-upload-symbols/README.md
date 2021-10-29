Bugfender iOS Symbols Upload Script
===================================

Used to automatically upload dSYM bundles to [Bugfender](https://bugfender.com).

## Usage
The script is generally meant to be called from XCode build environment.

For that we need to create a new Run Script on our Build Phases following this steps:

* Go to your App settings.

* Select your main target from the *TARGETS* list on the left.

* Go to *Build Phases* tab.

* Open menu under the `+` sign and select *New Run Script Phase*.

* Under the shell portion of *Run Script* add a script call to the script.
    * If you are using CocoaPods:
      ```sh
      ${PODS_ROOT}/BugfenderSDK/upload-symbols.sh <bugfender_symbolication_token>
      ```   
      
    * If you copied the script manually:
      ```sh
      <path_to_the_script>/upload-symbols.sh <bugfender_symbolication_token>
      ```   
  
* The **bugfender symbolication token** can be obtained from the Bugfender Dashboard and needs to be specified either as a first argument to the script or setting the `BUGFENDER_SYMBOLICATION_TOKEN` environment variable.

* Done!

![XCode Build Phases](/xcode-upload-symbols/xcode.png)
