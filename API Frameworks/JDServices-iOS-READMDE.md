JDServices-iOS
==============
[![Build Status](https://ci-myapps.sharedservices-prod.us.i01.c01.johndeerecloud.com/buildStatus/icon?job=MobileSDK-Pipeline/JDServices-iOS/develop)](https://ci-myapps.sharedservices-prod.us.i01.c01.johndeerecloud.com/job/MobileSDK-Pipeline/job/JDServices-iOS/)
[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)

iOS API client for Axiom platform `api.deere.com` endpoints.

## Contribution
Contributions are welcome! Just follow the [contribution guide](.github/CONTRIBUTING.md).

## How to integrate this library
This library is available as an iOS framework.

### Carthage

```ruby
github "https://github.deere.com/MobileSDK/JDServices-iOS"
```

Add the dynamic framework `JDServices.framework` and sub-dependencies `AFNetworking.framework` and `SBJSON5.framework` to your app target.

### CocoaPods
Available in the _DeerePods_ Specs repository.

```ruby
source 'https://github.deere.com/MobileSDK/DeerePods.git'
pod 'JDServices'
```

or

```ruby
pod 'JDServices', :git => 'git@github.deere.com:MobileSDK/JDServices-iOS.git'
```

### Transport Security
iOS 9+ Apps: You've to add the following Transport Security Exception into the Info.plist of your application.

```xml
<key>NSAppTransportSecurity</key>
<dict>
	<key>NSAllowsArbitraryLoads</key>
	<true/>
	<key>NSExceptionDomains</key>
	<dict>
		<key>deere.com</key>
		<dict>
			<key>NSExceptionAllowsInsecureHTTPLoads</key>
			<true/>
			<key>NSIncludesSubdomains</key>
			<true/>
			<key>NSTemporaryExceptionMinimumTLSVersion</key>
			<string>TLSv1.1</string>
			<key>NSTemporaryThirdPartyExceptionRequiresForwardSecrecy</key>
			<false/>
		</dict>
	</dict>
</dict>
```

## How to use this library
1. [Initialize JDServices](#api-keys) with your API keys
2. Present the [login screen](#login)
3. Call the [endpoints](#endpoints)

### API Keys
API consumer and secret key are required to access the MyJohnDeere API. They can be requested on [developer.deere.com](https://developer.deere.com).

Use `JDServicesSetup` to initialize your environment.
Please obfuscate your API keys to make it more difficult to extract the keys from the compiled binary.

```objc
NSString *consumerKey = JDObfuscate._m._y._c._o._n._s._u._m._e._r._k._e._y._1._2._3;
NSString *secretKey = JDObfuscate._m._y._s._e._c._r._e._t._k._e._y._1._2._3;

//Setup consumer and secret key for the STORE environment
[JDServicesSetup setupConsumerKey:consumerKey andSecretKey:secretKey];
```

### Environments
Multiple environments are supported. They must be initialized first.

```objc
[JDServicesSetup setupEnvironment:JDEnvironmentDEV withConsumerKey:consumerKey andSecretKey:secretKey];
[JDServicesSetup setupEnvironment:JDEnvironmentQA withConsumerKey:consumerKey andSecretKey:secretKey];
[JDServicesSetup setupEnvironment:JDEnvironmentCERT withConsumerKey:consumerKey andSecretKey:secretKey];
[JDServicesSetup setupEnvironment:JDEnvironmentPROD withConsumerKey:consumerKey andSecretKey:secretKey];
[JDServicesSetup setupEnvironment:JDEnvironmentSTORE withConsumerKey:consumerKey andSecretKey:secretKey];

//Set the active environment
[JDServicesSetup setActiveEnvironment:JDEnvironmentSTORE];
```
  
You can also define a custom sandbox environment.

```objc
JDEnvironmentConfiguration *sandboxConfiguration = [[JDEnvironmentConfiguration alloc] init];
sandboxConfiguration.baseURL = @"http://localhost.jdnet.deere.com:8081/platform/";
sandboxConfiguration.consentToUseDataURI = @"http://localhost.jdnet.deere.com:8082/consentToUseOfData/";
sandboxConfiguration.consumerKey = consumerKey;
sandboxConfiguration.secretKey = secretKey;

[JDServicesSetup setupSandboxEnvironmentWithConfiguration:sandboxConfiguration];
```

## Login
* A valid OAuthToken is needed to access the API. The login process is wrapped by the `JDLoginViewController`(`JDLoginViewControllerDelegate` tells you the status).

<img src="./common/screenshots/JDServices-iOS-LoginViewController.png" height="333">

* You can bypass the login by injecting an OAuth token with the `JDTokenInjectionVC`. 

* There is no need to show the login view if the user was logged in before `[JDSecretManager isLoggedIn]`.
  
## Endpoints
List of supported endpoints

* `chemicals`
* `clients`
* `cropTypes`
* `fields`
* `files`
* `fileResources`
* `firmwares`
* `flags`
* `forecast`
* `implements`
* `jobs`
* `machines`
* `machineStylePreferences`
* `mobileAccess`
* `notes`
* `organizations`
* `presignedUrl`
* `products`
* `staff`
* `tasks`
* `tillageTypes`
* `users`
* `varieties`
* `variableRepresentations`
* `weather`
* `workQuestions`

A lot of requests need the `organizationID`. It's best practice to call that endpoint first.

If you need a new endpoint, just follow the steps in the [Contribution Guide](https://github.deere.com/MobileSDK/JDServices-iOS/blob/dev/.github/CONTRIBUTING.md#how-to-add-a-new-endpoint).

```objc
[JDOrganizationRequests fetchOrganizationsWithEmbedOptions:(JDOrganizationEmbedPreferences | JDOrganizationEmbedAddresses)
                               completionBlockWithResponse:^(NSArray<JDOrganization *> *organizations, NSError *error, JDResponse *response) {

                                  if (organizations) {
                                       JDLogInfo(@"Fetched %lu organizations.", (unsigned long) organizations.count);

                                  } else if (error) {
                                       JDLogWarn(@"Unable to fetch organization list: %@", ((error) ? error.localizedDescription : nil));

```

## Logging
`JDLogUtils` provides file log features.

* Use `[JDLogUtils setLogLevel:]` to change the log level.
* Default is `JDLogLevelInfo`
* Use `JDLogLevelMute` to disable logging

Use the macros `JDLogDebug(), JDLogInfo(), JDLogWarn and JDLogError()` for file and command line logging.

`[JDLogUtils setHTTPLogEnabled:YES]` writes the HTTP payload into a separate file.

You can adjust the path for the log files with `[JDLogUtils setLogPath:]`.
