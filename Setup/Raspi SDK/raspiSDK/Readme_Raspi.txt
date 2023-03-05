Copyright © FEIG ELECTRONIC GmbH, All Rights Reserved.
			Lange Strasse 4
			D-35781 Weilburg
			Federal Republic of Germany
			phone    : +49 6471 31090
			fax      : +49 6471 310999
			e-mail   : identification-support@feig.de
			Internet : http://www.feig.de

OBID and OBID i-scan are registered trademarks of FEIG ELECTRONIC GmbH


============================================================================
	ID ISC.SDK.Raspi

        V5.05.02

	   2020-07-15

	with Image for Raspbian Stretch (GCC v6.3.0)
	with Image for Raspbian Buster (GCC v8.3.0)

============================================================================


1. What is new
C++:  The main Release Notes can be found in ReleaseNotes_Cpp.pdf
Java: The main Release Notes can be found in ReleaseNotes_Java.pdf
Minor improvements


NOTE: To learn more about FEIG readers use our Windows Tools ISOStart or CPRStart.


2. Compatibility
The libraries shipped with this SDK are compatible with Raspberry Pi 3 and 4 running Raspbian OS based on Debian.
For Raspberry Pi 1 and 2 is an older SDK available. The development and testing for these Raspberry Pi is discontinued.


3. Installation
Please follow the installation guide in
  Installation_Cpp_N70810-e-ID-B.pdf   or
  Installation_Java_N70812-e-ID-B.pdf


4. First Steps
To become familiar with the FEIG reader families, developers should read first the system manual of the reader.
We recommend to read secondly the tutorial. Although it is not yet completed, it gives a structured introduction into the library stack 
and the high-level APIs of the C++ and Java class libraries.
The migration guide (N80710-e-ID-B) contains necessary steps to migrate from old to new API.

Additionally, FEIG provides tools called ISOStart and CPRStart, which demonstrates all capabilities of each reader type.
These tools are a great help for developers to understand the commands, configuration and reader modes of an FEIG reader.


5. Samples can be found in the free available ID ISC.SDK.Linux or ID ISC.SDK.Java


===============================================================
REMARKS:
In case of USB communication errors we recommend an update of

- the firmware of your readers and

- the system software of your raspberry pi.
  An Update of your operating system can be done with:
  'sudo apt-get update'
  'sudo apt-get upgrade'
  An update of your hardware driver can be done with:
  'sudo apt-get rpi-update'

