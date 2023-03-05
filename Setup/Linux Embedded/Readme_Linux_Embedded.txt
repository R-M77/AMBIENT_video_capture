Copyright © 2014	FEIG ELECTRONIC GmbH, All Rights Reserved.
			Lange Strasse 4
			D-35781 Weilburg
			Federal Republic of Germany
			phone    : +49 6471 31090
			fax      : +49 6471 310999
			e-mail   : obid-support@feig.de
			Internet : http://www.feig.de

OBID and OBID i-scan are registereds trademark of FEIG ELECTRONIC GmbH


===============================
	ID ISC.SDK.Linux_embedded

	    V4.06.10

	   2014-12-11
===============================


1. What is new (main changes)
- This SDK supports actually only ARMv5TE, ARMv6 and ARMv7-a. Other platforms on request.
- Support for new Reader type ID ISC.CPR60
- Linux: Bugfix for Notification-Mode
- Support for new embedded Linux platform: ARMv7-a with hard-fp and thumb-mode (e.g. Odroid U3 with Debian)


NOTE: To learn more about OBID i-scan Readers use ISOStart V9.8.1 (or higher) and for OBID classic-pro Readers use CPRStart V9.7.1 (or higher)


2. Installation
Copy all directories into your local path.
To install the library files, follow the installation instructions of the manuals.
Cyphered protocol transmission depends on the installation of openSSL V0.9.8 or higher, which is not part of this SDK.


3. C++ Sample Code
- Please refer to the free available SDK for standard Linux (ID ISC.SDK.Linux) or take source code snippets from ID ISC.SDK.Win


4. Compiler Suite and Compiler Settings
- for ARMv5te: Mentor Graphics Sourcery CodeBench Lite Edition 2013.11-33 arm-none-linux-gnueabi    (-mabi=aapcs-linux -march=armv5te -mfloat-abi=softfp)
- for ARMv6  : Mentor Graphics Sourcery CodeBench Lite Edition 2013.11-33 arm-none-linux-gnueabi    (-mabi=aapcs-linux -march=armv6   -mfloat-abi=softfp)
- for ARMv6 vfp hard-fp ARM1176jfz-s (Raspberry Pi): gcc-linaro-arm-linux-gnueabihf-raspbian-2012.08-20120724_linux
- for ARMv7-a with soft-fp: Mentor Graphics Sourcery CodeBench Lite Edition 2013.11-33 arm-none-linux-gnueabi    (-mabi=aapcs-linux -march=armv7-a -mfloat-abi=softfp -mfpu=vfpv3-d16)
- for ARMv7-a with hard-fp: Linaro 4.9-2014.06 arm-linux-gnueabihf    (-mabi=aapcs-linux -march=armv7-a -mfloat-abi=hard -mfpu=vfpv3)
- for ARMv7-a with hard-fp and thumb-mode (e.g. Odroid U3 with Debian): Linaro 4.9-2014.06 arm-linux-gnueabihf    (-mabi=aapcs-linux -march=armv7-a -mfloat-abi=hard -mfpu=vfpv3-d16 -mthumb)
